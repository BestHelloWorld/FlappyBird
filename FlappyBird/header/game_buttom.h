#ifndef GAME_BUTTOM_H
#define GAME_BUTTOM_H
#include "alldefine.h"

class game_buttom : public QGraphicsItem
{
public:
    game_buttom();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QPixmap* pixmap;
};

#endif // GAME_BUTTOM_H
