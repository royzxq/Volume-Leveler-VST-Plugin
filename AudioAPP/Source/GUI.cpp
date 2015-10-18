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

#include "GUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GUI::GUI ():state(Stopped)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]
//    appComponent = p;
    formatManager.registerBasicFormats();
    
    addAndMakeVisible (fileButton = new TextButton ("file button"));
    fileButton->setButtonText (TRANS("choose file"));
    fileButton->addListener (this);

    addAndMakeVisible (textEditor = new TextEditor ("new text editor"));
    textEditor->setMultiLine (false);
    textEditor->setReturnKeyStartsNewLine (false);
    textEditor->setReadOnly (false);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (true);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setText (String::empty);

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

    addAndMakeVisible (SlopeSlider = new Slider ("SlopeSlider"));
    SlopeSlider->setRange (0.5, 1.2, 0);
    SlopeSlider->setSliderStyle (Slider::LinearHorizontal);
    SlopeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    SlopeSlider->addListener (this);
    SlopeSlider->setValue(1.0);

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
    AttackSlider->setValue(5.0);
    
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
    ReleaseSlider->setValue(500);
    
    addAndMakeVisible (ReleaseTime = new Label ("ReleaseTime",
                                                TRANS("Release Time (ms)")));
    ReleaseTime->setFont (Font (15.00f, Font::plain));
    ReleaseTime->setJustificationType (Justification::centredLeft);
    ReleaseTime->setEditable (false, false, false);
    ReleaseTime->setColour (TextEditor::textColourId, Colours::black);
    ReleaseTime->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (originalPlayButton = new TextButton ("originalPlayButton"));
    originalPlayButton->setButtonText (TRANS("play original sound"));
    originalPlayButton->addListener (this);

    addAndMakeVisible (adjustedPlayButton = new TextButton ("adjustedPlayButton"));
    adjustedPlayButton->setButtonText (TRANS("play adjusted sound"));
    adjustedPlayButton->addListener (this);

    addAndMakeVisible (stopButton = new TextButton ("stopButton"));
    stopButton->setButtonText (TRANS("stop"));
    stopButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

