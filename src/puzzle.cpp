#include "puzzle.h"
#include <Arduino.h>

Puzzle::Puzzle(LedMatrixAnimator * _animInst, UserInterface * _uiInst, Adafruit_DRV2605 * _buzzInst)
{
    animInst = _animInst;
    uiInst = _uiInst;
    buzzInst = _buzzInst;
}

void Puzzle::Update(void)
{
    UserInterface::UiElement_e nextEvent = uiInst->GetNextEvent();
    if (nextEvent == UserInterface::SW1POS1)
    {
        Serial.println("SW1POS1");

        buzzInst->go();

        // Increase Yellow Led's
        if (yellowLedCounter < 7)
        {
            yellowLedCounter++;
            UpdateYellowLeds();
        }
    }
    else if (nextEvent == UserInterface::SW1POS2)
    {
        Serial.println("SW1POS2");

        buzzInst->go();

        // Decrease Yellow Led's
        if (yellowLedCounter > 0)
        {
            yellowLedCounter--;
            UpdateYellowLeds();
        }        
    }
    else if (nextEvent == UserInterface::SW2POS1)
    {
        Serial.println("SW2POS1");

        buzzInst->go();
        
        // Map code of yellow LED's to animation
        switch (yellowLedCounter)
        {
            case 1:
                animInst->DoSmile();
                break;
            case 2:
            case 3:
            case 7:
                animInst->DoAlienDance();
                break;
            case 4:
                animInst->DoEyeRoll();
                break;
            case 5:
                animInst->DoEyeRoll2();
                break;
            case 6:
                animInst->DoEyeBlink();
                break;
            default:
                break;
        }

        // Clear yellow counter
        yellowLedCounter = 0;
        UpdateYellowLeds();

        // Change RGB counter
        rgbLedCounter++;
        if (rgbLedCounter > 3)
            rgbLedCounter = 0;
        UpdateRgbLeds();
    }
    else if (nextEvent == UserInterface::SW3POS1)
    {
        Serial.println("SW3POS1");
        
        // Cycle through Colors
        switch (rgColorSelected)
        {
            case Sel_Red: rgColorSelected = Sel_Green; break;
            case Sel_Green: rgColorSelected = Sel_Blue; break;
            case Sel_Blue: rgColorSelected = Sel_Red; break;            
            default: break;
        }

        UpdateRgbLeds();
    }
    else if (nextEvent == UserInterface::SW3POS2)
    {
        Serial.println("SW3POS2"); 

        // Cycle through Colors
        switch (rgColorSelected)
        {
            case Sel_Red: rgColorSelected = Sel_Green; break;
            case Sel_Green: rgColorSelected = Sel_Blue; break;
            case Sel_Blue: rgColorSelected = Sel_Red; break;            
            default: break;
        }

        UpdateRgbLeds();
    }
    else if (nextEvent == UserInterface::Button)
    {
        Serial.println("Button"); 

        // Buttons clears RGB LED's and does animation 
        rgbLedCounter = 0;
        UpdateRgbLeds();

        animInst->DoHeartPump();
    }
}

