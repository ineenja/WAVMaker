#include "common.h"

#ifndef SIGNAL_H
#define SIGNAL_H

#define TWOPI 6.28318530718
#define DISC_FREQ 44100

class Signal
{
public:
    Signal(float freq, float ampl, float duration, float startingTime, int sampleRate);
    float* samplesFloat32 = nullptr;

    int getSampleNumber();
    float getFreq();
    float getAmpl();
    int getStartingSample();

    void destructSamplesFloat32();

private:
    unsigned int sampleNumber;
    float freq;
    float ampl;
    int startingSample;
};

#endif // SIGNAL_H
