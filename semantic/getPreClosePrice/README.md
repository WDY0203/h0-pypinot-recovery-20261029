# getPreClosePrice (0x0010c7c0) — Semantic Reconstruction

## Summary

Python C-API wrapper around free function `H0PP_getPreClosePrice` (0x0010b980).
Takes `(symbol: str, date: int)` and returns the pre-close price as a Python float,
or `None` on parse failure.

## Semantic Contract

```
getPreClosePrice(symbol: str, date: int) -> float | None
```

- **symbol**: Security code string (Python str or bytes).
- **date**: Trading date as Python int via `PyLong_AsLong`.
- **return**: Pre-close price as float via `Py_BuildValue("d", double)`.
- **failure**: Returns `NULL` (Python `None`) on `PyArg_ParseTuple` failure.

## Implementation Flow

1. `PyArg_ParseTuple(args, "OO")` — extract two Python objects
2. Convert symbol to `char*` via UTF-8 or bytes API
3. Extract date via `PyLong_AsLong`
4. Call free function `H0PP_getPreClosePrice` (0x0010b980):
   - Constructs stack `SecInfo`
   - Delegates to `SecInfo::getPreClosePrice`
   - Returns -1.0 on invalid date
5. Wrap result in `Py_BuildValue("d", dVar2)` and return

## Claims: 7 total (5 observed, 2 derived)

| ID | Kind | Authority | Statement (abbrev.) |
|----|------|-----------|---------------------|
| A | contract | observed | Inputs (str, int), output float/None |
| B | contract | observed | Symbol accepts str/bytes, date via PyLong_AsLong |
| C | implementation | derived | Calls free H0PP_getPreClosePrice, creates stack SecInfo |
| D | implementation | observed | NULL on PyArg_ParseTuple failure |
| E | data | observed | Return via Py_BuildValue("d", double) |
| F | side_effect | observed | dlopen libpinot_reader.so, reset callback slot |
| G | data | derived | Returns -1.0 on failure (invalid date) |

## Build & Test

```bash
g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp && ./t
```

## GAPS

- **Actual price data source**: Mock price tables used; real data from `libpinot_reader.so` unavailable.
- **Date encoding**: Inferred as YYYYMMDD-like int from Python call sites; not verified against native library.
- **SecInfo internal layout**: Full struct layout beyond accessed fields is unknown.
