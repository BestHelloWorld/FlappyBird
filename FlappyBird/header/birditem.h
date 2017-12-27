#ifndef BIRDITEM_H
#define BIRDITEM_H
#include "alldefine.h"

class birdItem : public QGraphicsItem
{
public:
    birdItem(bool isClientBird = false);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    QPainterPath shape() const;

private:
    QPixmap* pixmap;
    bool isClientBird;
};

#endif // BIRDITEM_H
