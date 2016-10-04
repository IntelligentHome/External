#pragma once

#include <stdint.h>

namespace gpio_driver {

class IGpio {

public:
    virtual void Set(void) = 0;
    virtual void Clear(void) = 0;
    virtual void Toggle(void) = 0;
    virtual uint8_t GetState(void) = 0;
};

} /*namespace gpio_driver*/
