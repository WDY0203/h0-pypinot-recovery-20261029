// test.cpp — pinot_open reconstruction tests for H0PP
// Compile: g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp
// Run:     ./t

#include <cstdio>
#include <cstring>
#include <cstdint>
#include <string>
#include <cstdlib>
#include "shared.h"

extern "C" int64_t H0PP_pinot_open_wrapper(const char* path);
extern "C" void* H0PP_pinot_get_handle(int64_t ptr);
extern "C" void H0PP_pinot_destroy_handle(int64_t ptr);

static int failures = 0;
static int total = 0;

#define CHECK(cond, msg) do { \
    total++; \
    if (cond) { printf("  [PASS] %s\n", msg); } \
    else { printf("  [FAIL] %s\n", msg); failures++; } \
} while(0)

int main() {
    printf("=== pinot_open reconstruction tests ===\n\n");

    // Test 1: open with pinot_reader path -> dlopen succeeds
    printf("Test 1: open with 'libpinot_reader.so' path\n");
    {
        int64_t h = H0PP_pinot_open_wrapper("libpinot_reader.so");
        CHECK(h != 0, "returns non-zero handle");
        PinotHandle* ph = (PinotHandle*)H0PP_pinot_get_handle(h);
        CHECK(ph->dlopenSuccess == true, "dlopen succeeds for pinot_reader path");
        CHECK(ph->fallbackUsed == false, "fallback not used when dlopen succeeds");
        H0PP_pinot_destroy_handle(h);
    }

    // Test 2: open with non-pinot path -> fallback used
    printf("\nTest 2: open with non-pinot path -> fallback\n");
    {
        int64_t h = H0PP_pinot_open_wrapper("other.so");
        CHECK(h != 0, "returns non-zero handle even on fallback");
        PinotHandle* ph = (PinotHandle*)H0PP_pinot_get_handle(h);
        CHECK(ph->dlopenSuccess == false, "dlopen fails for non-pinot path");
        CHECK(ph->fallbackUsed == true, "fallback is used when dlopen fails");
        H0PP_pinot_destroy_handle(h);
    }

    // Test 3: NULL path -> handle created with empty path
    printf("\nTest 3: open with NULL path\n");
    {
        int64_t h = H0PP_pinot_open_wrapper(nullptr);
        CHECK(h != 0, "returns non-zero handle for NULL path");
        PinotHandle* ph = (PinotHandle*)H0PP_pinot_get_handle(h);
        CHECK(ph->path == "", "path is empty for NULL input");
        CHECK(ph->fallbackUsed == true, "fallback used when dlopen fails for NULL path");
        H0PP_pinot_destroy_handle(h);
    }

    // Test 4: handle is a valid pointer (non-zero)
    printf("\nTest 4: handle is valid pointer\n");
    {
        int64_t h = H0PP_pinot_open_wrapper("libpinot_reader.so");
        CHECK(h > 0, "handle is positive (valid pointer)");
        PinotHandle* ph = (PinotHandle*)H0PP_pinot_get_handle(h);
        CHECK(ph != nullptr, "handle points to valid memory");
        H0PP_pinot_destroy_handle(h);
    }

    printf("\n=== Results: %d/%d passed ===\n", total - failures, total);
    return failures > 0 ? 1 : 0;
}
