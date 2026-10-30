# pinot_close (0x0010c090) — Semantic Reconstruction

## Summary

Python C-API wrapper that closes a Pinot reader handle. Takes one argument
(the handle from `pinot_open`), frees associated resources, and returns `None`.

## Semantic Contract

```
pinot_close(handle: int) -> None
```

- **handle**: Handle int from `pinot_open` (void* cast to long).
- **return**: Always `None` via `Py_BuildValue("z", 0)`.
- **failure**: Returns `NULL` on `PyArg_ParseTuple` failure.

## Implementation Flow

1. `PyArg_ParseTuple(args, "O")` — extract single Python object (handle)
2. Convert handle back to `void*`
3. Free handle memory via `operator_delete`
4. Close any filebuf/ifstream resources
5. Return `None` via `Py_BuildValue("z", 0)`

## Side Effects

- Frees handle memory via `operator_delete`
- Closes filebuf/ifstream resources if fallback was used

## Claims: 6 total (3 observed, 2 derived, 1 inferred)

| ID | Kind | Authority | Statement (abbrev.) |
|----|------|-----------|---------------------|
| A | contract | observed | Single arg, returns None |
| B | implementation | derived | Frees via operator_delete, closes resources |
| C | data | observed | Return None via Py_BuildValue("z", 0) |
| D | implementation | observed | NULL on PyArg_ParseTuple failure |
| E | side_effect | derived | Frees memory and closes resources |
| F | contract | inferred | No Python call site found; callers unknown |

## Build & Test

```bash
g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp && ./t
```

## GAPS

- **Handle type**: The exact type conversion from Python int to void* is not fully clear from the decompiler.
- **Resource cleanup details**: The exact cleanup sequence (order of operator_delete vs filebuf close) is derived from decompiler patterns but not verified.
- **Callers**: No Python call site found in __init__.py.
