#include "wlc_begin_btn.h"

wlc_begin_btn::wlc_begin_btn()
{
    pixmap = new QPixmap(":/wlc/wlc_begin_btn.png");
}

QRectF wlc_begin_btn::boundingRect() const
{
    return QRectF(-25 - 0.5 -200,
                  80 - 0.5,
                  120 + 1,
                  25 + 1);
}

void wlc_begin_btn::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    QRect rect(-25 - 200,
               80,
               120,
               25);
    painter->drawPixmap(rect,
                        *pixmap);
    painter->drawText(rect,
                      "1P",
                      QTextOption(Qt::AlignVCenter|Qt::AlignHCenter));

}

game_over_restart_item::game_over_restart_item()
{
    pixmap = new QPixmap(":/game_over/game_over_restart_btn.png");
}

QRectF game_over_restart_item::boundingRect() const
{
    return QRectF(-40 - 0.5 -200,
                  80 - 0.5,
                  80 + 1,
                  80 + 1);
}
void game_over_restart_item::paint(QPainter *painter,
                                   const QStyleOptionGraphicsItem *option,
                                   QWidget *widget)
{
    QRect rect(-40 - 200,
               80,
               80,
               80);
    painter->drawPixmap(rect,
                        *pixmap);
    QFont font = painter->font();
    font.setPointSize(7);
    painter->setFont(font);
    painter->drawText(rect,
                      "RESTART",
                      QTextOption(Qt::AlignVCenter|Qt::AlignHCenter));
}
