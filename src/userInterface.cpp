#include "userInterface.h"
#include <Arduino.h>

UserInterface::UiElement::UiElement()
{
    enabled = false;
}
UserInterface::UiElement::UiElement(uiType _type, uint16_t _value, TriggerDirection_e _dir)
{
    enabled = true;
    type = _type;
    dir = _dir;

    if (type == SHIFT_Out)
    {
        bitMask = _value;
    }
    else
    {
        pin = _value;
        // Read default state
        state = digitalRead(pin);
    }
}

UserInterface::UserInterface()
{
    // Init UI buffer
    memset(&uiBuffer, 0, UI_BUFF_LEN);
    dataChanged = true;
    // Init ui elements
    for (int i=0; i<MAX_UI_ELEMENTS; i++)
    {
        uiElements[i] = UiElement();
    }
}

UserInterface::UserInterface(ShiftRegister * srInst)
{
    shiftRegInst = srInst;

    UserInterface();
}

void UserInterface::ConfigureShiftOutput(UiElement_e id, uint16_t bitmask)
{
    uiElements[id] = UiElement(SHIFT_Out, bitmask, NONE);
}

void UserInterface::ConfigureInput(UiElement_e id, uint8_t pin, TriggerDirection_e dir)
{
    pinMode(pin, INPUT);
    
    // Only pins 2 and 3 support interrupts
    if ((pin == 2) || (pin == 3))
    {
        uiElements[id] = UiElement(GPIO_In_Int, pin, dir);

        if (pin == 2)
            attachInterrupt(digitalPinToInterrupt(pin), ISR2_Callback, CHANGE);
        if (pin == 3)
            attachInterrupt(digitalPinToInterrupt(pin), ISR3_Callback, CHANGE);
    }
    else
    {
        uiElements[id] = UiElement(GPIO_In_Poll, pin, dir);
    }
}

UserInterface::UiElement_e UserInterface::GetNextEvent()
{
    if (!isEmpty())
    {
        uint8_t uiEventId;
        dequeue(&uiEventId);

        return (UiElement_e)uiEventId;
    }

    // Invalid return
    return MAX_UI_ELEMENTS;
}

bool UserInterface::IsActive(UiElement_e id)
{
    // A6 and A7 pins can only be used as analog inputs, not digital inputs
    if ((uiElements[id].pin == A6) ||
        (uiElements[id].pin == A7))
        return analogRead(uiElements[id].pin) > 512;
    else
        return digitalRead(uiElements[id].pin);
}

void UserInterface::SetOut(UiElement_e id, bool enable)
{
    if (uiElements[id].state != enable)
    {
        // Update local data
        uiElements[id].state = enable;

        if (enable)
            *((uint16_t*)&uiBuffer[0]) |= uiElements[id].bitMask;
        else
            *((uint16_t*)&uiBuffer[0]) &= ~uiElements[id].bitMask;

        Serial.print("uiBuffer=");
        Serial.print(uiBuffer[0], 16);
        Serial.println(uiBuffer[0], 16);

        // Flag that data has changed
        dataChanged = true;
    }    
}

void UserInterface::Update(void)
{
    // Update outputs via shift register
    if (dataChanged)
    {
        if (shiftRegInst != NULL)
        {
            shiftRegInst->Shift((uint8_t *)&uiBuffer, shiftRegInst->chainLen);
        }
        dataChanged = false;
    }

    // Update inputs
    for (int i=0; i<MAX_UI_ELEMENTS; i++)
    {
        // If UI element is pollable
        if ((uiElements[i].enabled) &&
            (uiElements[i].type == GPIO_In_Poll))
        {
            // Poll GPIO and handle any event changes
            uint8_t newVal = 0;
            // A6 and A7 pins can only be used as analog inputs, not digital inputs
            if ((uiElements[i].pin == A6) ||
                (uiElements[i].pin == A7))
                newVal = analogRead(uiElements[i].pin) > 512;
            else
                newVal = digitalRead(uiElements[i].pin);
            if (uiElements[i].state != newVal)
            {
                uiElements[i].state = newVal;

                if ((uiElements[i].dir == BOTH) ||
                    ((uiElements[i].dir == T_HIGH) && (newVal == HIGH)) ||
                    ((uiElements[i].dir == T_LOW) && (newVal == LOW)))
                {
                    //! Queue up UI event id
                    enqueue(i);
                }                
            }            
        }
    }
}

void UserInterface::ISR2_Callback(void)
{
    InputCallback(2);
}

void UserInterface::ISR3_Callback(void)
{
    InputCallback(3);
}

void UserInterface::InputCallback(uint8_t pin)
{
    Serial.print("Triggered:");
    Serial.println(pin);
}

bool UserInterface::enqueue(uint8_t value) 
{
    if (rear == QUEUE_SIZE - 1) {
        return false;
    } else {
        if (front == -1) {
            front = 0;  // If queue is initially empty, set front to 0
        }
        rear++;
        myQueue[rear] = value;
    }
    return true;
}

bool UserInterface::dequeue(uint8_t *value) 
{
    if (front == -1) {
        return false;
    } else {
        *value = myQueue[front];
        if (front == rear) {
            front = rear = -1;  // Reset front and rear when queue becomes empty
        } else {
            front++;
        }
    }
    return true;
}

bool UserInterface::isEmpty() 
{
    return (front == -1);
}
