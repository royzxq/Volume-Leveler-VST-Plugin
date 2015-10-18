/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_1B5DFE0B2C44A6__
#define __JUCE_HEADER_1B5DFE0B2C44A6__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "AutoGainControl.hpp"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
enum class SliderType{
    Target,
    Attack,
    Release,
    Slope
};

enum TransportState{
    Stopped,
    Starting,
    PlayingOri,
    PlayingAdj,
    Stopping
};

class GUI  : public Component,
             public ButtonListener,
             public SliderListener
{
public:
    //==============================================================================
    GUI ();
    ~GUI();
    
    
    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);
    
    
    double getSliderValue(SliderType slider);
    TransportState getState();
    ScopedPointer<AudioFormatReader>& getReader();
    void setACG(ACG * );
    
private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]
    
    
    
    AudioFormatManager formatManager;
    ScopedPointer<AudioFormatReader> reader = nullptr;
    String filename = "";
    TransportState state;
    
    //==============================================================================
    ScopedPointer<TextButton> fileButton;
    ScopedPointer<TextEditor> textEditor;
    ScopedPointer<Slider> TargetSlider;
    ScopedPointer<Label> Target;
    ScopedPointer<Slider> SlopeSlider;
    ScopedPointer<Label> DynamicSlope;
    ScopedPointer<Slider> AttackSlider;
    ScopedPointer<Label> AttackTime;
    ScopedPointer<Slider> ReleaseSlider;
    ScopedPointer<Label> ReleaseTime;
    ScopedPointer<TextButton> originalPlayButton;
    ScopedPointer<TextButton> adjustedPlayButton;
    ScopedPointer<TextButton> stopButton;
    ScopedPointer<AudioAppComponent> appComponent;
    ACG* acg;
    //==============================================================================
    void openFile();
    void Stop();
    void playOriSound();
    void playAdjSound();
    void changeState(TransportState );
    

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_1B5DFE0B2C44A6__
