#include "signal.h"

Signal::Signal(float freq, float ampl, float t)
{
    len = CALC_SAMPLES_N(t);
    this->ampl = ampl;
    this->freq = freq;
    samplesFloat32 = new float[len * sizeof(float)];
    samplesFloat32[0] = 0;

    samplesShort = new short int[len * sizeof(short int)];
    samplesShort[0] = 0;

    float coef = TWOPI * freq / DISC_FREQ;
    for(unsigned int i = 0; i < len; i++)
    {
        samplesFloat32[i] = ampl * sin(coef * i);
    }
}

int Signal::getLen()
{
    return len;
}

float Signal::getFreq()
{
    return freq;
}

float Signal::getAmpl()
{
    return ampl;
}

void Signal::destructSamplesFloat32()
{
    delete [] samplesFloat32;
}

void Signal::destructSamplesShort()
{
    delete [] samplesShort;
}



































