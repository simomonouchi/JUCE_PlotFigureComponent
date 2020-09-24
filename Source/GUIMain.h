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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "Figure.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GUIMain  : public juce::Component,
                 private Timer,
                 public juce::Slider::Listener,
                 public juce::ComboBox::Listener,
                 public juce::Button::Listener
{
public:
    //==============================================================================
    GUIMain ();
    ~GUIMain() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void addGraph2Data(float sample);
    void update();
    void timerCallback() override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    int plotIdx_;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextEditor> xMin_textEditor;
    std::unique_ptr<juce::Label> xAxisRange_label;
    std::unique_ptr<juce::TextEditor> xLength_textEditor;
    std::unique_ptr<juce::TextEditor> yMin_textEditor;
    std::unique_ptr<juce::Label> yAxisRange_label;
    std::unique_ptr<juce::TextEditor> yLength_textEditor;
    std::unique_ptr<Figure> graph;
    std::unique_ptr<Figure> graph2;
    std::unique_ptr<juce::Slider> juce__slider;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::Slider> juce__slider2;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::Label> deawWavelabel;
    std::unique_ptr<juce::Label> deawWavelabel3;
    std::unique_ptr<juce::ComboBox> WaveFormcomboBox;
    std::unique_ptr<juce::Label> yAxisRange_label3;
    std::unique_ptr<juce::Label> yAxisRange_label4;
    std::unique_ptr<juce::TextEditor> yMin_textEditor3;
    std::unique_ptr<juce::TextEditor> yMin_textEditor4;
    std::unique_ptr<juce::Label> yAxisRange_label5;
    std::unique_ptr<juce::TextEditor> yMin_textEditor5;
    std::unique_ptr<juce::Label> yAxisRange_label6;
    std::unique_ptr<juce::TextEditor> yMin_textEditor6;
    std::unique_ptr<juce::Label> yAxisRange_label7;
    std::unique_ptr<juce::TextEditor> yMin_textEditor7;
    std::unique_ptr<juce::Label> yAxisRange_label8;
    std::unique_ptr<juce::TextEditor> yMin_textEditor8;
    std::unique_ptr<juce::Label> yAxisRange_label9;
    std::unique_ptr<juce::TextButton> juce__textButton;
    std::unique_ptr<juce::Label> juce__label3;
    std::unique_ptr<juce::Label> juce__label4;
    std::unique_ptr<juce::Label> yAxisRange_label10;
    std::unique_ptr<juce::TextButton> juce__textButton2;
    std::unique_ptr<juce::Label> yAxisRange_label11;
    std::unique_ptr<juce::TextButton> juce__textButton3;
    std::unique_ptr<juce::Label> juce__label5;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUIMain)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

