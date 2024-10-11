#ifndef LED_PATERNS_H_
#define LED_PATERNS_H_

#define NUM_PATTERN_LINES   (8)

const unsigned char smilePattern[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b01100110,
    0b01100110,
    0b00000000,
    0b10011001,
    0b10011001,
    0b01000010,
    0b00111100
};

const unsigned char smileTransition1[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00000000,
    0b01100110,
    0b01100110,
    0b00000000,
    0b10011001,
    0b10011001,
    0b01000010
};

const unsigned char smileTransition2[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00000000,
    0b00000000,
    0b01100110,
    0b01100110,
    0b00000000,
    0b10011001,
    0b10011001
};

const unsigned char smileTransition3[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b01100110,
    0b01100110,
    0b00000000,
    0b10011001
};

const unsigned char smileTransition4[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b01100110,
    0b01100110,
    0b00000000
};

const unsigned char smileTransition5[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b01100110,
    0b01100110
};

const unsigned char smileTransition6[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b01100110
};

const unsigned char heartPattern[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b01100110,
    0b11111111,
    0b11111111,
    0b01111110,
    0b00111100,
    0b00011000,
    0b00000000
};

const unsigned char smallHeartPattern[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00000000,
    0b00110100,
    0b01111110,
    0b00111100,
    0b00011000,
    0b00000000,
    0b00000000
};

const unsigned char eyePosR[NUM_PATTERN_LINES] = { 
    0b00111100,
    0b01111110,
    0b11111111,
    0b10011111,
    0b10011111,
    0b11111111,
    0b01111110,
    0b00111100
};

const unsigned char eyePosRD[NUM_PATTERN_LINES] = { 
    0b00111100,
    0b01111110,
    0b11111111,
    0b11111111,
    0b10011111,
    0b10011111,
    0b01111110,
    0b00111100
};

const unsigned char eyePosRD2[NUM_PATTERN_LINES] = { 
    0b00111100,
    0b01111110,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11001111,
    0b01001110,
    0b00111100
};

const unsigned char eyePosD[NUM_PATTERN_LINES] = { 
    0b00111100,
    0b01111110,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11100111,
    0b01100110,
    0b00111100
};

const unsigned char eyePosDsmall[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00111100,
    0b01111110,
    0b01111110,
    0b01100110,
    0b01100110,
    0b00111100,
    0b00000000
};

const unsigned char eyePosL[NUM_PATTERN_LINES] = { 
    0b00111100,
    0b01111110,
    0b11111111,
    0b11111001,
    0b11111001,
    0b11111111,
    0b01111110,
    0b00111100
};

const unsigned char eyePosLsmall[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00111100,
    0b01111110,
    0b01110010,
    0b01110010,
    0b01111110,
    0b00111100,
    0b00000000
};

const unsigned char eyePosLD[NUM_PATTERN_LINES] = { 
    0b00111100,
    0b01111110,
    0b11111111,
    0b11111111,
    0b11111001,
    0b11111001,
    0b01111110,
    0b00111100
};

const unsigned char eyePosLDsmall[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00111100,
    0b01111110,
    0b01111110,
    0b01110010,
    0b01110010,
    0b00111100,
    0b00000000
};

const unsigned char eyePosLD2[NUM_PATTERN_LINES] = { 
    0b00111100,
    0b01111110,
    0b11111111,
    0b11111111,
    0b11111111,
    0b11110011,
    0b01110010,
    0b00111100
};

const unsigned char eyeBlink1[NUM_PATTERN_LINES] = { 
    0b00111100,
    0b01000010,
    0b01000010,
    0b01000010,
    0b01011010,
    0b01011010,
    0b01000010,
    0b00111100
};

const unsigned char eyeBlink2[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00111100,
    0b01000010,
    0b01000010,
    0b01011010,
    0b01011010,
    0b01000010,
    0b00111100
};

const unsigned char eyeBlink3[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00000000,
    0b00111100,
    0b01000010,
    0b01011010,
    0b01011010,
    0b01000010,
    0b00111100
};

const unsigned char eyeBlink4[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00000000,
    0b00000000,
    0b00111100,
    0b01011010,
    0b01011010,
    0b00111100,
    0b00000000
};

const unsigned char eyeBlink5[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00111100,
    0b01011010,
    0b00111100,
    0b00000000
};

const unsigned char eyeBlink6[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b01111110,
    0b00111100,
    0b00000000
};

const unsigned char alienPattern1[NUM_PATTERN_LINES] = {
    0b00000000,
    0b00111100,
    0b01111110,
    0b11011011,
    0b11011011,
    0b01111110,
    0b00100100,
    0b11000011
};

const unsigned char alienPattern2[NUM_PATTERN_LINES] = {
    0b00111100,
    0b01111110,
    0b11011011,
    0b11011011,
    0b01111110,
    0b00100100,
    0b01000010,
    0b01000010
};

const unsigned char offFrame[NUM_PATTERN_LINES] = { 
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
};

#endif
