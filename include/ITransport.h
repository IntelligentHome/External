#pragma once

#include <stdint.h>

namespace transport {

class ITransport {

public:

    virtual void Send(uint8_t send_buff[], uint16_t size) = 0;
    virtual void Get(uint8_t recv_buff[], uint16_t size) = 0;
    virtual void SendAndGet(uint8_t send_buff[], uint8_t recv_buff[], uint16_t size) = 0;

};

} /*namespace transport*/
