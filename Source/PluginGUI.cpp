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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginGUI::PluginGUI (AudioProcessorEditor * p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]
    editor = p;
    
    addAndMakeVisible (TargetSlider = new Slider ("TargetSlider"));
    TargetSlider->setRange (0, 1, 0);
    TargetSlider->setSliderStyle (Slider::LinearHorizontal);
    TargetSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    TargetSlider->addListener (this);
    TargetSlider->setValue(0.5);
    addAndMakeVisible (Target = new Label ("Target",
                                           TRANS("Target Value")));
    Target->setFont (Font (15.00f, Font::plain));
    Target->setJustificationType (Justification::centredLeft);
    Target->setEditable (false, false, false);
    Target->setColour (TextEditor::textColourId, Colours::black);
    Target->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (SlopeSlider2 = new Slider ("SlopeSlider"));
    SlopeSlider2->setRange (0, 1, 0);
    SlopeSlider2->setSliderStyle (Slider::LinearHorizontal);
    SlopeSlider2->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    SlopeSlider2->addListener (this);
    SlopeSlider2->setValue(1.0);

    addAndMakeVisible (DynamicSlope = new Label ("DynamicSlope",
                                                 TRANS("Dynamic Slope")));
    DynamicSlope->setFont (Font (15.00f, Font::plain));
    DynamicSlope->setJustificationType (Justification::centredLeft);
    DynamicSlope->setEditable (false, false, false);
    DynamicSlope->setColour (TextEditor::textColourId, Colours::black);
    DynamicSlope->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (AttackSlider = new Slider ("AttackSlider"));
    AttackSlider->setRange (1, 10, 0);
    AttackSlider->setSliderStyle (Slider::LinearHorizontal);
    AttackSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    AttackSlider->addListener (this);
    AttackSlider->setValue(2);
    
    addAndMakeVisible (AttackTime = new Label ("AttackTime",
                                               TRANS("Attack Time (ms)")));
    AttackTime->setFont (Font (15.00f, Font::plain));
    AttackTime->setJustificationType (Justification::centredLeft);
    AttackTime->setEditable (false, false, false);
    AttackTime->setColour (TextEditor::textColourId, Colours::black);
    AttackTime->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ReleaseSlider = new Slider ("ReleaseSlider"));
    ReleaseSlider->setRange (10, 1000, 0);
    ReleaseSlider->setSliderStyle (Slider::LinearHorizontal);
    ReleaseSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    ReleaseSlider->addListener (this);
    ReleaseSlider->setValue(800.0);
    
    addAndMakeVisible (ReleaseTime = new Label ("ReleaseTime",
                                                TRANS("Release Time (ms)")));
    ReleaseTime->setFont (Font (15.00f, Font::plain));
    ReleaseTime->setJustificationType (Justification::centredLeft);
    ReleaseTime->setEditable (false, false, false);
    ReleaseTime->setColour (TextEditor::textColourId, Colours::black);
    ReleaseTime->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginGUI::~PluginGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    TargetSlider = nullptr;
    Target = nullptr;
    SlopeSlider2 = nullptr;
    DynamicSlope = nullptr;
    AttackSlider = nullptr;
    AttackTime = nullptr;
    ReleaseSlider = nullptr;
    ReleaseTime = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginGUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    TargetSlider->setBounds (241, 40, 150, 24);
    Target->setBounds (136, 40, 150, 24);
    SlopeSlider2->setBounds (240, 72, 150, 24);
    DynamicSlope->setBounds (136, 72, 150, 24);
    AttackSlider->setBounds (241, 112, 150, 24);
    AttackTime->setBounds (129, 112, 150, 24);
    ReleaseSlider->setBounds (240, 144, 150, 24);
    ReleaseTime->setBounds (123, 144, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginGUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == TargetSlider)
    {
        //[UserSliderCode_TargetSlider] -- add your slider handling code here..
        //[/UserSliderCode_TargetSlider]
        editor->processor.setParameter(2, sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == SlopeSlider2)
    {
        //[UserSliderCode_SlopeSlider2] -- add your slider handling code here..
        //[/UserSliderCode_SlopeSlider2]
        editor->processor.setParameter(3, sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == AttackSlider)
    {
        //[UserSliderCode_AttackSlider] -- add your slider handling code here..
        //[/UserSliderCode_AttackSlider]
        editor->processor.setParameter(0, sliderThatWasMoved->getValue());
    }
    else if (sliderThatWasMoved == ReleaseSlider)
    {
        //[UserSliderCode_ReleaseSlider] -- add your slider handling code here..
        //[/UserSliderCode_ReleaseSlider]
        editor->processor.setParameter(1, sliderThatWasMoved->getValue());
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginGUI" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="TargetSlider" id="86485a4b279f3172" memberName="TargetSlider"
          virtualName="" explicitFocusOrder="0" pos="241 40 150 24" min="0"
          max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Target" id="25a3a6c34092b601" memberName="Target" virtualName=""
         explicitFocusOrder="0" pos="136 40 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Target Value" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="SlopeSlider" id="769254dfc8e6bc8d" memberName="SlopeSlider2"
          virtualName="" explicitFocusOrder="0" pos="240 72 150 24" min="0"
          max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="DynamicSlope" id="845e0cae7e20c4e2" memberName="DynamicSlope"
         virtualName="" explicitFocusOrder="0" pos="136 72 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Dynamic Slope" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="AttackSlider" id="9c4619f84d15f8f0" memberName="AttackSlider"
          virtualName="" explicitFocusOrder="0" pos="241 112 150 24" min="1"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="AttackTime" id="6ae8684d9b3fefd" memberName="AttackTime"
         virtualName="" explicitFocusOrder="0" pos="129 112 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack Time (ms)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="ReleaseSlider" id="b502a09a86bbb12c" memberName="ReleaseSlider"
          virtualName="" explicitFocusOrder="0" pos="240 144 150 24" min="10"
          max="1000" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="ReleaseTime" id="73c379f5b11af5c3" memberName="ReleaseTime"
         virtualName="" explicitFocusOrder="0" pos="123 144 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Release Time (ms)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
