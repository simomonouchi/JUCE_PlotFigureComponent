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

    xMin_textEditor.reset (new juce::TextEditor ("xMin text editor"));
    addAndMakeVisible (xMin_textEditor.get());
    xMin_textEditor->setMultiLine (false);
    xMin_textEditor->setReturnKeyStartsNewLine (false);
    xMin_textEditor->setReadOnly (false);
    xMin_textEditor->setScrollbarsShown (true);
    xMin_textEditor->setCaretVisible (true);
    xMin_textEditor->setPopupMenuEnabled (true);
    xMin_textEditor->setText (TRANS("0"));

    xMin_textEditor->setBounds (484, 588, 44, 24);

    xAxisRange_label.reset (new juce::Label ("xAxisRange_label",
                                             TRANS("X Range")));
    addAndMakeVisible (xAxisRange_label.get());
    xAxisRange_label->setFont (juce::Font (juce::Font::getDefaultMonospacedFontName(), 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    xAxisRange_label->setJustificationType (juce::Justification::centredRight);
    xAxisRange_label->setEditable (false, false, false);
    xAxisRange_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    xAxisRange_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    xAxisRange_label->setBounds (407, 588, 72, 24);

    xLength_textEditor.reset (new juce::TextEditor ("xLength test editor"));
    addAndMakeVisible (xLength_textEditor.get());
    xLength_textEditor->setMultiLine (false);
    xLength_textEditor->setReturnKeyStartsNewLine (false);
    xLength_textEditor->setReadOnly (false);
    xLength_textEditor->setScrollbarsShown (true);
    xLength_textEditor->setCaretVisible (true);
    xLength_textEditor->setPopupMenuEnabled (true);
    xLength_textEditor->setText (TRANS("8012"));

    xLength_textEditor->setBounds (560, 588, 43, 24);

    yMin_textEditor.reset (new juce::TextEditor ("yMin text editor"));
    addAndMakeVisible (yMin_textEditor.get());
    yMin_textEditor->setMultiLine (false);
    yMin_textEditor->setReturnKeyStartsNewLine (false);
    yMin_textEditor->setReadOnly (false);
    yMin_textEditor->setScrollbarsShown (true);
    yMin_textEditor->setCaretVisible (true);
    yMin_textEditor->setPopupMenuEnabled (true);
    yMin_textEditor->setText (TRANS("-1"));

    yMin_textEditor->setBounds (484, 615, 44, 24);

    yAxisRange_label.reset (new juce::Label ("yAxisRange_label",
                                             TRANS("Y Range")));
    addAndMakeVisible (yAxisRange_label.get());
    yAxisRange_label->setFont (juce::Font (juce::Font::getDefaultMonospacedFontName(), 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    yAxisRange_label->setJustificationType (juce::Justification::centredRight);
    yAxisRange_label->setEditable (false, false, false);
    yAxisRange_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    yAxisRange_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    yAxisRange_label->setBounds (407, 615, 72, 24);

    yLength_textEditor.reset (new juce::TextEditor ("yLength text editor"));
    addAndMakeVisible (yLength_textEditor.get());
    yLength_textEditor->setMultiLine (false);
    yLength_textEditor->setReturnKeyStartsNewLine (false);
    yLength_textEditor->setReadOnly (false);
    yLength_textEditor->setScrollbarsShown (true);
    yLength_textEditor->setCaretVisible (true);
    yLength_textEditor->setPopupMenuEnabled (true);
    yLength_textEditor->setText (TRANS("1"));

    yLength_textEditor->setBounds (560, 615, 43, 24);

    graph.reset (new Figure());
    addAndMakeVisible (graph.get());

    graph->setBounds (302, 64, 656, 208);

    graph2.reset (new Figure());
    addAndMakeVisible (graph2.get());

    graph2->setBounds (301, 352, 656, 208);

    juce__slider.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__slider.get());
    juce__slider->setRange (0.1, 1, 0.1);
    juce__slider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    juce__slider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider->addListener (this);

    juce__slider->setBounds (55, 168, 72, 96);

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("Amplitude")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (juce::Font::getDefaultMonospacedFontName(), 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centred);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (48, 144, 87, 24);

    juce__slider2.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (juce__slider2.get());
    juce__slider2->setRange (20, 15000, 10);
    juce__slider2->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    juce__slider2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    juce__slider2->addListener (this);

    juce__slider2->setBounds (162, 168, 72, 96);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("Frequency")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (juce::Font::getDefaultMonospacedFontName(), 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centred);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (144, 144, 104, 24);

    deawWavelabel.reset (new juce::Label ("deawWavelabel",
                                          TRANS("Draw Wave Demo")));
    addAndMakeVisible (deawWavelabel.get());
    deawWavelabel->setFont (juce::Font (juce::Font::getDefaultSansSerifFontName(), 24.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    deawWavelabel->setJustificationType (juce::Justification::centredLeft);
    deawWavelabel->setEditable (false, false, false);
    deawWavelabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    deawWavelabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    deawWavelabel->setBounds (40, 40, 240, 24);

    deawWavelabel3.reset (new juce::Label ("deawWavelabel",
                                           TRANS("Set Graph Property Demo")));
    addAndMakeVisible (deawWavelabel3.get());
    deawWavelabel3->setFont (juce::Font (juce::Font::getDefaultSansSerifFontName(), 24.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    deawWavelabel3->setJustificationType (juce::Justification::centredLeft);
    deawWavelabel3->setEditable (false, false, false);
    deawWavelabel3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    deawWavelabel3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    deawWavelabel3->setBounds (48, 320, 304, 24);

    WaveFormcomboBox.reset (new juce::ComboBox ("WaveFormcomboBox"));
    addAndMakeVisible (WaveFormcomboBox.get());
    WaveFormcomboBox->setEditableText (true);
    WaveFormcomboBox->setJustificationType (juce::Justification::centredLeft);
    WaveFormcomboBox->setTextWhenNothingSelected (juce::String());
    WaveFormcomboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    WaveFormcomboBox->addItem (TRANS("Sin"), 1);
    WaveFormcomboBox->addItem (TRANS("Cos"), 2);
    WaveFormcomboBox->addItem (TRANS("Triangle"), 3);
    WaveFormcomboBox->addItem (TRANS("Rectangle"), 4);
    WaveFormcomboBox->addListener (this);

    WaveFormcomboBox->setBounds (64, 88, 150, 24);

    yAxisRange_label3.reset (new juce::Label ("yAxisRange_label",
                                              TRANS("X Label")));
    addAndMakeVisible (yAxisRange_label3.get());
    yAxisRange_label3->setFont (juce::Font (juce::Font::getDefaultMonospacedFontName(), 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    yAxisRange_label3->setJustificationType (juce::Justification::centredRight);
    yAxisRange_label3->setEditable (false, false, false);
    yAxisRange_label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    yAxisRange_label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    yAxisRange_label3->setBounds (407, 639, 72, 24);

    yAxisRange_label4.reset (new juce::Label ("yAxisRange_label",
                                              TRANS("Y Label")));
    addAndMakeVisible (yAxisRange_label4.get());
    yAxisRange_label4->setFont (juce::Font (juce::Font::getDefaultMonospacedFontName(), 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    yAxisRange_label4->setJustificationType (juce::Justification::centredRight);
    yAxisRange_label4->setEditable (false, false, false);
    yAxisRange_label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    yAxisRange_label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    yAxisRange_label4->setBounds (407, 666, 72, 24);

    yMin_textEditor3.reset (new juce::TextEditor ("yMin text editor"));
    addAndMakeVisible (yMin_textEditor3.get());
    yMin_textEditor3->setMultiLine (false);
    yMin_textEditor3->setReturnKeyStartsNewLine (false);
    yMin_textEditor3->setReadOnly (false);
    yMin_textEditor3->setScrollbarsShown (true);
    yMin_textEditor3->setCaretVisible (true);
    yMin_textEditor3->setPopupMenuEnabled (true);
    yMin_textEditor3->setText (TRANS("Amplitude"));

    yMin_textEditor3->setBounds (483, 641, 120, 24);

    yMin_textEditor4.reset (new juce::TextEditor ("yMin text editor"));
    addAndMakeVisible (yMin_textEditor4.get());
    yMin_textEditor4->setMultiLine (false);
    yMin_textEditor4->setReturnKeyStartsNewLine (false);
    yMin_textEditor4->setReadOnly (false);
    yMin_textEditor4->setScrollbarsShown (true);
    yMin_textEditor4->setCaretVisible (true);
    yMin_textEditor4->setPopupMenuEnabled (true);
    yMin_textEditor4->setText (TRANS("Sample"));

    yMin_textEditor4->setBounds (483, 667, 120, 24);

    yAxisRange_label5.reset (new juce::Label ("yAxisRange_label",
                                              TRANS("Top")));
    addAndMakeVisible (yAxisRange_label5.get());
    yAxisRange_label5->setFont (juce::Font (juce::Font::getDefaultMonospacedFontName(), 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    yAxisRange_label5->setJustificationType (juce::Justification::centredRight);
    yAxisRange_label5->setEditable (false, false, false);
    yAxisRange_label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    yAxisRange_label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    yAxisRange_label5->setBounds (834, 592, 63, 24);

    yMin_textEditor5.reset (new juce::TextEditor ("yMin text editor"));
    addAndMakeVisible (yMin_textEditor5.get());
    yMin_textEditor5->setMultiLine (false);
    yMin_textEditor5->setReturnKeyStartsNewLine (false);
    yMin_textEditor5->setReadOnly (false);
    yMin_textEditor5->setScrollbarsShown (true);
    yMin_textEditor5->setCaretVisible (true);
    yMin_textEditor5->setPopupMenuEnabled (true);
    yMin_textEditor5->setText (TRANS("10"));

    yMin_textEditor5->setBounds (903, 592, 47, 24);

    yAxisRange_label6.reset (new juce::Label ("yAxisRange_label",
                                              TRANS("Bottom")));
    addAndMakeVisible (yAxisRange_label6.get());
    yAxisRange_label6->setFont (juce::Font (juce::Font::getDefaultMonospacedFontName(), 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    yAxisRange_label6->setJustificationType (juce::Justification::centredRight);
    yAxisRange_label6->setEditable (false, false, false);
    yAxisRange_label6->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    yAxisRange_label6->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    yAxisRange_label6->setBounds (834, 618, 63, 24);

    yMin_textEditor6.reset (new juce::TextEditor ("yMin text editor"));
    addAndMakeVisible (yMin_textEditor6.get());
    yMin_textEditor6->setMultiLine (false);
    yMin_textEditor6->setReturnKeyStartsNewLine (false);
    yMin_textEditor6->setReadOnly (false);
    yMin_textEditor6->setScrollbarsShown (true);
    yMin_textEditor6->setCaretVisible (true);
    yMin_textEditor6->setPopupMenuEnabled (true);
    yMin_textEditor6->setText (TRANS("10"));

    yMin_textEditor6->setBounds (903, 618, 47, 24);

    yAxisRange_label7.reset (new juce::Label ("yAxisRange_label",
                                              TRANS("Left")));
    addAndMakeVisible (yAxisRange_label7.get());
    yAxisRange_label7->setFont (juce::Font (juce::Font::getDefaultMonospacedFontName(), 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    yAxisRange_label7->setJustificationType (juce::Justification::centredRight);
    yAxisRange_label7->setEditable (false, false, false);
    yAxisRange_label7->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    yAxisRange_label7->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    yAxisRange_label7->setBounds (834, 643, 63, 23);

    yMin_textEditor7.reset (new juce::TextEditor ("yMin text editor"));
    addAndMakeVisible (yMin_textEditor7.get());
    yMin_textEditor7->setMultiLine (false);
    yMin_textEditor7->setReturnKeyStartsNewLine (false);
    yMin_textEditor7->setReadOnly (false);
    yMin_textEditor7->setScrollbarsShown (true);
    yMin_textEditor7->setCaretVisible (true);
    yMin_textEditor7->setPopupMenuEnabled (true);
    yMin_textEditor7->setText (TRANS("10"));

    yMin_textEditor7->setBounds (903, 643, 47, 24);

    yAxisRange_label8.reset (new juce::Label ("yAxisRange_label",
                                              TRANS("Right")));
    addAndMakeVisible (yAxisRange_label8.get());
    yAxisRange_label8->setFont (juce::Font (juce::Font::getDefaultMonospacedFontName(), 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    yAxisRange_label8->setJustificationType (juce::Justification::centredRight);
    yAxisRange_label8->setEditable (false, false, false);
    yAxisRange_label8->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    yAxisRange_label8->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    yAxisRange_label8->setBounds (834, 668, 63, 24);

    yMin_textEditor8.reset (new juce::TextEditor ("yMin text editor"));
    addAndMakeVisible (yMin_textEditor8.get());
    yMin_textEditor8->setMultiLine (false);
    yMin_textEditor8->setReturnKeyStartsNewLine (false);
    yMin_textEditor8->setReadOnly (false);
    yMin_textEditor8->setScrollbarsShown (true);
    yMin_textEditor8->setCaretVisible (true);
    yMin_textEditor8->setPopupMenuEnabled (true);
    yMin_textEditor8->setText (TRANS("10"));

    yMin_textEditor8->setBounds (903, 668, 47, 24);

    yAxisRange_label9.reset (new juce::Label ("yAxisRange_label",
                                              TRANS("Background")));
    addAndMakeVisible (yAxisRange_label9.get());
    yAxisRange_label9->setFont (juce::Font (juce::Font::getDefaultMonospacedFontName(), 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    yAxisRange_label9->setJustificationType (juce::Justification::centredRight);
    yAxisRange_label9->setEditable (false, false, false);
    yAxisRange_label9->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    yAxisRange_label9->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    yAxisRange_label9->setBounds (644, 591, 83, 23);

    juce__textButton.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (juce__textButton.get());
    juce__textButton->setButtonText (TRANS("FF000000"));
    juce__textButton->addListener (this);
    juce__textButton->setColour (juce::TextButton::buttonColourId, juce::Colours::black);

    juce__textButton->setBounds (732, 592, 80, 23);

    juce__label3.reset (new juce::Label ("new label",
                                         TRANS("Padding")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label3->setJustificationType (juce::Justification::centredLeft);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::Label::backgroundColourId, juce::Colour (0x00000000));
    juce__label3->setColour (juce::Label::textColourId, juce::Colours::white);
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3->setBounds (840, 568, 114, 16);

    juce__label4.reset (new juce::Label ("new label",
                                         TRANS("Colours")));
    addAndMakeVisible (juce__label4.get());
    juce__label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label4->setJustificationType (juce::Justification::centredLeft);
    juce__label4->setEditable (false, false, false);
    juce__label4->setColour (juce::Label::backgroundColourId, juce::Colour (0x00000000));
    juce__label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label4->setBounds (652, 568, 152, 16);

    yAxisRange_label10.reset (new juce::Label ("yAxisRange_label",
                                               TRANS("Plot Aria\n")));
    addAndMakeVisible (yAxisRange_label10.get());
    yAxisRange_label10->setFont (juce::Font (juce::Font::getDefaultMonospacedFontName(), 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    yAxisRange_label10->setJustificationType (juce::Justification::centredRight);
    yAxisRange_label10->setEditable (false, false, false);
    yAxisRange_label10->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    yAxisRange_label10->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    yAxisRange_label10->setBounds (644, 616, 83, 23);

    juce__textButton2.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (juce__textButton2.get());
    juce__textButton2->setButtonText (TRANS("FF000000"));
    juce__textButton2->addListener (this);
    juce__textButton2->setColour (juce::TextButton::buttonColourId, juce::Colours::black);

    juce__textButton2->setBounds (732, 617, 80, 23);

    yAxisRange_label11.reset (new juce::Label ("yAxisRange_label",
                                               TRANS("Font")));
    addAndMakeVisible (yAxisRange_label11.get());
    yAxisRange_label11->setFont (juce::Font (juce::Font::getDefaultMonospacedFontName(), 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    yAxisRange_label11->setJustificationType (juce::Justification::centredRight);
    yAxisRange_label11->setEditable (false, false, false);
    yAxisRange_label11->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    yAxisRange_label11->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    yAxisRange_label11->setBounds (644, 640, 83, 23);

    juce__textButton3.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (juce__textButton3.get());
    juce__textButton3->setButtonText (TRANS("FF000000"));
    juce__textButton3->addListener (this);
    juce__textButton3->setColour (juce::TextButton::buttonColourId, juce::Colours::black);

    juce__textButton3->setBounds (732, 641, 80, 23);

    juce__label5.reset (new juce::Label ("new label",
                                         TRANS("Axes Settings\n")));
    addAndMakeVisible (juce__label5.get());
    juce__label5->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label5->setJustificationType (juce::Justification::centredLeft);
    juce__label5->setEditable (false, false, false);
    juce__label5->setColour (juce::Label::backgroundColourId, juce::Colour (0x00000000));
    juce__label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label5->setBounds (408, 567, 192, 16);


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

    xMin_textEditor = nullptr;
    xAxisRange_label = nullptr;
    xLength_textEditor = nullptr;
    yMin_textEditor = nullptr;
    yAxisRange_label = nullptr;
    yLength_textEditor = nullptr;
    graph = nullptr;
    graph2 = nullptr;
    juce__slider = nullptr;
    juce__label = nullptr;
    juce__slider2 = nullptr;
    juce__label2 = nullptr;
    deawWavelabel = nullptr;
    deawWavelabel3 = nullptr;
    WaveFormcomboBox = nullptr;
    yAxisRange_label3 = nullptr;
    yAxisRange_label4 = nullptr;
    yMin_textEditor3 = nullptr;
    yMin_textEditor4 = nullptr;
    yAxisRange_label5 = nullptr;
    yMin_textEditor5 = nullptr;
    yAxisRange_label6 = nullptr;
    yMin_textEditor6 = nullptr;
    yAxisRange_label7 = nullptr;
    yMin_textEditor7 = nullptr;
    yAxisRange_label8 = nullptr;
    yMin_textEditor8 = nullptr;
    yAxisRange_label9 = nullptr;
    juce__textButton = nullptr;
    juce__label3 = nullptr;
    juce__label4 = nullptr;
    yAxisRange_label10 = nullptr;
    juce__textButton2 = nullptr;
    yAxisRange_label11 = nullptr;
    juce__textButton3 = nullptr;
    juce__label5 = nullptr;


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
        int x = 20, y = 28, width = 948, height = 260;
        juce::Colour fillColour = juce::Colour (0xff705555);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 20, y = 308, width = 948, height = 396;
        juce::Colour fillColour = juce::Colour (0xff293125);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 529, y = 580, width = 27, height = 30;
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
        int x = 529, y = 612, width = 27, height = 30;
        juce::String text (TRANS("to"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    graph->paint(g);
    graph2->paint(g);
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

    if (sliderThatWasMoved == juce__slider.get())
    {
        //[UserSliderCode_juce__slider] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider]
    }
    else if (sliderThatWasMoved == juce__slider2.get())
    {
        //[UserSliderCode_juce__slider2] -- add your slider handling code here..
        //[/UserSliderCode_juce__slider2]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void GUIMain::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == WaveFormcomboBox.get())
    {
        //[UserComboBoxCode_WaveFormcomboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_WaveFormcomboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void GUIMain::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == juce__textButton.get())
    {
        //[UserButtonCode_juce__textButton] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton]
    }
    else if (buttonThatWasClicked == juce__textButton2.get())
    {
        //[UserButtonCode_juce__textButton2] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton2]
    }
    else if (buttonThatWasClicked == juce__textButton3.get())
    {
        //[UserButtonCode_juce__textButton3] -- add your button handler code here..
        //[/UserButtonCode_juce__textButton3]
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
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="20 28 948 260" fill="solid: ff705555" hasStroke="0"/>
    <RECT pos="20 308 948 396" fill="solid: ff293125" hasStroke="0"/>
    <TEXT pos="529 580 27 30" fill="solid: ffffffff" hasStroke="0" text="to"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="529 612 27 30" fill="solid: ffffffff" hasStroke="0" text="to"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <TEXTEDITOR name="xMin text editor" id="f941bb328e2f390d" memberName="xMin_textEditor"
              virtualName="" explicitFocusOrder="0" pos="484 588 44 24" initialText="0"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="xAxisRange_label" id="966671ee3d2a3db" memberName="xAxisRange_label"
         virtualName="" explicitFocusOrder="0" pos="407 588 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="X Range" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="xLength test editor" id="b4f71c7914e65be5" memberName="xLength_textEditor"
              virtualName="" explicitFocusOrder="0" pos="560 588 43 24" initialText="8012"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="yMin text editor" id="49f57f76be8556a0" memberName="yMin_textEditor"
              virtualName="" explicitFocusOrder="0" pos="484 615 44 24" initialText="-1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="yAxisRange_label" id="2823c97f876b5e44" memberName="yAxisRange_label"
         virtualName="" explicitFocusOrder="0" pos="407 615 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Y Range" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="yLength text editor" id="3ba879aa96ca1f20" memberName="yLength_textEditor"
              virtualName="" explicitFocusOrder="0" pos="560 615 43 24" initialText="1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <GENERICCOMPONENT name="" id="8ceb0d0631a92e5c" memberName="graph" virtualName=""
                    explicitFocusOrder="0" pos="302 64 656 208" class="Figure" params=""/>
  <GENERICCOMPONENT name="" id="81c68bb0d1ac7024" memberName="graph2" virtualName=""
                    explicitFocusOrder="0" pos="301 352 656 208" class="Figure" params=""/>
  <SLIDER name="new slider" id="ff7cc6f6cc561f98" memberName="juce__slider"
          virtualName="" explicitFocusOrder="0" pos="55 168 72 96" min="0.1"
          max="1.0" int="0.1" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="e1ff519d66529079" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="48 144 87 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Amplitude" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="1c5d4c4c554bb235" memberName="juce__slider2"
          virtualName="" explicitFocusOrder="0" pos="162 168 72 96" min="20.0"
          max="15000.0" int="10.0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="new label" id="bcd97c36040d4f68" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="144 144 104 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Frequency" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="deawWavelabel" id="1468e582707cdc13" memberName="deawWavelabel"
         virtualName="" explicitFocusOrder="0" pos="40 40 240 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Draw Wave Demo" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="24.0" kerning="0.0" bold="1" italic="0" justification="33"
         typefaceStyle="Bold"/>
  <LABEL name="deawWavelabel" id="d07c3f5e300663ee" memberName="deawWavelabel3"
         virtualName="" explicitFocusOrder="0" pos="48 320 304 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Set Graph Property Demo" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="24.0" kerning="0.0" bold="1" italic="0" justification="33"
         typefaceStyle="Bold"/>
  <COMBOBOX name="WaveFormcomboBox" id="27264d42774e190c" memberName="WaveFormcomboBox"
            virtualName="" explicitFocusOrder="0" pos="64 88 150 24" editable="1"
            layout="33" items="Sin&#10;Cos&#10;Triangle&#10;Rectangle" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="yAxisRange_label" id="e45600ad4f73a719" memberName="yAxisRange_label3"
         virtualName="" explicitFocusOrder="0" pos="407 639 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="X Label" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <LABEL name="yAxisRange_label" id="a7e6b1a7c6a1a76d" memberName="yAxisRange_label4"
         virtualName="" explicitFocusOrder="0" pos="407 666 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Y Label" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="yMin text editor" id="e27c0ac7c91370c6" memberName="yMin_textEditor3"
              virtualName="" explicitFocusOrder="0" pos="483 641 120 24" initialText="Amplitude"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="yMin text editor" id="b82d3d7406b6b50a" memberName="yMin_textEditor4"
              virtualName="" explicitFocusOrder="0" pos="483 667 120 24" initialText="Sample"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="yAxisRange_label" id="a2cb63820e4328b6" memberName="yAxisRange_label5"
         virtualName="" explicitFocusOrder="0" pos="834 592 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Top" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="yMin text editor" id="86eb18733c2acfeb" memberName="yMin_textEditor5"
              virtualName="" explicitFocusOrder="0" pos="903 592 47 24" initialText="10"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="yAxisRange_label" id="32ad7c97f1db29fa" memberName="yAxisRange_label6"
         virtualName="" explicitFocusOrder="0" pos="834 618 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Bottom" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="yMin text editor" id="72a30d9145af3c5e" memberName="yMin_textEditor6"
              virtualName="" explicitFocusOrder="0" pos="903 618 47 24" initialText="10"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="yAxisRange_label" id="92ad1b022fc0d78c" memberName="yAxisRange_label7"
         virtualName="" explicitFocusOrder="0" pos="834 643 63 23" edTextCol="ff000000"
         edBkgCol="0" labelText="Left" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="yMin text editor" id="ee300c2614b1ab13" memberName="yMin_textEditor7"
              virtualName="" explicitFocusOrder="0" pos="903 643 47 24" initialText="10"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="yAxisRange_label" id="baa8535bb446b2bd" memberName="yAxisRange_label8"
         virtualName="" explicitFocusOrder="0" pos="834 668 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Right" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTEDITOR name="yMin text editor" id="dc313dd49ccd0d9c" memberName="yMin_textEditor8"
              virtualName="" explicitFocusOrder="0" pos="903 668 47 24" initialText="10"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="yAxisRange_label" id="544c2c24ed3dcdda" memberName="yAxisRange_label9"
         virtualName="" explicitFocusOrder="0" pos="644 591 83 23" edTextCol="ff000000"
         edBkgCol="0" labelText="Background" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTBUTTON name="new button" id="bd650b13354e23c7" memberName="juce__textButton"
              virtualName="" explicitFocusOrder="0" pos="732 592 80 23" bgColOff="ff000000"
              buttonText="FF000000" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="536e2b6ea0cabbed" memberName="juce__label3"
         virtualName="" explicitFocusOrder="0" pos="840 568 114 16" bkgCol="0"
         textCol="ffffffff" edTextCol="ff000000" edBkgCol="0" labelText="Padding"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <LABEL name="new label" id="7561501216b6dac2" memberName="juce__label4"
         virtualName="" explicitFocusOrder="0" pos="652 568 152 16" bkgCol="0"
         edTextCol="ff000000" edBkgCol="0" labelText="Colours" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="yAxisRange_label" id="17de61a38f0faff4" memberName="yAxisRange_label10"
         virtualName="" explicitFocusOrder="0" pos="644 616 83 23" edTextCol="ff000000"
         edBkgCol="0" labelText="Plot Aria&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default monospaced font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTBUTTON name="new button" id="1697de2136a98347" memberName="juce__textButton2"
              virtualName="" explicitFocusOrder="0" pos="732 617 80 23" bgColOff="ff000000"
              buttonText="FF000000" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="yAxisRange_label" id="e7d706a325205f63" memberName="yAxisRange_label11"
         virtualName="" explicitFocusOrder="0" pos="644 640 83 23" edTextCol="ff000000"
         edBkgCol="0" labelText="Font" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default monospaced font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="34"/>
  <TEXTBUTTON name="new button" id="50f55b948ce42b7c" memberName="juce__textButton3"
              virtualName="" explicitFocusOrder="0" pos="732 641 80 23" bgColOff="ff000000"
              buttonText="FF000000" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="7f1ba1f8a1e395c7" memberName="juce__label5"
         virtualName="" explicitFocusOrder="0" pos="408 567 192 16" bkgCol="0"
         edTextCol="ff000000" edBkgCol="0" labelText="Axes Settings&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

