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

    xMin_textEditor.reset (new juce::TextEditor ("xMin_textEditor"));
    addAndMakeVisible (xMin_textEditor.get());
    xMin_textEditor->setMultiLine (false);
    xMin_textEditor->setReturnKeyStartsNewLine (false);
    xMin_textEditor->setReadOnly (false);
    xMin_textEditor->setScrollbarsShown (true);
    xMin_textEditor->setCaretVisible (true);
    xMin_textEditor->setPopupMenuEnabled (true);
    xMin_textEditor->setText (TRANS("0"));

    xMin_textEditor->setBounds (96, 246, 41, 24);

    xMax_textEditor.reset (new juce::TextEditor ("xMax_textEditor"));
    addAndMakeVisible (xMax_textEditor.get());
    xMax_textEditor->setMultiLine (false);
    xMax_textEditor->setReturnKeyStartsNewLine (false);
    xMax_textEditor->setReadOnly (false);
    xMax_textEditor->setScrollbarsShown (true);
    xMax_textEditor->setCaretVisible (true);
    xMax_textEditor->setPopupMenuEnabled (true);
    xMax_textEditor->setText (TRANS("8012"));

    xMax_textEditor->setBounds (168, 246, 40, 24);

    yMin_textEditor.reset (new juce::TextEditor ("yMin_textEditor"));
    addAndMakeVisible (yMin_textEditor.get());
    yMin_textEditor->setMultiLine (false);
    yMin_textEditor->setReturnKeyStartsNewLine (false);
    yMin_textEditor->setReadOnly (false);
    yMin_textEditor->setScrollbarsShown (true);
    yMin_textEditor->setCaretVisible (true);
    yMin_textEditor->setPopupMenuEnabled (true);
    yMin_textEditor->setText (TRANS("-1"));

    yMin_textEditor->setBounds (96, 278, 41, 24);

    yMax_textEditor.reset (new juce::TextEditor ("yMax_textEditor"));
    addAndMakeVisible (yMax_textEditor.get());
    yMax_textEditor->setMultiLine (false);
    yMax_textEditor->setReturnKeyStartsNewLine (false);
    yMax_textEditor->setReadOnly (false);
    yMax_textEditor->setScrollbarsShown (true);
    yMax_textEditor->setCaretVisible (true);
    yMax_textEditor->setPopupMenuEnabled (true);
    yMax_textEditor->setText (TRANS("1"));

    yMax_textEditor->setBounds (168, 278, 40, 24);

    PropertySetting_figure.reset (new Figure());
    addAndMakeVisible (PropertySetting_figure.get());

    PropertySetting_figure->setBounds (440, 40, 512, 328);

    amplitude_slider.reset (new juce::Slider ("amplitude_slider"));
    addAndMakeVisible (amplitude_slider.get());
    amplitude_slider->setRange (0.1, 1, 0.1);
    amplitude_slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    amplitude_slider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    amplitude_slider->addListener (this);

    amplitude_slider->setBounds (39, 120, 70, 72);

    freq_slider.reset (new juce::Slider ("freq_slider"));
    addAndMakeVisible (freq_slider.get());
    freq_slider->setRange (20, 15000, 10);
    freq_slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    freq_slider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    freq_slider->addListener (this);

    freq_slider->setBounds (120, 120, 70, 72);

    WaveForm_comboBox.reset (new juce::ComboBox ("WaveForm_comboBox"));
    addAndMakeVisible (WaveForm_comboBox.get());
    WaveForm_comboBox->setEditableText (false);
    WaveForm_comboBox->setJustificationType (juce::Justification::centredLeft);
    WaveForm_comboBox->setTextWhenNothingSelected (TRANS("Sin"));
    WaveForm_comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    WaveForm_comboBox->addItem (TRANS("Sin"), 1);
    WaveForm_comboBox->addItem (TRANS("Cos"), 2);
    WaveForm_comboBox->addItem (TRANS("Triangle"), 3);
    WaveForm_comboBox->addItem (TRANS("Rectangle"), 4);
    WaveForm_comboBox->addListener (this);

    WaveForm_comboBox->setBounds (40, 64, 150, 24);

    XLabel_textEditor.reset (new juce::TextEditor ("XLabel_textEditor"));
    addAndMakeVisible (XLabel_textEditor.get());
    XLabel_textEditor->setMultiLine (false);
    XLabel_textEditor->setReturnKeyStartsNewLine (false);
    XLabel_textEditor->setReadOnly (false);
    XLabel_textEditor->setScrollbarsShown (true);
    XLabel_textEditor->setCaretVisible (true);
    XLabel_textEditor->setPopupMenuEnabled (true);
    XLabel_textEditor->setText (TRANS("Amplitude"));

    XLabel_textEditor->setBounds (96, 310, 112, 24);

    YLabel_textEditor.reset (new juce::TextEditor ("YLabel_textEditor"));
    addAndMakeVisible (YLabel_textEditor.get());
    YLabel_textEditor->setMultiLine (false);
    YLabel_textEditor->setReturnKeyStartsNewLine (false);
    YLabel_textEditor->setReadOnly (false);
    YLabel_textEditor->setScrollbarsShown (true);
    YLabel_textEditor->setCaretVisible (true);
    YLabel_textEditor->setPopupMenuEnabled (true);
    YLabel_textEditor->setText (TRANS("Sample"));

    YLabel_textEditor->setBounds (96, 344, 112, 22);

    top_textEditor.reset (new juce::TextEditor ("top_textEditor"));
    addAndMakeVisible (top_textEditor.get());
    top_textEditor->setMultiLine (false);
    top_textEditor->setReturnKeyStartsNewLine (false);
    top_textEditor->setReadOnly (false);
    top_textEditor->setScrollbarsShown (true);
    top_textEditor->setCaretVisible (true);
    top_textEditor->setPopupMenuEnabled (true);
    top_textEditor->setText (TRANS("10"));

    top_textEditor->setBounds (328, 280, 48, 24);

    bottom_textEditor.reset (new juce::TextEditor ("bottom_textEditor"));
    addAndMakeVisible (bottom_textEditor.get());
    bottom_textEditor->setMultiLine (false);
    bottom_textEditor->setReturnKeyStartsNewLine (false);
    bottom_textEditor->setReadOnly (false);
    bottom_textEditor->setScrollbarsShown (true);
    bottom_textEditor->setCaretVisible (true);
    bottom_textEditor->setPopupMenuEnabled (true);
    bottom_textEditor->setText (TRANS("10"));

    bottom_textEditor->setBounds (328, 344, 48, 24);

    Left_textEditor.reset (new juce::TextEditor ("Left_textEditor"));
    addAndMakeVisible (Left_textEditor.get());
    Left_textEditor->setMultiLine (false);
    Left_textEditor->setReturnKeyStartsNewLine (false);
    Left_textEditor->setReadOnly (false);
    Left_textEditor->setScrollbarsShown (true);
    Left_textEditor->setCaretVisible (true);
    Left_textEditor->setPopupMenuEnabled (true);
    Left_textEditor->setText (TRANS("10"));

    Left_textEditor->setBounds (328, 248, 48, 24);

    Right_textEditor.reset (new juce::TextEditor ("Right_textEditor"));
    addAndMakeVisible (Right_textEditor.get());
    Right_textEditor->setMultiLine (false);
    Right_textEditor->setReturnKeyStartsNewLine (false);
    Right_textEditor->setReadOnly (false);
    Right_textEditor->setScrollbarsShown (true);
    Right_textEditor->setCaretVisible (true);
    Right_textEditor->setPopupMenuEnabled (true);
    Right_textEditor->setText (TRANS("10"));

    Right_textEditor->setBounds (328, 312, 48, 24);

    buckgroundColour_button.reset (new juce::TextButton ("buckgroundColour_button"));
    addAndMakeVisible (buckgroundColour_button.get());
    buckgroundColour_button->setButtonText (TRANS("FF000000"));
    buckgroundColour_button->addListener (this);
    buckgroundColour_button->setColour (juce::TextButton::buttonColourId, juce::Colours::black);

    buckgroundColour_button->setBounds (328, 86, 80, 24);

    plotAriaColour_button.reset (new juce::TextButton ("plotAriaColour_button"));
    addAndMakeVisible (plotAriaColour_button.get());
    plotAriaColour_button->setButtonText (TRANS("FF393643"));
    plotAriaColour_button->addListener (this);
    plotAriaColour_button->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff393643));

    plotAriaColour_button->setBounds (328, 118, 80, 24);

    GridColour_button.reset (new juce::TextButton ("GridColour_button"));
    addAndMakeVisible (GridColour_button.get());
    GridColour_button->setButtonText (TRANS("FFFFFFFF"));
    GridColour_button->setConnectedEdges (juce::Button::ConnectedOnBottom);
    GridColour_button->addListener (this);
    GridColour_button->setColour (juce::TextButton::buttonColourId, juce::Colours::white);
    GridColour_button->setColour (juce::TextButton::buttonOnColourId, juce::Colours::white);
    GridColour_button->setColour (juce::TextButton::textColourOffId, juce::Colours::black);

    GridColour_button->setBounds (328, 150, 80, 24);

    fontColour_button.reset (new juce::TextButton ("fontColour_button"));
    addAndMakeVisible (fontColour_button.get());
    fontColour_button->setButtonText (TRANS("FFFFFFFF"));
    fontColour_button->setConnectedEdges (juce::Button::ConnectedOnBottom);
    fontColour_button->addListener (this);
    fontColour_button->setColour (juce::TextButton::buttonColourId, juce::Colours::white);
    fontColour_button->setColour (juce::TextButton::buttonOnColourId, juce::Colours::white);
    fontColour_button->setColour (juce::TextButton::textColourOffId, juce::Colours::black);

    fontColour_button->setBounds (328, 182, 80, 24);

    timeAxis_figure.reset (new Figure());
    addAndMakeVisible (timeAxis_figure.get());

    timeAxis_figure->setBounds (48, 464, 440, 224);

    maxBufferingSize_button.reset (new juce::TextEditor ("maxBufferingSize_button"));
    addAndMakeVisible (maxBufferingSize_button.get());
    maxBufferingSize_button->setMultiLine (false);
    maxBufferingSize_button->setReturnKeyStartsNewLine (false);
    maxBufferingSize_button->setReadOnly (false);
    maxBufferingSize_button->setScrollbarsShown (true);
    maxBufferingSize_button->setCaretVisible (true);
    maxBufferingSize_button->setPopupMenuEnabled (true);
    maxBufferingSize_button->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0xff201f22));
    maxBufferingSize_button->setColour (juce::TextEditor::outlineColourId, juce::Colour (0x00000000));
    maxBufferingSize_button->setColour (juce::TextEditor::shadowColourId, juce::Colour (0x00000000));
    maxBufferingSize_button->setColour (juce::CaretComponent::caretColourId, juce::Colour (0xff959595));
    maxBufferingSize_button->setText (TRANS("32768"));

    maxBufferingSize_button->setBounds (440, 424, 72, 24);

    freqAxis_figure.reset (new Figure());
    addAndMakeVisible (freqAxis_figure.get());

    freqAxis_figure->setBounds (512, 464, 440, 224);


    //[UserPreSize]
    xMin_textEditor->addListener(this);
    xMax_textEditor->addListener(this);
    yMin_textEditor->addListener(this);
    yMax_textEditor->addListener(this);
    XLabel_textEditor->addListener(this);
    YLabel_textEditor->addListener(this);
    top_textEditor->addListener(this);
    bottom_textEditor->addListener(this);
    Left_textEditor->addListener(this);
    Right_textEditor->addListener(this);

    PropertySetting_figure->setXLabel("X axis");
    PropertySetting_figure->setYLabel("Y axis");
    PropertySetting_figure->setXLabel(XLabel_textEditor->getText());
    PropertySetting_figure->setYLabel(YLabel_textEditor->getText());
    PropertySetting_figure->setXLim(0, 1024);

    Font a = bottom_textEditor->getFont();

    int bufferSize = 1024;
    auto sin_wave = new float[bufferSize];
    for (int i_sample = 0; i_sample<bufferSize; i_sample++){
        sin_wave[i_sample] = 0.8*sinf(2*float_Pi*440/48000*i_sample);
    }

    PropertySetting_figure->addDataSet(sin_wave, bufferSize);
    delete[] sin_wave;

    timeAxis_figure->setFontSize(10.0f);
    timeAxis_figure->setPadding(25, 0, 0, 12);

    freqAxis_figure->setFontSize(10.0f);
    freqAxis_figure->setPadding(25, 0, 0, 12);
    //[/UserPreSize]

    setSize (1000, 900);


    //[Constructor] You can add your own custom stuff here..
    plotIdx_ = timeAxis_figure->creatreDataSet();

    startTimerHz (60);
    //[/Constructor]
}

