/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "Figure.h"
//[/Headers]

#include "GUIMain.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GUIMain::GUIMain ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__textButton.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (juce__textButton.get());
    juce__textButton->addListener (this);

    juce__textButton->setBounds (24, 32, 150, 24);

    xMin_textEditor.reset (new juce::TextEditor ("xMin text editor"));
    addAndMakeVisible (xMin_textEditor.get());
    xMin_textEditor->setMultiLine (false);
    xMin_textEditor->setReturnKeyStartsNewLine (false);
    xMin_textEditor->setReadOnly (false);
    xMin_textEditor->setScrollbarsShown (true);
    xMin_textEditor->setCaretVisible (true);
    xMin_textEditor->setPopupMenuEnabled (true);
    xMin_textEditor->setText (TRANS("0"));

    xMin_textEditor->setBounds (104, 128, 72, 24);

    xMin_label.reset (new juce::Label ("xMin label",
                                       TRANS("X Min")));
    addAndMakeVisible (xMin_label.get());
    xMin_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    xMin_label->setJustificationType (juce::Justification::centredRight);
    xMin_label->setEditable (false, false, false);
    xMin_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    xMin_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    xMin_label->setBounds (16, 128, 72, 24);

    xLength_label.reset (new juce::Label ("xLength label",
                                          TRANS("X Length")));
    addAndMakeVisible (xLength_label.get());
    xLength_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    xLength_label->setJustificationType (juce::Justification::centredRight);
    xLength_label->setEditable (false, false, false);
    xLength_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    xLength_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    xLength_label->setBounds (16, 160, 72, 24);

    xLength_textEditor.reset (new juce::TextEditor ("xLength test editor"));
    addAndMakeVisible (xLength_textEditor.get());
    xLength_textEditor->setMultiLine (false);
    xLength_textEditor->setReturnKeyStartsNewLine (false);
    xLength_textEditor->setReadOnly (false);
    xLength_textEditor->setScrollbarsShown (true);
    xLength_textEditor->setCaretVisible (true);
    xLength_textEditor->setPopupMenuEnabled (true);
    xLength_textEditor->setText (TRANS("0"));

    xLength_textEditor->setBounds (104, 160, 72, 24);

    yMin_textEditor.reset (new juce::TextEditor ("yMin text editor"));
    addAndMakeVisible (yMin_textEditor.get());
    yMin_textEditor->setMultiLine (false);
    yMin_textEditor->setReturnKeyStartsNewLine (false);
    yMin_textEditor->setReadOnly (false);
    yMin_textEditor->setScrollbarsShown (true);
    yMin_textEditor->setCaretVisible (true);
    yMin_textEditor->setPopupMenuEnabled (true);
    yMin_textEditor->setText (TRANS("0"));

    yMin_textEditor->setBounds (104, 192, 72, 24);

    yMin_label.reset (new juce::Label ("yMin label",
                                       TRANS("Y Min")));
    addAndMakeVisible (yMin_label.get());
    yMin_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    yMin_label->setJustificationType (juce::Justification::centredRight);
    yMin_label->setEditable (false, false, false);
    yMin_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    yMin_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    yMin_label->setBounds (16, 192, 72, 24);

    yLength_textEditor.reset (new juce::TextEditor ("yLength text editor"));
    addAndMakeVisible (yLength_textEditor.get());
    yLength_textEditor->setMultiLine (false);
    yLength_textEditor->setReturnKeyStartsNewLine (false);
    yLength_textEditor->setReadOnly (false);
    yLength_textEditor->setScrollbarsShown (true);
    yLength_textEditor->setCaretVisible (true);
    yLength_textEditor->setPopupMenuEnabled (true);
    yLength_textEditor->setText (TRANS("0"));

    yLength_textEditor->setBounds (104, 224, 72, 24);

    yLength_label.reset (new juce::Label ("yLength label",
                                          TRANS("Y Length")));
    addAndMakeVisible (yLength_label.get());
    yLength_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    yLength_label->setJustificationType (juce::Justification::centredRight);
    yLength_label->setEditable (false, false, false);
    yLength_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    yLength_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    yLength_label->setBounds (16, 224, 72, 24);

    graph.reset (new Figure());
    addAndMakeVisible (graph.get());

    graph->setBounds (216, 16, 744, 208);

    graph2.reset (new Figure());
    addAndMakeVisible (graph2.get());

    graph2->setBounds (216, 232, 744, 208);

    graph3.reset (new Figure());
    addAndMakeVisible (graph3.get());

    graph3->setBounds (216, 448, 744, 208);


    //[UserPreSize]
    int bufferSize = 1024;
    auto sin_wave = new float[bufferSize];
    for (int i_sample = 0; i_sample<bufferSize; i_sample++){
        sin_wave[i_sample] = 10*sinf(2*float_Pi*440/48000*i_sample);
    }

    graph->setBackgroundColour(Colours::black);
    graph->setXLabel("X axis");
    graph->setYLabel("Y axis");
    graph->addDataSet(sin_wave, bufferSize);

    graph->setBackgroundColour(Colours::black);
    graph2->setXLim(0, 1024);
    graph2->setYLim(-1, 1);

    delete[] sin_wave;
    //[/UserPreSize]

    setSize (1200, 800);


    //[Constructor] You can add your own custom stuff here..
    plotIdx_ = graph2->creatreDataSet();

    startTimerHz (60);
    //[/Constructor]
}

