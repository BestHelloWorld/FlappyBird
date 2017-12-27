#include "tcp_select_server_item.h"

tcp_select_server_item::tcp_select_server_item()
{
    pixmap = new QPixmap(":/wlc/wlc_begin_btn.png");
}

QRectF tcp_select_server_item::boundingRect() const
{
    return QRectF(-25 - 0.5 + 200,
                  120 - 0.5,
                  120 + 1,
                  25 + 1);
}

void tcp_select_server_item::paint(QPainter *painter,
                                   const QStyleOptionGraphicsItem *option,
                                   QWidget *widget)
{
    painter->drawPixmap(-25 + 200,
                        120,
                        120,
                        25,
                        *pixmap);
    painter->drawText(QRectF(-25 + 200,
                             120,
                             120,
                             25),
                      "create server",
                      QTextOption(Qt::AlignVCenter | Qt::AlignHCenter));
}
