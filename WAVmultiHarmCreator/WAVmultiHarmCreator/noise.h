#include "common.h"

#ifndef NOISE_H
#define NOISE_H

class Noise
{
public:

    Noise(int sampleNumber, float dispersion, float startingTime, int sampleRate);

    float* noise = nullptr;
    unsigned int sampleNumber = 0;
    float dispersion = 0.0;
    unsigned int startingSample = 0.0;

    void generateNoise();

    void destructNoise();
};

#endif
