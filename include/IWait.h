#pragma once

#include <stdint.h>

namespace iwait {

class IWait {

public:
    virtual void wait_us(uint16_t time) = 0;
    virtual void wait_ms(uint16_t time) = 0;
};

} /* namespace sleep */
