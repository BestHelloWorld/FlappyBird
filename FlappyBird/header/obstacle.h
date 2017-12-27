#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "alldefine.h"

class obstacle;

typedef struct obstacleGroup
{
    obstacle* obstacleUp;
    obstacle* obstacleDown;
}GROUP;

class obstacle : public QGraphicsItem
{
public:
    obstacle(int n,
             int length);
    inline void MOVE();
    bool isAddScore;

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    int nLocation;
    int nLength;
    QPixmap* obstacle_up;
    QPixmap* obstacle_down;
};

inline void obstacle::MOVE()
{
    this->moveBy(-OBSTACLESPEED, 0);
}

#endif // OBSTACLE_H
