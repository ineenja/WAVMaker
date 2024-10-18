#include "operations.h"
#include "filereader.h"
#include "noise.h"

Operations::Operations(float fileDuration, int sampleRate)
{
    sampleNumber = fileReader::DurationToSamplesNumber(fileDuration, sampleRate);
    this->sampleRate = sampleRate;
    this->fileDuration = fileDuration;

    completeSignalFloat = new float[sampleNumber*sizeof(float)];
    completeSignalFloat[0] = 0;

    completeSignalShort = new short[sampleNumber*sizeof(short)];
    completeSignalShort[0] = 0;
}

void Operations::floatSigToShort(const float *signalFloat, short int* signalShort)
{
    float maxAmpl = 0.0;
    for(unsigned int i = 0; i < sampleNumber; i++)
    {
        if(signalFloat[i] > maxAmpl)
        {
            maxAmpl = signalFloat[i];
        }
    }

    float m = __SHRT_MAX__ / maxAmpl;

    for(unsigned int i = 0; i < sampleNumber; i++)
    {
        signalShort[i] = static_cast<short int>(round(signalFloat[i] * m));
    }
}

void Operations::completeSignalMaker(std::vector<Signal>&vectorOfHarms, float* noise, int NoiseStartingSample, float* completeSignalFloat){

    for(unsigned int i = 0; i < sampleNumber; i++){
        completeSignalFloat[i] = 0;
    }

    for(size_t i = 0; i < vectorOfHarms.size(); i++){
        for(int j = 0; j < vectorOfHarms[i].getSampleNumber(); j++){
            if (sampleNumber >= j + vectorOfHarms[i].getStartingSample()){ //проверка на нахождение внутри массива полного сигнала
                completeSignalFloat[j + vectorOfHarms[i].getStartingSample()] += vectorOfHarms[i].samplesFloat32[j];
            }
        }
    }
    for(int i = 0; i < 1; i++){
        if (sampleNumber >= i + NoiseStartingSample){ //проверка на нахождение внутри массива полного сигнала
            completeSignalFloat[i + NoiseStartingSample] += noise[i];
        }
    }
}

void Operations::destructCompleteSignalFloat(){
    delete [] completeSignalFloat;
}

void Operations::destructCompleteSignalShort(){
    delete [] completeSignalShort;
}



