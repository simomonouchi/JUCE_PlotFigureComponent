/*
  ==============================================================================

    SourceCode.cpp
    Created: 12 Sep 2020 10:57:26pm
    Author:  Ryota Shimokawara

  ==============================================================================
*/

#include "Figure.h"

//PlotPoint::PlotPoint(float x, float y)
// :  x(x), y(y)
//{
//}

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
            graphAria_.getX() + padding_.left,
            graphAria_.getY() + padding_.top,
            graphAria_.getWidth() - padding_.right - padding_.left,
            graphAria_.getHeight() - padding_.bottom - padding_.top
     );
}

Figure::Figure()
{
}

Figure::Figure(Rectangle<int> graphAria):
    graphAria_(graphAria)
{
    setPlotAriaBounds();
}

Figure::~Figure()
{
    plotData_.deleteAll();
}

void Figure::setBounds(int x, int y, int width, int height)
{
    graphAria_.setBounds(x, y, width, height);
    
    setPlotAriaBounds();
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


void Figure::paint(Graphics& g)
{
    g.setColour(backGroungColour_);
    g.fillRect(graphAria_);
    
    g.setColour(plotAriaColour_);
    g.fillRect(plotAria_);
    float xLength = XRange_.getLength();
    float yLength = YRange_.getLength();
    float dx = xLength / (xTickRes_-1);
    float dy = yLength / (yTickRes_-1);
    float tickX = plotAria_.getWidth() / xLength;
    float scaleY = plotAria_.getHeight() / yLength;

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
                int y = plotAria_.getHeight() - (scaleY * (pointY - YRange_.getStart())) + plotAria_.getY();
                
                if ( (x>plotAria_.getX()) && (x<plotAria_.getRight()) &&
                    (y>plotAria_.getY()) && (y<plotAria_.getBottom())){
                    if(!firstFlag){
                        g.drawLine(preX, preY, x, y, 2);
                        
                        if(marker_ == Markers::none)
                        {
                        }
                        else if(marker_ == Markers::square)
                        {
                            g.fillRect(x - 2, y - 2, 4, 4);
                        }
                        else if (marker_ == Markers::circle)
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
    
    /* draw x-axis */
    g.setFont(Font(fontSize_));
    float dashLength[]{ 4.0f, 2.0f };
    
    int y = plotAria_.getBottomLeft().getY();
    int y0 = plotAria_.getTopLeft().getY();
    for (int i = 0; i < xTickRes_; i++)
    {
        g.setColour(gridColour_);
        int x = tickX*dx*i + plotAria_.getBottomLeft().getX();
        g.drawDashedLine(Line<float>(x, y, x, y0), dashLength,gridLineThick);
        
        g.setColour(fontColour_);
        float axisValue = XRange_.getStart() + (dx * i);
        g.drawSingleLineText(String(axisValue), x, y + 15, Justification::horizontallyCentred);
    }

    /* draw y-axis */
    int x = plotAria_.getTopLeft().getX();
    int x0 = plotAria_.getTopRight().getX();
    for (int i = 0; i < yTickRes_; i++)
    {
        g.setColour(gridColour_);
        int y = plotAria_.getHeight() - (scaleY * i * dy) + plotAria_.getTopLeft().getY();
        g.drawDashedLine(Line<float>(x, y, x0, y), dashLength, gridLineThick);
        
        g.setColour(fontColour_);
        float axisValue = YRange_.getStart() + (dy * i);
        g.drawSingleLineText(String(axisValue), x - 5, y, Justification::right);
    }

    /* draw x-axis label */
    g.drawText(xLabel_, graphAria_, Justification::centredBottom, true);

    /* draw y-axis label (rotate 90 deg.)*/
    g.saveState();
    g.addTransform(AffineTransform::rotation(
        -MathConstants<float>::halfPi,
        graphAria_.getX()+10,
        graphAria_.getCentreY()
     ));
    g.drawText(yLabel_, graphAria_, Justification::centredLeft, true);
    g.restoreState();
}

void Figure::resized()
{
    
}








