/*
 ==============================================================================
 
 This file is part of SPARTA; a suite of spatial audio plug-ins.
 Copyright (c) 2018 - Leo McCormack.
 
 SPARTA is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 SPARTA is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with SPARTA.  If not, see <http://www.gnu.org/licenses/>.
 
 ==============================================================================
*/
#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

//#include <JuceHeader.h>
#include "ambi_roomsim.h"

#define CONFIGURATIONHELPER_ENABLE_GENERICLAYOUT_METHODS 1 
//#include "../../resources/ConfigurationHelper.h"
#define BUILD_VER_SUFFIX "alpha" /* String to be added before the version name on the GUI (e.g. beta, alpha etc..) */ 
#ifndef MIN
# define MIN(a,b) (( (a) < (b) ) ? (a) : (b))
#endif
#ifndef MAX
# define MAX(a,b) (( (a) > (b) ) ? (a) : (b))
#endif

/* Parameter tags: for the default VST GUI */
enum {
    k_outputOrder,
    k_channelOrder,
    k_normType,
    k_numSources,
    k_numReceivers,
    
    k_NumOfParameters /* not including source directions */
};

class PluginProcessor  
/*: public AudioProcessor,
                         public VSTCallbackHandler*/
{
public:
    /* Get functions */
    //void* getFXHandle() { return hAmbi; }
    int getCurrentBlockSize(){ return nHostBlockSize; }
    int getCurrentNumInputs(){ return nNumInputs; }
    int getCurrentNumOutputs(){ return nNumOutputs; }
    
    /* For refreshing window during automation */ 
    //void setRefreshWindow(bool newState) { refreshWindow = newState; }
    //bool getRefreshWindow() { return refreshWindow; }
    
    /* VST CanDo */
    //pointer_sized_int handleVstManufacturerSpecific (int32 /*index*/, pointer_sized_int /*value*/, void* /*ptr*/, float /*opt*/) override { return 0; }
    //pointer_sized_int handleVstPluginCanDo (int32 /*index*/, pointer_sized_int /*value*/, void* ptr, float /*opt*/) override{
    //    auto text = (const char*) ptr;
    //    auto matches = [=](const char* s) { return strcmp (text, s) == 0; };
    //    if (matches ("wantsChannelCountNotifications"))
    //        return 1;
    //    return 0;
    //}
    
private:
    void* hAmbi;          /* ambi_roomsim handle */
    int nNumInputs;       /* current number of input channels */
    int nNumOutputs;      /* current number of output channels */
    int nSampleRate;      /* current host sample rate */
    int nHostBlockSize;   /* typical host block size to expect, in samples */
    bool refreshWindow;
    
    /***************************************************************************\
                                    JUCE Functions
    \***************************************************************************/
public:
    PluginProcessor();
    ~PluginProcessor();

    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();
    void processBlock (float& buffer);
    //AudioProcessorEditor* createEditor();
    //bool hasEditor();
    //const std::string getName() ;
    int getNumParameters() ;
    float getParameter (int index) ;
    void setParameter (int index, float newValue) ;
    //const std::string getParameterName (int index) ;
    //const std::string getParameterText (int index) ;
    //const std::string getInputChannelName (int channelIndex)  ;
    //const std::string getOutputChannelName (int channelIndex)  ;
    //bool acceptsMidi() ;
    //bool producesMidi() ;
    bool silenceInProducesSilenceOut();
    //double getTailLengthSeconds() ;
    int getNumPrograms() ;
    int getCurrentProgram() ;
    void setCurrentProgram(int index) ;
    //const std::string getProgramName(int index) ;
    bool isInputChannelStereoPair (int index)  ;
    bool isOutputChannelStereoPair(int index)  ;
    //void changeProgramName(int index, const std::string& newName) ;
    //void getStateInformation (MemoryBlock& destData) ;
    //void setStateInformation (const void* data, int sizeInBytes) ;

private:
//    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginProcessor)
};

#endif  // PLUGINPROCESSOR_H_INCLUDED
