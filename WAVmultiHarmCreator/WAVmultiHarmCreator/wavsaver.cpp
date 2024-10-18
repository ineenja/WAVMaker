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

WavSaver::WavSaver(short* data, int sampleNumber, int sampleRate, float fileDuration)
{
    sigToSave = new short[sampleNumber * sizeof(short int)];
    memcpy(sigToSave, data, sampleNumber * sizeof(short int));
    this->sampleNumber = sampleNumber;
    this->sampleRate = sampleRate;
    this->fileDuration = fileDuration;
}

void WavSaver::save()
{
    WavHeader MyWavHeader;
    MyWavHeader.sampleRate = this->sampleRate;
    MyWavHeader.byteRate = this->sampleRate * (sizeof(short int));
    MyWavHeader.chunkSize = (sizeof(short int) * (uint32_t)(sampleNumber) + WAV_HEADER_SIZE - sizeof(MyWavHeader.chunkId) - sizeof(MyWavHeader.chunkSize));
    MyWavHeader.subchunk2Size = (sizeof(short int) * (uint32_t)sampleNumber);

    std::fstream fs;
    fs.open("1.wav");

    fs.write((char*)(&MyWavHeader), sizeof(WavHeader));
    fs.write((char*)(sigToSave), sizeof(short int)*sampleNumber);

    fs.close();
}

void WavSaver::destructSigToSave()
{
    delete [] sigToSave;
}
