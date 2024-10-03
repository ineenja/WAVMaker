#include "signal.h"

Signal::Signal(float freq, float ampl, float t)
{
    this->len = CALC_SAMPLES_N(t);
    this->ampl = ampl;
    this->freq = freq;
    this->samplesFloat32 = (float*)malloc(len * sizeof(float));
    samplesFloat32[0] = 0;
    for(int i = 1; i < len; i++)
    {
        samplesFloat32[i] = ampl * sinf(TWOPI * freq * i / DISC_FREQ);
    }
}

int Signal::getLen()
{
    return this->len;
}

float Signal::getFreq()
{
    return this->freq;
}

float Signal::getAmpl()
{
    return this->ampl;
}

void Signal::addNoise(float *noise, int len)
{
    if(len != this->len)
    {
        std::cout << "Num of noise samples NOT equal to sigLen!\n";
    }
    else
    {
        if((this->samplesFloat32 != nullptr) && (noise != nullptr)) // float* samples;
        {
            for(int i = 0; i < len; i++)
            {
                this->samplesFloat32[i] += noise[i];
            }
        }
        else
        {
            std::cout << "Data or noise array is empty!\n";
        }
    }
}

void Signal::floatSigToShort()
{
    if(this->samplesFloat32 != nullptr)
    {
        float maxAmpl = 0.0;
        for(int i = 0; i < this->len; i++)
        {
            if(samplesFloat32[i] > maxAmpl)
            {
                maxAmpl = samplesFloat32[i];
            }
        }
        this->samplesShort = (short int*)malloc(this->len * sizeof(short int));
        for(int i = 0; i < this->len; i++)
        {
            samplesShort[i] = (short int)(samplesFloat32[i] * __SHRT_MAX__ / maxAmpl);
        }
    }
    else
    {
        std::cout << "No data!\n";
    }
}

































