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

#ifndef __JUCE_HEADER_AD07FA593BDA3138__
#define __JUCE_HEADER_AD07FA593BDA3138__

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
class PluginGUI  : public Component,
                   public SliderListener
{
public:
    //==============================================================================
    PluginGUI ();
    ~PluginGUI();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> TargetSlider;
    ScopedPointer<Label> Target;
    ScopedPointer<Slider> SlopeSlider2;
    ScopedPointer<Label> DynamicSlope;
    ScopedPointer<Slider> AttackSlider;
    ScopedPointer<Label> AttackTime;
    ScopedPointer<Slider> ReleaseSlider;
    ScopedPointer<Label> ReleaseTime;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_AD07FA593BDA3138__
