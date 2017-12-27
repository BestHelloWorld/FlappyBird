#include "game_over_return_home.h"

game_over_return_home::game_over_return_home()
{
    pixmap = new QPixmap(":/game_over/game_over_home.png");
    this->setZValue(20);
}

QRectF game_over_return_home::boundingRect() const
{
    return QRectF(-110 - 0.5,
                  210 - 0.5,
                  30 + 1,
                  30 + 1);
}
void game_over_return_home::paint(QPainter *painter,
                                  const QStyleOptionGraphicsItem *option,
                                  QWidget *widget)
{
    painter->drawPixmap(-110,
                        210,
                        30,
                        30,
                        *pixmap);
}
