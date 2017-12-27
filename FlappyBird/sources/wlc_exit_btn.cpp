#include "wlc_exit_btn.h"

wlc_exit_btn::wlc_exit_btn()
{
    pixmap = new QPixmap(":/wlc/wlc_begin_btn.png");
}

QRectF wlc_exit_btn::boundingRect() const
{
    return QRectF(-25 - 200 - 0.5,
                  160 - 0.5,
                  120 + 1,
                  25 + 1);
}

void wlc_exit_btn::paint(QPainter *painter,
                         const QStyleOptionGraphicsItem *option,
                         QWidget *widget)
{
    QRect rect(-25 - 200,
               160,
               120,
               25);
    painter->drawPixmap(rect,
                        *pixmap);
//    painter->setFont(*font);
    painter->drawText(rect,
                      "EXIT",
                      QTextOption(Qt::AlignVCenter|Qt::AlignHCenter));

}

game_over_exit_item::game_over_exit_item()
{
    pixmap = new QPixmap(":/game_over/game_over_exit_btn.png");
}

QRectF game_over_exit_item::boundingRect() const
{
    return QRectF(60-0.5 + 200,
                  100-0.5,
                  60+1,
                  60+1);
}

void game_over_exit_item::paint(QPainter *painter,
                         const QStyleOptionGraphicsItem *option,
                         QWidget *widget)
{
    QRect rect(60 + 200,
               100,
               60,
               60);
    painter->drawPixmap(rect,
                        *pixmap);
//    painter->setFont(*font);
    painter->drawText(rect,
                      "EXIT",
                      QTextOption(Qt::AlignVCenter|Qt::AlignHCenter));

}
