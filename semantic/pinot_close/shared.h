// Shared header for pinot_open/close tests and impl
#ifndef PINOT_SHARED_H
#define PINOT_SHARED_H

#include <string>

struct PinotHandle {
    std::string path;
    bool dlopenSuccess;
    bool fallbackUsed;
    void* dlopenHandle;
};

#endif
