#include <stdint.h>
#include "ShiftRegister.h"

#ifndef LED_MATRIX_H_
#define LED_MATRIX_H_

class LedMatrix
{
    public:
        // Constructor
        LedMatrix(ShiftRegister * sr);

        void Draw(uint8_t *buf, uint8_t len);

    private:
        ShiftRegister * shiftRegInst;
};


#endif
