# H0PP.so — Python C extension data-structure dump

Mechanical read-only extraction. The binary was **not** executed, loaded, or
network-accessed. Every value below is a byte/relocation read from
`D:\tmp\H0PP.so` (ELF64 x86-64, non-stripped, has `.symtab` + DWARF).

Extractor: `extract.py` (in this directory). It reads section headers, `.symtab`,
`.rela.dyn`/`.rela.plt` and `.rodata` directly from the file.

> `readelf` in this environment is a binutils build that does **not** accept
> `--defined-only`, so `exports.txt` is the raw full output of `readelf -sW`
> (it contains both `.dynsym` and `.symtab`, undefined and defined entries).
> That is the only deviation from the requested command.

## Headline numbers

| item | value |
|---|---|
| `PyInit_*` symbol | `PyInit__pypinot` @ **0x6fc0**, size 17, `.text` (shndx 12), GLOBAL DEFAULT |
| module name (`m_name`) | `_pypinot` (string @ 0xfc1a) |
| `PyModuleDef` | **0x2123c0** (`.data`, symbol `_ZL15module__pypinot`, size 104) |
| `PyMethodDef` table (`m_methods`) | **0x212440** (`.data`, symbol `_ZL7methods`, size 320) |
| method entries | **9** (+ 1 zero sentinel) |
| `PyTypeObject` present | **no** (see below) |
| parse failures | **none** |

## PyInit

```
0000000000006fc0 <PyInit__pypinot>:
    6fc0: 48 8d 3d f9 b3 20 00   lea  0x20b3f9(%rip),%rdi   # 2123c0 <_ZL15module__pypinot>
    6fc7: be f5 03 00 00         mov  $0x3f5,%esi           # 1013
    6fcc: e9 ff e4 ff ff         jmp  54d0 <PyModule_Create2@plt>
```

`0x3f5` = 1013 = module API version argument to `PyModule_Create2`.
Single-phase init, so the `PyModuleDef` at 0x2123c0 is the method table owner.

## PyModuleDef @ 0x2123c0 (104 bytes)

Layout used (CPython 3.x, 64-bit): `PyModuleDef_Base` = 40 bytes
(`ob_refcnt`, `ob_type`, `m_init`, `m_index`, `m_copy`), then
`m_name +40`, `m_doc +48`, `m_size +56`, `m_methods +64`, `m_slots +72`,
`m_traverse +80`, `m_clear +88`, `m_free +96`.

| offset | field | bytes / relocation | resolved |
|---|---|---|---|
| +0 | `m_base.ob_refcnt` | `01 00 00 00 00 00 00 00` | 1 |
| +8 | `m_base.ob_type` | zero | 0 |
| +16 | `m_base.m_init` | zero | 0 |
| +24 | `m_base.m_index` | zero | 0 |
| +32 | `m_base.m_copy` | zero | 0 |
| +40 | `m_name` | R_X86_64_RELATIVE addend 0xfc1a | `_pypinot` |
| +48 | `m_doc` | R_X86_64_RELATIVE addend 0xfb90 | `""` (empty string) |
| +56 | `m_size` | `ff ff ff ff ff ff ff ff` | -1 |
| +64 | `m_methods` | R_X86_64_RELATIVE addend 0x212440 | table, see below |
| +72 | `m_slots` | zero | NULL (no multi-phase slots) |
| +80 | `m_traverse` | zero | NULL |
| +88 | `m_clear` | zero | NULL |
| +96 | `m_free` | zero | NULL |

## PyMethodDef table @ 0x212440 (320 bytes = 10 × 32)

Entry layout: `ml_name(8) | ml_meth(8) | ml_flags(4) | pad(4) | ml_doc(8)`.

All 9 entries have `ml_flags = 0x1` and `ml_doc` pointing at 0xfb90 (empty
string). Terminator at 0x212560 is 32 zero bytes (verified).

