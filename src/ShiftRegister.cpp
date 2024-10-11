#include "ShiftRegister.h"
#include <Arduino.h>

ShiftRegister::ShiftRegister(uint8_t _dataPin, uint8_t _clkPin, uint8_t _latchPin, uint8_t _chainLen)
{
    dataPin = _dataPin;
    clkPin = _clkPin;
    latchPin =_latchPin;
    chainLen = _chainLen;

    pinMode(latchPin, OUTPUT);
    pinMode(clkPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
}

int ShiftRegister::Shift(uint8_t *buf, uint8_t len) 
{
    if (len > chainLen)
        return -1;

    // ST_CP LOW to keep LEDs from changing while reading serial data
    digitalWrite(latchPin, LOW);
 
    // Shift out the bits
    for (int i=0; i<len; i++)
        shiftOut(dataPin, clkPin, MSBFIRST, buf[i]);
 
    // ST_CP HIGH change LEDs
    digitalWrite(latchPin, HIGH);

    return 0;
}
