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
    
//==============================================================================
    /* Setter */
    inline void setBackgroundColour(Colour backGroungColour) noexcept {backGroungColour_ = backGroungColour;}
    inline void setFigureColour(Colour figureColour) noexcept { plotAriaColour_ = figureColour; }
    inline void setFontSize(float fontSize) noexcept { fontSize_ = fontSize; }
    inline void setTitle(String title) noexcept { title_ = title; }
    inline void setXLabel(String xLabel) noexcept { xLabel_ = xLabel; }
    inline void setYLabel(String yLabel) noexcept { yLabel_ = yLabel; }
    inline void setXLim(float xMin, float xMax) noexcept
    {
        xMin_ = xMin;
        xMax_ = xMax;
        autoSettingXAxisRange_ = false;
    }
    inline void setYLim(float yMin, float yMax) noexcept
    {
        yMin_ = yMin;
        yMax_ = yMax;
        autoSettingYAxisRange_ = false;
    }
    
    inline void setPadding(int left, int top, int right, int bottom) noexcept
    {
        paddingLeft_ = left;
        paddingTop_ = top;
        paddingRight_ = right;
        paddingBottom_ = bottom;
        setPlotAriaBounds();
    }
    inline void setPaddingLeft(int left) noexcept {
        paddingLeft_ = left;
        setPlotAriaBounds();
    }
    inline void setPaddingTop(int top) noexcept {
        paddingTop_ = top;
        setPlotAriaBounds();
    }
    inline void setPaddingRight(int right) noexcept {
        paddingRight_ = right;
        setPlotAriaBounds();
    }
    inline void setPaddingBottom(int bottom) noexcept {
        paddingBottom_ = bottom;
        setPlotAriaBounds();
    }
    inline void setMaxBufferingSize(int maxBufferingSize) noexcept {
        maxBufferingSize_ = maxBufferingSize;
    }
    inline void setMarker(Markers marker) noexcept {marker_ = marker;}

    
    /* Getter */
    inline int getPaddingTop() const noexcept { return paddingTop_; }
    inline int getPaddingBottom() const noexcept { return paddingBottom_; }
    inline int getPaddingLeft() const noexcept { return paddingLeft_; }
    inline int getPaddingRight() const noexcept { return paddingRight_; }
    inline Range<float> getXLim() const noexcept { return XRange; }
    inline Range<float> getYLim() const noexcept { return YRange; }
    inline Colour getBackgroundColour()const noexcept { return backGroungColour_; }
    inline Colour getPlotAriaColour()const noexcept { return plotAriaColour_; }
    inline Colour getFontColour()const noexcept { return fontColour_; }
 
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
    float fontSize_ = 12.0f;
    Range<float> XRange;
    Range<float> YRange;
    float xMin_ = 1.0f;
    float xMax_ = 32768.0f;
    float yMin_ = -1.0f;
    float yMax_ = 1.0f;
    int maxBufferingSize_ = 32768;
    bool autoSettingXAxisRange_ = true;
    bool autoSettingYAxisRange_ = true;
    int xScaleRes_ = 5;
    int yScaleRes_ = 5;
    Markers marker_ = Markers::none;
    
    LinkedListPointer<PlotDataset> plotData_;

    GridItem::Margin Padding;
    int paddingLeft_    = 50;
    int paddingTop_     = 20;
    int paddingRight_   = 20;
    int paddingBottom_  = 40;
    
     //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Figure)
};
