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
    x_ = new float[len];
    y_ = new float[len];

    memcpy(x_, x, sizeof(float)*len);
    memcpy(y_, y, sizeof(float)*len);
    
    addable_ = false;
}


PlotDataset::PlotDataset(float* y, int len)
: len_(len)
{
    x_ = new float[len];
    y_ = new float[len];
    
    /* add natural number */
    for(int i = 0; i<len; i++){
        x_[i] = i+1;
    }
    memcpy(y_, y, sizeof(float)*len);

    addable_ = false;
}

PlotDataset::PlotDataset(int maxLen)
: len_(maxLen)
{
    x_ = new float[maxLen];
    y_ = new float[maxLen];
    
    memset(x_, 0, sizeof(float)*maxLen);
    memset(y_, 0, sizeof(float)*maxLen);
    
    addable_ = true;
}

PlotDataset::~PlotDataset()
{
    delete[] x_;
    delete[] y_;
}

void PlotDataset::updateDataset(float* x, float* y, int len)
{
    if(x_ != NULL){
    if(len == len_){
        memcpy(x_, x, sizeof(float)*len);
        memcpy(y_, y, sizeof(float)*len);
    }
    else
    {
        delete[] x_;
        delete[] y_;
        
        x_ = new float[len];
        y_ = new float[len];

        memcpy(x_, x, sizeof(float)*len);
        memcpy(y_, y, sizeof(float)*len);
    }
    }
}
void PlotDataset::updateDataset(float* y, int len)
{
    if(x_ != NULL){
    if(len == len_){
        memcpy(y_, y, sizeof(float)*len);
    }
    else
    {
        delete[] x_;
        delete[] y_;
        
        x_ = new float[len];
        y_ = new float[len];

        /* add natural number */
        for(int i = 0; i<len; i++){
            x_[i] = i+1;
        }
        memcpy(y_, y, sizeof(float)*len);
    }
    }
}

void PlotDataset::addData(float* y, int len)
{
    for(int i=0; i<len; i++){
        y_[additionPoint_] = y[i];
        additionPoint_ = (additionPoint_+1)%len_;
    }
}

void PlotDataset::addData(float* x, float* y, int len)
{
    for(int i=0; i<len; i++){
        x_[additionPoint_] = x[i];
        y_[additionPoint_] = y[i];
        additionPoint_ = (additionPoint_+1)%len_;
    }
}

//===============================================================================

void Figure::setPlotAriaBounds() noexcept
{
    plotAria_.setBounds(
            padding_.left,
            padding_.top,
            getWidth() - padding_.right - padding_.left,
            getHeight() - padding_.bottom - padding_.top
     );
}

Figure::~Figure()
{
    delete axisDrawer_;
    
    for(int i=0; i<numUsingPlotDataSet; i++)
    {
        delete plotdattaset[i];
    }
}

void Figure::setDataset(float* y, int len, int datasetIndex)
{
    if(plotdattaset[datasetIndex] == nullptr)
    {
    plotdattaset[datasetIndex] = new PlotDataset(y, len);
    numUsingPlotDataSet++;
    }
    else
    {
        plotdattaset[datasetIndex]->updateDataset(y, len);
    }
    repaint();
}

