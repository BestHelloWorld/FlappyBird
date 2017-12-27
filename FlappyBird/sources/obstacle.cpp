#include "obstacle.h"

obstacle::obstacle(int n,
                   int length)
{
    this->nLocation = n;
    this->nLength = length;
    this->isAddScore = false;
    this->setZValue(5);

    if(n == OBSTACLEDOWN)
    {
        obstacle_up = new QPixmap(":/game/game_obstacle_up.png");
        obstacle_down = new QPixmap(":/game/game_obstacle_down.png");
    }
    else
    {
        obstacle_up = new QPixmap(":/game/game_obstacle_up_top.png");
        obstacle_down = new QPixmap(":/game/game_obstacle_down_top.png");
    }
}

QRectF obstacle::boundingRect() const
{
    QRectF rect;
    if(nLocation == OBSTACLEUP)
    {
        rect.setRect(OBSTACLESTART-0.5,
                     -155-0.5,
                     OBSTACLEWIDTH+1,
                     nLength+1);
    }
    else if(nLocation == OBSTACLEDOWN)
    {
        rect.setRect(OBSTACLESTART-0.5,
                     250-nLength-0.5,
                     OBSTACLEWIDTH+1,
                     nLength+1);
    }
    return rect;
}

void obstacle::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    painter->setBrush(QBrush(Qt::green));
    if(nLocation == OBSTACLEUP)
    {
        painter->drawPixmap(QRect(OBSTACLESTART+2,
                                  -155,
                                  OBSTACLEWIDTH - 4,
                                  nLength - 30),
                            *obstacle_down);
        painter->drawPixmap(QRect(OBSTACLESTART,
                                  nLength - 30 - 155,
                                  OBSTACLEWIDTH + 1,
                                  30),
                            *obstacle_up);
    }
    else if(nLocation == OBSTACLEDOWN)
    {
        painter->drawPixmap(QRect(OBSTACLESTART + 2,
                                  250-nLength + 30,
                                  OBSTACLEWIDTH - 4,
                                  nLength - 30),
                            *obstacle_down);
        painter->drawPixmap(QRect(OBSTACLESTART - 1,
                                  250-nLength,
                                  OBSTACLEWIDTH + 1,
                                  30),
                            *obstacle_up);
    }
}