| # | entry addr | name addr | name | ml_meth | flags | doc | ml_meth symbol (from relocation) |
|---|---|---|---|---|---|---|---|
| 0 | 0x212440 | 0xfc23 | `getRescale` | 0xcc10 | 0x1 | 0xfb90 | `pydetail::PyWrapper<double(*)(std::string const&,int),&getRescale(std::string const&,int)>::wrap(_object*, _object*)` |
| 1 | 0x212460 | 0xfc2e | `getPreClosePrice` | 0xc7c0 | 0x1 | 0xfb90 | `PyWrapper<...,&getPreClosePrice>::wrap` |
| 2 | 0x212480 | 0xfc3f | `getLastClosePrice` | 0xc930 | 0x1 | 0xfb90 | `PyWrapper<...,&getLastClosePrice>::wrap` |
| 3 | 0x2124a0 | 0xfc51 | `getClosePrice` | 0xcaa0 | 0x1 | 0xfb90 | `PyWrapper<...,&getClosePrice>::wrap` |
| 4 | 0x2124c0 | 0xfc5f | `pinot_open` | 0xbf60 | 0x1 | 0xfb90 | `PyWrapper<void*(*)(std::string),&pinot_open(std::string)>::wrap` |
| 5 | 0x2124e0 | 0xfc6a | `pinot_close` | 0xc090 | 0x1 | 0xfb90 | `PyWrapper<void(*)(void*),&pinot_close(void*)>::wrap` |
| 6 | 0x212500 | 0xfc76 | `pinot_getline` | 0xc0e0 | 0x1 | 0xfb90 | `PyWrapper<std::pair<int,std::string>(*)(void*),&pinot_getline(void*)>::wrap` |
| 7 | 0x212520 | 0xfc84 | `pinot_decode_slice_helper` | 0xab80 | 0x1 | 0xfb90 | `PyWrapper<...,&pinot_decode_slice_helper>::wrap` (LOCAL, size 4966) |
| 8 | 0x212540 | 0xfcd8 | `pinot_decode_trader_helper_request_helper` | 0x94e0 | 0x1 | 0xfb90 | `PyWrapper<...,&pinot_decode_trader_helper_request_helper>::wrap` (LOCAL, size 5785) |
| — | 0x212560 | 0 | — | 0 | 0 | 0 | sentinel |

Important byte-level detail: the raw `ml_meth` words at 0x212448, 0x212468,
…, 0x212548 are **0x0000000000000000** in the file. Their real values come from
`R_X86_64_64` entries in `.rela.dyn`:

```
0000000000212448  R_X86_64_64  0xcc10  ...&getRescale...::wrap
0000000000212468  R_X86_64_64  0xc7c0  ...&getPreClosePrice...::wrap
0000000000212488  R_X86_64_64  0xc930  ...&getLastClosePrice...::wrap
00000000002124a8  R_X86_64_64  0xcaa0  ...&getClosePrice...::wrap
00000000002124c8  R_X86_64_64  0xbf60  ...&pinot_open...::wrap
00000000002124e8  R_X86_64_64  0xc090  ...&pinot_close...::wrap
0000000000212508  R_X86_64_64  0xc0e0  ...&pinot_getline...::wrap
0000000000212528  R_X86_64_64  0xab80  ...pinot_decode_slice_helper...::wrap
0000000000212548  R_X86_64_64  0x94e0  ...pinot_decode_trader_helper_request_helper...::wrap
```

`methods.tsv` reports the **post-relocation** value. All 9 targets were
cross-checked to be defined `FUNC` symbols in `.symtab` at exactly those
addresses.

## PyTypeObject

**None.**

- `.data.rel.ro` is 8 bytes total (0x211d70..0x211d78) and holds only
  `__dso_handle` (self-referential `R_X86_64_RELATIVE` addend 0x211d70).
- `.data` is 0x1c8 bytes: `_ZL15module__pypinot` (0x2123c0, 104),
  `_ZL7methods` (0x212440, 320), zero padding, `DW.ref.__gxx_personality_v0` (0x212580).
- `.bss` is 0x108 bytes and contains only C++/loader statics:
  `completed.6355`, `SecInfo::data`, `SecInfo::data_store2`,
  `SecInfo::group_data_store1/2`, and `static void* pinot_reader_*` dlsym handles.
- No symbol in `.symtab`/`.dynsym` contains `TypeObject` or starts with `PyType_`,
  and no `PyType_*` symbol is imported. The only `PyObject*` API imports used are
  `PyModule_Create2`, `PyArg_ParseTuple`, `Py_BuildValue`, `PyBytes_*`,
  `PyList_*`, `PyTuple_New`, `PyLong_*`, `PyUnicode_AsUTF8`.
- The C++ class `SecInfo` (methods such as `get30DayTurnoverRate`, `getMembers`,
  `getGroups`) is plain C++ and is not exposed as a Python type here.

## Files

| file | content |
|---|---|
| `methods.tsv` | `name<TAB>func_addr<TAB>flags<TAB>doc_addr`, 9 rows + header |
| `strings.tsv` | every printable run in `.rodata` (0xfb68..0xfd20), `addr<TAB>string`, 27 rows |
| `exports.txt` | raw `readelf -sW` output, 435 lines |
| `sections.txt` | raw `readelf -SW` output (for address↔file-offset mapping) |
| `extract.py` | the extractor that produced the TSVs |

### `strings.tsv` caveats

- `.rodata` is only 440 bytes; it is the whole string pool used by this module
  (method names, module name, dlsym'd symbol names, library path, format strings).
- Last row `0xfd1f  ?` is a single printable byte `0x3f` inside the IEEE-754
  double constant `1.0` stored at 0xfd18..0xfd20 (pair with the `0xfd08..0xfd10`
  NaN constant). It is not a string literal; it is kept because the dump is purely
  byte-driven.
- `0xfb90` (the `ml_doc` target) is the NUL terminator byte of `"."` at 0xfb8f,
  i.e. it reads as the empty string `""`.

## Parse failures

None. Every entry of the table was resolved to a real address, a real name in
`.rodata`, and a real defined `FUNC` symbol.
