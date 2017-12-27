#ifndef GAME_OVER_RETURN_HOME_H
#define GAME_OVER_RETURN_HOME_H
#include "alldefine.h"

class game_over_return_home : public QGraphicsItem
{
public:
    game_over_return_home();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QPixmap* pixmap;
};

#endif // GAME_OVER_RETURN_HOME_H
