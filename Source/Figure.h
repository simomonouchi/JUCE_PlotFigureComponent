/*
  ==============================================================================

    SourceCode.h
    Created: 12 Sep 2020 10:57:26pm
    Author:  Ryota Shimokawara

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class PlotDataset
{
public:
    PlotDataset(float* x, float* y, int len);
    PlotDataset(float* y, int len);
    PlotDataset();
    void add(float y);
    void add(float x, float y);
    void clear();
    ~PlotDataset();
    
    struct PlotPoints
    {
        float x;
        float y;
        LinkedListPointer<PlotPoints> nextListItem;
    };

    /* Setter */
    inline void setLineColour(Colour lineColour) noexcept { lineColour_ = lineColour; };
    inline void setMarkerColour(Colour markerColour) noexcept { markerColour_ = markerColour; };
    
    /* Getter */
    inline Colour getLineColour() const noexcept { return lineColour_; };
    inline Colour getMarkerColour() const noexcept { return markerColour_; };
    
public:
    LinkedListPointer<PlotDataset> nextListItem;
    LinkedListPointer<PlotPoints> points;
    
private:
    Colour lineColour_ = Colours::orange;
    Colour markerColour_ = Colours::orange;
};

//==============================================================================

class Figure : public juce::Component
{
public:
    Figure();
    Figure(Rectangle<int> graphAria);
    ~Figure() override;

//==============================================================================

    void paint(Graphics& g) override;
    void resized() override;
    void setBounds(int x, int y, int width, int height);
    
    void addDataSet(float* y, int len);
    void addDataSet(float* x, float* y, int len);
    
    int creatreDataSet();
    void addPoint(float y, int idx);
    void addPoint(float x, float y, int idx);
    void clear();
    
    enum class Markers
    {
        none,
        square,
        circle,
    };
    
    using Padding = struct {
        int left;
        int top;
        int right;
        int bottom;
    };
    
//==============================================================================
    /* Setter */
    inline void setBackgroundColour(Colour backGroungColour) noexcept {backGroungColour_ = backGroungColour;}
    inline void setFigureColour(Colour figureColour) noexcept { plotAriaColour_ = figureColour; }
    inline void setFontSize(float fontSize) noexcept { fontSize_ = fontSize; }
    inline void setTitle(String title) noexcept { title_ = title; }
    inline void setXLabel(String xLabel) noexcept { xLabel_ = xLabel; }
    inline void setYLabel(String yLabel) noexcept { yLabel_ = yLabel; }
    inline void setXRange(Range<float> xRange) noexcept
    {
        XRange_ = xRange;
        autoSettingXAxisRange_ = false;
    }
    inline void setYRange(Range<float> yRange) noexcept
    {
        YRange_ = yRange;
        autoSettingYAxisRange_ = false;
    }
    
    inline void setPadding(Padding padding) noexcept
    {
        padding_ = padding;
        setPlotAriaBounds();
    }
    inline void setMaxBufferingSize(int maxBufferingSize) noexcept {
        maxBufferingSize_ = maxBufferingSize;
    }
    inline void setMarker(Markers marker) noexcept {marker_ = marker;}
    inline void setPlotAriaColour(Colour newColour) noexcept {plotAriaColour_ = newColour;}
    inline void setBackGroungColour(Colour newColour) noexcept {plotAriaColour_ = newColour;}
    inline void setFontColour(Colour newColour) noexcept {fontColour_ = newColour;}
    inline void setGridColour(Colour newColour) noexcept {gridColour_ = newColour;}
    
    /* Getter */
    inline Padding getPadding() const noexcept { return padding_; }
    inline Colour getBackgroundColour()const noexcept { return backGroungColour_; }
    inline Colour getPlotAriaColour()const noexcept { return plotAriaColour_; }
    inline Colour getFontColour()const noexcept { return fontColour_; }
    inline Colour getGridColour() const noexcept { return gridColour_;}
 
/* Private Methods */
private:
    void setPlotAriaBounds() noexcept;
    
/* Private Properties */
private:
    Rectangle<int> graphAria_;
    Rectangle<int> plotAria_;
    
    String title_ = "";
    String xLabel_ = "";
    String yLabel_ = "";
    Colour plotAriaColour_ = Colour(0xFF393643);
    Colour backGroungColour_ = Colours::black;
    Colour fontColour_ = Colours::white;
    Colour gridColour_ = Colours::white;
    float fontSize_ = 12.0f;
    Padding padding_{50,20,20,40};
    Range<float> XRange_ = Range<float>(0.0f, 32768.0f);
    Range<float> YRange_ = Range<float>(-1.0f, 1.0f);
    int maxBufferingSize_ = 32768;
    bool autoSettingXAxisRange_ = true;
    bool autoSettingYAxisRange_ = true;
    int xTickRes_ = 5;
    int yTickRes_ = 5;
    Markers marker_ = Markers::none;
    int gridLineThick = 2;
    
    LinkedListPointer<PlotDataset> plotData_;
    
     //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Figure)
};
