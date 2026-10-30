# pinot_getline (0x0010c0e0) — Semantic Reconstruction

## Summary

Python C-API wrapper that reads a line from a Pinot binary stream. Takes one
argument (a stream/handle), reads a line, and returns a tuple
`(success_flag: int, line_data: bytes)`.

## Semantic Contract

```
pinot_getline(stream: int) -> tuple[int, bytes]
```

- **stream**: Stream handle int.
- **return**: 2-tuple `(int success_flag, bytes line_data)`.
  - `success_flag`: 0 on EOF, 1 on success (built via `PyLong_FromLong`).
  - `line_data`: Raw bytes read from the stream.
- **failure**: Returns `NULL` on `PyArg_ParseTuple` failure.

## Implementation Flow

1. `PyArg_ParseTuple(args, "O")` — extract single Python object (stream handle)
2. Convert handle to stream pointer
3. Read a line from the binary stream (up to newline `\n`)
4. Build success flag via `PyLong_FromLong` (format "l" at S_0010fbf4)
5. Build line data via `PyBytes_FromStringAndSize`
6. Pack and return 2-tuple via `PyTuple_Pack`

## Side Effects

- Advances the binary stream position by the number of bytes read

## Claims: 6 total (3 observed, 2 derived, 1 inferred)

| ID | Kind | Authority | Statement (abbrev.) |
|----|------|-----------|---------------------|
| A | contract | observed | Single arg, returns (int, bytes) tuple |
| B | implementation | derived | Reads line, packs 2-tuple |
| C | data | observed | Flag via PyLong_FromLong, data via PyBytes |
| D | implementation | observed | NULL on PyArg_ParseTuple failure |
| E | side_effect | derived | Advances stream position |
| F | contract | inferred | No Python call site found; callers unknown |

## Build & Test

```bash
g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp && ./t
```

## GAPS

- **Stream type**: The exact type of the stream handle and how it maps to a C stream is unknown.
- **Line terminator**: The decompiler shows newline (`\n`) as the line terminator, but the real library may use a different terminator or support multiple terminators.
- **Binary data handling**: Whether null bytes are preserved in the line data is inferred from the PyBytes construction but not verified against the real library.
- **Callers**: No Python call site found in __init__.py.
