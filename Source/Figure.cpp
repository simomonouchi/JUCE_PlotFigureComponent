/*
  ==============================================================================

    SourceCode.cpp
    Created: 12 Sep 2020 10:57:26pm
    Author:  Ryota Shimokawara

  ==============================================================================
*/

#include "Figure.h"

PlotDataset::PlotDataset(float* x, float* y, int len)
{
    for(int sample = 0; sample<len;sample++){
        points.append( new PlotPoints{x[sample], y[sample]});
    }
}


PlotDataset::PlotDataset(float* y, int len)
{
    for(int sample = 0; sample<len;sample++){
        points.append( new PlotPoints{static_cast<float>(sample), y[sample]});
    }
}

PlotDataset::PlotDataset()
{
}

void PlotDataset::add(float y)
{
    float x = 1;
    if (points.size()){
        int index = points.size()-1;
        const LinkedListPointer<PlotPoints>& ope = points.operator[](index);
        
        PlotPoints* lastPoint = ope.get();
        x = lastPoint->x + 1;
    }
    
    points.append( new PlotPoints{x, y});
}

void PlotDataset::add(float x, float y)
{
    points.append( new PlotPoints{x, y});
}


PlotDataset::~PlotDataset()
{
    points.deleteAll();
}

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
    plotData_.deleteAll();
    delete axisDrawer_;
}

void Figure::addDataSet(float* y, int len)
{
    plotData_.append(new PlotDataset(y, len));
}

void Figure::addDataSet(float* x, float* y, int len)
{
     plotData_.append(new PlotDataset(x, y, len));
}

int Figure::creatreDataSet(){
    plotData_.append(new PlotDataset());
    return plotData_.size();
}

void Figure::addPoint(float y, int idx)
{
    LinkedListPointer<PlotDataset>& ope = plotData_.operator[](idx-1);
    PlotDataset* dataset = ope.get();
    
    if(dataset->points.size() > maxBufferingSize_)
    {
        PlotDataset::PlotPoints* point = dataset->points.get();
        dataset->points.remove(point);
        delete point;
        
        /* shift x range */
        XRange_ = Range<float>(XRange_.getStart()+1, XRange_.getEnd()+1);
    }
    
    dataset->add(y);
    
}

void Figure::addPoint(float x, float y, int idx)
{
    LinkedListPointer<PlotDataset>& ope = plotData_.operator[](idx-1);
    PlotDataset* dataset = ope.get();
    dataset->add(x, y);
}

void Figure::clear()
{
    plotData_.deleteAll();
}

void Figure::axesSetUp()
{
    axisDrawer_ = new AxesDrawer(*this);
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

    /* draw plots */
    {
        PlotDataset* dataset = plotData_.get();
        while (dataset != NULL)
        {
            g.setColour(dataset->getLineColour());
            PlotDataset::PlotPoints* point = dataset->points.get();
            bool firstFlag = true;
            int preX;
            int preY;
            while (point != NULL)
            {
                float pointX = point->x;
                float pointY = point->y;
                int x = (tickX * (pointX - XRange_.getStart())) + plotAria_.getX();
                int y = plotAria_.getHeight() - (tickY * (pointY - YRange_.getStart())) + plotAria_.getY();
                
                if ( (x>plotAria_.getX()) && (x<plotAria_.getRight()) &&
                    (y>plotAria_.getY()) && (y<plotAria_.getBottom())){
                    if(!firstFlag){
                        g.drawLine(preX, preY, x, y, 2);
                        
                        if(marker_ == Marker::none)
                        {
                        }
                        else if(marker_ == Marker::square)
                        {
                            g.fillRect(x - 2, y - 2, 4, 4);
                        }
                        else if (marker_ == Marker::circle)
                        {
                            g.fillEllipse(x - 2, y - 2, 4, 4);
                        }
                    }
                    else{ // firstFlag == true
                        firstFlag = false;
                    }
                    
                    preX = x;
                    preY = y;
                }
                else{ // point is out of plotAria
                    firstFlag = true;
//                    g.drawLine(preX, preY, x, y, 2);
                }
                
                point = point->nextListItem;
            }
            dataset = dataset->nextListItem;
        }
    }

    /* draw axes */
    axisDrawer_->drawAxes(g);
    
        
    /* draw x-axis label */
    g.drawText(xLabel_, plotAria_, Justification::centredBottom, true);

    /* draw y-axis label (rotate 90 deg.)*/
    g.saveState();
    g.addTransform(AffineTransform::rotation(
        -MathConstants<float>::halfPi,
        getX()+10,
        getWidth()/2
     ));
    g.drawText(yLabel_, plotAria_, Justification::centredLeft, true);
    g.restoreState();
}

