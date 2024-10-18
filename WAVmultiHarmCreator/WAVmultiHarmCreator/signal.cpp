#include "signal.h"
#include "filereader.h"

Signal::Signal(float freq, float ampl, float duration, float startingTime, int sampleRate)
{
    sampleNumber = fileReader::DurationToSamplesNumber(duration, sampleRate);
    startingSample = fileReader::StartingTimeToStartingSample(startingTime, sampleRate);
    this->ampl = ampl;
    this->freq = freq;
    samplesFloat32 = new float[sampleNumber*sizeof(float)];
    samplesFloat32[0] = 0;

    float coef = TWOPI * freq / sampleRate;
    for(unsigned int i = 0; i < sampleNumber; i++)
    {
        samplesFloat32[i] = ampl * sin(coef * i);
    }
}

int Signal::getSampleNumber()
{
    return sampleNumber;
}

float Signal::getFreq()
{
    return freq;
}

float Signal::getAmpl()
{
    return ampl;
}

int Signal::getStartingSample()
{
    return startingSample;
}

void Signal::destructSamplesFloat32()
{
    delete [] samplesFloat32;
}



