GUI::~GUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    fileButton = nullptr;
    textEditor = nullptr;
    TargetSlider = nullptr;
    Target = nullptr;
    SlopeSlider = nullptr;
    DynamicSlope = nullptr;
    AttackSlider = nullptr;
    AttackTime = nullptr;
    ReleaseSlider = nullptr;
    ReleaseTime = nullptr;
    originalPlayButton = nullptr;
    adjustedPlayButton = nullptr;
    stopButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    fileButton->setBounds (48, 32, 88, 24);
    textEditor->setBounds (152, 32, 150, 24);
    TargetSlider->setBounds (153, 88, 150, 24);
    Target->setBounds (48, 88, 150, 24);
    SlopeSlider->setBounds (152, 120, 150, 24);
    DynamicSlope->setBounds (48, 120, 150, 24);
    AttackSlider->setBounds (153, 160, 150, 24);
    AttackTime->setBounds (41, 160, 150, 24);
    ReleaseSlider->setBounds (152, 192, 150, 24);
    ReleaseTime->setBounds (35, 192, 150, 24);
    originalPlayButton->setBounds (320, 32, 150, 24);
    adjustedPlayButton->setBounds (320, 64, 150, 24);
    stopButton->setBounds (320, 104, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GUI::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == fileButton)
    {
        //[UserButtonCode_fileButton] -- add your button handler code here..
        //[/UserButtonCode_fileButton]
        openFile();
    }
    else if (buttonThatWasClicked == originalPlayButton)
    {
        //[UserButtonCode_originalPlayButton] -- add your button handler code here..
        //[/UserButtonCode_originalPlayButton]
        playOriSound();
    }
    else if (buttonThatWasClicked == adjustedPlayButton)
    {
        //[UserButtonCode_adjustedPlayButton] -- add your button handler code here..
        //[/UserButtonCode_adjustedPlayButton]
        playAdjSound();
    }
    else if (buttonThatWasClicked == stopButton)
    {
        //[UserButtonCode_stopButton] -- add your button handler code here..
        //[/UserButtonCode_stopButton]
        Stop();
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

// to do, set params in acg by sliders
void GUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == TargetSlider)
    {
        //[UserSliderCode_TargetSlider] -- add your slider handling code here..
        //[/UserSliderCode_TargetSlider]
        acg -> setParams(sliderThatWasMoved->getValue(), 2);
    }
    else if (sliderThatWasMoved == SlopeSlider)
    {
        //[UserSliderCode_SlopeSlider] -- add your slider handling code here..
        //[/UserSliderCode_SlopeSlider]
        acg -> setParams(sliderThatWasMoved->getValue(), 3);
    }
    else if (sliderThatWasMoved == AttackSlider)
    {
        //[UserSliderCode_AttackSlider] -- add your slider handling code here..
        //[/UserSliderCode_AttackSlider]
        acg -> setParams(sliderThatWasMoved->getValue(), 0);
    }
    else if (sliderThatWasMoved == ReleaseSlider)
    {
        //[UserSliderCode_ReleaseSlider] -- add your slider handling code here..
        //[/UserSliderCode_ReleaseSlider]
        acg -> setParams(sliderThatWasMoved->getValue(), 1);
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void GUI::openFile(){
    FileChooser chooser ("Select a Wave file to play...",
                         File::nonexistent,
                         "*.wav");
    if (chooser.browseForFileToOpen())                                    // [8]
    {
        File file (chooser.getResult());                                  // [9]
        filename = chooser.getResult().getFileName();
        reader = formatManager.createReaderFor (file); // [10]

        textEditor->setText(filename);
        if (reader != 0)
        {
            originalPlayButton->setEnabled (true);                                             // [13]
            adjustedPlayButton->setEnabled(true);
        }
    }
}

void GUI::Stop(){
    changeState(Stopped);
}

void GUI::playOriSound(){
    changeState(PlayingOri);
}

void GUI::playAdjSound(){
    changeState(PlayingAdj);
}

void GUI::changeState(TransportState newState){
    if (state != newState) {
        state = newState;
        switch (state) {
            case Stopped:
                stopButton->setEnabled(false);
                originalPlayButton->setEnabled(true);
                adjustedPlayButton->setEnabled(true);
//                transportSource.setPosition(0.0);
                break;
            case Starting:
                originalPlayButton->setEnabled(false);
                adjustedPlayButton->setEnabled(false);
//                transportSource.start();
                break;
            case PlayingAdj:
                stopButton->setEnabled(true);
                break;
            case PlayingOri:
                stopButton->setEnabled(true);
                break;

            default:
                break;
        }
    }
}

ScopedPointer<AudioFormatReader>& GUI::getReader(){
    return reader;
}

double GUI::getSliderValue(SliderType slider){
    switch (slider) {
        case SliderType::Target:
            return TargetSlider->getValue();
            break;
        case SliderType::Slope:
            return SlopeSlider->getValue();
            break;
        case SliderType::Attack:
            return AttackSlider->getValue();
            break;
        case SliderType::Release:
            return AttackSlider->getValue();
            break;
        default:
            break;
    }
}

TransportState GUI::getState(){
    return state;
}

void GUI::setACG(ACG * a){
    acg = a;
}
//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GUI" componentName="" parentClasses="public Component"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="file button" id="c4366c683ceaf6b4" memberName="fileButton"
              virtualName="" explicitFocusOrder="0" pos="48 32 88 24" buttonText="choose file"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="new text editor" id="defedc97a02906e4" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="152 32 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <SLIDER name="TargetSlider" id="86485a4b279f3172" memberName="TargetSlider"
          virtualName="" explicitFocusOrder="0" pos="153 88 150 24" min="0"
          max="1" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Target" id="25a3a6c34092b601" memberName="Target" virtualName=""
         explicitFocusOrder="0" pos="48 88 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Target Value" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="SlopeSlider" id="769254dfc8e6bc8d" memberName="SlopeSlider"
          virtualName="" explicitFocusOrder="0" pos="152 120 150 24" min="0.5"
          max="1.1999999999999999556" int="0" style="LinearHorizontal"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="DynamicSlope" id="845e0cae7e20c4e2" memberName="DynamicSlope"
         virtualName="" explicitFocusOrder="0" pos="48 120 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Dynamic Slope" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="AttackSlider" id="9c4619f84d15f8f0" memberName="AttackSlider"
          virtualName="" explicitFocusOrder="0" pos="153 160 150 24" min="1"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="AttackTime" id="6ae8684d9b3fefd" memberName="AttackTime"
         virtualName="" explicitFocusOrder="0" pos="41 160 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack Time (ms)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="ReleaseSlider" id="b502a09a86bbb12c" memberName="ReleaseSlider"
          virtualName="" explicitFocusOrder="0" pos="152 192 150 24" min="10"
          max="1000" int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="ReleaseTime" id="73c379f5b11af5c3" memberName="ReleaseTime"
         virtualName="" explicitFocusOrder="0" pos="35 192 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Release Time (ms)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="originalPlayButton" id="f20b32d6166117b6" memberName="originalPlayButton"
              virtualName="" explicitFocusOrder="0" pos="320 32 150 24" buttonText="play original sound"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="adjustedPlayButton" id="74bcdc600a739b69" memberName="adjustedPlayButton"
              virtualName="" explicitFocusOrder="0" pos="320 64 150 24" buttonText="play adjusted sound"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="stopButton" id="a363c90e89918b9f" memberName="stopButton"
              virtualName="" explicitFocusOrder="0" pos="320 104 150 24" buttonText="stop"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
