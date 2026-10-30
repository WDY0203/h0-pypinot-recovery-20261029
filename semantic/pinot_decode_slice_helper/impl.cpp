// impl.cpp — pinot_decode_slice_helper semantic reconstruction for H0PP
// Compile: g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp
// Run:     ./t
//
// Evidence: reconstructed_cpp/H0PP/H0PP_all_decompiled.txt IDX 160 (0x0010ab80)
//           PyArg_ParseTuple format "O" (single arg - bytes)
//           Returns outer tuple (bytes_ts, inner_tuple)
//           inner_tuple = (list_of_bytes_codes, bytes_buffer)
//           Timestamp: 8 bytes at offset 0
//           Codes: fixed-length byte strings (6 bytes each)
//           Doubles: 8 bytes each, stored as raw bytes buffer

#include <cstring>
#include <cstdint>
#include <string>
#include <vector>
#include <cstdio>

// Constants derived from decompiler analysis
static const size_t TIMESTAMP_SIZE = 8;     // 8 bytes for timestamp
static const size_t CODE_SIZE = 6;          // 6 bytes per code (e.g., "600000")
static const size_t DOUBLE_SIZE = 8;        // 8 bytes per double

// Result structure: equivalent to (bytes_ts, (list_of_bytes_codes, bytes_buffer))
struct DecodeResult {
    std::vector<uint8_t> ts;                    // timestamp bytes (8)
    std::vector<std::vector<uint8_t>> codes;   // list of code byte strings
    std::vector<uint8_t> data_buffer;           // raw bytes of doubles
};

// Free function H0PP_pinot_decode_slice_helper (0x0010ab80):
// Parse binary slice data blob
static DecodeResult H0PP_pinot_decode_slice_helper_impl(const uint8_t* data, size_t len) {
    DecodeResult result;
    
    // Extract timestamp (8 bytes at offset 0)
    if (len < TIMESTAMP_SIZE) {
        return result; // too short
    }
    result.ts.assign(data, data + TIMESTAMP_SIZE);
    size_t pos = TIMESTAMP_SIZE;
    
    // Read number of codes (4 bytes int at offset 8)
    if (pos + 4 > len) return result;
    uint32_t num_codes = *(uint32_t*)(data + pos);
    pos += 4;
    
    // Extract code list (num_codes * 6 bytes each)
    if (pos + (size_t)num_codes * CODE_SIZE > len) return result;
    for (uint32_t i = 0; i < num_codes; i++) {
        std::vector<uint8_t> code(data + pos, data + pos + CODE_SIZE);
        result.codes.push_back(code);
        pos += CODE_SIZE;
    }
    
    // Extract doubles buffer (remaining bytes)
    if (pos > len) return result;
    result.data_buffer.assign(data + pos, data + len);
    
    return result;
}

// Python wrapper: pinot_decode_slice_helper(data: bytes) -> (bytes, (list, bytes))
// Returns via output parameters for testing
extern "C" int H0PP_pinot_decode_slice_helper_wrapper(
    const uint8_t* data, size_t len,
    uint8_t* out_ts, size_t out_ts_len,
    uint32_t* out_num_codes, uint8_t* out_codes, size_t out_codes_len,
    uint8_t* out_data_buf, size_t out_data_len) {
    
    DecodeResult result = H0PP_pinot_decode_slice_helper_impl(data, len);
    
    if (result.ts.size() > out_ts_len) return -1;
    memcpy(out_ts, result.ts.data(), result.ts.size());
    
    *out_num_codes = (uint32_t)result.codes.size();
    size_t codes_size = result.codes.size() * CODE_SIZE;
    if (codes_size > out_codes_len) return -1;
    for (size_t i = 0; i < result.codes.size(); i++) {
        memcpy(out_codes + i * CODE_SIZE, result.codes[i].data(), CODE_SIZE);
    }
    
    if (result.data_buffer.size() > out_data_len) return -1;
    memcpy(out_data_buf, result.data_buffer.data(), result.data_buffer.size());
    
    return 0;
}

// Helper to get sizes
extern "C" size_t H0PP_pinot_decode_get_ts_len() { return TIMESTAMP_SIZE; }
extern "C" size_t H0PP_pinot_decode_get_code_len() { return CODE_SIZE; }
extern "C" size_t H0PP_pinot_decode_get_double_len() { return DOUBLE_SIZE; }
