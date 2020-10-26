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
    xMin_textEditor->setText (TRANS("1"));

    xMin_textEditor->setBounds (104, 246, 41, 24);

    xMax_textEditor.reset (new juce::TextEditor ("xMax_textEditor"));
    addAndMakeVisible (xMax_textEditor.get());
    xMax_textEditor->setMultiLine (false);
    xMax_textEditor->setReturnKeyStartsNewLine (false);
    xMax_textEditor->setReadOnly (false);
    xMax_textEditor->setScrollbarsShown (true);
    xMax_textEditor->setCaretVisible (true);
    xMax_textEditor->setPopupMenuEnabled (true);
    xMax_textEditor->setText (TRANS("1024"));

    xMax_textEditor->setBounds (176, 246, 40, 24);

    yMin_textEditor.reset (new juce::TextEditor ("yMin_textEditor"));
    addAndMakeVisible (yMin_textEditor.get());
    yMin_textEditor->setMultiLine (false);
    yMin_textEditor->setReturnKeyStartsNewLine (false);
    yMin_textEditor->setReadOnly (false);
    yMin_textEditor->setScrollbarsShown (true);
    yMin_textEditor->setCaretVisible (true);
    yMin_textEditor->setPopupMenuEnabled (true);
    yMin_textEditor->setText (TRANS("-1"));

    yMin_textEditor->setBounds (104, 278, 41, 24);

    yMax_textEditor.reset (new juce::TextEditor ("yMax_textEditor"));
    addAndMakeVisible (yMax_textEditor.get());
    yMax_textEditor->setMultiLine (false);
    yMax_textEditor->setReturnKeyStartsNewLine (false);
    yMax_textEditor->setReadOnly (false);
    yMax_textEditor->setScrollbarsShown (true);
    yMax_textEditor->setCaretVisible (true);
    yMax_textEditor->setPopupMenuEnabled (true);
    yMax_textEditor->setText (TRANS("1"));

    yMax_textEditor->setBounds (176, 278, 40, 24);

    PropertySetting_figure.reset (new Figure());
    addAndMakeVisible (PropertySetting_figure.get());

    PropertySetting_figure->setBounds (440, 40, 512, 328);

    amplitude_slider.reset (new juce::Slider ("amplitude_slider"));
    addAndMakeVisible (amplitude_slider.get());
    amplitude_slider->setRange (0.1, 1, 0.1);
    amplitude_slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    amplitude_slider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    amplitude_slider->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff29667e));
    amplitude_slider->setColour (juce::Slider::rotarySliderOutlineColourId, juce::Colour (0xff495e68));
    amplitude_slider->addListener (this);

    amplitude_slider->setBounds (39, 88, 81, 88);

    XLabel_textEditor.reset (new juce::TextEditor ("XLabel_textEditor"));
    addAndMakeVisible (XLabel_textEditor.get());
    XLabel_textEditor->setMultiLine (false);
    XLabel_textEditor->setReturnKeyStartsNewLine (false);
    XLabel_textEditor->setReadOnly (false);
    XLabel_textEditor->setScrollbarsShown (true);
    XLabel_textEditor->setCaretVisible (true);
    XLabel_textEditor->setPopupMenuEnabled (true);
    XLabel_textEditor->setText (TRANS("Sample"));

    XLabel_textEditor->setBounds (104, 310, 112, 24);

    YLabel_textEditor.reset (new juce::TextEditor ("YLabel_textEditor"));
    addAndMakeVisible (YLabel_textEditor.get());
    YLabel_textEditor->setMultiLine (false);
    YLabel_textEditor->setReturnKeyStartsNewLine (false);
    YLabel_textEditor->setReadOnly (false);
    YLabel_textEditor->setScrollbarsShown (true);
    YLabel_textEditor->setCaretVisible (true);
    YLabel_textEditor->setPopupMenuEnabled (true);
    YLabel_textEditor->setText (TRANS("Amplitude"));

    YLabel_textEditor->setBounds (104, 344, 112, 22);

    top_textEditor.reset (new juce::TextEditor ("top_textEditor"));
    addAndMakeVisible (top_textEditor.get());
    top_textEditor->setMultiLine (false);
    top_textEditor->setReturnKeyStartsNewLine (false);
    top_textEditor->setReadOnly (false);
    top_textEditor->setScrollbarsShown (true);
    top_textEditor->setCaretVisible (true);
    top_textEditor->setPopupMenuEnabled (true);
    top_textEditor->setText (TRANS("20"));

    top_textEditor->setBounds (328, 280, 48, 24);

    bottom_textEditor.reset (new juce::TextEditor ("bottom_textEditor"));
    addAndMakeVisible (bottom_textEditor.get());
    bottom_textEditor->setMultiLine (false);
    bottom_textEditor->setReturnKeyStartsNewLine (false);
    bottom_textEditor->setReadOnly (false);
    bottom_textEditor->setScrollbarsShown (true);
    bottom_textEditor->setCaretVisible (true);
    bottom_textEditor->setPopupMenuEnabled (true);
    bottom_textEditor->setText (TRANS("40"));

    bottom_textEditor->setBounds (328, 344, 48, 24);

    Left_textEditor.reset (new juce::TextEditor ("Left_textEditor"));
    addAndMakeVisible (Left_textEditor.get());
    Left_textEditor->setMultiLine (false);
    Left_textEditor->setReturnKeyStartsNewLine (false);
    Left_textEditor->setReadOnly (false);
    Left_textEditor->setScrollbarsShown (true);
    Left_textEditor->setCaretVisible (true);
    Left_textEditor->setPopupMenuEnabled (true);
    Left_textEditor->setText (TRANS("50"));

    Left_textEditor->setBounds (328, 248, 48, 24);

    Right_textEditor.reset (new juce::TextEditor ("Right_textEditor"));
    addAndMakeVisible (Right_textEditor.get());
    Right_textEditor->setMultiLine (false);
    Right_textEditor->setReturnKeyStartsNewLine (false);
    Right_textEditor->setReadOnly (false);
    Right_textEditor->setScrollbarsShown (true);
    Right_textEditor->setCaretVisible (true);
    Right_textEditor->setPopupMenuEnabled (true);
    Right_textEditor->setText (TRANS("20"));

    Right_textEditor->setBounds (328, 312, 48, 24);

    buckgroundColour_button.reset (new juce::TextButton ("buckgroundColour_button"));
    addAndMakeVisible (buckgroundColour_button.get());
    buckgroundColour_button->setButtonText (TRANS("FF000000"));
    buckgroundColour_button->addListener (this);
    buckgroundColour_button->setColour (juce::TextButton::buttonColourId, juce::Colours::black);

    buckgroundColour_button->setBounds (328, 88, 88, 24);

    plotAriaColour_button.reset (new juce::TextButton ("plotAriaColour_button"));
    addAndMakeVisible (plotAriaColour_button.get());
    plotAriaColour_button->setButtonText (TRANS("FF393643"));
    plotAriaColour_button->addListener (this);
    plotAriaColour_button->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff393643));

    plotAriaColour_button->setBounds (328, 120, 88, 24);

    gridColour_button.reset (new juce::TextButton ("gridColour_button"));
    addAndMakeVisible (gridColour_button.get());
    gridColour_button->setButtonText (TRANS("FFFFFFFF"));
    gridColour_button->addListener (this);
    gridColour_button->setColour (juce::TextButton::buttonColourId, juce::Colours::white);
    gridColour_button->setColour (juce::TextButton::buttonOnColourId, juce::Colours::white);
    gridColour_button->setColour (juce::TextButton::textColourOffId, juce::Colours::black);

    gridColour_button->setBounds (328, 152, 88, 24);

    fontColour_button.reset (new juce::TextButton ("fontColour_button"));
    addAndMakeVisible (fontColour_button.get());
    fontColour_button->setButtonText (TRANS("FFFFFFFF"));
    fontColour_button->addListener (this);
    fontColour_button->setColour (juce::TextButton::buttonColourId, juce::Colours::white);
    fontColour_button->setColour (juce::TextButton::buttonOnColourId, juce::Colours::white);
    fontColour_button->setColour (juce::TextButton::textColourOffId, juce::Colours::black);

    fontColour_button->setBounds (328, 184, 88, 24);

    timeAxis_figure.reset (new Figure());
    addAndMakeVisible (timeAxis_figure.get());

    timeAxis_figure->setBounds (48, 464, 440, 224);

    freqAxis_figure.reset (new Figure());
    addAndMakeVisible (freqAxis_figure.get());

    freqAxis_figure->setBounds (512, 464, 440, 224);

    freq_slider.reset (new juce::Slider ("freq_slider"));
    addAndMakeVisible (freq_slider.get());
    freq_slider->setRange (20, 15000, 1);
    freq_slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    freq_slider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    freq_slider->setColour (juce::Slider::rotarySliderFillColourId, juce::Colour (0xff29667e));
    freq_slider->setColour (juce::Slider::rotarySliderOutlineColourId, juce::Colour (0xff495e68));
    freq_slider->addListener (this);

    freq_slider->setBounds (136, 88, 81, 88);


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

    forwardFFT_.reset (new dsp::FFT(fftOrder));

    PropertySetting_figure->setXLabel(XLabel_textEditor->getText());
    PropertySetting_figure->setYLabel(YLabel_textEditor->getText());
    PropertySetting_figure->setXRange(Range<float>(0, 1024));
    amplitude_slider->setValue(0.8);
    freq_slider->setValue(100);
    drawWaves();

    timeAxis_figure->setPadding(Figure::Padding{40, 20, 20, 30});
    timeAxis_figure->setYRange(Range<float>(-0.5, 0.5));
    micDatasetIndex_ = 0;
    timeAxis_figure->creatreAddableDataSet(32768, micDatasetIndex_);

    freqAxis_figure->setPadding(Figure::Padding{40, 20, 20, 30});
    freqAxis_figure->setXRange(Range<float>(0, 24000));
    freqAxis_figure->setYRange(Range<float>(-120, 0));
    freqAxis_figure->setXScale(Figure::Scale::log);

    //[/UserPreSize]

    setSize (1000, 750);


    //[Constructor] You can add your own custom stuff here..
    startTimerHz (30);
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
    XLabel_textEditor = nullptr;
    YLabel_textEditor = nullptr;
    top_textEditor = nullptr;
    bottom_textEditor = nullptr;
    Left_textEditor = nullptr;
    Right_textEditor = nullptr;
    buckgroundColour_button = nullptr;
    plotAriaColour_button = nullptr;
    gridColour_button = nullptr;
    fontColour_button = nullptr;
    timeAxis_figure = nullptr;
    freqAxis_figure = nullptr;
    freq_slider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    forwardFFT_ = nullptr;
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
        int x = 148, y = 244, width = 27, height = 28;
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
        int x = 148, y = 276, width = 27, height = 30;
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
        int x = 39, y = 60, width = 81, height = 26;
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
        int x = 132, y = 60, width = 84, height = 26;
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
        juce::String text (TRANS("Graph Property Settings Demo"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (26.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::topLeft, true);
    }

    {
        int x = 36, y = 212, width = 96, height = 30;
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
        int x = 36, y = 244, width = 60, height = 28;
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
        int x = 36, y = 276, width = 60, height = 28;
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
        int x = 36, y = 308, width = 60, height = 28;
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
        int x = 36, y = 340, width = 60, height = 28;
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
        int x = 16, y = 412, width = 960, height = 316;
        juce::Colour fillColour = juce::Colour (0xff0e174a);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 44, y = 420, width = 252, height = 30;
        juce::String text (TRANS("Real-time Plot Demo"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (26.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centredLeft, true);
    }

    {
        int x = 188, y = 148, width = 36, height = 36;
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
    drawWaves();
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

void GUIMain::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == buckgroundColour_button.get())
    {
        //[UserButtonCode_buckgroundColour_button] -- add your button handler code here..
        colourSelector.reset(new ColourSelectBox(PropertySetting_figure->getBackgroundColour()));

        colourSelector->onChange = [&](auto& c){
            PropertySetting_figure->setBackgroundColour(c);
            buckgroundColour_button->setColour(TextButton::buttonColourId, c);

            std::stringstream ss;
            ss << std::uppercase << std::hex << c.getARGB();
            buckgroundColour_button->setButtonText(ss.str());

        };


        CallOutBox::launchAsynchronously(std::move(colourSelector), buckgroundColour_button->getScreenBounds(),nullptr);
       //[/UserButtonCode_buckgroundColour_button]
    }
    else if (buttonThatWasClicked == plotAriaColour_button.get())
    {
        //[UserButtonCode_plotAriaColour_button] -- add your button handler code here..
        colourSelector.reset(new ColourSelectBox(PropertySetting_figure->getPlotAriaColour()));

        colourSelector->onChange = [&](auto& c){
            PropertySetting_figure->setPlotAriaColour(c);
            plotAriaColour_button->setColour(TextButton::buttonColourId, c);

            std::stringstream ss;
            ss << std::uppercase << std::hex << c.getARGB();
            plotAriaColour_button->setButtonText(ss.str());
        };

        CallOutBox::launchAsynchronously (std::move(colourSelector),
                                           plotAriaColour_button->getScreenBounds(), nullptr);
        //[/UserButtonCode_plotAriaColour_button]
    }
    else if (buttonThatWasClicked == gridColour_button.get())
    {
        //[UserButtonCode_gridColour_button] -- add your button handler code here..

        colourSelector.reset(new ColourSelectBox(PropertySetting_figure->getGridColour()));

        colourSelector->onChange = [&](auto& c){
            PropertySetting_figure->setGridColour(c);
            gridColour_button->setColour(TextButton::buttonColourId, c);

            std::stringstream ss;
            ss << std::uppercase << std::hex << c.getARGB();
            gridColour_button->setButtonText(ss.str());
        };

        CallOutBox::launchAsynchronously (std::move(colourSelector), gridColour_button->getScreenBounds(), nullptr);
        //[/UserButtonCode_gridColour_button]
    }
    else if (buttonThatWasClicked == fontColour_button.get())
    {
        //[UserButtonCode_fontColour_button] -- add your button handler code here..
        colourSelector.reset(new ColourSelectBox(PropertySetting_figure->getFontColour()));

        colourSelector->onChange = [&](auto& c){
            PropertySetting_figure->setFontColour(c);
            fontColour_button->setColour(TextButton::buttonColourId, c);

            std::stringstream ss;
            ss << std::uppercase << std::hex << c.getARGB();
            fontColour_button->setButtonText(ss.str());
        };

        CallOutBox::launchAsynchronously (std::move(colourSelector), fontColour_button->getScreenBounds(), nullptr);
        //[/UserButtonCode_fontColour_button]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void GUIMain::textEditorTextChanged (juce::TextEditor& textEditorThatWasTextChanged)
{
    String Value = textEditorThatWasTextChanged.getText();

    if (&textEditorThatWasTextChanged == xMin_textEditor.get()
        || &textEditorThatWasTextChanged == xMax_textEditor.get())
    {
        float min = xMin_textEditor.get()->getText().getFloatValue();
        float max = xMax_textEditor.get()->getText().getFloatValue();
        PropertySetting_figure->setXRange(Range<float>(min, max));
    }
    else if (&textEditorThatWasTextChanged == yMin_textEditor.get()
        || &textEditorThatWasTextChanged == yMax_textEditor.get())
    {
        float min = yMin_textEditor.get()->getText().getFloatValue();
        float max = yMax_textEditor.get()->getText().getFloatValue();
        PropertySetting_figure->setYRange(Range<float>(min, max));
    }

    else if (&textEditorThatWasTextChanged == XLabel_textEditor.get())
    {
        String text = textEditorThatWasTextChanged.getText();
        PropertySetting_figure->setXLabel(text);
    }
    else if (&textEditorThatWasTextChanged == YLabel_textEditor.get())
    {
        String text = textEditorThatWasTextChanged.getText();
        PropertySetting_figure->setYLabel(text);
    }
    else if (&textEditorThatWasTextChanged == Left_textEditor.get())
    {
        int value = textEditorThatWasTextChanged.getText().getIntValue();
        Figure::Padding padding = PropertySetting_figure->getPadding();
        padding.left = value;
        PropertySetting_figure->setPadding(padding);
    }
    else if (&textEditorThatWasTextChanged == top_textEditor.get())
    {
        int value = textEditorThatWasTextChanged.getText().getIntValue();
        Figure::Padding padding = PropertySetting_figure->getPadding();
        padding.top = value;
        PropertySetting_figure->setPadding(padding);
    }
    else if (&textEditorThatWasTextChanged == Right_textEditor.get())
    {
        int value = textEditorThatWasTextChanged.getText().getIntValue();
        Figure::Padding padding = PropertySetting_figure->getPadding();
        padding.right = value;
        PropertySetting_figure->setPadding(padding);
    }
    else if (&textEditorThatWasTextChanged == bottom_textEditor.get())
    {
        int value = textEditorThatWasTextChanged.getText().getIntValue();
        Figure::Padding padding = PropertySetting_figure->getPadding();
        padding.bottom = value;
        PropertySetting_figure->setPadding(padding);
    }
}

void GUIMain::addMicdata(float* data, int len)
{
    timeAxis_figure->addData(data, len, micDatasetIndex_);

    for(int i=0; i<len; i++){
        fifo_[fifoIndex_] = data[i];
        fifoIndex_ = (fifoIndex_+1)%fftSize;
    }
}

void GUIMain::timerCallback()
{
    /* fft */
    memcpy (fftData_, fifo_, sizeof (fifo_));
    forwardFFT_->performFrequencyOnlyForwardTransform
    (fftData_);
    float* x = new float[fftSize/2];

    for(int i=0;i<fftSize/2;i++)
    {
        fftData_[i] /= (fftSize/2);
        fftData_[i] = 20*log10(fftData_[i]);
        x[i] = 24000/(fftSize/2)*i;
    }

    freqAxis_figure->setDataset(x, fftData_, fftSize/2, 0);

    delete[] x;

}

void GUIMain::drawWaves()
{
    int bufferSize = 4096;
    auto* waveBuffer = new float[bufferSize];
    float amp = amplitude_slider.get()->getValue();
    float freq = freq_slider.get()->getValue();

    /* draw sine */
    for (int sample = 0; sample<bufferSize; sample++){
        waveBuffer[sample] = amp*sinf(2.0f*float_Pi*freq/Fs*sample);
    }
    PropertySetting_figure->setDataset(waveBuffer, bufferSize, 0);

    /* draw triangle wave */
//    for (auto sample = 0; sample<bufferSize; sample++){
//        waveBuffer[sample] = 0.0f;
//        for(auto n=1;n<freq;n++){
//            waveBuffer[sample] += amp * 8.0f/(M_PI*M_PI) * 1.0f/(float)(n*n)
//              * sinf((float)n*M_PI/2.0f)*sinf(2.0f*M_PI*freq/Fs*n*sample);
//         }
//    }
//    PropertySetting_figure->setDataset(waveBuffer, bufferSize, 1, Colours::magenta);

    /* draw square wave */
    for (int sample = 0; sample<bufferSize; sample++){
        float x = fmod(2.0f*M_PI*freq/Fs*sample, 2.0f*M_PI);
        waveBuffer[sample] = amp * (0<x && x<M_PI ? 1.0f: -1.0f);
    }
    PropertySetting_figure->setDataset(waveBuffer, bufferSize, 1, Colours::cyan);

    delete[] waveBuffer;
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
                 initialHeight="750">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="16 12 960 380" fill="solid: ff182d0e" hasStroke="0"/>
    <TEXT pos="148 244 27 28" fill="solid: ffffffff" hasStroke="0" text="to"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="148 276 27 30" fill="solid: ffffffff" hasStroke="0" text="to"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="39 60 81 26" fill="solid: ffffffff" hasStroke="0" text="Amplitude"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="132 60 84 26" fill="solid: ffffffff" hasStroke="0" text="Frequency"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="28 20 380 30" fill="solid: ffffffff" hasStroke="0" text="Graph Property Settings Demo"
          fontname="Default font" fontsize="26.0" kerning="0.0" bold="1"
          italic="0" justification="9" typefaceStyle="Bold"/>
    <TEXT pos="36 212 96 30" fill="solid: ffffffff" hasStroke="0" text="&#9632; Axes Setting"
          fontname="Default font" fontsize="16.5" kerning="0.0" bold="0"
          italic="0" justification="33"/>
    <TEXT pos="36 244 60 28" fill="solid: ffffffff" hasStroke="0" text="X Range"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="36 276 60 28" fill="solid: ffffffff" hasStroke="0" text="Y Range"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="36 308 60 28" fill="solid: ffffffff" hasStroke="0" text="X Label"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="34"/>
    <TEXT pos="36 340 60 28" fill="solid: ffffffff" hasStroke="0" text="Y Label"
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
    <RECT pos="16 412 960 316" fill="solid: ff0e174a" hasStroke="0"/>
    <TEXT pos="44 420 252 30" fill="solid: ffffffff" hasStroke="0" text="Real-time Plot Demo"
          fontname="Default font" fontsize="26.0" kerning="0.0" bold="1"
          italic="0" justification="33" typefaceStyle="Bold"/>
    <TEXT pos="188 148 36 36" fill="solid: ffffffff" hasStroke="0" text="Hz"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <TEXTEDITOR name="xMin_textEditor" id="f941bb328e2f390d" memberName="xMin_textEditor"
              virtualName="" explicitFocusOrder="0" pos="104 246 41 24" initialText="1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="xMax_textEditor" id="b4f71c7914e65be5" memberName="xMax_textEditor"
              virtualName="" explicitFocusOrder="0" pos="176 246 40 24" initialText="1024"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="yMin_textEditor" id="49f57f76be8556a0" memberName="yMin_textEditor"
              virtualName="" explicitFocusOrder="0" pos="104 278 41 24" initialText="-1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="yMax_textEditor" id="3ba879aa96ca1f20" memberName="yMax_textEditor"
              virtualName="" explicitFocusOrder="0" pos="176 278 40 24" initialText="1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <GENERICCOMPONENT name="" id="8ceb0d0631a92e5c" memberName="PropertySetting_figure"
                    virtualName="" explicitFocusOrder="0" pos="440 40 512 328" class="Figure"
                    params=""/>
  <SLIDER name="amplitude_slider" id="ff7cc6f6cc561f98" memberName="amplitude_slider"
          virtualName="" explicitFocusOrder="0" pos="39 88 81 88" rotarysliderfill="ff29667e"
          rotaryslideroutline="ff495e68" min="0.1" max="1.0" int="0.1"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTEDITOR name="XLabel_textEditor" id="e27c0ac7c91370c6" memberName="XLabel_textEditor"
              virtualName="" explicitFocusOrder="0" pos="104 310 112 24" initialText="Sample"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="YLabel_textEditor" id="b82d3d7406b6b50a" memberName="YLabel_textEditor"
              virtualName="" explicitFocusOrder="0" pos="104 344 112 22" initialText="Amplitude"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="top_textEditor" id="86eb18733c2acfeb" memberName="top_textEditor"
              virtualName="" explicitFocusOrder="0" pos="328 280 48 24" initialText="20"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="bottom_textEditor" id="72a30d9145af3c5e" memberName="bottom_textEditor"
              virtualName="" explicitFocusOrder="0" pos="328 344 48 24" initialText="40"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="Left_textEditor" id="ee300c2614b1ab13" memberName="Left_textEditor"
              virtualName="" explicitFocusOrder="0" pos="328 248 48 24" initialText="50"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="Right_textEditor" id="dc313dd49ccd0d9c" memberName="Right_textEditor"
              virtualName="" explicitFocusOrder="0" pos="328 312 48 24" initialText="20"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="buckgroundColour_button" id="bd650b13354e23c7" memberName="buckgroundColour_button"
              virtualName="" explicitFocusOrder="0" pos="328 88 88 24" bgColOff="ff000000"
              buttonText="FF000000" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="plotAriaColour_button" id="1697de2136a98347" memberName="plotAriaColour_button"
              virtualName="" explicitFocusOrder="0" pos="328 120 88 24" bgColOff="ff393643"
              buttonText="FF393643" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="gridColour_button" id="50f55b948ce42b7c" memberName="gridColour_button"
              virtualName="" explicitFocusOrder="0" pos="328 152 88 24" bgColOff="ffffffff"
              bgColOn="ffffffff" textCol="ff000000" buttonText="FFFFFFFF" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="fontColour_button" id="a3563fffb9c9422a" memberName="fontColour_button"
              virtualName="" explicitFocusOrder="0" pos="328 184 88 24" bgColOff="ffffffff"
              bgColOn="ffffffff" textCol="ff000000" buttonText="FFFFFFFF" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <GENERICCOMPONENT name="" id="3b2d7d4faa8bc38f" memberName="timeAxis_figure" virtualName=""
                    explicitFocusOrder="0" pos="48 464 440 224" class="Figure" params=""/>
  <GENERICCOMPONENT name="" id="a74a3abef4b0e258" memberName="freqAxis_figure" virtualName=""
                    explicitFocusOrder="0" pos="512 464 440 224" class="Figure" params=""/>
  <SLIDER name="freq_slider" id="bb03a2ac908aad6" memberName="freq_slider"
          virtualName="" explicitFocusOrder="0" pos="136 88 81 88" rotarysliderfill="ff29667e"
          rotaryslideroutline="ff495e68" min="20.0" max="15000.0" int="1.0"
          style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

