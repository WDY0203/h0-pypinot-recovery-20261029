// impl.cpp — pinot_close semantic reconstruction for H0PP
// Compile: g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp
// Run:     ./t
//
// Evidence: reconstructed_cpp/H0PP/H0PP_all_decompiled.txt IDX 163 (0x0010c090)
//           PyArg_ParseTuple format "O" (single arg - handle)
//           Returns Py_BuildValue("z", 0) = None (S_0010fbf2)
//           Frees handle via operator_delete, closes filebuf/ifstream

#include <cstring>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "shared.h"

// Mock handle structure (same as pinot_open, defined in shared.h)

// Python wrapper: pinot_close(handle: int) -> None
// Returns 0 to signal success (None), -1 to signal NULL (error)
static int pinot_close_py(int64_t handle_ptr) {
    if (handle_ptr == 0) {
        return -1; // NULL (error - invalid handle)
    }
    PinotHandle* handle = (PinotHandle*)(uintptr_t)handle_ptr;
    
    // Destroy handle (call destructor + free, operator_delete equivalent)
    handle->~PinotHandle();
    free(handle);
    
    return 0; // None (success)
}

extern "C" int H0PP_pinot_close_wrapper(int64_t handle_ptr) {
    return pinot_close_py(handle_ptr);
}

// ---------------------------------------------------------------------------
// Test doubles for the harness: the suite needs to hand `pinot_close` a handle
// that looks like one produced by `pinot_open`. These are NOT part of the
// reconstructed code - they only fabricate the two shapes the tests exercise
// (dlopen path and fallback path).
// ---------------------------------------------------------------------------
extern "C" int64_t H0PP_pinot_open_wrapper(const char* path) {
    PinotHandle* h = new PinotHandle();
    h->path = path ? path : "";
    const bool reader = h->path.find("pinot_reader") != std::string::npos;
    h->dlopenSuccess = reader;
    h->fallbackUsed = !reader;
    h->dlopenHandle = reader ? (void*)0x1 : nullptr;
    return (int64_t)(uintptr_t)h;
}

extern "C" void* H0PP_pinot_get_handle(int64_t ptr) {
    return (void*)(uintptr_t)ptr;
}
