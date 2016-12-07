#pragma once

#include <stdint.h>
#include "Common.h"

namespace nrf24_driver {

typedef enum { R0, R1, R2, R3, R4, R5,
    RxMax
} Rx;

typedef enum { T0,
    TxMax
} Tx;

union NrfStatusRegister {
    struct {
        uint8_t tx_full         : 1,
                rx_pipe_no      : 3,
                max_rt          : 1,
                tx_data_ready   : 1,
                rx_data_ready   : 1,
                reserved        : 1;
    };
    uint8_t raw_data;
};

class INrf24 {

public:

    virtual Status SetDefaults(void) = 0;
    virtual Status SetRfChannel(uint8_t channel) = 0;
    virtual Status SetPayloadSize(uint8_t payload_size) = 0;
    virtual Status SetPayloadSize(Rx rx, uint8_t paylaod_size) = 0;
    virtual Status SetRetries(uint8_t delay, uint8_t retries) = 0;
    virtual Status SetAddress(Rx rx, const uint8_t address[], uint8_t size) = 0;
    virtual Status SetAddress(Tx tx, const uint8_t address[], uint8_t size) = 0;
    virtual Status SetPayload(const uint8_t payload[], const uint8_t size) = 0;
    virtual Status SetAutoAck(const uint8_t auto_ack) = 0;

    virtual Status StartListening(void) = 0;
    virtual Status StopListening(void) = 0;

    virtual NrfStatusRegister GetStatus(void) = 0;
    virtual Status GetPayload(uint8_t payload[], const uint8_t size) = 0;
};

} /*namespace nrf24_driver*/
