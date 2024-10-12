#include "common.h"
#include "signal.h"

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
    uint32_t chunkSize = (sizeof(short int) * (uint32_t)(CALC_SAMPLES_N(TIME)) + WAV_HEADER_SIZE - sizeof(chunkId) - sizeof(chunkSize));
    uint32_t format = reverseBytes32U(0x57415645);
    uint32_t subchunk1Id = reverseBytes32U(0x666d7420);
    uint32_t subchunk1Size = (16);
    uint16_t audioFormat = (1);
    uint16_t numChannels = (1);
    uint32_t sampleRate = (DISC_FREQ);
    uint32_t byteRate = (DISC_FREQ * (sizeof(short int)));
    uint16_t blockAlign = (sizeof(short int));
    uint16_t bitsPerSample = (8 * (sizeof(short int)));
    uint32_t subchunk2Id = reverseBytes32U(0x64617461);
    uint32_t subchunk2Size = (sizeof(short int) * (CALC_SAMPLES_N(TIME)));
}   WavHeader;
#pragma pack(pop)

class WavSaver
{
public:
    WavSaver(short int* data, int len);
    short int* sigToSave = nullptr;
    uint32_t len;
    void save();

    void destructSigToSave();
};

#endif // WAVSAVER_H
