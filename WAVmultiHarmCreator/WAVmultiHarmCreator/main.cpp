#include "signal.h"
#include "noise.h"
#include "wavsaver.h"
#include "operations.h"
#include "filereader.h"

int main()
{
    fileReader file = fileReader();

    file.getInformation();

    Noise noise = Noise(file.noiseSampleNumber, file.dispersion, file.noiseStartingTime, file.sampleRate);

    noise.generateNoise();

    Operations sigOper = Operations(file.wavDuration, file.sampleRate);

    sigOper.completeSignalMaker(file.vectorOfHarms, noise.noise, noise.startingSample, sigOper.completeSignalFloat);

    noise.destructNoise();

    for (int i = 0; i < file.vectorOfHarms.size(); i++){
        file.vectorOfHarms[i].destructSamplesFloat32();
    }

    sigOper.floatSigToShort(sigOper.completeSignalFloat, sigOper.completeSignalShort);

    WavSaver saver = WavSaver(sigOper.completeSignalShort, sigOper.sampleNumber, file.sampleRate, file.wavDuration);
    saver.save();

    saver.destructSigToSave();

    return 0;
}
