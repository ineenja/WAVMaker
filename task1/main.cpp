#include "signal.h"
#include "noise.h"
#include "wavsaver.h"
#include "operations.h"

int main()
{
    class Signal sig = Signal(300.0, 100.0, TIME);
    class Noise noise = Noise(sig.getLen(), 0.0);

    noise.generateNoise();

    class Operations sigOper = Operations(sig.getLen());

    sigOper.addNoise(noise.noise, sig.samplesFloat32);

    noise.destructNoise();

    sigOper.floatSigToShort(sig.samplesFloat32, sig.samplesShort);

    sig.destructSamplesFloat32();

    WavSaver saver = WavSaver(sig.samplesShort, sig.getLen());
    saver.save();

    sig.destructSamplesShort();

    return 0;
}
