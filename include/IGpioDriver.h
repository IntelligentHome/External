#pragma once

#include <stdint.h>

namespace gpio_driver {

typedef enum {
    GPIO_INPUT = 0,
    GPIO_OUTPUT,
} GpioDirection;

typedef enum {
    GPIO_NO_PULL = 0,
    GPIO_PULL_UP,
} GpioPull;

class IGpio {

public:

    virtual void SetDirection(const GpioDirection gpio_direction) = 0;
    virtual void SetPull(const GpioPull gpio_pull) = 0;
    virtual void Set(void) = 0;
    virtual void Clear(void) = 0;
    virtual void Toggle(void) = 0;
    virtual uint8_t GetState(void) = 0;
};

} /*namespace gpio_driver*/
