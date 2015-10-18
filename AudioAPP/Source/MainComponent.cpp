/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "GUI.h"
#include "AutoGainControl.hpp"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public AudioAppComponent
{
public:
    //==============================================================================
    MainContentComponent()
    {
        setSize (800, 600);

        // specify the number of input and output channels that we want to open
        gui = new GUI();
        setAudioChannels (2, 2);
        addAndMakeVisible(gui);
    }

    ~MainContentComponent()
    {
        shutdownAudio();
        if (acg) {
            delete acg;

        }
        delete gui;
    }

    //=======================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        // This function will be called when the audio device is started, or when
        // its settings (i.e. sample rate, block size, etc) are changed.

        // You can use this function to initialise any resources you might need,
        // but be careful - it will be called on the audio thread, not the GUI thread.

        // For more details, see the help for AudioProcessor::prepareToPlay()
        blocksize = samplesPerBlockExpected;
        buffer = new AudioSampleBuffer(2, blocksize);
        acg = new ACG(gui->getSliderValue(SliderType::Target), gui->getSliderValue(SliderType::Slope),
                      gui->getSliderValue(SliderType::Attack), gui->getSliderValue(SliderType::Release));
        acg->init(sampleRate, blocksize);
        gui->setACG(acg);
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        // Your audio-processing code goes here!

        // For more details, see the help for AudioProcessor::getNextAudioBlock()

        // Right now we are not producing any data, in which case we need to clear the buffer
        // (to prevent the output of random noise)
        
        bufferToFill.clearActiveBufferRegion();
        if(gui->getReader() != 0){
            length = gui->getReader()->lengthInSamples;
            if(gui->getState() == TransportState::Stopped || startPosition + blocksize > length ){
                startPosition = 0;
                return;
            }
            gui->getReader()->read(buffer, 0, blocksize, startPosition, true, true);
            for(int i = 0 ; i < bufferToFill.buffer->getNumChannels(); i++){
                if(gui->getState() == TransportState::PlayingAdj){
                    acg->process(buffer->getReadPointer(i), bufferToFill.buffer->getWritePointer(i));
                }
                else if(gui->getState() == TransportState::PlayingOri){
                    memcpy(bufferToFill.buffer->getWritePointer(i), buffer->getReadPointer(i), sizeof(float)*blocksize);
                }
            }
            startPosition += blocksize;
        }
    }

    void releaseResources() override
    {
        // This will be called when the audio device stops, or when it is being
        // restarted due to a setting change.

        // For more details, see the help for AudioProcessor::releaseResources()
        
    }

    //=======================================================================
    void paint (Graphics& g) override
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (Colours::black);
        gui->setBounds(getLocalBounds());

        // You can add your drawing code here!
    }

    void resized() override
    {
        // This is called when the MainContentComponent is resized.
        // If you add any child components, this is where you should
        // update their positions.
//        gui->resized();
    }
    
private:
    //==============================================================================

    // Your private member variables go here...
    GUI * gui = nullptr;
    ACG * acg = nullptr;
    int64 length =0, startPosition = 0;
    int blocksize = 0 ;
    ScopedPointer<AudioSampleBuffer>  buffer;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
