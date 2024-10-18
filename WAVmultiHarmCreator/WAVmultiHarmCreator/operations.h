#include "common.h"
#include "filereader.h"

#ifndef OPERATIONS_H
#define OPERATIONS_H


class Operations
{
public:
    Operations(float fileDuration, int sampleRate);

    float fileDuration;
    int sampleRate;
    unsigned int sampleNumber;

    float* completeSignalFloat = nullptr;
    short int* completeSignalShort = nullptr;

    void floatSigToShort(const float* signal, short int* signalShort);

    void completeSignalMaker(std::vector<Signal>&vectorOfHarms, float* noise, int NoiseStartingSample, float* completeSignalFloat);

    void destructCompleteSignalFloat();

    void destructCompleteSignalShort();
};

#endif // OPERATIONS_H
