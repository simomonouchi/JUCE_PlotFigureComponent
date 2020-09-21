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
    ~PlotPoint();
    
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
    
public:
    LinkedListPointer<PlotData> nextListItem;
    LinkedListPointer<PlotPoint> point_;
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
    inline void setFigureColour(Colour figureColour) noexcept { figureColour_ = figureColour; }
    inline void setTitle(String title) noexcept { title_ = title; }
    inline void setXLabel(String xLabel) noexcept { xLabel_ = xLabel; }
    inline void setYLabel(String yLabel) noexcept { yLabel_ = yLabel; }
    inline void setXLim(float xMin, float xMax) noexcept
    {
        xMin_ = xMin;
        xMax_ = xMax;
    }
    inline void setYLim(float yMin, float yMax) noexcept
    {
        yMin_ = yMin;
        yMax_ = yMax;
        
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
    inline Range<int> getXLim() const noexcept { return XRange; }
    inline Range<int> getYLim() const noexcept { return YRange; }
    
/* Private Properties */
private:
    Rectangle<int> graphAria_;
    Rectangle<int> regionGraph_;
    
    String title_;
    String xLabel_;
    String yLabel_;
    Colour figureColour_;
    Colour backGroungColour_;
    Range<int> XRange;
    Range<int> YRange;
    float xMin_;
    float xMax_;
    float yMin_;
    float yMax_;
    int datasetMaxSize;
    
    LinkedListPointer<PlotData> plotData_;

    GridItem::Margin Padding;
    int paddingTop_;
    int paddingBottom_;
    int paddingLeft_;
    int paddingRight_;
    
     //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Figure)
};
