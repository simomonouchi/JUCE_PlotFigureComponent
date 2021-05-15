//
//  Selector.h
//  PlotFigureComponentTest - App
//
//  Created by Ryota Shimokawara on 2020/09/27.
//

#pragma once

class Selector :
    public juce::Component,
    public juce::ChangeListener
{
public:
    Selector(const juce::Colour& colour) :
        selector(juce::ColourSelector::showColourspace | juce::ColourSelector::showAlphaChannel, 0, 0)
    {
        selector.setCurrentColour(colour);
        selector.addChangeListener(this);
        addAndMakeVisible(selector);
    
        setSize(200, 200);
    }
        
public:
    std::function<void(const juce::Colour&)> onChange;
        
private:
    void changeListenerCallback(juce::ChangeBroadcaster* source) final
    {
        if (onChange)
            onChange(selector.getCurrentColour());
    }
        
    void resized() final
    {
        selector.setBounds(getLocalBounds());
    }
    
private:
    juce::ColourSelector selector;
};
