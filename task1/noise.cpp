#include "noise.h"

Noise::Noise(int samplesN, float disp)
{
    len = samplesN;
    dispersion = disp;
    noise = new float[samplesN * sizeof(float)];
}

void Noise::generateNoise()
{
    float upperValue = sqrtf(dispersion * 12.0) / 2.0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(-upperValue, upperValue);

    for(unsigned int i = 0; i < len; i++)
    {
        float temp = 0;
        for (unsigned int j = 0; j < 100; j++)
        {
            temp += (float)distrib(gen);
        }
        noise[i] = temp / 100.0;
    }
}

void Noise::destructNoise()
{
    delete [] noise;
}
