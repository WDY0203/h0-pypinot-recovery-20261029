# pinot_open (0x0010bf60) — Semantic Reconstruction

## Summary

Python C-API wrapper that opens a Pinot reader library. Takes one argument
(a path or options object), attempts to `dlopen` `libpinot_reader.so`, falls
back to `std::filebuf`/`ifstream` on failure, and returns a handle as a
Python `int` (void* cast to long).

## Semantic Contract

```
pinot_open(path: str) -> int
```

- **path**: Path or options as a Python object (converted to C string).
- **return**: Handle as Python int via `PyLong_FromVoidPtr`.
- **failure**: Returns `NULL` on `PyArg_ParseTuple` failure.

## Implementation Flow

1. `PyArg_ParseTuple(args, "O")` — extract single Python object
2. Convert argument to C string path
3. Try `dlopen("libpinot_reader.so")` via PIN_CALLBACK mechanism
4. On dlopen failure, fall back to `std::filebuf` or `ifstream`
5. Allocate `void**` handle via `operator_new(8)`
6. Return handle as Python int via `PyLong_FromVoidPtr`

## Side Effects

- `dlopen` of `libpinot_reader.so`
- Allocation of `void**` handle (8 bytes) via `operator_new`
- PIN_CALLBACK handler registration

## Claims: 6 total (4 observed, 1 derived, 1 inferred)

| ID | Kind | Authority | Statement (abbrev.) |
|----|------|-----------|---------------------|
| A | contract | observed | Single arg, returns int handle |
| B | implementation | derived | dlopen with fallback to filebuf/ifstream |
| C | implementation | observed | operator_new(8), PyLong_FromVoidPtr |
| D | implementation | observed | NULL on PyArg_ParseTuple failure |
| E | side_effect | observed | dlopen + PIN_CALLBACK registration |
| F | contract | inferred | No Python call site found; callers unknown |

## Build & Test

```bash
g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp && ./t
```

## GAPS

- **Argument type**: The exact type of the single argument is unknown — it could be a path string, a bytes object, or a dict of options. The decompiler shows it's extracted as a single "O" but the conversion path is not fully clear.
- **dlopen mechanism**: The exact PIN_CALLBACK mechanism for dlopen is not fully reconstructed. The fallback path (filebuf vs ifstream) is derived from decompiler patterns but not verified.
- **Handle format**: The void** handle structure is allocated via operator_new(8) but the internal layout is unknown.
- **Callers**: No Python call site found in __init__.py.
