#include "common.h"

#ifndef SIGNAL_H
#define SIGNAL_H

#define TWOPI 6.28318530718
#define DISC_FREQ 44100

class Signal
{
public:
    Signal(float freq, float ampl, float t);
    float* samplesFloat32 = nullptr;
    short int* samplesShort = nullptr;

    int getLen();
    float getFreq();
    float getAmpl();

    void destructSamplesFloat32();

    void destructSamplesShort();

private:
    unsigned int len;
    float freq;
    float ampl;
};

#endif // SIGNAL_H
