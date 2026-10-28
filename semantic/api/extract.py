# -*- coding: utf-8 -*-
"""Mechanical extraction: PyModuleDef / PyMethodDef from H0PP.so.

No execution, no network, no heuristics. Every value written is read from
section bytes plus (where applicable) the .rela.dyn relocation entry that
patches that word.
"""
import struct, sys, io, os

PATH = r"D:\tmp\H0PP.so"
OUT = r"D:\tmp\semantic\H0PP\api"

data = open(PATH, "rb").read()

# ---------------- ELF64 header ----------------
assert data[:4] == b"\x7fELF" and data[4] == 2 and data[5] == 1
e_shoff, = struct.unpack_from("<Q", data, 0x28)
e_shentsize, e_shnum, e_shstrndx = struct.unpack_from("<HHH", data, 0x3A)

secs = []
for i in range(e_shnum):
    off = e_shoff + i * e_shentsize
    name, typ, flags, addr, offset, size, link, info, align, entsize = \
        struct.unpack_from("<IIQQQQIIQQ", data, off)
    secs.append(dict(name_off=name, type=typ, addr=addr, offset=offset, size=size,
                     entsize=entsize, link=link, info=info))

shstr = secs[e_shstrndx]
def shname(off):
    s = shstr["offset"] + off
    return data[s:data.index(b"\0", s)].decode()

for s in secs:
    s["name"] = shname(s["name_off"])
byname = {s["name"]: s for s in secs}

def sec_of(addr):
    for s in secs:
        if s["type"] != 8 and s["addr"] and s["addr"] <= addr < s["addr"] + s["size"]:
            return s
    return None

def read_bytes(addr, n):
    s = sec_of(addr)
    if s is None:
        return None
    fo = s["offset"] + (addr - s["addr"])
    return data[fo:fo + n]

def cstr(addr):
    if addr == 0:
        return ""
    b = read_bytes(addr, 512)
    if b is None:
        return None
    z = b.find(b"\0")
    if z < 0:
        return None
    return b[:z].decode("utf-8", "backslashreplace")

# ---------------- symbol table (.symtab) ----------------
sym = byname[".symtab"]
strtab = secs[sym["link"]]
def symname(off):
    s = strtab["offset"] + off
    return data[s:data.index(b"\0", s)].decode()
