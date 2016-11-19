#pragma once

#include <stdint.h>
#include "ITransport.h"

namespace spi_driver {

class ISpi : public transport::ITransport {

public:
    virtual void Send(uint8_t *psend_buff, uint16_t size) = 0;
    virtual void Get(uint8_t *precv_buff, uint16_t size) = 0;
    virtual void SendAndGet(uint8_t *psend_buff, uint8_t *precv_buff, uint16_t size) = 0;
};

} /*namespace spi_driver*/
