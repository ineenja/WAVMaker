#include "common.h"

#ifndef NOISE_H
#define NOISE_H

class Noise
{
public:

    Noise(int samplesN, float disp);

    float* noise = nullptr;
    int len = 0;
    float dispersion = 0.0;

    void generateNoise();
};

#endif
