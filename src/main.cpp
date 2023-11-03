#include <iostream>
#include <binauralplayer/binauralplayer.h>
#include <tinywav.h>
#include <assert.h>

#define NUM_CHANNELS 1
#define SAMPLE_RATE 48000
#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {
    char* outputPath = "output.wav";

    if (argc < 2) return -1;
    const char *inputPath = argv[1];

    TinyWav twReader;
    tinywav_open_read(&twReader, inputPath, TW_INLINE);
    if (twReader.numChannels != NUM_CHANNELS || twReader.h.SampleRate != SAMPLE_RATE) {
        std::cout << "Supplied test wav has wrong format - should be [" << NUM_CHANNELS <<"]channels, fs=[" << SAMPLE_RATE<<"]" <<std::endl;
        return -1;
    }

    TinyWav twWriter;
    tinywav_open_write(&twWriter, NUM_CHANNELS, SAMPLE_RATE, TW_FLOAT32, TW_INLINE, outputPath);

    int totalNumSamples = twReader.numFramesInHeader;
    int samplesProcessed = 0;
    while (samplesProcessed < totalNumSamples) {
        float buffer[NUM_CHANNELS * BLOCK_SIZE];
    
        int samplesRead = tinywav_read_f(&twReader, buffer, BLOCK_SIZE);
        assert(samplesRead > 0 && " Could not read from file!");
    
        int samplesWritten = tinywav_write_f(&twWriter, buffer, samplesRead);
        assert(samplesWritten > 0 && "Could not write to file!");

        samplesProcessed += samplesRead * NUM_CHANNELS;
    }

    tinywav_close_read(&twReader);
    tinywav_close_write(&twWriter);

    return 0;
}

