#include <iostream>
#include <binauralplayer/binauralplayer.h>
#include <binauralplayer/PluginProcessor.h>
#include "ambi_roomsim.h"
#include <assert.h>


#define NUM_CHANNELS 2
#define SAMPLE_RATE 24000
#define BLOCK_SIZE 512
#define MAX_NUM_CHANNELS 2

#define SOURCEX_0 5
#define SOURCEY_0 6
#define SOURCEZ_0 7

#define RECEIVERX_0 53
#define RECEIVERY_0 54
#define RECEIVERZ_0 55

int main(int argc, char *argv[]) {
    char* outputPath = "output.wav";

    if (argc < 3) {
		printf("Invalid arguments\nUse ./binauralplayer <input file> <framerate>");
		return 1;
	}

    const char *inputPath = argv[1];

    TinyWav twReader;
    tinywav_open_read(&twReader, inputPath, TW_INLINE);

	//const int blockSize = sampleRate/atoi(argv[3]);
    const int sampleRate = twReader.h.SampleRate;
	const int nchannels = twReader.numChannels;
	const int order = sqrt(nchannels)-1;
	const int blockSize = sampleRate/atoi(argv[3]);
	
    void* hAmbi;
    ambi_roomsim_create(&hAmbi);
    ambi_roomsim_init(hAmbi, sampleRate);
    ambi_roomsim_setOutputOrder(hAmbi, SH_ORDER_FIRST );
    ambi_roomsim_setNumSources(hAmbi,1);                    //Sets the number of input signals/sources to encode. 
    ambi_roomsim_setSourceX(hAmbi, 0, 1.0f);                //Sets the 'x' coordinate for a specific source index. 
    ambi_roomsim_setSourceY(hAmbi, 0, 0.5f);
    ambi_roomsim_setSourceZ(hAmbi, 0, 1.7f);
    ambi_roomsim_setNumReceivers(hAmbi, 2);                 //Sets the number of input SH receivers. 
    ambi_roomsim_setReceiverX(hAmbi, 0, 0.2f);              //Sets the 'x' coordinate for a specific receiver index. 
    ambi_roomsim_setReceiverY(hAmbi, 0, 0.08f);
	ambi_roomsim_setReceiverZ(hAmbi, 0, 1.7f);

    ambi_roomsim_setReceiverX(hAmbi, 1, 0.2f);              //Sets the 'x' coordinate for a specific receiver index. 
    ambi_roomsim_setReceiverY(hAmbi, 1, -0.08f);
	ambi_roomsim_setReceiverZ(hAmbi, 1, 1.7f);

    ambi_roomsim_setRoomDimX(hAmbi, 4.0f);
    ambi_roomsim_setRoomDimY(hAmbi, 4.0f);
    ambi_roomsim_setRoomDimZ(hAmbi, 2.5f);
/**//
    ambi_roomsim_setWallAbsCoeff(hAmbi, 0, 0, 0.2f);
    ambi_roomsim_setChOrder (hAmbi, CH_ACN );               //Available Ambisonic channel ordering conventions.
    	ambi_roomsim_setNormType (void *const hAmbi, int newType)
 	//sets the Ambisonic normalisation convention to encode with (see NORM_TYPES enum)



Sets the 'x' coordinate for a specific receiver index. 

    if (twReader.numChannels != NUM_CHANNELS || twReader.h.SampleRate != SAMPLE_RATE) {
        std::cout << "Supplied test wav has wrong format - should be [" << NUM_CHANNELS <<"]channels, fs=[" << SAMPLE_RATE<<"]" <<std::endl;
        return -1;
    }

    void* safBP;

    TinyWav twWriter;
    tinywav_open_write(&twWriter, NUM_CHANNELS, SAMPLE_RATE, TW_FLOAT32, TW_INLINE, outputPath);

    int totalNumSamples = twReader.numFramesInHeader;
    int samplesProcessed = 0;

    //void* hAmbi;          /* ambi_roomsim handle */
    int nNumInputs;       /* current number of input channels */
    int nNumOutputs;      /* current number of output channels */
    //int nSampleRate;      /* current host sample rate */
    //int nHostBlockSize;   /* typical host block size to expect, in samples */
    //float* pFrameData[MAX_NUM_CHANNELS];
    //int frameSize = ambi_roomsim_getFrameSize();

    PluginProcessor pp;

//    return 0;

    pp.setParameter(k_numReceivers, 2.0f);
    pp.setParameter(k_channelOrder,2.0f);
    pp.setParameter(k_outputOrder,2.0f);
    pp.setParameter(k_numSources, 2.0f);
    pp.setParameter(SOURCEX_0 , 0.0f);
    pp.setParameter(SOURCEY_0 , 0.0f);
    pp.setParameter(SOURCEZ_0 , 1.7f);
    
    pp.setParameter(RECEIVERX_0, 1.5f);
    pp.setParameter(RECEIVERY_0, 0.5f);
    pp.setParameter(RECEIVERZ_0, 1.7f);

    pp.prepareToPlay(sampleRate, blockSize);

    for (int i=0; i<(ROOM_SIM_MAX_NUM_SOURCES*3)+(ROOM_SIM_MAX_NUM_RECEIVERS*3)+k_NumOfParameters;i++){
        std::string name = pp.getParameterName(i);
        float value = pp.getParameter(i);
        std::cout << i << ", "<< name << ": "<< value <<std::endl;
        if (i ==SOURCEZ_0)
            i = RECEIVERX_0-1;
        if (i ==RECEIVERZ_0)
            break;
    }

    std::cout << NUM_CHANNELS * BLOCK_SIZE << std::endl;

    while (samplesProcessed < totalNumSamples) {
        /* standard parameters */
  //      (float)(ambi_roomsim_getOutputOrder(hAmbi)-1)/(float)(MAX_SH_ORDER-1);

        float buffer[NUM_CHANNELS * BLOCK_SIZE];

        //float buffer[nchannels * blockSize];
		/*float* buffer[nchannels];
		for (int i = 0; i < nchannels; i++) {
			buffer[i] = samples + i*blockSize;
		}*/
    
        int samplesRead = tinywav_read_f(&twReader, buffer, blockSize);
        assert(samplesRead > 0 && " Could not read from file!");
        //powermap_analysis(hPm, data, channels, blockSize, 1);
        pp.processBlock(buffer, samplesRead, nchannels, blockSize);
        //ambi_roomsim_process(hAmbi, pFrameData, pFrameData, nNumInputs, nNumOutputs, frameSize);
    
        int samplesWritten = tinywav_write_f(&twWriter, buffer, samplesRead);
        assert(samplesWritten > 0 && "Could not write to file!");

        samplesProcessed += samplesRead * NUM_CHANNELS;
    }

    tinywav_close_read(&twReader);
    tinywav_close_write(&twWriter);
    pp.releaseResources();
    return 0;
}

