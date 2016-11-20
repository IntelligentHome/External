#pragma once

#include <stdint.h>
#include "Common.h"

namespace nrf24_driver {

enum Rx { R0 = 0, R1, R2, R3, R4, R5,
    RxMax,
};

enum Tx { T0 = 0,
    TxMax,
};

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
    virtual Status SetRxAddress(Rx rx, uint8_t address[], uint8_t size) = 0;
    virtual Status SetTxAddress(Tx tx, uint8_t address[], uint8_t size) = 0;

    virtual NrfStatusRegister GetStatus(void) = 0;
};

} /*namespace nrf24_driver*/
