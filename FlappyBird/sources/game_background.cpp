#include "game_background.h"

game_background::game_background()
{
    this->setZValue(-1);
    pixmap = new QPixmap(":/game/game_bk.png");
}

QRectF game_background::boundingRect() const
{
    return QRectF(-120 - 0.5,
                  -155 - 0.5,
                  879 + 1,
                  400 + 1);
}

void game_background::paint(QPainter *painter,
                            const QStyleOptionGraphicsItem *option,
                            QWidget *widget)
{
    painter->drawPixmap(QRect(-120,
                              -155,
                              879,
                              400),
                        *pixmap);
}

QPainterPath game_background::shape() const
{
    QPainterPath path;
    path.addRect(-100,
                 -160,
                 300,
                 2);
    return path;
}
