#include <iostream>
#include <binauralplayer/binauralplayer.h>
#include <binauralplayer/PluginProcessor.h>
#include "ambi_roomsim.h"
#include <assert.h>


#define NUM_CHANNELS 1
#define SAMPLE_RATE 48000
#define BLOCK_SIZE 512
#define MAX_NUM_CHANNELS 2

int main(int argc, char *argv[]) {
    char* outputPath = "output.wav";

    if (argc < 2) return -1;
    const char *inputPath = argv[1];

    TinyWav tw;
    tinywav_open_read(&tw, inputPath, TW_INLINE);
    const int sampleRate = tw.h.SampleRate;
	const int channels = tw.numChannels;
	const int order = sqrt(channels)-1;
	const int blockSize = BLOCK_SIZE; //sampleRate/atoi(argv[3]);
	

    if (tw.numChannels != NUM_CHANNELS || tw.h.SampleRate != SAMPLE_RATE) {
        std::cout << "Supplied test wav has wrong format - should be [" << NUM_CHANNELS <<"]channels, fs=[" << SAMPLE_RATE<<"]" <<std::endl;
        return -1;
    }

    void* safBP;

    TinyWav twWriter;
    tinywav_open_write(&twWriter, NUM_CHANNELS, SAMPLE_RATE, TW_FLOAT32, TW_INLINE, outputPath);

    int totalNumSamples = tw.numFramesInHeader;
    int samplesProcessed = 0;

    void* hAmbi;          /* ambi_roomsim handle */
    int nNumInputs;       /* current number of input channels */
    int nNumOutputs;      /* current number of output channels */
    int nSampleRate;      /* current host sample rate */
    int nHostBlockSize;   /* typical host block size to expect, in samples */
    float* pFrameData[MAX_NUM_CHANNELS];
    int frameSize = ambi_roomsim_getFrameSize();

    PluginProcessor pp;

    std::cout << k_NumOfParameters << std::endl;
//    return 0;

    pp.setParameter(k_numReceivers, 1.0f);
    pp.setParameter(k_numSources, 1.0f);

    while (samplesProcessed < totalNumSamples) {
        /* standard parameters */
  //      (float)(ambi_roomsim_getOutputOrder(hAmbi)-1)/(float)(MAX_SH_ORDER-1);
        /* source position parameters */

        /* Receiver position parameters */


    //    ambi_roomsim_process(hAmbi, pFrameData, pFrameData, nNumInputs, nNumOutputs, frameSize);

        float buffer[NUM_CHANNELS * BLOCK_SIZE];
    
        int samplesRead = tinywav_read_f(&tw, buffer, BLOCK_SIZE);
        assert(samplesRead > 0 && " Could not read from file!");
    
        int samplesWritten = tinywav_write_f(&twWriter, buffer, samplesRead);
        assert(samplesWritten > 0 && "Could not write to file!");

        samplesProcessed += samplesRead * NUM_CHANNELS;
    }

    tinywav_close_read(&tw);
    tinywav_close_write(&twWriter);

    return 0;
}