GUIMain::~GUIMain()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__textButton = nullptr;
    xMin_textEditor = nullptr;
    xMin_label = nullptr;
    xLength_label = nullptr;
    xLength_textEditor = nullptr;
    yMin_textEditor = nullptr;
    yMin_label = nullptr;
    yLength_textEditor = nullptr;
    yLength_label = nullptr;
    graph = nullptr;
    graph2 = nullptr;
    graph3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GUIMain::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    graph->paint(g);
    graph2->paint(g);
    graph3->paint(g);
    //[/UserPaint]
}

void GUIMain::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GUIMain::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__textButton.get())
    {
        //[UserButtonCode_juce__textButton] -- add your button handler code here..

        int bufferSize = 1024;
        auto sin_wave = new float[bufferSize];
        for (int i_sample = 0; i_sample<bufferSize; i_sample++){
            sin_wave[i_sample] = random()/powf(2, 32-1);
        }

        graph->clear();
        graph->addDataSet(sin_wave, bufferSize);


        repaint();
        //[/UserButtonCode_juce__textButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void GUIMain::addGraph2Data(float sample)
{
    graph2->addPoint(sample, plotIdx_);
}

void GUIMain::update()
{
    repaint();
}

void GUIMain::timerCallback()
{
    repaint();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GUIMain" componentName=""
                 parentClasses="public juce::Component, private Timer" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="1200" initialHeight="800">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTBUTTON name="new button" id="8e51bcc35f35f419" memberName="juce__textButton"
              virtualName="" explicitFocusOrder="0" pos="24 32 150 24" buttonText="new button"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="xMin text editor" id="f941bb328e2f390d" memberName="xMin_textEditor"
              virtualName="" explicitFocusOrder="0" pos="104 128 72 24" initialText="0"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="xMin label" id="966671ee3d2a3db" memberName="xMin_label"
         virtualName="" explicitFocusOrder="0" pos="16 128 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="X Min" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <LABEL name="xLength label" id="7133d529deb7dc16" memberName="xLength_label"
         virtualName="" explicitFocusOrder="0" pos="16 160 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="X Length" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="xLength test editor" id="b4f71c7914e65be5" memberName="xLength_textEditor"
              virtualName="" explicitFocusOrder="0" pos="104 160 72 24" initialText="0"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="yMin text editor" id="49f57f76be8556a0" memberName="yMin_textEditor"
              virtualName="" explicitFocusOrder="0" pos="104 192 72 24" initialText="0"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="yMin label" id="2823c97f876b5e44" memberName="yMin_label"
         virtualName="" explicitFocusOrder="0" pos="16 192 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Y Min" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="yLength text editor" id="3ba879aa96ca1f20" memberName="yLength_textEditor"
              virtualName="" explicitFocusOrder="0" pos="104 224 72 24" initialText="0"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="yLength label" id="a5d2694d5b631286" memberName="yLength_label"
         virtualName="" explicitFocusOrder="0" pos="16 224 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Y Length" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <GENERICCOMPONENT name="" id="8ceb0d0631a92e5c" memberName="graph" virtualName=""
                    explicitFocusOrder="0" pos="216 16 744 208" class="Figure" params=""/>
  <GENERICCOMPONENT name="" id="81c68bb0d1ac7024" memberName="graph2" virtualName=""
                    explicitFocusOrder="0" pos="216 232 744 208" class="Figure" params=""/>
  <GENERICCOMPONENT name="" id="cf1ad95a56735ab5" memberName="graph3" virtualName=""
                    explicitFocusOrder="0" pos="216 448 744 208" class="Figure" params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

