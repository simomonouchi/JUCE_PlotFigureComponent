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
    float x = 0;
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


Figure::Figure()
{
}

Figure::Figure(Rectangle<int> graphAria):
    graphAria_(graphAria)
{
    regionGraph_.setBounds(
            graphAria_.getX()+graphAria_.getWidth()*0.1,
            graphAria_.getY()+graphAria_.getHeight()*0.1,
            graphAria_.getWidth()*0.8,
            graphAria_.getHeight()*0.8
     );
}

Figure::~Figure()
{
    plotData_.deleteAll();
}

void Figure::setBounds(int x, int y, int width, int height)
{
    graphAria_.setBounds(x, y, width, height);
    regionGraph_.setBounds(
            graphAria_.getX()+50+paddingLeft_,
            graphAria_.getY()+paddingTop_,
            graphAria_.getWidth()-(50+paddingRight_),
            graphAria_.getHeight()-(50+paddingBottom_)
     );
}

void Figure::addDataSet(float* y, int len)
{
    plotData_.append(new PlotDataset(y, len));
}

void Figure::addDateSet(float* x, float* y, int len)
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
    
    if(dataset->points.size() > datasetMaxSize_)
    {
        PlotDataset::PlotPoints* point = dataset->points.get();
        dataset->points.remove(point);
        delete point;
        
        xMin_++;
        xMax_++;
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
    g.fillRect(regionGraph_);
    
//    {
//        PlotData* dataset = plotData_.get();
//        while (dataset != NULL)
//        {
//        PlotPoint* point = dataset->point_.get();
//            while (dataset != NULL)
//            {
//                xMin_ = point->x;
//                xMax_ = point->x;
//                yMin_ = point->y;
//                yMax_ = point->y;
//                break;
//            }
//            break;
//        }
//    }
    PlotDataset* dataset = plotData_.get();
    while (dataset != NULL)
    {
        PlotDataset::PlotPoints* point = dataset->points.get();
        while (point != NULL)
        {
            if(autoSettingXAxisRange_){
                if (point->x > xMax_) xMax_ = point->x;
                if (point->x < xMin_) xMin_ = point->x;
            }
            if(autoSettingYAxisRange_){
                if (point->y > yMax_) yMax_ = point->y;
                if (point->y < yMin_) yMin_ = point->y;
            }
            point = point->nextListItem;
        }
        dataset = dataset->nextListItem;
    }
    
    float dx = (xMax_ - xMin_) / 5;
    float dy = (yMax_ - yMin_) / 5;
    float scaleX = regionGraph_.getWidth()
        / ((xMax_ == xMin_ ? 0.0001 : xMax_ - xMin_) * 1.10);
    float scaleY = regionGraph_.getHeight()
        / ((yMax_ == yMin_ ? 0.0001 : yMax_ - yMin_) * 1.10);


    // draw points
    {
        PlotDataset* dataset = plotData_.get();
        while (dataset != NULL)
        {
            g.setColour(dataset->getLineColour());
            PlotDataset::PlotPoints* point = dataset->points.get();
            bool notFirstFlag = false;
            int preX;
            int preY;
            while (point != NULL)
            {
                int x = (scaleX * (point->x - xMin_)) + regionGraph_.getX();
                int y = regionGraph_.getHeight() - (scaleY * (point->y - yMin_)) + regionGraph_.getY();
                if(notFirstFlag){
//                    if(regionGraph_.getRight()>x && regionGraph_.getY()>y){
                        g.drawLine(preX, preY, x, y, 2);
                    //          g.fillRect(x - 2, y - 2, 5, 5);
//                    }
                }
                else{
                    notFirstFlag = true;
                }

                
                
                preX = x;
                preY = y;
                
                point = point->nextListItem;
                
            }
            dataset = dataset->nextListItem;
        }
    }
    
    // draw x-axis
    g.setFont(Font(fontSize_));
    g.setColour(fontColour_);
    for (int i = 0; i < 6; i++)
    {
        int x = (scaleX * i * dx) + regionGraph_.getBottomLeft().getX();
        int y = regionGraph_.getBottomLeft().getY();
        int y0 = regionGraph_.getTopLeft().getY();
        float value = xMin_ + (dx * i);
        Line<float> line(x, y, x, y0);
        float len[] = { 4, 2 };
        g.drawDashedLine(line, len, 2);
        g.drawLine(x, y - 5, x, y + 5, 2);
        g.drawSingleLineText(String(value), x, y + 20, Justification::left);
    }

    // draw y-axis
    for (int i = 0; i < 6; i++)
    {
        int x = regionGraph_.getTopLeft().getX();
        int y = regionGraph_.getHeight() - (scaleY * i * dy) + regionGraph_.getTopLeft().getY();
        int x0 = regionGraph_.getTopRight().getX();
        float value = yMin_ + (dy * i);
        Line<float> line(x, y, x0, y);
        float len[] = { 4, 2 };
        g.drawDashedLine(line, len, 2);
        g.drawLine(x - 5, y, x + 5, y, 2);
        g.drawSingleLineText(String(value), x - 5, y, Justification::right);
    }

    g.drawText(xLabel_, graphAria_, Justification::centredBottom, true);

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







