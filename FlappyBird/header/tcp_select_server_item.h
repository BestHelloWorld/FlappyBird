#ifndef TCP_SELECT_SERVER_ITEM_H
#define TCP_SELECT_SERVER_ITEM_H
#include "alldefine.h"


class tcp_select_server_item : public QGraphicsItem
{
public:
    tcp_select_server_item();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QPixmap* pixmap;
};

#endif // TCP_SELECT_SERVER_ITEM_H
