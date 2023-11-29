#include <iostream>
#include <binauralplayer/binauralplayer.h>
#include <binauralplayer/PluginProcessor.h>
#include "ambi_roomsim.h"
#include <assert.h>


#define NUM_CHANNELS 2
#define SAMPLE_RATE 24000
#define BLOCK_SIZE 512
//#define MAX_NUM_CHANNELS 16

#define SOURCEX_0 5
#define SOURCEY_0 6
#define SOURCEZ_0 7

#define RECEIVERX_0 53
#define RECEIVERY_0 54
#define RECEIVERZ_0 55

int main(int argc, char *argv[]) {
    std::string outputPath = "output.wav";

    if (argc < 3) {
		printf("Invalid arguments\nUse ./binauralplayer <input file> <framerate>\n");
		return 1;
	}

    const char *inputPath = argv[1];

    TinyWav twReader;
    tinywav_open_read(&twReader, inputPath, TW_INLINE);

	//const int blockSize = sampleRate/atoi(argv[3]);
    const int sampleRate = twReader.h.SampleRate;
	const int nchannels = twReader.numChannels;
    int totalNumSamples = twReader.numFramesInHeader;
    const int order = sqrt(nchannels)-1;
	//const int blockSize = BLOCK_SIZE;
    const int blockSize =sampleRate/atoi(argv[2]);
/*
     if (twReader.numChannels != NUM_CHANNELS || twReader.h.SampleRate != SAMPLE_RATE) {
        std::cout << "Supplied test wav has wrong format - should be [" << NUM_CHANNELS <<"]channels, fs=[" << SAMPLE_RATE<<"]" <<std::endl;
        return -1;
    }
*/
	
    int numReceivers= 2;
	
    void* hAmbi;
    ambi_roomsim_create(&hAmbi);
    ambi_roomsim_init(hAmbi, sampleRate);
    ambi_roomsim_setChOrder (hAmbi, CH_ACN );               //Available Ambisonic channel ordering conventions.
    ambi_roomsim_setMaxReflectionOrder(hAmbi, 3); 
    ambi_roomsim_setOutputOrder(hAmbi, SH_ORDER_FIRST );
    ambi_roomsim_setNormType(hAmbi, NORM_N3D);              //sets the Ambisonic normalisation convention to encode with (see NORM_TYPES enum)
    ambi_roomsim_setNumReceivers(hAmbi, numReceivers);      //Sets the number of input SH receivers. 
    ambi_roomsim_setNumSources(hAmbi, nchannels);           //Sets the number of input signals/sources to encode. 
    
    ambi_roomsim_setSourceX(hAmbi, 0, 3.0f);                //Sets the 'x' coordinate for a specific source index. 
    ambi_roomsim_setSourceY(hAmbi, 0, 3.0f);
    ambi_roomsim_setSourceZ(hAmbi, 0, 1.7f);
    ambi_roomsim_setSourceX(hAmbi, 1, 3.0f);                //Sets the 'x' coordinate for a specific source index. 
    ambi_roomsim_setSourceY(hAmbi, 1, 2.5f);
    ambi_roomsim_setSourceZ(hAmbi, 1, 1.7f);
    
    ambi_roomsim_setReceiverX(hAmbi, 0, 0.2f);              //Sets the 'x' coordinate for a specific receiver index. 
    ambi_roomsim_setReceiverY(hAmbi, 0, 0.2f);
	ambi_roomsim_setReceiverZ(hAmbi, 0, 1.7f);
    ambi_roomsim_setReceiverX(hAmbi, 1, 0.2f);              //Sets the 'x' coordinate for a specific receiver index. 
    ambi_roomsim_setReceiverY(hAmbi, 1, 0.4f);
	ambi_roomsim_setReceiverZ(hAmbi, 1, 1.7f);

    ambi_roomsim_setRoomDimX(hAmbi, 4.0f);
    ambi_roomsim_setRoomDimY(hAmbi, 4.0f);
    ambi_roomsim_setRoomDimZ(hAmbi, 2.5f);

    ambi_roomsim_setWallAbsCoeff(hAmbi, 0, 0, 0.2f);
    
    TinyWav twWriter;
    tinywav_open_write(&twWriter, nchannels, sampleRate, TW_FLOAT32, TW_INLINE, outputPath.c_str());

    
    int samplesProcessed = 0;
    
    while (samplesProcessed < totalNumSamples) {
        float buffer[nchannels * blockSize];
		int samplesRead = tinywav_read_f(&twReader, buffer, blockSize);
		assert(samplesRead > 0 && " Could not read from file!");

        float* pFrameData[MAX_NUM_CHANNELS];
        int frameSize = ambi_roomsim_getFrameSize();
        
        pFrameData[0] = &buffer[0];
        pFrameData[1] = &buffer[blockSize];
        ambi_roomsim_process(hAmbi, pFrameData, pFrameData, nchannels, numReceivers, frameSize);    
        
        int samplesWritten = tinywav_write_f(&twWriter, buffer, samplesRead);
        assert(samplesWritten > 0 && "Could not write to file!");
        samplesProcessed += samplesRead * NUM_CHANNELS;
    }
    tinywav_close_read(&twReader);
    tinywav_close_write(&twWriter);
    
    return 0;
}