void Figure::setDataset(float* x, float* y, int len, int datasetIndex)
{
    if(plotdattaset[datasetIndex] == nullptr)
    {
        plotdattaset[datasetIndex] = new PlotDataset(x, y, len);
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
        axesSetUp();
        PropertyChanged_ = false;
    }

    g.setColour(backGroungColour_);
    g.fillAll();
    
    g.setColour(plotAriaColour_);
    g.fillRect(plotAria_);
    
    float xLength = XRange_.getLength();
    float yLength = YRange_.getLength();
    float tickX = plotAria_.getWidth() / xLength;
    float tickY = plotAria_.getHeight() / yLength;

    /* plot */
    {
        for(int i=0; i<numUsingPlotDataSet; i++)
        {
            PlotDataset* dataset = plotdattaset[i];
            g.setColour(dataset->getLineColour());
            int prePosX;
            int prePosY;
            for(int sample=0; sample < dataset->getLength(); sample++)
            {
                float x = dataset[i].getX(sample);
                float y = dataset[i].getY(sample);
                int posX = (tickX * (x - XRange_.getStart())) + plotAria_.getX();
                int posY = plotAria_.getHeight() - (tickY * (y - YRange_.getStart())) + plotAria_.getY();
                
//                if ( (posX>plotAria_.getX()) && (posX<plotAria_.getRight()) &&
//                    (posY>plotAria_.getY()) && (posY<plotAria_.getBottom())){
                    if(sample){
                        g.drawLine(prePosX, prePosY, posX, posY, 2);
                        
                        if(marker_ == Marker::none) { }
                        else if(marker_ == Marker::square)
                        {
                            g.fillRect(
                               posX - markerSize_, posY - markerSize_,
                               markerSize_*2, markerSize_*2
                            );
                        }
                        else if (marker_ == Marker::circle)
                        {
                            g.fillEllipse(
                              posX - markerSize_, posY - markerSize_,
                              markerSize_*2, markerSize_*2
                            );
                        }
                    }
                    
                    prePosX = posX;
                    prePosY = posY;
//                }
//                else{ // point is out of plotAria
//
//                    //                    g.drawLine(preX, preY, x, y, 2);
//                }
            }
        }
    }

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
}

void Figure::resized()
{
    
}

//==============================================================================
/* Figure inner class AxesDrawer methods*/

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
        xGridXPos_ = new float[figure_.xTickRes_];
        xAxisTickLabel_ = new float[figure_.xTickRes_];
        for (int i = 0; i < numXGridLine_; i++)
        {
            xGridXPos_[i] = tickX*dx*i + figure_.plotAria_.getX();
            xAxisTickLabel_[i] = figure_.XRange_.getStart() + (dx * i);
        }
    }
    else if(figure_.xScale_ == Scale::log)
    {
        float xLength = figure_.XRange_.getLength();
        int exp = log10(xLength);

        float frac = (xLength / pow(10, exp));
        int width = figure_.plotAria_.getWidth()/(exp+log10(frac));
        numXGridLine_ = exp*10+floor(frac);
        
        xGridXPos_ = new float[numXGridLine_];
        xAxisTickLabel_ = new float[exp+1];
        
        float* tickLabel = xAxisTickLabel_;
        float pos = 0;
        for(int i=0;i<numXGridLine_;i++){
            pos += width*(LOG10_RATIO[i%10]);
            xGridXPos_[i] = pos + figure_.plotAria_.getX();
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
    yGridYPos_ = new float[figure_.yTickRes_];
    yAxisTickLabel_ = new float[figure_.yTickRes_];
    for (int i = 0; i < numYGridLine_; i++)
    {
        yGridYPos_[i] = tickY*dy*i + figure_.plotAria_.getY();
        yAxisTickLabel_[i] = figure_.YRange_.getStart() + (dy * i);
    }
}
else if(figure_.yScale_ == Scale::log)
{
    float yLength = figure_.YRange_.getLength();
    int exp = log10(yLength);

    float frac = (yLength / pow(10, exp));
    int width = figure_.plotAria_.getWidth()/(exp+log10(frac));
    numYGridLine_ = exp*10+floor(frac);
    
    yGridYPos_ = new float[numYGridLine_];
    yAxisTickLabel_ = new float[exp+1];
    
    float* tickLabel = yAxisTickLabel_;
    float pos = 0;
    for(int i=0;i<numYGridLine_;i++){
        pos += width*(LOG10_RATIO[i%10]);
        yGridYPos_[i] = pos + figure_.plotAria_.getBottom();
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
    float* tickLabel = xAxisTickLabel_;
    
    for(int i=0;i<numXGridLine_;i++)
    {
        g.setColour(figure_.gridColour_);
        
        float x = xGridXPos_[i];
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
    float* tickLabel = yAxisTickLabel_;
    
    for(int i=0;i<numYGridLine_;i++)
    {
        g.setColour(figure_.gridColour_);
        
        float y = yGridYPos_[i];
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