void Puzzle::UpdateYellowLeds(void)
{
    switch (yellowLedCounter)
    {
        case 1:
            uiInst->SetOut(UserInterface::YellowLed1, true);
            uiInst->SetOut(UserInterface::YellowLed2, false);
            uiInst->SetOut(UserInterface::YellowLed3, false);
            break;
        case 2:
            uiInst->SetOut(UserInterface::YellowLed1, false);
            uiInst->SetOut(UserInterface::YellowLed2, true);
            uiInst->SetOut(UserInterface::YellowLed3, false);
            break;
        case 3:
            uiInst->SetOut(UserInterface::YellowLed1, true);
            uiInst->SetOut(UserInterface::YellowLed2, true);
            uiInst->SetOut(UserInterface::YellowLed3, false);
            break;
        case 4:
            uiInst->SetOut(UserInterface::YellowLed1, false);
            uiInst->SetOut(UserInterface::YellowLed2, false);
            uiInst->SetOut(UserInterface::YellowLed3, true);
            break;
        case 5:
            uiInst->SetOut(UserInterface::YellowLed1, true);
            uiInst->SetOut(UserInterface::YellowLed2, false);
            uiInst->SetOut(UserInterface::YellowLed3, true);
            break;
        case 6:
            uiInst->SetOut(UserInterface::YellowLed1, false);
            uiInst->SetOut(UserInterface::YellowLed2, true);
            uiInst->SetOut(UserInterface::YellowLed3, true);
            break;
        case 7:
            uiInst->SetOut(UserInterface::YellowLed1, true);
            uiInst->SetOut(UserInterface::YellowLed2, true);
            uiInst->SetOut(UserInterface::YellowLed3, true);
            break;
            
        default:
        case 0:
            uiInst->SetOut(UserInterface::YellowLed1, false);
            uiInst->SetOut(UserInterface::YellowLed2, false);
            uiInst->SetOut(UserInterface::YellowLed3, false);
            break;
    }
}

