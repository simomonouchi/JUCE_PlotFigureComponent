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

    void paint (Graphics& g) override;
    void resized() override;
    void setBounds(int x, int y, int width, int height);
    
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
    Scale xScale_ = Scale::linear;
    Scale yScale_ = Scale::linear;
    Marker marker_ = Marker::none;
    int gridLineThick_ = 2;
    
    LinkedListPointer<PlotDataset> plotData_;
    
    class AxesDrawer : public juce::Component
    {
    public:
        AxesDrawer(Figure& figure)
        : figure(figure)
        {
            
            float xLength = figure.XRange_.getLength();
            float yLength = figure.YRange_.getLength();
            float tickX = figure.plotAria_.getWidth() / xLength;
            float tickY = figure.plotAria_.getHeight() / yLength;
            float dx = xLength / (figure.xTickRes_-1);
            float dy = yLength / (figure.yTickRes_-1);
            
            /* X axis */
            xGridYPos = Limits<int>{figure.plotAria_.getBottom(), figure.plotAria_.getY()};
            if(figure.xScale_ == Scale::linear)
            {
                numXGridLine_ = figure.xTickRes_;
                xGridXPos = new float[figure.xTickRes_];
                xAxisTickLabel = new float[figure.xTickRes_];
                for (int i = 0; i < numXGridLine_; i++)
                {
                    xGridXPos[i] = tickX*dx*i + figure.plotAria_.getX();
                    xAxisTickLabel[i] = figure.XRange_.getStart() + (dx * i);
                }
            }
            else if(figure.xScale_ == Scale::log)
            {
                float xLength = figure.XRange_.getLength();
                int exp = log10(xLength);

                float frac = (xLength / pow(10, exp));
                int width = figure.plotAria_.getWidth()/(exp+log10(frac));
                numXGridLine_ = exp*10+floor(frac);
                
                xGridXPos = new float[numXGridLine_];
                xAxisTickLabel = new float[exp+1];
                
                float* tickLabel = xAxisTickLabel;
                float pos = 0;
                for(int i=0;i<numXGridLine_;i++){
                    pos += width*(LOG10_RATIO[i%10]);
                    xGridXPos[i] = pos + figure.plotAria_.getX();
                    if(i%10==0) {
                        *tickLabel = pow(10, i/9);
                        tickLabel++;
                    }
                }
            }
        
        /* Y axis */
        yGridXPos = Limits<int>{figure.plotAria_.getX(), figure.plotAria_.getRight()};
        if(figure.yScale_ == Scale::linear)
        {
            numYGridLine_ = figure.yTickRes_;
            yGridYPos = new float[figure.yTickRes_];
            yAxisTickLabel = new float[figure.yTickRes_];
            for (int i = 0; i < numYGridLine_; i++)
            {
                yGridYPos[i] = tickY*dy*i + figure.plotAria_.getY();
                yAxisTickLabel[i] = figure.YRange_.getStart() + (dy * i);
            }
        }
        else if(figure.yScale_ == Scale::log)
        {
            float yLength = figure.YRange_.getLength();
            int exp = log10(yLength);

            float frac = (yLength / pow(10, exp));
            int width = figure.plotAria_.getWidth()/(exp+log10(frac));
            numYGridLine_ = exp*10+floor(frac);
            
            yGridYPos = new float[numYGridLine_];
            yAxisTickLabel = new float[exp+1];
            
            float* tickLabel = yAxisTickLabel;
            float pos = 0;
            for(int i=0;i<numYGridLine_;i++){
                pos += width*(LOG10_RATIO[i%10]);
                yGridYPos[i] = pos + figure.plotAria_.getBottom();
                if(i%10==0) {
                    *tickLabel = pow(10, i/9);
                    tickLabel++;
                }
            }
        }
    }
        
        void paint (Graphics& g) override
        {
            g.setFont(Font(figure.fontSize_));
            g.setColour(figure.gridColour_);

            /* X axis */
            {
            float* tickLabel = xAxisTickLabel;
            
            for(int i=0;i<numXGridLine_;i++)
            {
                g.setColour(figure.gridColour_);
                
                float x = xGridXPos[i];
                g.drawDashedLine(
                     Line<float>(x, xGridYPos.min, x, xGridYPos.max),
                     dashLength_,
                     figure.gridLineThick_
                );
                
                if (figure.xScale_ == Scale::log && i%10) { continue; }
                
                g.setColour(figure.fontColour_);
                g.drawSingleLineText(
                  String(*tickLabel),
                    x,
                    xGridYPos.min + 15,
                    Justification::horizontallyCentred
                );
                tickLabel++;
            }
            }
            
            /* Y axis */
            {
            float* tickLabel = yAxisTickLabel;
            
            for(int i=0;i<numYGridLine_;i++)
            {
                g.setColour(figure.gridColour_);
                
                float y = yGridYPos[i];
                g.drawDashedLine(
                     Line<float>(yGridXPos.min, y, yGridXPos.max, y),
                     dashLength_,
                     figure.gridLineThick_
                );
                
                if (figure.yScale_ == Scale::log && i%10) { continue; }
                
                g.setColour(figure.fontColour_);
                g.drawSingleLineText(
                  String(*tickLabel),
                    yGridXPos.min -5,
                    y,
                    Justification::right
                );
                tickLabel++;
            }
            }
        }
        
    private:
        Figure& figure;
        
        float dashLength_[2]{ 4.0f, 2.0f };
        
        int numXGridLine_;
        float* xGridXPos;
        Limits<int>  xGridYPos;
        float* xAxisTickLabel;
        
        int numYGridLine_;
        Limits<int> yGridXPos;
        float* yGridYPos;
        float* yAxisTickLabel;
    };
    
    AxesDrawer* axisDravwer;
    
     //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Figure)
};

