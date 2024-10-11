#include <Arduino.h>
#include <SPI.h>
#include "ledMatrix.h"
#include "ledMatrixAnimator.h"
#include "userInterface.h"
#include "ShiftRegister.h"
#include <Wire.h>
#include "Adafruit_DRV2605.h"
#include "puzzle.h"

const int latchPin = 12;
const int clockPin = 11;
const int dataPin = 10;

const int sr2_latchPin = 8;
const int sr2_clockPin = 9;
const int sr2_dataPin = 7;

// Global Instances
ShiftRegister sr1(dataPin, clockPin, latchPin, 2);
ShiftRegister sr2(sr2_dataPin, sr2_clockPin, sr2_latchPin, 2);
LedMatrix matrix8x8(&sr1);
LedMatrixAnimator animation;
UserInterface uiInst(&sr2);
Adafruit_DRV2605 hapticInst;
Puzzle puzzle(&animation, &uiInst, &hapticInst);

void setup() {
  // Start serial
  Serial.begin(9600);
  while (!Serial);

  // Setup pins as Outputs  
  pinMode(LED_BUILTIN, OUTPUT);
  
  uiInst.ConfigureInput( UserInterface::SW1POS1, 
                     A0, 
                     UserInterface::TriggerDirection_e::T_LOW );
  uiInst.ConfigureInput( UserInterface::SW1POS2, 
                     A1, 
                     UserInterface::TriggerDirection_e::T_LOW );
  uiInst.ConfigureInput( UserInterface::Button, 
                     A2, 
                     UserInterface::TriggerDirection_e::T_LOW );
  uiInst.ConfigureInput( UserInterface::SW2POS1, 
                     A3, 
                     UserInterface::TriggerDirection_e::T_LOW );
  uiInst.ConfigureInput( UserInterface::SW3POS1, 
                     A6, 
                     UserInterface::TriggerDirection_e::T_LOW );
  uiInst.ConfigureInput( UserInterface::SW3POS2, 
                     A7, 
                     UserInterface::TriggerDirection_e::T_LOW );
  
  uiInst.ConfigureShiftOutput(UserInterface::YellowLed1, 0B0000000100000000);
  uiInst.ConfigureShiftOutput(UserInterface::YellowLed2, 0B0000001000000000);
  uiInst.ConfigureShiftOutput(UserInterface::YellowLed3, 0B0000010000000000);
  uiInst.ConfigureShiftOutput(UserInterface::ButtonLed,  0B0000100000000000);
  uiInst.ConfigureShiftOutput(UserInterface::RGB1R,      0B0001000000000000);
  uiInst.ConfigureShiftOutput(UserInterface::RGB1G,      0B0010000000000000);
  uiInst.ConfigureShiftOutput(UserInterface::RGB1B,      0B0100000000000000);
  uiInst.ConfigureShiftOutput(UserInterface::RGB2R,      0B1000000000000000);
  uiInst.ConfigureShiftOutput(UserInterface::RGB2G,      0B0000000000000001);
  uiInst.ConfigureShiftOutput(UserInterface::RGB2B,      0B0000000000000010);
  uiInst.ConfigureShiftOutput(UserInterface::RGB3R,      0B0000000000000100);
  uiInst.ConfigureShiftOutput(UserInterface::RGB3G,      0B0000000000001000);
  uiInst.ConfigureShiftOutput(UserInterface::RGB3B,      0B0000000000010000);

  if (! hapticInst.begin()) {
    Serial.println("Could not find DRV2605");
    while (1) delay(10);
  } 
  hapticInst.selectLibrary(1);  
  // I2C trigger by sending 'go' command 
  // default, internal trigger when sending GO command
  hapticInst.setMode(DRV2605_MODE_INTTRIG);
  hapticInst.setWaveform(0, 52); // Pulsing Strong 1
  hapticInst.setWaveform(1, 0);  // end of waveforms

  Serial.println("Finished");
}

uint32_t interval = 1000;
uint32_t iteration = 0;

void loop() {  
  // the next time that you want to do your action
  static uint32_t nextTime;

  // check if it's time
  if (millis() - nextTime >= interval)
  {
    // update next time
    nextTime += interval;

    #ifdef DEBUG
    Serial.print("iteration=");
    Serial.println(iteration);

    if ((iteration++ % 2) == 0)
    {
      digitalWrite(LED_BUILTIN, LOW);
    }
    else
    {
      digitalWrite(LED_BUILTIN, HIGH);   
    }
    #endif
  }

  puzzle.Update();
  animation.Update();
  uiInst.Update();

  matrix8x8.Draw( animation.GetFrameBuffer(), 
                  animation.GetFrameBufferLen() );
}
