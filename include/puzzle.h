#include <stdint.h>

#include "ledMatrixAnimator.h"
#include "userInterface.h"
#include "Adafruit_DRV2605.h"

#ifndef PUZZLE_H_
#define PUZZLE_H_

class Puzzle
{
    public:
        // Constructor
        Puzzle(LedMatrixAnimator * _animInst, UserInterface * _uiInst, Adafruit_DRV2605 * _buzzInst);

        void Update(void);

    private:
        //! RGB COlor Selection ENum
        typedef enum
        {
            Sel_Red = 0,
            Sel_Green,
            Sel_Blue
        } RgColoSel_e;

        LedMatrixAnimator * animInst;
        UserInterface * uiInst;
        Adafruit_DRV2605 * buzzInst;

        uint8_t yellowLedCounter;
        uint8_t rgbLedCounter;
        RgColoSel_e rgColorSelected;

        void UpdateYellowLeds(void);
        void UpdateRgbLeds(void);
};


#endif
