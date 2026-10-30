// test.cpp — pinot_decode_trader_helper_request_helper reconstruction tests for H0PP
// Compile: g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp
// Run:     ./t

#include <cstdio>
#include <cstring>
#include <cstdint>
#include <vector>
#include <cmath>

extern "C" int H0PP_pinot_decode_trader_helper_request_helper_wrapper(
    const uint8_t* data, size_t len,
    uint8_t* out_ts, size_t out_ts_len,
    uint32_t* out_num_codes, uint8_t* out_codes, size_t out_codes_len,
    uint8_t* out_data_buf, size_t out_data_len);
extern "C" size_t H0PP_pinot_decode_trader_get_ts_len();
extern "C" size_t H0PP_pinot_decode_trader_get_code_len();
extern "C" size_t H0PP_pinot_decode_trader_get_double_len();

static int failures = 0;
static int total = 0;

#define CHECK(cond, msg) do { \
    total++; \
    if (cond) { printf("  [PASS] %s\n", msg); } \
    else { printf("  [FAIL] %s\n", msg); failures++; } \
} while(0)

int main() {
    printf("=== pinot_decode_trader_helper_request_helper reconstruction tests ===\n\n");

    size_t TS = H0PP_pinot_decode_trader_get_ts_len();
    size_t CL = H0PP_pinot_decode_trader_get_code_len();
    size_t DL = H0PP_pinot_decode_trader_get_double_len();

    // Test 1: decode a trader helper request with 2 codes and 2 doubles
    printf("Test 1: decode with 2 codes, 2 doubles\n");
    {
        std::vector<uint8_t> data;
        // Timestamp: 0x0000000000000002
        data.push_back(0x02); data.push_back(0x00); data.push_back(0x00); data.push_back(0x00);
        data.push_back(0x00); data.push_back(0x00); data.push_back(0x00); data.push_back(0x00);
        // num_codes = 2
        data.push_back(2); data.push_back(0); data.push_back(0); data.push_back(0);
        // code1 = "600000"
        const char* c1 = "600000";
        for (int i = 0; i < 6; i++) data.push_back((uint8_t)c1[i]);
        // code2 = "300750"
        const char* c2 = "300750";
        for (int i = 0; i < 6; i++) data.push_back((uint8_t)c2[i]);
        // double1 = 5.5
        double d1 = 5.5;
        uint8_t* d1b = (uint8_t*)&d1;
        for (int i = 0; i < 8; i++) data.push_back(d1b[i]);
        // double2 = 15.25
        double d2 = 15.25;
        uint8_t* d2b = (uint8_t*)&d2;
        for (int i = 0; i < 8; i++) data.push_back(d2b[i]);

        uint8_t ts[16] = {0}, codes[32] = {0}, buf[64] = {0};
        uint32_t num_codes = 0;
        int r = H0PP_pinot_decode_trader_helper_request_helper_wrapper(data.data(), data.size(),
            ts, 16, &num_codes, codes, 32, buf, 64);
        CHECK(r == 0, "decode returns 0 (success)");
        CHECK(num_codes == 2, "num_codes is 2");
        CHECK(memcmp(ts, data.data(), 8) == 0, "timestamp bytes match");
        CHECK(memcmp(codes, "600000", 6) == 0, "code1 is '600000'");
        CHECK(memcmp(codes + 6, "300750", 6) == 0, "code2 is '300750'");
        
        double* dd = (double*)buf;
        CHECK(dd[0] == 5.5, "double1 is 5.5");
        CHECK(dd[1] == 15.25, "double2 is 15.25");
    }

    // Test 2: decode with 0 codes
    printf("\nTest 2: decode with 0 codes\n");
    {
        std::vector<uint8_t> data;
        for (int i = 0; i < 8; i++) data.push_back(0xCC); // ts
        data.push_back(0); data.push_back(0); data.push_back(0); data.push_back(0); // num_codes=0

        uint8_t ts[16] = {0}, codes[32] = {0}, buf[64] = {0};
        uint32_t num_codes = 99;
        int r = H0PP_pinot_decode_trader_helper_request_helper_wrapper(data.data(), data.size(),
            ts, 16, &num_codes, codes, 32, buf, 64);
        CHECK(r == 0, "decode returns 0 (success)");
        CHECK(num_codes == 0, "num_codes is 0");
    }

    // Test 3: decode too-short data
    printf("\nTest 3: decode too-short data\n");
    {
        uint8_t data[4] = {0, 0, 0, 0};
        uint8_t ts[16] = {0}, codes[32] = {0}, buf[64] = {0};
        uint32_t num_codes = 0;
        int r = H0PP_pinot_decode_trader_helper_request_helper_wrapper(data, 4,
            ts, 16, &num_codes, codes, 32, buf, 64);
        CHECK(r == 0, "decode returns 0 even for short data");
        CHECK(num_codes == 0, "num_codes is 0 for short data");
    }

    // Test 4: decode with 1 code and 1 double
    printf("\nTest 4: decode with 1 code, 1 double\n");
    {
        std::vector<uint8_t> data;
        for (int i = 0; i < 8; i++) data.push_back(0xDD); // ts
        data.push_back(1); data.push_back(0); data.push_back(0); data.push_back(0); // num_codes=1
        const char* c1 = "000001";
        for (int i = 0; i < 6; i++) data.push_back((uint8_t)c1[i]);
        double d1 = 99.5;
        uint8_t* d1b = (uint8_t*)&d1;
        for (int i = 0; i < 8; i++) data.push_back(d1b[i]);

        uint8_t ts[16] = {0}, codes[32] = {0}, buf[64] = {0};
        uint32_t num_codes = 0;
        int r = H0PP_pinot_decode_trader_helper_request_helper_wrapper(data.data(), data.size(),
            ts, 16, &num_codes, codes, 32, buf, 64);
        CHECK(r == 0, "decode returns 0 (success)");
        CHECK(num_codes == 1, "num_codes is 1");
        CHECK(memcmp(codes, "000001", 6) == 0, "code is '000001'");
        double* dd = (double*)buf;
        CHECK(dd[0] == 99.5, "double is 99.5");
    }

    printf("\n=== Results: %d/%d passed ===\n", total - failures, total);
    return failures > 0 ? 1 : 0;
}
