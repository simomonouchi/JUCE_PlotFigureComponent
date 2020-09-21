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
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    int plotIdx_;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> juce__textButton;
    std::unique_ptr<juce::TextEditor> xMin_textEditor;
    std::unique_ptr<juce::Label> xMin_label;
    std::unique_ptr<juce::Label> xLength_label;
    std::unique_ptr<juce::TextEditor> xLength_textEditor;
    std::unique_ptr<juce::TextEditor> yMin_textEditor;
    std::unique_ptr<juce::Label> yMin_label;
    std::unique_ptr<juce::TextEditor> yLength_textEditor;
    std::unique_ptr<juce::Label> yLength_label;
    std::unique_ptr<Figure> graph;
    std::unique_ptr<Figure> graph2;
    std::unique_ptr<Figure> graph3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUIMain)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

