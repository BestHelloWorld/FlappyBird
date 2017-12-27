#ifndef WAIT_ITEM_H
#define WAIT_ITEM_H
#include "alldefine.h"


class wait_item : public QGraphicsItem
{
public:
    wait_item();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QString addr;
};

#endif // WAIT_ITEM_H
