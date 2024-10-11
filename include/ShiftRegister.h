#include <stdint.h>

#ifndef SHIFT_REGISTER_H_
#define SHIFT_REGISTER_H_

class ShiftRegister
{
    public:
        uint8_t chainLen;
        
        // Constructor
        ShiftRegister(uint8_t _dataPin, uint8_t _clkPin, uint8_t _latchPin, uint8_t _chainLen);

        int Shift(uint8_t *buf, uint8_t len);

    private:
        uint8_t dataPin;
        uint8_t clkPin;
        uint8_t latchPin;
};


#endif
