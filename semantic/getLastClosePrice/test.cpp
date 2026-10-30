// test.cpp — getLastClosePrice reconstruction tests for H0PP
// Compile: g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp
// Run:     ./t

#include <cstdio>
#include <cstring>
#include <cmath>

extern "C" double H0PP_getLastClosePrice_wrapper(const char* symbol, int date);

static int failures = 0;
static int total = 0;

#define CHECK(cond, msg) do { \
    total++; \
    if (cond) { printf("  [PASS] %s\n", msg); } \
    else { printf("  [FAIL] %s\n", msg); failures++; } \
} while(0)

int main() {
    printf("=== getLastClosePrice reconstruction tests ===\n\n");

    // Test 1: valid symbol and date -> returns close price
    printf("Test 1: valid symbol '600000', date 20240102\n");
    {
        double r = H0PP_getLastClosePrice_wrapper("600000", 20240102);
        // offset=1: close[1]=10.7
        CHECK(r == 10.7, "returns close price 10.7");
    }

    // Test 2: first day -> close[0]
    printf("\nTest 2: valid symbol '600000', date 20240101\n");
    {
        double r = H0PP_getLastClosePrice_wrapper("600000", 20240101);
        CHECK(r == 10.2, "returns close price 10.2 for first day");
    }

    // Test 3: unknown symbol -> NULL (None)
    printf("\nTest 3: unknown symbol -> None\n");
    {
        double r = H0PP_getLastClosePrice_wrapper("UNKNOWN", 20240102);
        CHECK(r == -1.0, "returns -1.0 (None) for unknown symbol");
    }

    // Test 4: date before base -> -1.0 (invalid)
    printf("\nTest 4: date before base -> -1.0 (invalid)\n");
    {
        double r = H0PP_getLastClosePrice_wrapper("600000", 20231231);
        CHECK(r == -1.0, "returns -1.0 for date before base");
    }

    // Test 5: date beyond data range -> returns last available close
    printf("\nTest 5: date beyond data range -> last available close\n");
    {
        double r = H0PP_getLastClosePrice_wrapper("600000", 20241231);
        CHECK(r == 11.3, "returns last available close price 11.3");
    }

    // Test 6: symbol '000001'
    printf("\nTest 6: valid symbol '000001', date 20240103\n");
    {
        double r = H0PP_getLastClosePrice_wrapper("000001", 20240103);
        // offset=2: close[2]=14.9
        CHECK(r == 14.9, "returns close price 14.9");
    }

    printf("\n=== Results: %d/%d passed ===\n", total - failures, total);
    return failures > 0 ? 1 : 0;
}