void Figure::resized()
{
    
}

Figure::AxesDrawer::AxesDrawer(Figure& figure)
: figure_(figure)
{
    
    float xLength = figure.XRange_.getLength();
    float yLength = figure.YRange_.getLength();
    float tickX = figure.plotAria_.getWidth() / xLength;
    float tickY = figure.plotAria_.getHeight() / yLength;
    float dx = xLength / (figure.xTickRes_-1);
    float dy = yLength / (figure.yTickRes_-1);
    
    /* X axis */
    xGridYPos_ = Limits<int>{figure.plotAria_.getBottom(), figure.plotAria_.getY()};
    if(figure.xScale_ == Scale::linear)
    {
        numXGridLine_ = figure.xTickRes_;
        xGridXPos_ = new float[figure.xTickRes_];
        xAxisTickLabel_ = new float[figure.xTickRes_];
        for (int i = 0; i < numXGridLine_; i++)
        {
            xGridXPos_[i] = tickX*dx*i + figure.plotAria_.getX();
            xAxisTickLabel_[i] = figure.XRange_.getStart() + (dx * i);
        }
    }
    else if(figure.xScale_ == Scale::log)
    {
        float xLength = figure.XRange_.getLength();
        int exp = log10(xLength);

        float frac = (xLength / pow(10, exp));
        int width = figure.plotAria_.getWidth()/(exp+log10(frac));
        numXGridLine_ = exp*10+floor(frac);
        
        xGridXPos_ = new float[numXGridLine_];
        xAxisTickLabel_ = new float[exp+1];
        
        float* tickLabel = xAxisTickLabel_;
        float pos = 0;
        for(int i=0;i<numXGridLine_;i++){
            pos += width*(LOG10_RATIO[i%10]);
            xGridXPos_[i] = pos + figure.plotAria_.getX();
            if(i%10==0) {
                *tickLabel = pow(10, i/9);
                tickLabel++;
            }
        }
    }

/* Y axis */
yGridXPos_ = Limits<int>{figure.plotAria_.getX(), figure.plotAria_.getRight()};
if(figure.yScale_ == Scale::linear)
{
    numYGridLine_ = figure.yTickRes_;
    yGridYPos_ = new float[figure.yTickRes_];
    yAxisTickLabel_ = new float[figure.yTickRes_];
    for (int i = 0; i < numYGridLine_; i++)
    {
        yGridYPos_[i] = tickY*dy*i + figure.plotAria_.getY();
        yAxisTickLabel_[i] = figure.YRange_.getStart() + (dy * i);
    }
}
else if(figure.yScale_ == Scale::log)
{
    float yLength = figure.YRange_.getLength();
    int exp = log10(yLength);

    float frac = (yLength / pow(10, exp));
    int width = figure.plotAria_.getWidth()/(exp+log10(frac));
    numYGridLine_ = exp*10+floor(frac);
    
    yGridYPos_ = new float[numYGridLine_];
    yAxisTickLabel_ = new float[exp+1];
    
    float* tickLabel = yAxisTickLabel_;
    float pos = 0;
    for(int i=0;i<numYGridLine_;i++){
        pos += width*(LOG10_RATIO[i%10]);
        yGridYPos_[i] = pos + figure.plotAria_.getBottom();
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




