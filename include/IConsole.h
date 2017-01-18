#pragma once

#include <stdint.h>

namespace iconsole {

class IConsole {

public:

    virtual IConsole& print(const char* str) = 0;
    virtual IConsole& print(const uint8_t value) = 0;
    virtual IConsole& newline(void) = 0;
};

} /*namespace IConsole*/
