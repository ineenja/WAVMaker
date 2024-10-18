#include "filereader.h"

fileReader::fileReader()
{
    std::fstream fs;
    fs.open("info.txt");

    if (fs.is_open()){

        std::string s;
        unsigned int i = 0;

        while(std::getline(fs, s))
        {
            fileStrings.push_back(s);
            i++;
        }

        fileLength = i;
    }

    fs.close();
}

void fileReader::getInformation(){

    wavDuration = std::stof(fileStrings[0]);
    sampleRate = std::stoi(fileStrings[1]);


    for (unsigned int i = 2; i < fileLength; i++){
        if (fileStrings[i] == "harm"){
            harmDuration = std::stof(fileStrings[i+1]);
            harmAmpl = std::stof(fileStrings[i+2]);
            harmStartingTime = std::stof(fileStrings[i+3]);
            harmFreq = std::stof(fileStrings[i+4]);

            i += 4;
            vectorOfHarms.push_back(Signal(harmFreq, harmAmpl, harmDuration, harmStartingTime, sampleRate));
        }

        if (fileStrings[i] == "noise"){
            dispersion = std::stof(fileStrings[i+1]);
            noiseSampleNumber = fileReader::DurationToSamplesNumber((std::stof(fileStrings[i+2])), sampleRate);
            noiseStartingTime = std::stof(fileStrings[i+3]);

            i += 3;

        }
    }
}

int fileReader::DurationToSamplesNumber(const float Duration, const int sampleRate){
    return (int)(Duration * sampleRate);
}


int fileReader::StartingTimeToStartingSample(const float StartingTime, const int sampleRate){
    return (int)(StartingTime * sampleRate);
}





