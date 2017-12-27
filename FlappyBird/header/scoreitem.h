#ifndef SCOREITEM_H
#define SCOREITEM_H
#include "alldefine.h"


class scoreItem : public QGraphicsItem
{
public:
    scoreItem();
    static int mostScore;
    static int score;

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

public:
    void updateScore(int score);

private:
    QTimer* timer;
    QFont* font;
};

#endif // SCOREITEM_H
