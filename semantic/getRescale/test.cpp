// test.cpp — getRescale reconstruction tests for H0PP
// Compile: g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp
// Run:     ./t

#include <cstdio>
#include <cstring>
#include <cmath>

extern "C" double H0PP_getRescale_wrapper(const char* symbol, int date);

static int failures = 0;
static int total = 0;

#define CHECK(cond, msg) do { \
    total++; \
    if (cond) { printf("  [PASS] %s\n", msg); } \
    else { printf("  [FAIL] %s\n", msg); failures++; } \
} while(0)

int main() {
    printf("=== getRescale reconstruction tests ===\n\n");

    // Test 1: valid symbol and date -> returns rescale ratio (preClose/prevClose)
    printf("Test 1: valid symbol '600000', date 20240102\n");
    {
        double r = H0PP_getRescale_wrapper("600000", 20240102);
        // base=20240101, date=20240102 => offset=1
        // preClose[1]=10.5, close[0]=10.2 => rescale=10.5/10.2≈1.02941
        CHECK(r > 1.02 && r < 1.03, "rescale ratio ~1.0294 (preClose/prevClose)");
    }

    // Test 2: first day (no previous close) -> should return 1.0 (identity default)
    printf("\nTest 2: first day, no prev close -> 1.0 identity\n");
    {
        double r = H0PP_getRescale_wrapper("600000", 20240101);
        CHECK(r == 1.0, "returns 1.0 when no previous close available");
    }

    // Test 3: unknown symbol -> NULL (None), return -1.0 in mock
    printf("\nTest 3: unknown symbol -> None\n");
    {
        double r = H0PP_getRescale_wrapper("UNKNOWN", 20240102);
        CHECK(r == -1.0, "returns -1.0 (None) for unknown symbol");
    }

    // Test 4: different symbol '000001'
    printf("\nTest 4: valid symbol '000001', date 20240103\n");
    {
        double r = H0PP_getRescale_wrapper("000001", 20240103);
        // offset=2: preClose[2]=14.8, close[1]=15.5 => 14.8/15.5≈0.95484
        CHECK(r > 0.95 && r < 0.96, "rescale ratio ~0.9548 (preClose/prevClose)");
    }

    // Test 5: '300750' symbol
    printf("\nTest 5: valid symbol '300750', date 20240103\n");
    {
        double r = H0PP_getRescale_wrapper("300750", 20240103);
        // offset=2: preClose[2]=210.0, close[1]=206.0 => 210.0/206.0≈1.01942
        CHECK(r > 1.019 && r < 1.020, "rescale ratio ~1.0194 (preClose/prevClose)");
    }

    // Test 6: date before base -> 1.0 identity
    printf("\nTest 6: date before base date -> 1.0 identity\n");
    {
        double r = H0PP_getRescale_wrapper("600000", 20231231);
        CHECK(r == 1.0, "returns 1.0 when date is before base date");
    }

    // Test 7: out of range date -> 1.0 identity
    printf("\nTest 7: date beyond data range -> 1.0 identity\n");
    {
        double r = H0PP_getRescale_wrapper("600000", 20241231);
        CHECK(r == 1.0, "returns 1.0 when date exceeds available data");
    }

    printf("\n=== Results: %d/%d passed ===\n", total - failures, total);
    return failures > 0 ? 1 : 0;
}
