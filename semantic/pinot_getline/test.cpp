// test.cpp — pinot_getline reconstruction tests for H0PP
// Compile: g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp
// Run:     ./t

#include <cstdio>
#include <cstring>
#include <cstdint>
#include <vector>

extern "C" int H0PP_pinot_getline_wrapper(int stream_id, uint8_t* out_buf, size_t out_len);
extern "C" int H0PP_pinot_create_stream(const uint8_t* data, size_t len);

static int failures = 0;
static int total = 0;

#define CHECK(cond, msg) do { \
    total++; \
    if (cond) { printf("  [PASS] %s\n", msg); } \
    else { printf("  [FAIL] %s\n", msg); failures++; } \
} while(0)

int main() {
    printf("=== pinot_getline reconstruction tests ===\n\n");

    // Test 1: read a single line from stream
    printf("Test 1: read single line\n");
    {
        const uint8_t data[] = {'h', 'e', 'l', 'l', 'o', '\n'};
        int sid = H0PP_pinot_create_stream(data, 6);
        uint8_t buf[256] = {0};
        int flag = H0PP_pinot_getline_wrapper(sid, buf, 256);
        CHECK(flag == 1, "success flag is 1");
        CHECK(memcmp(buf, "hello", 5) == 0, "line data is 'hello'");
    }

    // Test 2: read multiple lines sequentially
    printf("\nTest 2: read multiple lines\n");
    {
        const uint8_t data[] = {'l', 'i', 'n', 'e', '1', '\n', 'l', 'i', 'n', 'e', '2', '\n'};
        int sid = H0PP_pinot_create_stream(data, 12);
        uint8_t buf[256] = {0};
        
        int f1 = H0PP_pinot_getline_wrapper(sid, buf, 256);
        CHECK(f1 == 1 && memcmp(buf, "line1", 5) == 0, "first line is 'line1'");
        
        int f2 = H0PP_pinot_getline_wrapper(sid, buf, 256);
        CHECK(f2 == 1 && memcmp(buf, "line2", 5) == 0, "second line is 'line2'");
    }

    // Test 3: read from empty stream -> EOF (flag 0)
    printf("\nTest 3: read from empty stream -> EOF\n");
    {
        const uint8_t data[] = {};
        int sid = H0PP_pinot_create_stream(data, 0);
        uint8_t buf[256] = {0};
        int flag = H0PP_pinot_getline_wrapper(sid, buf, 256);
        CHECK(flag == 0, "EOF returns flag 0");
    }

    // Test 4: read from stream without newline -> reads to end
    printf("\nTest 4: read without trailing newline\n");
    {
        const uint8_t data[] = {'d', 'a', 't', 'a'};
        int sid = H0PP_pinot_create_stream(data, 4);
        uint8_t buf[256] = {0};
        int flag = H0PP_pinot_getline_wrapper(sid, buf, 256);
        CHECK(flag == 1, "returns success flag 1");
        CHECK(memcmp(buf, "data", 4) == 0, "line data is 'data'");
    }

    // Test 5: invalid stream id -> error (flag -1)
    printf("\nTest 5: invalid stream id -> error\n");
    {
        uint8_t buf[256] = {0};
        int flag = H0PP_pinot_getline_wrapper(-1, buf, 256);
        CHECK(flag == -1, "invalid stream returns flag -1 (error)");
    }

    // Test 6: read binary data with null bytes
    printf("\nTest 6: read binary data with null bytes\n");
    {
        const uint8_t data[] = {0x01, 0x02, 0x00, 0x03, 0x0A};
        int sid = H0PP_pinot_create_stream(data, 5);
        uint8_t buf[256] = {0};
        int flag = H0PP_pinot_getline_wrapper(sid, buf, 256);
        CHECK(flag == 1, "returns success flag 1");
        CHECK(buf[0] == 0x01 && buf[1] == 0x02 && buf[2] == 0x00 && buf[3] == 0x03, "binary data preserved");
    }

    printf("\n=== Results: %d/%d passed ===\n", total - failures, total);
    return failures > 0 ? 1 : 0;
}
