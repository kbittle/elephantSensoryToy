#include "ledMatrix.h"
#include <Arduino.h>

LedMatrix::LedMatrix(ShiftRegister * sr)
{
    shiftRegInst = sr;
}

void LedMatrix::Draw(uint8_t *buf, uint8_t len)
{
    uint8_t formattedData[2];
    uint8_t delayMs = 0;

    for (int i=0; i<len; i++)
    {
        formattedData[0] = buf[i];
        formattedData[1] = ~(1<<i);

        if (shiftRegInst != NULL)
            shiftRegInst->Shift(formattedData, shiftRegInst->chainLen);
        
        delay(delayMs);
    }
}
