#include "ledMatrixAnimator.h"
#include "8x8ledPatterns.h"

#include <arduino.h>
#include <cppQueue.h>

cppQueue frameQueue(sizeof(LedMatrixAnimator::animationFrame_t), 20, FIFO, false);

LedMatrixAnimator::LedMatrixAnimator()
{
    currentState = MAX_ANIMATION_STATES;
}

void LedMatrixAnimator::DoEyeBlink(void)
{
    animationFrame_t frame;
    frame.state = EyeBlink1;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = EyeBlink2;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = EyeBlink3;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = EyeBlink4;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = EyeBlink5;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = EyeBlink6;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = EyeBlink5;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = EyeBlink4;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = EyeBlink3;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = EyeBlink2;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = EyeBlink1;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = MAX_ANIMATION_STATES;
    frame.durationMs = 200;
    frameQueue.push(&frame);

    // Kick off animation
    nextFrameTime = millis();
}

void LedMatrixAnimator::DoEyeRoll(void)
{
    animationFrame_t frame;
    frame.state = SmallEyeLeft;
    frame.durationMs = 500;
    frameQueue.push(&frame);
    frame.state = SmallEyeLeftDown;
    frame.durationMs = 400;
    frameQueue.push(&frame);
    frame.state = SmallEyeDown;
    frame.durationMs = 300;
    frameQueue.push(&frame);
    frame.state = SmallEyeLeftDown;
    frame.durationMs = 300;
    frameQueue.push(&frame);
    frame.state = SmallEyeDown;
    frame.durationMs = 500;
    frameQueue.push(&frame);
    frame.state = SmallEyeLeftDown;
    frame.durationMs = 400;
    frameQueue.push(&frame);
    frame.state = SmallEyeLeft;
    frame.durationMs = 400;
    frameQueue.push(&frame);
    frame.state = MAX_ANIMATION_STATES;
    frame.durationMs = 100;
    frameQueue.push(&frame);

    // Kick off animation
    nextFrameTime = millis();
}

void LedMatrixAnimator::DoEyeRoll2(void)
{
    animationFrame_t frame;
    frame.state = EyeLeft;
    frame.durationMs = 500;
    frameQueue.push(&frame);
    frame.state = EyeLeftDown;
    frame.durationMs = 400;
    frameQueue.push(&frame);
    frame.state = EyeLeftDown2;
    frame.durationMs = 300;
    frameQueue.push(&frame);
    frame.state = EyeDown;
    frame.durationMs = 500;
    frameQueue.push(&frame);
    frame.state = EyeLeftDown2;
    frame.durationMs = 300;
    frameQueue.push(&frame);
    frame.state = EyeLeftDown;
    frame.durationMs = 400;
    frameQueue.push(&frame);
    frame.state = EyeLeft;
    frame.durationMs = 400;
    frameQueue.push(&frame);
    frame.state = MAX_ANIMATION_STATES;
    frame.durationMs = 100;
    frameQueue.push(&frame);

    // Kick off animation
    nextFrameTime = millis();
}

void LedMatrixAnimator::DoHeartPump(void)
{
    animationFrame_t frame;
    frame.state = Heart;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = SmallHeart;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = Heart;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = SmallHeart;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = Heart;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = SmallHeart;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = MAX_ANIMATION_STATES; // end animation
    frame.durationMs = 200;
    frameQueue.push(&frame);

    // Kick off animation
    nextFrameTime = millis();
}

void LedMatrixAnimator::DoSmile(void)
{
    animationFrame_t frame;
    frame.state = MAX_ANIMATION_STATES; // blank
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = SmileTransition6;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = SmileTransition5;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = SmileTransition4;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = SmileTransition3;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = SmileTransition2;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = SmileTransition1;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = Smile;
    frame.durationMs = 1000;
    frameQueue.push(&frame);
    frame.state = MAX_ANIMATION_STATES;
    frame.durationMs = 200;
    frameQueue.push(&frame);

    // Kick off animation
    nextFrameTime = millis();
}

void LedMatrixAnimator::DoAlienDance(void)
{
    animationFrame_t frame;
    frame.state = Alien1;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = Alien2;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = Alien1;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = Alien2;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = Alien1;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = Alien2;
    frame.durationMs = 200;
    frameQueue.push(&frame);
    frame.state = MAX_ANIMATION_STATES;
    frame.durationMs = 200;
    frameQueue.push(&frame);

    // Kick off animation
    nextFrameTime = millis();
}

void LedMatrixAnimator::Update(void)
{
    if (millis() > nextFrameTime)
    {
        // Move to next frame
        if (!frameQueue.isEmpty()) 
        {
            animationFrame_t frame;
            frameQueue.pop(&frame);

            currentState = frame.state;
            nextFrameTime += frame.durationMs;

            // Serial.print("currentState=");
            // Serial.print(currentState);
            // Serial.print(", dur=");
            // Serial.println(nextFrameTime);
        }
    }
}

uint8_t * LedMatrixAnimator::GetFrameBuffer(void)
{
    switch (currentState)
    {
        case Heart:
            return (uint8_t *)&heartPattern;
        case SmallHeart:
            return (uint8_t *)&smallHeartPattern;
        case EyeLeft:
            return (uint8_t *)&eyePosL;
        case EyeLeftDown:
            return (uint8_t *)&eyePosLD;
        case EyeLeftDown2:
            return (uint8_t *)&eyePosLD2;
        case EyeDown:
            return (uint8_t *)&eyePosD;
        case SmallEyeLeft:
            return (uint8_t *)&eyePosLsmall;
        case SmallEyeLeftDown:
            return (uint8_t *)&eyePosLDsmall;
        case SmallEyeDown:
            return (uint8_t *)&eyePosDsmall;
        case EyeBlink1:
            return (uint8_t *)&eyeBlink1;
        case EyeBlink2:
            return (uint8_t *)&eyeBlink2;
        case EyeBlink3:
            return (uint8_t *)&eyeBlink3;
        case EyeBlink4:
            return (uint8_t *)&eyeBlink4;
        case EyeBlink5:
            return (uint8_t *)&eyeBlink5;
        case EyeBlink6:
            return (uint8_t *)&eyeBlink6;
        case Smile:
            return (uint8_t *)&smilePattern;
        case SmileTransition1:
            return (uint8_t *)&smileTransition1;
        case SmileTransition2:
            return (uint8_t *)&smileTransition2;
        case SmileTransition3:
            return (uint8_t *)&smileTransition3;
        case SmileTransition4:
            return (uint8_t *)&smileTransition4;
        case SmileTransition5:
            return (uint8_t *)&smileTransition5;
        case SmileTransition6:
            return (uint8_t *)&smileTransition6;
        case Alien1:
            return (uint8_t *)&alienPattern1;
        case Alien2:
            return (uint8_t *)&alienPattern2;
        case MAX_ANIMATION_STATES:
        default:
            return (uint8_t *)&offFrame;
    }
}
uint8_t LedMatrixAnimator::GetFrameBufferLen(void)
{
    return NUM_PATTERN_LINES;
}
