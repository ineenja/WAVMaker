#include "signal.h"
#include "noise.h"
#include "wavsaver.h"

int main()
{
    class Signal sig = Signal(300.0, 100.0, TIME);
    class Noise noise = Noise(sig.getLen(), 10.0);

    noise.generateNoise();
    sig.addNoise(noise.noise, noise.len);

    sig.floatSigToShort();
    WavSaver saver = WavSaver(sig.samplesShort, sig.getLen());
    saver.save();
    return 0;
}