syms = []   # (value, size, type, bind, shndx, name)
for i in range(sym["size"] // 24):
    off = sym["offset"] + i * 24
    nm, info, other, shndx, value, size = struct.unpack_from("<IBBHQQ", data, off)
    syms.append(dict(value=value, size=size, type=info & 0xF, bind=info >> 4,
                     shndx=shndx, name=symname(nm)))

# ---------------- relocations (.rela.dyn / .rela.plt) ----------------
relocs = {}   # place vaddr -> resolved qword
reloc_desc = {}  # place vaddr -> text
for rs in secs:
    if rs["type"] != 4:      # SHT_RELA
        continue
    tgt = secs[rs["link"]]   # symbol table used
    tstr = secs[tgt["link"]]
    for i in range(rs["size"] // 24):
        off = rs["offset"] + i * 24
        r_offset, r_info, r_addend = struct.unpack_from("<QQq", data, off)
        rtype = r_info & 0xFFFFFFFF
        rsym = r_info >> 32
        soff = tgt["offset"] + rsym * 24
        nm, info, other, shndx, value, size = struct.unpack_from("<IBBHQQ", data, soff)
        s0 = tstr["offset"] + nm
        symn = data[s0:data.index(b"\0", s0)].decode()
        if rtype == 8:            # R_X86_64_RELATIVE
            val = r_addend & 0xFFFFFFFFFFFFFFFF
            desc = "RELATIVE addend=0x%x" % val
        elif rtype in (1, 6):     # R_X86_64_64 / GLOB_DAT
            val = (value + r_addend) & 0xFFFFFFFFFFFFFFFF
            desc = "SYM %s+0x%x" % (symn, r_addend)
        else:
            continue
        relocs[r_offset] = val
        reloc_desc[r_offset] = desc

def qword(addr):
    """Resolve one 8-byte pointer: relocation wins, else raw bytes."""
    if addr in relocs:
        return relocs[addr], reloc_desc[addr]
    b = read_bytes(addr, 8)
    if b is None:
        return None, "unmapped"
    return struct.unpack("<Q", b)[0], "raw"

def dword(addr):
    b = read_bytes(addr, 4)
    return struct.unpack("<i", b)[0]

# ---------------- locate PyInit / module def / methods ----------------
pyinit = [s for s in syms if s["name"].startswith("PyInit_") and s["shndx"] != 0]
modsym = [s for s in syms if s["name"] in ("_ZL15module__pypinot", "module__pypinot")]
assert len(pyinit) == 1 and len(modsym) == 1
PI = pyinit[0]
MOD = modsym[0]

# PyModuleDef (CPython 3.x, 64-bit): base(ob_refcnt,ob_type,m_init,m_index,m_copy)=40
# then m_name @+40, m_doc @+48, m_size @+56, m_methods @+64, m_slots @+72,
# m_traverse @+80, m_clear @+88, m_free @+96  -> 104 bytes
md = MOD["value"]
m_name_p, _ = qword(md + 40)
m_doc_p, _ = qword(md + 48)
m_size = struct.unpack("<q", read_bytes(md + 56, 8))[0]
m_methods_p, methdesc = qword(md + 64)
m_slots_p, _ = qword(md + 72)
m_traverse_p, _ = qword(md + 80)
m_clear_p, _ = qword(md + 88)
m_free_p, _ = qword(md + 96)

# ---------------- walk PyMethodDef table ----------------
# 32 bytes: ml_name(8) ml_meth(8) ml_flags(4) pad(4) ml_doc(8)
methods = []
addr = m_methods_p
while True:
    b = read_bytes(addr, 32)
    if b is None:
        methods.append(dict(addr=addr, name=None, func=None, flags=None, doc=None,
                            err="unmapped entry at 0x%x" % addr))
        break
    name_p, func_p, flags, doc_p = struct.unpack("<QQi4xQ", b)
    if name_p == 0 and func_p == 0 and flags == 0 and doc_p == 0:
        break
    nm = cstr(name_p)
    fr, fdesc = qword(addr + 8)
    methods.append(dict(addr=addr, name=nm, name_p=name_p, name_desc="",
                        func=fr, func_sym=fdesc, flags=flags,
                        doc_p=doc_p, doc=cstr(doc_p), err=None))
    addr += 32
table_end = addr
sentinel = read_bytes(table_end, 32)
n_entries = len(methods)

# ---------------- strings from .rodata ----------------
ro = byname[".rodata"]
strings = []
i = 0
while i < ro["size"]:
    j = i
    while j < ro["size"] and 32 <= data[ro["offset"] + j] < 127:
        j += 1
    if j - i >= 1:
        strings.append((ro["addr"] + i, data[ro["offset"] + i:ro["offset"] + j].decode()))
        i = j
    else:
        i += 1

# ---------------- write outputs ----------------
os.makedirs(OUT, exist_ok=True)

with io.open(os.path.join(OUT, "methods.tsv"), "w", encoding="utf-8", newline="\n") as f:
    f.write("name\tfunc_addr\tflags\tdoc_addr\n")
    for m in methods:
        if m.get("err"):
            f.write("?\t?\t?\t?\t# 0x%x: %s\n" % (m["addr"], m["err"]))
            continue
        f.write("%s\t0x%x\t0x%x\t0x%x\n" % (m["name"], m["func"], m["flags"], m["doc_p"]))

with io.open(os.path.join(OUT, "strings.tsv"), "w", encoding="utf-8", newline="\n") as f:
    f.write("addr\tstring\n")
    for a, s in strings:
        f.write("0x%x\t%s\n" % (a, s))

# type object search: any symbol whose type is OBJECT and name contains Type / any
# PyType_Ready-like undefined import
type_syms = [s for s in syms if "TypeObject" in s["name"] or s["name"].startswith("PyType_")]
dynsyms = [s["name"] for s in syms if s["shndx"] == 0]

info = dict(
    pyinit=PI, mod=MOD, md=md, m_name_p=m_name_p, m_name=cstr(m_name_p),
    m_doc_p=m_doc_p, m_doc=cstr(m_doc_p), m_size=m_size, m_methods=m_methods_p,
    m_slots=m_slots_p, m_traverse=m_traverse_p, m_clear=m_clear_p, m_free=m_free_p,
    table_end=table_end, sentinel_zero=(sentinel is not None and sentinel == b"\0" * 32),
    n=n_entries, type_syms=[(s["name"], s["value"]) for s in type_syms],
    pytype_imports=[n for n in dynsyms if "Type" in n],
    rodata=(ro["addr"], ro["size"]), nstrings=len(strings),
)
import json
print(json.dumps(info, indent=2, default=str))
