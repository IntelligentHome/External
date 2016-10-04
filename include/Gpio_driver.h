
#pragma once

#include "IGpio_driver.h"

namespace gpio_driver {

class GpioAvr : public IGpio {

public:
    virtual void Set(void);
    virtual void Clear(void);
    virtual void Toggle(void);
    virtual uint8_t GetState(void);
};

} /*namespace gpio_driver*/
