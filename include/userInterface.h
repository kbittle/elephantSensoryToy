#include <stdint.h>
#include "ShiftRegister.h"

#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_

class UserInterface
{
    public:
        typedef enum
        {
            GPIO_In_Poll = 0,
            GPIO_In_Int,
            GPIO_Out,
            SHIFT_Out
        } uiType;

        //! GPIO Detection Input Direction
        typedef enum
        {
            NONE,
            T_HIGH,
            T_LOW,
            BOTH
        } TriggerDirection_e;

    class UiElement
    {
        public:
            UiElement();
            UiElement(uiType _type, uint16_t _value, TriggerDirection_e _dir);

        public:
            //! Flag to enable UI element
            bool enabled;
            //! Enumeration of UI element 'uiType'
            uiType type;
            //! Pin value
            uint8_t pin;
            //! Shift register bitmask
            uint16_t bitMask;
            //! GPIO trigger direction
            TriggerDirection_e dir;
            //! UI element state
            bool state;
    };

    public:
        //! UI Elements that are present in the project
        typedef enum
        {
            YellowLed1 = 0,
            YellowLed2,
            YellowLed3,
            Button,
            ButtonLed,
            RGB1R,
            RGB1G,
            RGB1B,
            RGB2R,
            RGB2G,
            RGB2B,
            RGB3R,
            RGB3G,
            RGB3B,
            SW1POS1,
            SW1POS2,
            SW2POS1,
            SW3POS1,
            SW3POS2,
            MAX_UI_ELEMENTS
        } UiElement_e;

        // Constructor
        UserInterface();
        UserInterface(ShiftRegister * srInst);

        /*! Configure UI output event via shift register
         *
         *  id: UI Element enumeration id
         */
        void ConfigureShiftOutput(UiElement_e id, uint16_t bitmask);

        /*! Configure GPIO as UI input event
         *
         *  id: UI Element enumeration id
         *  pin: pin number
         *  dir: GPIO trigger direction
         */
        void ConfigureInput(UiElement_e id, uint8_t pin, TriggerDirection_e dir);

        /*! Get UI input event by ID
         */
        UiElement_e GetNextEvent();

        /*! Get UI input by ID
         */
        bool IsActive(UiElement_e id);

        /*! Set UI output by ID
         */
        void SetOut(UiElement_e id, bool enable);

        /*! Main loop update function
         */
        void Update(void);

    private:
        ShiftRegister * shiftRegInst;

        bool dataChanged;

        // Shift register buffer
        static const uint8_t UI_BUFF_LEN = 2;
        uint8_t uiBuffer[UI_BUFF_LEN];

        // List of al supported UI elements
        UiElement uiElements[MAX_UI_ELEMENTS];

        static const uint8_t QUEUE_SIZE = 5;  // Define the maximum size of the queue
        uint8_t myQueue[QUEUE_SIZE];  // Array to act as a queue
        int front = -1;  // Front of the queue
        int rear = -1;   // Rear of the queue

    private:
        static void ISR2_Callback(void);
        static void ISR3_Callback(void);
        static void InputCallback(uint8_t pin);

        bool enqueue(uint8_t value);
        bool dequeue(uint8_t * value);
        bool isEmpty();
};


#endif
