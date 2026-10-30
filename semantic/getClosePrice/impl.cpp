// impl.cpp — getClosePrice semantic reconstruction for H0PP
// Compile: g++ -std=gnu++17 -O2 -o t test.cpp impl.cpp
// Run:     ./t
//
// Evidence: reconstructed_cpp/H0PP/H0PP_all_decompiled.txt IDX 174 (0x0010caa0)
//           PyArg_ParseTuple format "OO" (S_0010fc03)
//           Py_BuildValue format "d" (S_0010fc04)
//           PyLong_AsLong for second arg (date)
//           Free function H0PP_getClosePrice at 0x0010b890 creates stack SecInfo,
//           delegates to SecInfo::getClosePrice, returns -1.0 on failure

#include <cstring>
#include <cstdint>
#include <string>
#include <vector>

struct SecInfo {
    std::string symbol;
    std::vector<double> preClose;
    std::vector<double> close;
    size_t baseDate = 0;
    void (*priceCallback)(double) = nullptr;
};

static SecInfo g_secs[] = {
    {"600000", {10.0, 10.5, 11.0, 10.8, 11.2}, {10.2, 10.7, 11.1, 10.9, 11.3}, 20240101},
    {"000001", {15.0, 15.3, 14.8, 15.1, 15.5}, {15.1, 15.5, 14.9, 15.2, 15.6}, 20240101},
    {"300750", {200.0, 205.0, 210.0, 208.0, 212.0}, {201.0, 206.0, 211.0, 209.0, 213.0}, 20240101},
};

static const size_t g_secCount = sizeof(g_secs) / sizeof(g_secs[0]);

static SecInfo* findSec(const char* symbol) {
    for (size_t i = 0; i < g_secCount; i++) {
        if (g_secs[i].symbol == symbol) return &g_secs[i];
    }
    return nullptr;
}

// Free function H0PP_getClosePrice (0x0010b890): creates stack SecInfo,
// calls SecInfo::getClosePrice, returns -1.0 on failure
static double H0PP_getClosePrice(SecInfo& si, int date, const char* symbol) {
    if (date < 0 || (size_t)(date - (int)si.baseDate) >= si.close.size()) {
        return -1.0;
    }
    return si.close[date - (int)si.baseDate];
}

// Python wrapper: getClosePrice(symbol: str, date: int) -> float | None
static double getClosePrice_py(const char* symbol, int date) {
    SecInfo* si = findSec(symbol);
    if (!si) return -1.0; // NULL (None)
    return H0PP_getClosePrice(*si, date, symbol);
}

extern "C" double H0PP_getClosePrice_wrapper(const char* symbol, int date) {
    return getClosePrice_py(symbol, date);
}
