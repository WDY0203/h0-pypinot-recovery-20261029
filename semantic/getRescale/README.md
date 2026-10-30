# getRescale (0x0010cc10) — Semantic Reconstruction

## Summary

Python C-API wrapper around the free function `H0PP_getRescale` (0x0010b780).
Takes `(symbol: str, date: int)` and returns the rescale ratio as a Python float,
or `None` on parse failure.

## Semantic Contract

```
getRescale(symbol: str, date: int) -> float | None
```

- **symbol**: Security code string (Python str or bytes). Converted to C `char*`
  via `PyUnicode_AsUTF8String` or `PyBytes_AsString`.
- **date**: Trading date as Python int, extracted via `PyLong_AsLong`.
- **return**: Rescale ratio = `preClose(date) / close(date-1)`, built via
  `Py_BuildValue("d", double)` using format char at S_0010fc04.
- **failure**: Returns `NULL` (Python `None`) on `PyArg_ParseTuple` failure.

## Implementation Flow

1. `PyArg_ParseTuple(args, "OO")` — extract two Python objects (S_0010fc03)
2. Convert first arg (symbol) to `char*` via UTF-8 string or bytes API
3. Extract second arg (date) via `PyLong_AsLong`
4. Call free function `H0PP_getRescale` (0x0010b780):
   - Constructs a stack `SecInfo` (local_stack_0x28)
   - Delegates to `SecInfo::getRescale` method (0x0010b790)
   - Computes `preClose / close(prevDay)`
   - Returns 1.0 (identity default) on failure path (DAT_0010fd18)
5. Wrap result in `Py_BuildValue("d", dVar2)` and return

## Side Effects

- `libpinot_reader.so` is `dlopen`ed during `PIN_CALLBACK` handler initialization
- Handler resets price callback slot at `SecInfo+0x28`
- `PIN_Abort` on unresolved symbol addresses during init

## Claims: 7 total (5 observed, 2 derived)

| ID | Kind | Authority | Statement (abbrev.) |
|----|------|-----------|---------------------|
| A | contract | observed | Inputs (str, int), output float/None |
| B | contract | observed | Symbol accepts str/bytes, date via PyLong_AsLong |
| C | implementation | derived | Calls free H0PP_getRescale, creates stack SecInfo |
| D | implementation | observed | NULL on PyArg_ParseTuple failure |
| E | data | observed | Return via Py_BuildValue("d", double) |
| F | side_effect | observed | dlopen libpinot_reader.so, reset callback slot |
| G | data | derived | Returns 1.0 on failure path (DAT_0010fd18) |

## Build & Test

```bash
g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp && ./t
```

## GAPS

- **Actual price data source**: The reconstruction uses mock price tables. The
  real data comes from `libpinot_reader.so` which is not available in this
  environment. The exact data format and source are unknown.
- **Date encoding**: The date is passed as an `int` but the exact encoding
  (e.g., YYYYMMDD vs ordinal) is inferred from Python call sites. Not verified
  against the native library.
- **SecInfo internal layout**: The decompiler shows `SecInfo` as a stack
  object with a callback slot at +0x28. The full struct layout beyond what
  the methods access is unknown.
