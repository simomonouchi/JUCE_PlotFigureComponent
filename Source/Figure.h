/*
  ==============================================================================

    SourceCode.h
    Created: 12 Sep 2020 10:57:26pm
    Author:  Ryota Shimokawara

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class PlotPoint
{
public:
    PlotPoint(float x, float y);
    ~PlotPoint(){};
    
public:
     LinkedListPointer<PlotPoint> nextListItem;
     float x;
     float y;
};

//==============================================================================

class PlotData
{
public:
    PlotData(float* x, float* y, int len);
    PlotData(float* y, int len);
    PlotData();
    void add(float y);
    void add(float x, float y);
    ~PlotData();
    
    /* Setter */
    inline void setLineColour(Colour lineColour) noexcept { lineColour_ = lineColour; };
    inline void setMarkerColour(Colour markerColour) noexcept { markerColour_ = markerColour; };
    
    /* Getter */
    inline Colour getLineColour() const noexcept { return lineColour_; };
    inline Colour getMarkerColour() const noexcept { return markerColour_; };
    
public:
    LinkedListPointer<PlotData> nextListItem;
    LinkedListPointer<PlotPoint> point_;

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
    void addDateSet(float* x, float* y, int len);
    
    int creatreDataSet();
    void addPoint(float y, int idx);
    void addPoint(float x, float y, int idx);
    void clear();
    
    
//==============================================================================
    /* Setter */
    inline void setBackgroundColour(Colour backGroungColour) noexcept {backGroungColour_ = backGroungColour;}
    inline void setFigureColour(Colour figureColour) noexcept { plotAriaColour_ = figureColour; }
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
    
    inline void setPadding(int top, int bottom, int left, int right) noexcept
    {
        paddingTop_ = top;
        paddingBottom_ = bottom;
        paddingLeft_ = left;
        paddingRight_ = right;
    }
    inline void setPaddingTop(int top) noexcept { paddingTop_ = top; }
    inline void setPaddingBottom(int bottom) noexcept { paddingBottom_ = bottom; }
    inline void setPaddingLeft(int left) noexcept { paddingLeft_ = left; }
    inline void setPaddingRight(int right) noexcept { paddingRight_ = right; }
    
    /* Getter */
    inline int getPaddingTop() const noexcept { return paddingTop_; }
    inline int getPaddingBottom() const noexcept { return paddingBottom_; }
    inline int getPaddingLeft() const noexcept { return paddingLeft_; }
    inline int getPaddingRight() const noexcept { return paddingRight_; }
    inline Range<float> getXLim() const noexcept { return XRange; }
    inline Range<float> getYLim() const noexcept { return YRange; }
    
/* Private Properties */
private:
    Rectangle<int> graphAria_;
    Rectangle<int> regionGraph_;
    
    String title_ = "";
    String xLabel_ = "";
    String yLabel_ = "";
    Colour plotAriaColour_ = Colour(0, 0, 0x33);
    Colour backGroungColour_ = Colours::black;
    Colour fontColour_ = Colours::white;
    float fontSize_ = 15.0f;
    Range<float> XRange;
    Range<float> YRange;
    float xMin_ = 0.0f;
    float xMax_ = 512.0f;
    float yMin_ = -1.0f;
    float yMax_ = 1.0f;
    int datasetMaxSize_ = 32768;
    bool autoSettingXAxisRange_ = true;
    bool autoSettingYAxisRange_ = true;
    
    LinkedListPointer<PlotData> plotData_;

    GridItem::Margin Padding;
    int paddingTop_     = 10;
    int paddingBottom_  = 10;
    int paddingLeft_    = 10;
    int paddingRight_   = 10;
    
     //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Figure)
};
