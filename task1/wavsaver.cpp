#include "wavsaver.h"

uint32_t reverseBytes32U(uint32_t n)
{
    uint32_t temp1 = n >> 24;
    uint32_t temp2 = ((n << 8) >> 24) << 8;
    uint32_t temp3 = ((n << 16) >> 24) << 16;
    uint32_t temp4 = n << 24;
    return (temp4 | temp3 | temp2 | temp1);
}

uint16_t reverseBytes16U(uint16_t n)
{
    uint16_t temp1 = n >> 8;
    uint16_t temp2 = n << 8;
    return (temp2 | temp1);
}

WavSaver::WavSaver(short* data, int len)
{
    sigToSave = new short[len * sizeof(short int)];
    memcpy(sigToSave, data, len * sizeof(short int));
    this->len = len;
}

void WavSaver::save()
{
    WavHeader MyWavHeader;

    std::fstream fs;
    fs.open("1.wav");

    //fs.write(reinterpret_cast<const char*> (&MyWavHeader), sizeof(WavHeader));
    //fs.write(reinterpret_cast<const char*> (sigToSave), sizeof(short int)*len);

    fs.write((char*)(&MyWavHeader), sizeof(WavHeader));
    fs.write((char*)(sigToSave), sizeof(short int)*len);

    for(unsigned int i = 0; i < len; i++)
        {
            std::cout << sigToSave[i] << std::endl;
        }
    fs.close();
}

void WavSaver::destructSigToSave()
{
    delete [] sigToSave;
}
