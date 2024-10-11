#include <stdint.h>

#ifndef LED_MATRIX_ANIMATOR_H_
#define LED_MATRIX_ANIMATOR_H_

class LedMatrixAnimator
{
    public:
        typedef enum
        {
            Heart = 0,
            SmallHeart,
            EyeLeft,
            EyeLeftDown,
            EyeLeftDown2,
            EyeDown,
            SmallEyeLeft,
            SmallEyeLeftDown,
            SmallEyeDown,
            EyeBlink1,
            EyeBlink2,
            EyeBlink3,
            EyeBlink4,
            EyeBlink5,
            EyeBlink6,
            Smile,
            SmileTransition1,
            SmileTransition2,
            SmileTransition3,
            SmileTransition4,
            SmileTransition5,
            SmileTransition6,
            Alien1,
            Alien2,
            MAX_ANIMATION_STATES
        } animationState_e;

        typedef struct
        {
            animationState_e state;
            uint16_t durationMs;
        } animationFrame_t;        

        // Constructor
        LedMatrixAnimator();

        void DoEyeBlink(void);
        void DoEyeRoll(void);
        void DoEyeRoll2(void);
        void DoHeartPump(void);
        void DoSmile(void);
        void DoAlienDance(void);

        void Update(void);
        uint8_t * GetFrameBuffer(void);
        uint8_t GetFrameBufferLen(void);

    private:
        animationState_e currentState;
        uint32_t nextFrameTime;
};


#endif
