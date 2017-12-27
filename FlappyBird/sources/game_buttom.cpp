#include "game_buttom.h"

game_buttom::game_buttom()
{
    pixmap = new QPixmap(":/game/game_buttom.png");
    this->setZValue(11);
}

QRectF game_buttom::boundingRect() const
{
    return QRectF(-150 - 0.5,
                  200 - 0.5,
                  500 + 1,
                  50 + 1);
}

void game_buttom::paint(QPainter *painter,
                        const QStyleOptionGraphicsItem *option,
                        QWidget *widget)
{
    painter->drawPixmap(QRect(-150,
                               200,
                               500,
                               50),
                        *pixmap);
}
