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
    Figure() {}
    ~Figure() override;

//==============================================================================

    void paint (juce::Graphics& g)  override;
    void resized() override;
//    void setBounds (int x, int y, int w, int h);
    
    void addDataSet(float* y, int len);
    void addDataSet(float* x, float* y, int len);
    
    int creatreDataSet();
    void addPoint(float y, int idx);
    void addPoint(float x, float y, int idx);
    void clear();
    
    void axesSetUp();
    
    enum class Marker
    {
        none,
        square,
        circle,
    };
    
    enum class Scale
    {
        linear,
        log,
        // symlog // TBD
        // logit  // TBD
    };
    
    using Padding = struct {
        float left;
        float top;
        float right;
        float bottom;
    };
    
    template<typename T>
    struct Limits
    {
        T min;
        T max;
        inline T getLength() const noexcept { return max - min; }
    };
    
    /* for log scale */
    static constexpr double LOG10_RATIO[10] ={
        0.0,
        0.301029995663981198017467022509663365781307220458984375,
        0.17609125905568123737765517944353632628917694091796875,
        0.124938736608299960639811843066127039492130279541015625,
        0.0969100130080564614587501637288369238376617431640625,
        0.07918124604762477591890501571469940245151519775390625,
        0.06694678963061317933380678368848748505115509033203125,
        0.05799194697768672579485382811981253325939178466796875,
        0.05115252244738133224899456763523630797863006591796875,
        0.04575749056067512920975559609360061585903167724609375,
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
    inline void setMarker(Marker marker) noexcept {marker_ = marker;}
    inline void setPlotAriaColour(Colour newColour) noexcept {plotAriaColour_ = newColour;}
    inline void setBackGroungColour(Colour newColour) noexcept {plotAriaColour_ = newColour;}
    inline void setFontColour(Colour newColour) noexcept {fontColour_ = newColour;}
    inline void setGridColour(Colour newColour) noexcept {gridColour_ = newColour;}
    inline void setXScale(Scale scale) noexcept{ xScale_ = scale; }
    inline void setYScale(Scale scale) noexcept{ yScale_ = scale; }
    
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
    Rectangle<int> plotAria_;
    
    bool PropertyChanged_ = true;
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
    Scale xScale_ = Scale::linear;
    Scale yScale_ = Scale::linear;
    Marker marker_ = Marker::none;
    int gridLineThick_ = 2;
    
    LinkedListPointer<PlotDataset> plotData_;
    
    class AxesDrawer
    {
    public:
        AxesDrawer(Figure& figure);
        ~AxesDrawer() {}
        
        void drawAxes(Graphics& g);
        
    private:
        Figure& figure_;
        
        float dashLength_[2]{ 4.0f, 2.0f };
        
        /* X axis */
        int numXGridLine_;
        float* xGridXPos_;
        Limits<int>  xGridYPos_;
        float* xAxisTickLabel_;
        
        /* Y axis */
        int numYGridLine_;
        Limits<int> yGridXPos_;
        float* yGridYPos_;
        float* yAxisTickLabel_;
    };
    
    AxesDrawer* axisDrawer_;
    
     //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Figure)
};

