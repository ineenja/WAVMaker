#include "noise.h"

Noise::Noise(int samplesN, float disp)
{
    this->len = samplesN;
    this->dispersion = disp;
    this->noise = (float*)malloc(samplesN * sizeof(float));
}

void Noise::generateNoise()
{
    float upperU = sqrtf(this->dispersion / 12.0);
    srand(time(0));
    if(this->len != 0)
    {
        for(int i = 0; i < this->len; i++)
        {
            this->noise[i] = ( ((float)rand() / (float)RAND_MAX) - 0.5 ) * 2 * upperU;
        }
    }
    else
    {
        std::cout << "Noise array empty!\n";
    }
}