GUIMain::~GUIMain()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    xMin_textEditor = nullptr;
    xMax_textEditor = nullptr;
    yMin_textEditor = nullptr;
    yMax_textEditor = nullptr;
    PropertySetting_figure = nullptr;
    amplitude_slider = nullptr;
    freq_slider = nullptr;
    WaveForm_comboBox = nullptr;
    XLabel_textEditor = nullptr;
    YLabel_textEditor = nullptr;
    top_textEditor = nullptr;
    bottom_textEditor = nullptr;
    Left_textEditor = nullptr;
    Right_textEditor = nullptr;
    buckgroundColour_button = nullptr;
    plotAriaColour_button = nullptr;
    GridColour_button = nullptr;
    fontColour_button = nullptr;
    timeAxis_figure = nullptr;
    maxBufferingSize_button = nullptr;
    freqAxis_figure = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GUIMain::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = 16, y = 12, width = 960, height = 380;
        juce::Colour fillColour = juce::Colour (0xff182d0e);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 140, y = 244, width = 27, height = 28;
        juce::String text (TRANS("to"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 140, y = 276, width = 27, height = 30;
        juce::String text (TRANS("to"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 39, y = 100, width = 72, height = 26;
        juce::String text (TRANS("Amplitude"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 116, y = 100, width = 72, height = 26;
        juce::String text (TRANS("Frequency"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 28, y = 20, width = 380, height = 30;
        juce::String text (TRANS("Graph Property Settins Demo"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (26.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::topLeft, true);
    }

    {
        int x = 28, y = 212, width = 96, height = 30;
        juce::String text (juce::CharPointer_UTF8 ("\xe2\x96\xa0 Axes Setting"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (16.50f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredLeft, true);
    }

    {
        int x = 28, y = 244, width = 60, height = 28;
        juce::String text (TRANS("X Range"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredRight, true);
    }

    {
        int x = 28, y = 276, width = 60, height = 28;
        juce::String text (TRANS("Y Range"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredRight, true);
    }

    {
        int x = 28, y = 308, width = 60, height = 28;
        juce::String text (TRANS("X Label"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredRight, true);
    }

    {
        int x = 28, y = 340, width = 60, height = 28;
        juce::String text (TRANS("Y Label"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredRight, true);
    }

    {
        int x = 252, y = 212, width = 96, height = 30;
        juce::String text (juce::CharPointer_UTF8 ("\xe2\x96\xa0 Padding"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (16.50f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredLeft, true);
    }

    {
        int x = 268, y = 276, width = 44, height = 28;
        juce::String text (TRANS("Top"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredRight, true);
    }

    {
        int x = 268, y = 340, width = 44, height = 28;
        juce::String text (TRANS("Bottom"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredRight, true);
    }

    {
        int x = 268, y = 244, width = 44, height = 28;
        juce::String text (TRANS("Left"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredRight, true);
    }

    {
        int x = 268, y = 308, width = 44, height = 28;
        juce::String text (TRANS("Right"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredRight, true);
    }

    {
        int x = 244, y = 52, width = 124, height = 28;
        juce::String text (juce::CharPointer_UTF8 ("\xe2\x96\xa0 Colour Setting"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (16.50f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredLeft, true);
    }

    {
        int x = 236, y = 84, width = 80, height = 28;
        juce::String text (TRANS("Background"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredRight, true);
    }

    {
        int x = 236, y = 116, width = 80, height = 28;
        juce::String text (TRANS("Plot Aria"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredRight, true);
    }

    {
        int x = 236, y = 180, width = 80, height = 28;
        juce::String text (TRANS("Font"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredRight, true);
    }

    {
        int x = 236, y = 148, width = 80, height = 28;
        juce::String text (TRANS("Grid"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredRight, true);
    }

    {
        int x = 16, y = 412, width = 960, height = 300;
        juce::Colour fillColour = juce::Colour (0xff0e174a);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 44, y = 420, width = 252, height = 30;
        juce::String text (TRANS("Realtime Plot Demo"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (26.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredLeft, true);
    }

    {
        int x = 316, y = 420, width = 116, height = 30;
        juce::String text (TRANS("Max Buffering size"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredLeft, true);
    }

    {
        int x = 162, y = 167, width = 36, height = 30;
        juce::String text (TRANS("Hz"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    PropertySetting_figure->paint(g);
    timeAxis_figure->paint(g);
    freqAxis_figure->paint(g);
    //[/UserPaint]
}

void GUIMain::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GUIMain::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == amplitude_slider.get())
    {
        //[UserSliderCode_amplitude_slider] -- add your slider handling code here..
        //[/UserSliderCode_amplitude_slider]
    }
    else if (sliderThatWasMoved == freq_slider.get())
    {
        //[UserSliderCode_freq_slider] -- add your slider handling code here..
        //[/UserSliderCode_freq_slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void GUIMain::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == WaveForm_comboBox.get())
    {
        //[UserComboBoxCode_WaveForm_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_WaveForm_comboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void GUIMain::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == buckgroundColour_button.get())
    {
        //[UserButtonCode_buckgroundColour_button] -- add your button handler code here..
        //[/UserButtonCode_buckgroundColour_button]
    }
    else if (buttonThatWasClicked == plotAriaColour_button.get())
    {
        //[UserButtonCode_plotAriaColour_button] -- add your button handler code here..
        //[/UserButtonCode_plotAriaColour_button]
    }
    else if (buttonThatWasClicked == GridColour_button.get())
    {
        //[UserButtonCode_GridColour_button] -- add your button handler code here..
        //[/UserButtonCode_GridColour_button]
    }
    else if (buttonThatWasClicked == fontColour_button.get())
    {
        //[UserButtonCode_fontColour_button] -- add your button handler code here..
        //[/UserButtonCode_fontColour_button]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void GUIMain::addGraph2Data(float sample)
{
    timeAxis_figure->addPoint(sample, plotIdx_);
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
                 parentClasses="public juce::Component, private Timer, public juce::TextEditor::Listener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="1000"
                 initialHeight="900">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="16 12 960 380" fill="solid: ff182d0e" hasStroke="0"/>
    <TEXT pos="140 244 27 28" fill="solid: ffffffff" hasStroke="0" text="to"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="140 276 27 30" fill="solid: ffffffff" hasStroke="0" text="to"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="39 100 72 26" fill="solid: ffffffff" hasStroke="0" text="Amplitude"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="116 100 72 26" fill="solid: ffffffff" hasStroke="0" text="Frequency"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="28 20 380 30" fill="solid: ffffffff" hasStroke="0" text="Graph Property Settins Demo"
          fontname="Default font" fontsize="26.0" kerning="0.0" bold="1"
          italic="0" justification="9" typefaceStyle="Bold"/>
    <TEXT pos="28 212 96 30" fill="solid: ffffffff" hasStroke="0" text="&#9632; Axes Setting"
          fontname="Default font" fontsize="16.5" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="28 244 60 28" fill="solid: ffffffff" hasStroke="0" text="X Range"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="28 276 60 28" fill="solid: ffffffff" hasStroke="0" text="Y Range"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="28 308 60 28" fill="solid: ffffffff" hasStroke="0" text="X Label"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="28 340 60 28" fill="solid: ffffffff" hasStroke="0" text="Y Label"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="252 212 96 30" fill="solid: ffffffff" hasStroke="0" text="&#9632; Padding"
          fontname="Default font" fontsize="16.5" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="268 276 44 28" fill="solid: ffffffff" hasStroke="0" text="Top"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="268 340 44 28" fill="solid: ffffffff" hasStroke="0" text="Bottom"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="268 244 44 28" fill="solid: ffffffff" hasStroke="0" text="Left"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="268 308 44 28" fill="solid: ffffffff" hasStroke="0" text="Right"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="244 52 124 28" fill="solid: ffffffff" hasStroke="0" text="&#9632; Colour Setting"
          fontname="Default font" fontsize="16.5" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="236 84 80 28" fill="solid: ffffffff" hasStroke="0" text="Background"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="236 116 80 28" fill="solid: ffffffff" hasStroke="0" text="Plot Aria"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="236 180 80 28" fill="solid: ffffffff" hasStroke="0" text="Font"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="236 148 80 28" fill="solid: ffffffff" hasStroke="0" text="Grid"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <RECT pos="16 412 960 300" fill="solid: ff0e174a" hasStroke="0"/>
    <TEXT pos="44 420 252 30" fill="solid: ffffffff" hasStroke="0" text="Realtime Plot Demo"
          fontname="Default font" fontsize="26.0" kerning="0.0" bold="1"
          italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="316 420 116 30" fill="solid: ffffffff" hasStroke="0" text="Max Buffering size"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="162 167 36 30" fill="solid: ffffffff" hasStroke="0" text="Hz"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <TEXTEDITOR name="xMin_textEditor" id="f941bb328e2f390d" memberName="xMin_textEditor"
              virtualName="" explicitFocusOrder="0" pos="96 246 41 24" initialText="0"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="xMax_textEditor" id="b4f71c7914e65be5" memberName="xMax_textEditor"
              virtualName="" explicitFocusOrder="0" pos="168 246 40 24" initialText="8012"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="yMin_textEditor" id="49f57f76be8556a0" memberName="yMin_textEditor"
              virtualName="" explicitFocusOrder="0" pos="96 278 41 24" initialText="-1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="yMax_textEditor" id="3ba879aa96ca1f20" memberName="yMax_textEditor"
              virtualName="" explicitFocusOrder="0" pos="168 278 40 24" initialText="1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <GENERICCOMPONENT name="" id="8ceb0d0631a92e5c" memberName="PropertySetting_figure"
                    virtualName="" explicitFocusOrder="0" pos="440 40 512 328" class="Figure"
                    params=""/>
  <SLIDER name="amplitude_slider" id="ff7cc6f6cc561f98" memberName="amplitude_slider"
          virtualName="" explicitFocusOrder="0" pos="39 120 70 72" min="0.1"
          max="1.0" int="0.1" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="freq_slider" id="1c5d4c4c554bb235" memberName="freq_slider"
          virtualName="" explicitFocusOrder="0" pos="120 120 70 72" min="20.0"
          max="15000.0" int="10.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <COMBOBOX name="WaveForm_comboBox" id="27264d42774e190c" memberName="WaveForm_comboBox"
            virtualName="" explicitFocusOrder="0" pos="40 64 150 24" editable="0"
            layout="33" items="Sin&#10;Cos&#10;Triangle&#10;Rectangle" textWhenNonSelected="Sin"
            textWhenNoItems="(no choices)"/>
  <TEXTEDITOR name="XLabel_textEditor" id="e27c0ac7c91370c6" memberName="XLabel_textEditor"
              virtualName="" explicitFocusOrder="0" pos="96 310 112 24" initialText="Amplitude"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="YLabel_textEditor" id="b82d3d7406b6b50a" memberName="YLabel_textEditor"
              virtualName="" explicitFocusOrder="0" pos="96 344 112 22" initialText="Sample"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="top_textEditor" id="86eb18733c2acfeb" memberName="top_textEditor"
              virtualName="" explicitFocusOrder="0" pos="328 280 48 24" initialText="10"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="bottom_textEditor" id="72a30d9145af3c5e" memberName="bottom_textEditor"
              virtualName="" explicitFocusOrder="0" pos="328 344 48 24" initialText="10"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="Left_textEditor" id="ee300c2614b1ab13" memberName="Left_textEditor"
              virtualName="" explicitFocusOrder="0" pos="328 248 48 24" initialText="10"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="Right_textEditor" id="dc313dd49ccd0d9c" memberName="Right_textEditor"
              virtualName="" explicitFocusOrder="0" pos="328 312 48 24" initialText="10"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="buckgroundColour_button" id="bd650b13354e23c7" memberName="buckgroundColour_button"
              virtualName="" explicitFocusOrder="0" pos="328 86 80 24" bgColOff="ff000000"
              buttonText="FF000000" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="plotAriaColour_button" id="1697de2136a98347" memberName="plotAriaColour_button"
              virtualName="" explicitFocusOrder="0" pos="328 118 80 24" bgColOff="ff393643"
              buttonText="FF393643" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="GridColour_button" id="50f55b948ce42b7c" memberName="GridColour_button"
              virtualName="" explicitFocusOrder="0" pos="328 150 80 24" bgColOff="ffffffff"
              bgColOn="ffffffff" textCol="ff000000" buttonText="FFFFFFFF" connectedEdges="8"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="fontColour_button" id="a3563fffb9c9422a" memberName="fontColour_button"
              virtualName="" explicitFocusOrder="0" pos="328 182 80 24" bgColOff="ffffffff"
              bgColOn="ffffffff" textCol="ff000000" buttonText="FFFFFFFF" connectedEdges="8"
              needsCallback="1" radioGroupId="0"/>
  <GENERICCOMPONENT name="" id="3b2d7d4faa8bc38f" memberName="timeAxis_figure" virtualName=""
                    explicitFocusOrder="0" pos="48 464 440 224" class="Figure" params=""/>
  <TEXTEDITOR name="maxBufferingSize_button" id="961bfa50b775e8c9" memberName="maxBufferingSize_button"
              virtualName="" explicitFocusOrder="0" pos="440 424 72 24" bkgcol="ff201f22"
              outlinecol="0" shadowcol="0" caretcol="ff959595" initialText="32768"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <GENERICCOMPONENT name="" id="a74a3abef4b0e258" memberName="freqAxis_figure" virtualName=""
                    explicitFocusOrder="0" pos="512 464 440 224" class="Figure" params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

