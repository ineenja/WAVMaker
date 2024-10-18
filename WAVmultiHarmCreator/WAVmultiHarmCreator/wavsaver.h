#include "common.h"
#include "signal.h"
#include "filereader.h"

#ifndef WAVSAVER_H
#define WAVSAVER_H

#define WAV_HEADER_SIZE 44

uint16_t reverseBytes16U(uint16_t n);
uint32_t reverseBytes32U(uint32_t n);
float reverseBytes32F(float n);

#pragma pack(push, 1)
typedef struct
{
    uint32_t chunkId = reverseBytes32U(0x52494646);
    uint32_t chunkSize;
    uint32_t format = reverseBytes32U(0x57415645);
    uint32_t subchunk1Id = reverseBytes32U(0x666d7420);
    uint32_t subchunk1Size = (16);
    uint16_t audioFormat = (1);
    uint16_t numChannels = (1);
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign = (sizeof(short int));
    uint16_t bitsPerSample = (8 * (sizeof(short int)));
    uint32_t subchunk2Id = reverseBytes32U(0x64617461);
    uint32_t subchunk2Size = 0;
}   WavHeader;
#pragma pack(pop)

class WavSaver
{
public:
    WavSaver(short int* data, int sampleNumber, int sampleRate, float fileDuration);
    short int* sigToSave = nullptr;
    uint32_t sampleNumber;
    int sampleRate;
    float fileDuration;

    void save();

    void destructSigToSave();
};

#endif // WAVSAVER_H
