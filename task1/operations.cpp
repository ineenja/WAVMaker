#include "operations.h"

Operations::Operations(unsigned int len)
{
    this->len = len;
}

void Operations::addNoise(const float *noise, float *signal)
{
        if((signal != nullptr) && (noise != nullptr))
        {
            for(unsigned int i = 0; i < len; i++)
            {
                signal[i] += noise[i];
            }
        }
}

void Operations::floatSigToShort(const float *signalFloat, short int* signalShort)
{
    float maxAmpl = 0.0;
    for(unsigned int i = 0; i < len; i++)
    {
        if(signalFloat[i] > maxAmpl)
        {
            maxAmpl = signalFloat[i];
        }
    }

    float m = __SHRT_MAX__ / maxAmpl;

    for(unsigned int i = 0; i < len; i++)
    {
        signalShort[i] = static_cast<short int>(round(signalFloat[i] * m));
    }
}
