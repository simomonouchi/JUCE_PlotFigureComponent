/*
  ==============================================================================

    SourceCode.cpp
    Created: 12 Sep 2020 10:57:26pm
    Author:  Ryota Shimokawara

  ==============================================================================
*/

#include "Figure.h"



PlotDataset::PlotDataset(float* x, float* y, int len)
 : len_(len)
{
    x_.reset(new float[len]);
    y_.reset(new float[len]);

    memcpy(x_.get(), x, sizeof(float)*len);
    memcpy(y_.get(), y, sizeof(float)*len);
    
    addable_ = false;
}


PlotDataset::PlotDataset(float* y, int len)
: len_(len)
{
    x_.reset(new float[len]);
    y_.reset(new float[len]);
    
    /* add natural number */
    for(int i = 0; i<len; i++){
        x_.get()[i] = i+1;
    }
    memcpy(y_.get(), y, sizeof(float)*len);

    addable_ = false;
}

PlotDataset::PlotDataset(int maxLen)
: len_(maxLen)
{
    x_.reset(new float[maxLen]);
    y_.reset(new float[maxLen]);
    
    memset(x_.get(), 0, sizeof(float)*maxLen);
    memset(y_.get(), 0, sizeof(float)*maxLen);
    
    addable_ = true;
}

PlotDataset::~PlotDataset()
{
    x_ = nullptr;
    y_ = nullptr;
}

void PlotDataset::updateDataset(float* x, float* y, int len)
{
    if(len == len_){
        memcpy(x_.get(), x, sizeof(float)*len);
        memcpy(y_.get(), y, sizeof(float)*len);
    }
    else
    {
        x_.reset(new float[len]);
        y_.reset(new float[len]);

        memcpy(x_.get(), x, sizeof(float)*len);
        memcpy(y_.get(), y, sizeof(float)*len);
    }
}
void PlotDataset::updateDataset(float* y, int len)
{
    if(len == len_){
        memcpy(y_.get(), y, sizeof(float)*len);
    }
    else
    {
        x_.reset(new float[len]);
        y_.reset(new float[len]);

        /* add natural number */
        for(int i = 0; i<len; i++){
            x_.get()[i] = i+1;
        }
        memcpy(y_.get(), y, sizeof(float)*len);
    }
}

void PlotDataset::addData(float* y, int len)
{
    for(int i=0; i<len; i++){
        y_.get()[additionPoint_] = y[i];
        additionPoint_ = (additionPoint_+1)%len_;
    }
}

void PlotDataset::addData(float* x, float* y, int len)
{
    for(int i=0; i<len; i++){
        x_.get()[additionPoint_] = x[i];
        y_.get()[additionPoint_] = y[i];
        additionPoint_ = (additionPoint_+1)%len_;
    }
}

//===============================================================================
Figure::Figure()
{
    plotter.reset(new Plotter(*this));
    addAndMakeVisible(plotter.get());
    
    for(int i=0;i<10;i++)
    {
        plotdattaset[i] = nullptr;
    }
    
}

void Figure::setPlotAriaBounds() noexcept
{
    plotAria_.setBounds(
            padding_.left,
            padding_.top,
            getWidth() - padding_.right - padding_.left,
            getHeight() - padding_.bottom - padding_.top
     );
    
    plotter->setBounds(plotAria_);
    
    axesSetUp();
}

Figure::~Figure()
{
    delete axisDrawer_;
    
    for(int i=0; i<numUsingPlotDataSet; i++)
    {
        delete plotdattaset[i];
    }
}

void Figure::setDataset(float* y, int len, int datasetIndex, Colour lineColour)
{
    if(plotdattaset[datasetIndex] == nullptr)
    {
        plotdattaset[datasetIndex] = new PlotDataset(y, len);
        plotdattaset[datasetIndex]->setLineColour(lineColour);
        numUsingPlotDataSet++;
    }
    else
    {
        plotdattaset[datasetIndex]->updateDataset(y, len);
    }
    repaint();
}

void Figure::setDataset(float* x, float* y, int len, int datasetIndex, Colour lineColour)
{
    if(plotdattaset[datasetIndex] == nullptr)
    {
        plotdattaset[datasetIndex] = new PlotDataset(x, y, len);
        plotdattaset[datasetIndex]->setLineColour(lineColour);
        numUsingPlotDataSet++;
    }
    else
    {
        plotdattaset[datasetIndex]->updateDataset(x, y, len);
    }
    repaint();
}

void Figure::creatreAddableDataSet(int maxLen, int datasetIndex) {
    plotdattaset[numUsingPlotDataSet] = new PlotDataset(maxLen);
    numUsingPlotDataSet++;
    startTimerHz (30);
}

