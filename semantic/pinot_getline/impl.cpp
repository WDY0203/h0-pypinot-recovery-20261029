// impl.cpp — pinot_getline semantic reconstruction for H0PP
// Compile: g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp
// Run:     ./t
//
// Evidence: reconstructed_cpp/H0PP/H0PP_all_decompiled.txt IDX 164 (0x0010c0e0)
//           PyArg_ParseTuple format "O" (single arg - stream/handle)
//           Returns PyTuple_Pack(2, int success_flag, bytes line_data)
//           Int built via PyLong_FromLong (format "l" at S_0010fbf4)
//           Bytes built via PyBytes_FromStringAndSize

#include <cstring>
#include <cstdint>
#include <string>
#include <vector>
#include <cstdio>

// Mock stream structure: simulates a binary stream that pinot_getline reads from
struct MockStream {
    std::vector<uint8_t> data;
    size_t pos = 0;
    bool eof = false;
    
    bool readLine(std::vector<uint8_t>& out) {
        if (pos >= data.size()) {
            eof = true;
            return false;
        }
        size_t start = pos;
        while (pos < data.size() && data[pos] != 0x0A) { // newline
            pos++;
        }
        out.assign(data.begin() + start, data.begin() + pos);
        if (pos < data.size()) pos++; // skip newline
        return true;
    }
};

// Global stream table for testing
static MockStream g_streams[8];
static size_t g_streamCount = 0;

// Create a new stream with data
static int create_stream(const uint8_t* data, size_t len) {
    if (g_streamCount >= 8) return -1;
    g_streams[g_streamCount].data.assign(data, data + len);
    g_streams[g_streamCount].pos = 0;
    g_streams[g_streamCount].eof = false;
    return (int)g_streamCount++;
}

// Python wrapper: pinot_getline(stream: int) -> (int, bytes)
// Returns -1 on error, 0 on EOF, 1 on success
// line_data is returned via a global buffer for testing
static int pinot_getline_py(int stream_id, std::vector<uint8_t>& out_data) {
    if (stream_id < 0 || stream_id >= (int)g_streamCount) {
        return -1; // error
    }
    MockStream& stream = g_streams[stream_id];
    if (!stream.readLine(out_data)) {
        return 0; // EOF
    }
    return 1; // success
}

extern "C" int H0PP_pinot_getline_wrapper(int stream_id, uint8_t* out_buf, size_t out_len) {
    std::vector<uint8_t> line;
    int flag = pinot_getline_py(stream_id, line);
    if (flag > 0 && line.size() <= out_len) {
        memcpy(out_buf, line.data(), line.size());
    }
    return flag;
}

// Helper for tests
extern "C" int H0PP_pinot_create_stream(const uint8_t* data, size_t len) {
    return create_stream(data, len);
}
