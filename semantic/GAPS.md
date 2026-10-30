# GAPS — H0PP Semantic Reconstruction

## Overview

9 semantic reconstruction suites created for H0PP `_pypinot.so` exports.
Total claims: 60 (36 observed, 16 derived, 4 inferred — 6.67% inferred, well under 20% threshold).

## Cross-Cutting GAPS

### GAP-001: libpinot_reader.so unavailable
**Affected suites**: getRescale, getPreClosePrice, getLastClosePrice, getClosePrice, pinot_open
**Description**: The real `libpinot_reader.so` is not available in this environment. All price data comes from mock tables. The exact data format, source, and lookup mechanism are unknown.
**Impact**: Cannot verify actual price data correctness; mock data is used for structural testing only.

### GAP-002: Date encoding unverified
**Affected suites**: getRescale, getPreClosePrice, getLastClosePrice, getClosePrice
**Description**: Dates are passed as Python `int` via `PyLong_AsLong`. The encoding (e.g., YYYYMMDD vs ordinal) is inferred from Python call sites but not verified against the native library.
**Impact**: Date format assumptions may be incorrect for edge cases (pre-base dates, leap years, etc.).

### G003: SecInfo struct layout unknown
**Affected suites**: getRescale, getPreClosePrice, getLastClosePrice, getClosePrice
**Description**: The decompiler shows `SecInfo` as a stack object with a callback slot at +0x28. The full struct layout beyond what the methods access is unknown.
**Impact**: Cannot verify internal consistency of SecInfo across methods.

### GAP-004: pinot_open/close/getline callers unknown
**Affected suites**: pinot_open, pinot_close, pinot_getline
**Description**: No Python call sites found in `__init__.py` for these three exports. They may be called via a different mechanism (e.g., C-level direct calls, other modules, or dynamic loading).
**Impact**: Cannot verify the exact usage pattern and argument types from Python side.

### GAP-005: Binary format details unverified
**Affected suites**: pinot_decode_slice_helper, pinot_decode_trader_helper_request_helper
**Description**: The binary format (timestamp size, code size, header layout) is derived from decompiler analysis and Python-side consumption patterns. Not verified against real data samples.
**Impact**: Structural correctness tested, but exact byte-level format may differ from real library.

### GAP-006: Trader helper request format differences
**Affected suites**: pinot_decode_trader_helper_request_helper
**Description**: The exact differences between trader helper request format and slice format are not fully clear from the decompiler. The reconstruction assumes the same format structure.
**Impact**: Trader helper request binary format may have different field sizes or layout.

### GAP-007: Handle internal structure unknown
**Affected suites**: pinot_open, pinot_close
**Description**: The `void**` handle allocated by `pinot_open` has an unknown internal structure. The reconstruction uses a mock `PinotHandle` struct.
**Impact**: Cannot verify the real handle's internal layout or cleanup behavior.

## Most Uncertain Claims

1. **pinot_open-001-F** (inferred): "No Python call site found for pinot_open; callers are unknown"
   - Cannot determine who calls pinot_open or what arguments they pass

2. **pinot_decode_trader_helper_request_helper-001-F** (inferred): "Binary format similar to slice helper but may differ"
   - The exact format differences between trader helper and slice data are unknown
