#include "common.h"

#ifndef OPERATIONS_H
#define OPERATIONS_H


class Operations
{
public:
    Operations(unsigned int len);

    unsigned int len;

    void addNoise(const float* noise, float* signal);

    void floatSigToShort(const float* signal, short int* signalShort);
};

#endif // OPERATIONS_H
