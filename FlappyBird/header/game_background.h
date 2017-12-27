#ifndef GAME_BACKGROUND_H
#define GAME_BACKGROUND_H
#include "alldefine.h"

class game_background : public QGraphicsItem
{
public:
    game_background();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    QPainterPath shape() const;

private:
    QPixmap* pixmap;
};

#endif // GAME_BACKGROUND_H
