#include "common.h"

#ifndef SIGNAL_H
#define SIGNAL_H

#define TWOPI 6.28
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

    void addNoise(float* noise, int len);
    void floatSigToShort();

private:
    int len;
    float freq;
    float ampl;
};

#endif // SIGNAL_H