void Puzzle::UpdateRgbLeds(void)
{
    switch (rgbLedCounter)
    {
        case 1:
            if (rgColorSelected == Sel_Red)
            {
                uiInst->SetOut(UserInterface::RGB1R, true);
                uiInst->SetOut(UserInterface::RGB2R, false);
                uiInst->SetOut(UserInterface::RGB3R, false);
                uiInst->SetOut(UserInterface::RGB1G, false);
                uiInst->SetOut(UserInterface::RGB2G, false);
                uiInst->SetOut(UserInterface::RGB3G, false); 
                uiInst->SetOut(UserInterface::RGB1B, false);
                uiInst->SetOut(UserInterface::RGB2B, false);
                uiInst->SetOut(UserInterface::RGB3B, false);
            }
            else if (rgColorSelected == Sel_Green)
            {
                uiInst->SetOut(UserInterface::RGB1R, false);
                uiInst->SetOut(UserInterface::RGB2R, false);
                uiInst->SetOut(UserInterface::RGB3R, false);
                uiInst->SetOut(UserInterface::RGB1G, true);
                uiInst->SetOut(UserInterface::RGB2G, false);
                uiInst->SetOut(UserInterface::RGB3G, false); 
                uiInst->SetOut(UserInterface::RGB1B, false);
                uiInst->SetOut(UserInterface::RGB2B, false);
                uiInst->SetOut(UserInterface::RGB3B, false);
            }
            else if (rgColorSelected == Sel_Blue)
            {
                uiInst->SetOut(UserInterface::RGB1R, false);
                uiInst->SetOut(UserInterface::RGB2R, false);
                uiInst->SetOut(UserInterface::RGB3R, false);
                uiInst->SetOut(UserInterface::RGB1G, false);
                uiInst->SetOut(UserInterface::RGB2G, false);
                uiInst->SetOut(UserInterface::RGB3G, false); 
                uiInst->SetOut(UserInterface::RGB1B, true);
                uiInst->SetOut(UserInterface::RGB2B, false);
                uiInst->SetOut(UserInterface::RGB3B, false);
            }
            break;
        case 2:
            if (rgColorSelected == Sel_Red)
            {
                uiInst->SetOut(UserInterface::RGB1R, true);
                uiInst->SetOut(UserInterface::RGB2R, true);
                uiInst->SetOut(UserInterface::RGB3R, false);
                uiInst->SetOut(UserInterface::RGB1G, false);
                uiInst->SetOut(UserInterface::RGB2G, false);
                uiInst->SetOut(UserInterface::RGB3G, false); 
                uiInst->SetOut(UserInterface::RGB1B, false);
                uiInst->SetOut(UserInterface::RGB2B, false);
                uiInst->SetOut(UserInterface::RGB3B, false);
            }
            else if (rgColorSelected == Sel_Green)
            {
                uiInst->SetOut(UserInterface::RGB1R, false);
                uiInst->SetOut(UserInterface::RGB2R, false);
                uiInst->SetOut(UserInterface::RGB3R, false);
                uiInst->SetOut(UserInterface::RGB1G, true);
                uiInst->SetOut(UserInterface::RGB2G, true);
                uiInst->SetOut(UserInterface::RGB3G, false); 
                uiInst->SetOut(UserInterface::RGB1B, false);
                uiInst->SetOut(UserInterface::RGB2B, false);
                uiInst->SetOut(UserInterface::RGB3B, false);
            }
            else if (rgColorSelected == Sel_Blue)
            {
                uiInst->SetOut(UserInterface::RGB1R, false);
                uiInst->SetOut(UserInterface::RGB2R, false);
                uiInst->SetOut(UserInterface::RGB3R, false);
                uiInst->SetOut(UserInterface::RGB1G, false);
                uiInst->SetOut(UserInterface::RGB2G, false);
                uiInst->SetOut(UserInterface::RGB3G, false); 
                uiInst->SetOut(UserInterface::RGB1B, true);
                uiInst->SetOut(UserInterface::RGB2B, true);
                uiInst->SetOut(UserInterface::RGB3B, false);
            }
            break;
        case 3:
            if (rgColorSelected == Sel_Red)
            {
                uiInst->SetOut(UserInterface::RGB1R, true);
                uiInst->SetOut(UserInterface::RGB2R, true);
                uiInst->SetOut(UserInterface::RGB3R, true);
                uiInst->SetOut(UserInterface::RGB1G, false);
                uiInst->SetOut(UserInterface::RGB2G, false);
                uiInst->SetOut(UserInterface::RGB3G, false); 
                uiInst->SetOut(UserInterface::RGB1B, false);
                uiInst->SetOut(UserInterface::RGB2B, false);
                uiInst->SetOut(UserInterface::RGB3B, false);
            }
            else if (rgColorSelected == Sel_Green)
            {
                uiInst->SetOut(UserInterface::RGB1R, false);
                uiInst->SetOut(UserInterface::RGB2R, false);
                uiInst->SetOut(UserInterface::RGB3R, false);
                uiInst->SetOut(UserInterface::RGB1G, true);
                uiInst->SetOut(UserInterface::RGB2G, true);
                uiInst->SetOut(UserInterface::RGB3G, true); 
                uiInst->SetOut(UserInterface::RGB1B, false);
                uiInst->SetOut(UserInterface::RGB2B, false);
                uiInst->SetOut(UserInterface::RGB3B, false);
            }
            else if (rgColorSelected == Sel_Blue)
            {
                uiInst->SetOut(UserInterface::RGB1R, false);
                uiInst->SetOut(UserInterface::RGB2R, false);
                uiInst->SetOut(UserInterface::RGB3R, false);
                uiInst->SetOut(UserInterface::RGB1G, false);
                uiInst->SetOut(UserInterface::RGB2G, false);
                uiInst->SetOut(UserInterface::RGB3G, false); 
                uiInst->SetOut(UserInterface::RGB1B, true);
                uiInst->SetOut(UserInterface::RGB2B, true);
                uiInst->SetOut(UserInterface::RGB3B, true);
            }
            break;
        
        case 0:
        default:            
            uiInst->SetOut(UserInterface::RGB1R, false);
            uiInst->SetOut(UserInterface::RGB2R, false);
            uiInst->SetOut(UserInterface::RGB3R, false);
            uiInst->SetOut(UserInterface::RGB1G, false);
            uiInst->SetOut(UserInterface::RGB2G, false);
            uiInst->SetOut(UserInterface::RGB3G, false);
            uiInst->SetOut(UserInterface::RGB1B, false);
            uiInst->SetOut(UserInterface::RGB2B, false);
            uiInst->SetOut(UserInterface::RGB3B, false);
            break;
    }
}