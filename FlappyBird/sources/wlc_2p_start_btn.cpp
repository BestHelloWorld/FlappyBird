#include "wlc_2p_start_btn.h"

wlc_2p_start_btn::wlc_2p_start_btn()
{
    pixmap = new QPixmap(":/wlc/wlc_begin_btn.png");
}

QRectF wlc_2p_start_btn::boundingRect() const
{
    return QRectF(-25 + 200 - 0.5,
                  120 - 0.5,
                  120 + 1,
                  25 + 1);
}

void wlc_2p_start_btn::paint(QPainter *painter,
                             const QStyleOptionGraphicsItem *option,
                             QWidget *widget)
{
    QRect rect(-25 + 200,
               120,
               120,
               25);
    painter->drawPixmap(rect,
                        *pixmap);
//    painter->setFont(*font);
    painter->drawText(rect,
                      "2P (Beta)",
                      QTextOption(Qt::AlignVCenter|Qt::AlignHCenter));
}