void Figure::addData(float* y, int len, int datasetIndex)
{
    jassert(plotdattaset[datasetIndex]->isAddable());
    
    plotdattaset[datasetIndex]->addData(y, len);
}

void Figure::addPoint(float* x, float* y, int len, int datasetIndex)
{
    jassert(plotdattaset[datasetIndex]->isAddable());
    
    plotdattaset[datasetIndex]->addData(x, y, len);
}

void Figure::timerCallback()
{
    repaint();
}

void Figure::axesSetUp()
{
    if(axisDrawer_ == nullptr){
        axisDrawer_ = new AxesDrawer(*this);
    }
    else
    {
        axisDrawer_->calcAxesPosition();
    }
}

void Figure::paint (juce::Graphics& g)
{
    if(PropertyChanged_){
        setPlotAriaBounds();
        PropertyChanged_ = false;
    }

    g.setColour(backGroungColour_);
    g.fillAll();
    
    g.setColour(plotAriaColour_);
    g.fillRect(plotAria_);
    
  
   

    /* draw axes */
    axisDrawer_->drawAxes(g);
    
        
    /* draw x-axis label */
    g.drawText(xLabel_, 0, getBottom()-(fontSize_+40), getWidth(), (fontSize_+40),
               Justification::centredTop, true
               );

    /* draw y-axis label (rotate 90 deg.)*/
    g.saveState();
    g.addTransform(AffineTransform::rotation(
        -MathConstants<float>::halfPi,
        10,
        getHeight()/2
     ));
    g.drawText(yLabel_,
               10, 0, // x, y
               (fontSize_+40), getHeight(), // width, height
               Justification::centred, true
               );
    g.restoreState();
    
    plotter->repaint();
}

void Figure::resized()
{
    
}

//================================================================
void Figure::Plotter::paint (juce::Graphics& g)
{
    float tickX = getWidth() / figure_.XRange_.getLength();
    float tickY = getHeight() / figure_.YRange_.getLength();

    /* plot */
        for(int i=0; i<figure_.numUsingPlotDataSet; i++)
        {
            PlotDataset* dataset = figure_.plotdattaset[i];
            g.setColour(dataset->getLineColour());
            int prePosX;
            int prePosY;
            for(int sample=0; sample < dataset->getLength(); sample++)
            {
                float x = dataset->getX(sample);
                float y = dataset->getY(sample);
            
                int posX=0;
                int posY=0;
                if(figure_.xScale_ == Scale::linear){
                    posX = (tickX * (x - figure_.XRange_.getStart()));
                }
                else if(figure_.xScale_ == Scale::log)
                {
                    float xLength = figure_.XRange_.getLength();
                    int exp = log10(xLength);

                    float frac = (xLength / pow(10, exp));
                    int width = getWidth()/(exp+log10(frac));
                    
                    posX = width * log10(x - figure_.XRange_.getStart());
                }
                
                if(figure_.yScale_ == Scale::linear){
                posY = getHeight() - (tickY * (y - figure_.YRange_.getStart()));
                }
                else if(figure_.xScale_ == Scale::log)
                {
                    float yLength = figure_.YRange_.getLength();
                    int exp = log10(yLength);

                    float frac = (yLength / pow(10, exp));
                    int width = getWidth()/(exp+log10(frac));
                    
                    posY = width * log10(y - figure_.YRange_.getStart());
                }
                
                if(sample){
                    g.drawLine(prePosX, prePosY, posX, posY, 2);
                    
                    if(figure_.marker_ == Marker::none) { }
                    else if(figure_.marker_ == Marker::square)
                    {
                        g.fillRect(
                           posX - figure_.markerSize_, posY - figure_.markerSize_,
                                   figure_.markerSize_*2, figure_.markerSize_*2
                        );
                    }
                    else if (figure_.marker_ == Marker::circle)
                    {
                        g.fillEllipse(
                          posX - figure_.markerSize_, posY - figure_.markerSize_,
                                      figure_.markerSize_*2, figure_.markerSize_*2
                        );
                    }
                }
                
                prePosX = posX;
                prePosY = posY;

            }
        }
}
//==============================================================================
/* methods of Figure's inner class AxesDrawer */

Figure::AxesDrawer::AxesDrawer(Figure& figure)
: figure_(figure)
{
   calcAxesPosition();
}

