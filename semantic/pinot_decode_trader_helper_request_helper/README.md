# pinot_decode_trader_helper_request_helper (0x001094e0) — Semantic Reconstruction

## Summary

Python C-API wrapper that decodes a binary trader helper request blob. Takes
one argument (bytes), parses it into timestamp bytes, a list of code bytes, and
a data buffer of doubles, and returns an outer tuple `(bytes_ts, inner_tuple)`
where `inner_tuple = (list_of_bytes_codes, bytes_buffer)`. Similar to
`pinot_decode_slice_helper` but for trader helper request data.

## Semantic Contract

```
pinot_decode_trader_helper_request_helper(data: bytes) -> tuple[bytes, tuple[list[bytes], bytes]]
```

- **data**: Binary blob as Python bytes.
- **return**: Outer tuple `(bytes_ts, inner_tuple)`.
  - `bytes_ts`: 8-byte timestamp.
  - `inner_tuple[0]`: `PyList` of code byte strings (6 bytes each).
  - `inner_tuple[1]`: `PyBytes` of raw double values (8 bytes each).

## Binary Format

```
[0:8]     Timestamp (8 bytes)
[8:12]    Number of codes (uint32)
[12:...]  Codes (num_codes * 6 bytes each)
[...]     Data buffer (doubles, 8 bytes each)
```

## Implementation Flow

1. `PyArg_ParseTuple(args, "O")` — extract single Python bytes object
2. Parse binary blob:
   - Extract timestamp (8 bytes at offset 0)
   - Read num_codes (uint32 at offset 8)
   - Extract code list (num_codes * 6 bytes)
   - Extract doubles buffer (remaining bytes)
3. Build `bytes_ts` via `PyBytes_FromStringAndSize`
4. Build code list via `PyList_New` + `PyBytes_FromStringAndSize`
5. Build data buffer via `PyBytes_FromStringAndSize`
6. Build inner tuple via `PyTuple_Pack(2, list, bytes)`
7. Build outer tuple via `PyTuple_Pack(2, bytes_ts, inner_tuple)`

## Python-Side Consumption

```python
decoded = pinot_decode_trader_helper_request_helper(raw_data)
ts = decoded[0]                          # bytes timestamp
codes = decoded[1][0]                    # list of code bytes
data = np.frombuffer(decoded[1][1], dtype=np.double)  # numpy double array
```

## Claims: 6 total (4 observed, 1 derived, 1 inferred)

| ID | Kind | Authority | Statement (abbrev.) |
|----|------|-----------|---------------------|
| A | contract | observed | Single bytes arg, returns outer tuple |
| B | implementation | derived | Parses: ts(8), codes(6 each), doubles(8 each) |
| C | implementation | observed | Returns (bytes_ts, (list, bytes)) |
| D | implementation | observed | NULL on PyArg_ParseTuple failure |
| E | data | observed | Python side uses decoded[1][1] as np.double, decoded[1][0] as codes |
| F | data | inferred | Binary format similar to slice helper but may differ |

## Build & Test

```bash
g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp && ./t
```

## GAPS

- **Binary format differences**: The exact differences between trader helper request format and slice format are not fully clear from the decompiler. The reconstruction assumes the same format structure.
- **Binary format details**: The exact binary format is derived from decompiler analysis and Python-side consumption patterns. Not verified against the real library with actual data samples.
- **Code size**: Code size of 6 bytes is inferred from common A-share stock codes (6 digits). The real library may support different code lengths.
- **Endianness**: The double values are stored as raw bytes; endianness is assumed to be native (little-endian on x86_64) but not verified.
