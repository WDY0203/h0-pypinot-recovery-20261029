// impl.cpp — getRescale semantic reconstruction for H0PP
// Not the original C++ code; a typed reconstruction that makes the same
// observable calls at the same decision points with the same argument shapes.
// Compile: g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp
// Run:     ./t
//
// Evidence: reconstructed_cpp/H0PP/H0PP_all_decompiled.txt IDX 175 (0x0010cc10)
//           PyArg_ParseTuple format "OO" (S_0010fc03)
//           Py_BuildValue format "d" (S_0010fc04)
//           PyLong_AsLong for second arg (date)
//           Free function H0PP_getRescale at 0x0010b780 creates stack SecInfo,
//           delegates to SecInfo::getRescale at 0x0010b790, returns 1.0 on failure (DAT_0010fd18)

#include <cstring>
#include <cstdint>
#include <string>
#include <vector>
#include <cmath>

struct SecInfo {
    std::string symbol;
    // Pre-close and close price tables for mock data
    std::vector<double> preClose;    // index = day offset from base
    std::vector<double> close;       // index = day offset from base
    size_t baseDate = 0;
    // Callback slot at +0x28 (reset by PIN_CALLBACK handler)
    void (*priceCallback)(double) = nullptr;
};

// Mock SecInfo database: a few symbols with price series
static SecInfo g_secs[] = {
    {"600000", {10.0, 10.5, 11.0, 10.8, 11.2}, {10.2, 10.7, 11.1, 10.9, 11.3}, 20240101},
    {"000001", {15.0, 15.3, 14.8, 15.1, 15.5}, {15.1, 15.5, 14.9, 15.2, 15.6}, 20240101},
    {"300750", {200.0, 205.0, 210.0, 208.0, 212.0}, {201.0, 206.0, 211.0, 209.0, 213.0}, 20240101},
};

static const size_t g_secCount = sizeof(g_secs) / sizeof(g_secs[0]);

// Find SecInfo by symbol string
static SecInfo* findSec(const char* symbol) {
    for (size_t i = 0; i < g_secCount; i++) {
        if (g_secs[i].symbol == symbol) return &g_secs[i];
    }
    return nullptr;
}

// Get close price for a given date offset from base
static double getClose(SecInfo& si, int date) {
    if (date < 0 || (size_t)(date - (int)si.baseDate) >= si.close.size()) return -1.0;
    return si.close[date - (int)si.baseDate];
}

// Get pre-close price for a given date offset from base
static double getPreClose(SecInfo& si, int date) {
    if (date < 0 || (size_t)(date - (int)si.baseDate) >= si.preClose.size()) return -1.0;
    return si.preClose[date - (int)si.baseDate];
}

// Free function H0PP_getRescale (0x0010b780): creates stack SecInfo,
// calls SecInfo::getRescale which computes preClose/close(prevDay)
// Returns 1.0 on failure (DAT_0010fd18)
static double H0PP_getRescale(SecInfo& si, int date, const char* symbol) {
    // getRescale = getPreClosePrice(symbol, date) / getClosePrice(symbol, prevDay)
    // prevDay = date - 1
    double preClose = getPreClose(si, date);
    double prevClose = getClose(si, date - 1);
    if (preClose < 0 || prevClose <= 0) {
        return 1.0; // identity default on failure
    }
    return preClose / prevClose;
}

// Python wrapper: getRescale(symbol: str, date: int) -> float | None
// Returns -1.0 to signal NULL/None (since we can't return Python objects natively)
static double getRescale_py(const char* symbol, int date) {
    SecInfo* si = findSec(symbol);
    if (!si) return -1.0; // NULL (None)
    return H0PP_getRescale(*si, date, symbol);
}

// Exported reconstruction entry point (mimics the C ABI of the wrap function)
extern "C" double H0PP_getRescale_wrapper(const char* symbol, int date) {
    return getRescale_py(symbol, date);
}
