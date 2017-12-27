#ifndef TCP_SELECT_SEARCH_ITEM_H
#define TCP_SELECT_SEARCH_ITEM_H
#include "alldefine.h"


class tcp_select_search_item : public QGraphicsItem
{
public:
    tcp_select_search_item();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QPixmap* pixmap;
};

#endif // TCP_SELECT_SEARCH_ITEM_H