void Figure::AxesDrawer::calcAxesPosition()
{
    float xLength = figure_.XRange_.getLength();
    float yLength = figure_.YRange_.getLength();
    float tickX = figure_.plotAria_.getWidth() / xLength;
    float tickY = figure_.plotAria_.getHeight() / yLength;
    float dx = xLength / (figure_.xTickRes_-1);
    float dy = yLength / (figure_.yTickRes_-1);
    
    /* X axis */
    xGridYPos_ = Limits<int>{figure_.plotAria_.getBottom(), figure_.plotAria_.getY()};
    if(figure_.xScale_ == Scale::linear)
    {
        numXGridLine_ = figure_.xTickRes_;
        xGridXPos_.reset(new float[figure_.xTickRes_]);
        xAxisTickLabel_.reset(new float[figure_.xTickRes_]);
        for (int i = 0; i < numXGridLine_; i++)
        {
            xGridXPos_.get()[i] = tickX*dx*i + figure_.plotAria_.getX();
            xAxisTickLabel_.get()[i] = figure_.XRange_.getStart() + (dx * i);
        }
    }
    else if(figure_.xScale_ == Scale::log)
    {
        float xLength = figure_.XRange_.getLength();
        int exp = log10(xLength);

        float frac = (xLength / pow(10, exp));
        int width = figure_.plotAria_.getWidth()/(exp+log10(frac));
        numXGridLine_ = exp*10+floor(frac);
        
        xGridXPos_.reset(new float[numXGridLine_]);
        xAxisTickLabel_.reset(new float[exp+1]);
        
        float* tickLabel = xAxisTickLabel_.get();
        float pos = 0;
        for(int i=0;i<numXGridLine_;i++){
            pos += width*(LOG10_RATIO[i%10]);
            xGridXPos_.get()[i] = pos + figure_.plotAria_.getX();
            if(i%10==0) {
                *tickLabel = pow(10, i/9);
                tickLabel++;
            }
        }
}

/* Y axis */
yGridXPos_ = Limits<int>{figure_.plotAria_.getX(), figure_.plotAria_.getRight()};
if(figure_.yScale_ == Scale::linear)
{
    numYGridLine_ = figure_.yTickRes_;
    yGridYPos_.reset(new float[figure_.yTickRes_]);
    yAxisTickLabel_.reset(new float[figure_.yTickRes_]);
    for (int i = 0; i < numYGridLine_; i++)
    {
        yGridYPos_.get()[i] = tickY*dy*i + figure_.plotAria_.getY();
        yAxisTickLabel_.get()[i] = figure_.YRange_.getEnd() - (dy * i);
    }
}
else if(figure_.yScale_ == Scale::log)
{
    float yLength = figure_.YRange_.getLength();
    int exp = log10(yLength);

    float frac = (yLength / pow(10, exp));
    int width = figure_.plotAria_.getWidth()/(exp+log10(frac));
    numYGridLine_ = exp*10+floor(frac);
    
    yGridYPos_.reset(new float[numYGridLine_]);
    yAxisTickLabel_.reset(new float[exp+1]);
    
    float* tickLabel = yAxisTickLabel_.get();
    float pos = 0;
    for(int i=0;i<numYGridLine_;i++){
        pos += width*(LOG10_RATIO[i%10]);
        yGridYPos_.get()[i] = pos + figure_.plotAria_.getBottom();
        if(i%10==0) {
            *tickLabel = pow(10, i/9);
            tickLabel++;
        }
    }
}
}


void Figure::AxesDrawer::drawAxes (Graphics& g)
{
    g.setFont(Font(figure_.fontSize_));
    g.setColour(figure_.gridColour_);

    /* X axis */
    {
    float* tickLabel = xAxisTickLabel_.get();
    
    for(int i=0;i<numXGridLine_;i++)
    {
        g.setColour(figure_.gridColour_);
        
        float x = xGridXPos_.get()[i];
        g.drawDashedLine(
             Line<float>(x, xGridYPos_.min, x, xGridYPos_.max),
             dashLength_,
             figure_.gridLineThick_
        );
        
        if (figure_.xScale_ == Scale::log && i%10) { continue; }
        
        g.setColour(figure_.fontColour_);
        g.drawSingleLineText(
          String(*tickLabel),
            x,
            xGridYPos_.min + 15,
            Justification::horizontallyCentred
        );
        tickLabel++;
    }
    }
    
    /* Y axis */
    {
    float* tickLabel = yAxisTickLabel_.get();
    
    for(int i=0;i<numYGridLine_;i++)
    {
        g.setColour(figure_.gridColour_);
        
        float y = yGridYPos_.get()[i];
        g.drawDashedLine(
             Line<float>(yGridXPos_.min, y, yGridXPos_.max, y),
             dashLength_,
             figure_.gridLineThick_
        );
        
        if (figure_.yScale_ == Scale::log && i%10) { continue; }
        
        g.setColour(figure_.fontColour_);
        g.drawSingleLineText(
          String(*tickLabel),
            yGridXPos_.min -5,
            y,
            Justification::right
        );
        tickLabel++;
    }
    }
}

Figure::AxesDrawer::~AxesDrawer()
{
    xGridXPos_ = nullptr;
    xAxisTickLabel_ = nullptr;
    yGridYPos_ = nullptr;
    yAxisTickLabel_ = nullptr;
}




