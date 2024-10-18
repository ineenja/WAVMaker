#include "common.h"
#include "signal.h"
#include "noise.h"

#ifndef FILEREADER_H
#define FILEREADER_H


class fileReader
{
public:
    fileReader();

    std::vector<std::string> fileStrings;

    std::vector<Signal> vectorOfHarms;

    unsigned int fileLength;

    //wav file properties
    float wavDuration;
    int sampleRate;
    int lengthInSamples;

    //harmonic signal properties
    float harmDuration;
    float harmAmpl;
    float harmStartingTime;
    float harmFreq;

    //noise properties
    float dispersion;
    int noiseSampleNumber;
    float noiseStartingTime;

    void getInformation();

    static int DurationToSamplesNumber(const float Duration, const int sampleRate);

    static int StartingTimeToStartingSample(const float StartingTime, const int sampleRate);

};

#endif // FILEREADER_H
