// test.cpp — pinot_close reconstruction tests for H0PP
// Compile: g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp
// Run:     ./t

#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <string>

extern "C" int H0PP_pinot_close_wrapper(int64_t handle_ptr);
extern "C" int64_t H0PP_pinot_open_wrapper(const char* path);
extern "C" void* H0PP_pinot_get_handle(int64_t ptr);

struct PinotHandle {
    std::string path;
    bool dlopenSuccess;
    bool fallbackUsed;
    void* dlopenHandle;
};

static int failures = 0;
static int total = 0;

#define CHECK(cond, msg) do { \
    total++; \
    if (cond) { printf("  [PASS] %s\n", msg); } \
    else { printf("  [FAIL] %s\n", msg); failures++; } \
} while(0)

int main() {
    printf("=== pinot_close reconstruction tests ===\n\n");

    // Test 1: close a valid handle -> returns 0 (None/success)
    printf("Test 1: close valid handle\n");
    {
        int64_t h = H0PP_pinot_open_wrapper("libpinot_reader.so");
        CHECK(h != 0, "opened handle successfully");
        PinotHandle* ph = (PinotHandle*)H0PP_pinot_get_handle(h);
        CHECK(ph->fallbackUsed == false, "handle uses dlopen");
        int r = H0PP_pinot_close_wrapper(h);
        CHECK(r == 0, "returns 0 (None) on successful close");
    }

    // Test 2: close with NULL/0 handle -> returns -1 (error)
    printf("\nTest 2: close NULL handle -> error\n");
    {
        int r = H0PP_pinot_close_wrapper(0);
        CHECK(r == -1, "returns -1 (NULL/error) for invalid handle");
    }

    // Test 3: close a handle from fallback path
    printf("\nTest 3: close fallback handle\n");
    {
        int64_t h = H0PP_pinot_open_wrapper("other.so");
        CHECK(h != 0, "opened fallback handle");
        PinotHandle* ph = (PinotHandle*)H0PP_pinot_get_handle(h);
        CHECK(ph->fallbackUsed == true, "handle uses fallback");
        int r = H0PP_pinot_close_wrapper(h);
        CHECK(r == 0, "returns 0 (None) when closing fallback handle");
    }

    // Test 4: close handle and verify memory is freed (double close should fail)
    printf("\nTest 4: double close -> second close errors\n");
    {
        int64_t h = H0PP_pinot_open_wrapper("libpinot_reader.so");
        int r1 = H0PP_pinot_close_wrapper(h);
        CHECK(r1 == 0, "first close succeeds");
        // Second close with freed pointer - behavior is undefined but should not crash
        // In the real code, this would be a use-after-free; here we just check the first close
        printf("  [INFO] second close on freed pointer is use-after-free (not tested)\n");
    }

    printf("\n=== Results: %d/%d passed ===\n", total - failures, total);
    return failures > 0 ? 1 : 0;
}
