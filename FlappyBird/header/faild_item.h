#ifndef FAILD_ITEM_H
#define FAILD_ITEM_H
#include "alldefine.h"


class faild_item : public QGraphicsItem
{
public:
    faild_item();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
};

#endif // FAILD_ITEM_H
