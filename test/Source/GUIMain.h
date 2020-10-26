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
#include "ColourSelectBox.h"
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
                 public juce::TextEditor::Listener,
                 public juce::Slider::Listener,
                 public juce::Button::Listener
{
public:
    //==============================================================================
    GUIMain ();
    ~GUIMain() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void addMicdata(float* data, int len);
    void timerCallback() override;

    void textEditorTextChanged (juce::TextEditor& textEditorThatWasReturnKeyPressed) override;

    enum
    {
        fftOrder = 10,
        fftSize  = 1 << fftOrder
    };
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    void drawWaves();

    int micDatasetIndex_;

    std::unique_ptr<dsp::FFT> forwardFFT_;
    float fifo_ [fftSize] = {};
    float fftData_ [2 * fftSize];
    int fifoIndex_ = 0;

    int Fs = 48000;
    
    std::unique_ptr<ColourSelectBox> colourSelector;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextEditor> xMin_textEditor;
    std::unique_ptr<juce::TextEditor> xMax_textEditor;
    std::unique_ptr<juce::TextEditor> yMin_textEditor;
    std::unique_ptr<juce::TextEditor> yMax_textEditor;
    std::unique_ptr<Figure> PropertySetting_figure;
    std::unique_ptr<juce::Slider> amplitude_slider;
    std::unique_ptr<juce::TextEditor> XLabel_textEditor;
    std::unique_ptr<juce::TextEditor> YLabel_textEditor;
    std::unique_ptr<juce::TextEditor> top_textEditor;
    std::unique_ptr<juce::TextEditor> bottom_textEditor;
    std::unique_ptr<juce::TextEditor> Left_textEditor;
    std::unique_ptr<juce::TextEditor> Right_textEditor;
    std::unique_ptr<juce::TextButton> buckgroundColour_button;
    std::unique_ptr<juce::TextButton> plotAriaColour_button;
    std::unique_ptr<juce::TextButton> gridColour_button;
    std::unique_ptr<juce::TextButton> fontColour_button;
    std::unique_ptr<Figure> timeAxis_figure;
    std::unique_ptr<Figure> freqAxis_figure;
    std::unique_ptr<juce::Slider> freq_slider;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUIMain)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

