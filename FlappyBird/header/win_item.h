#ifndef WIN_ITEM_H
#define WIN_ITEM_H
#include "alldefine.h"


class win_Item : public QGraphicsItem
{
public:
    win_Item();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
};

#endif // WIN_ITEM_H
