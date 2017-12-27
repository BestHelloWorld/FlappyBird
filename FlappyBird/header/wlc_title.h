#ifndef WLC_TITLE_H
#define WLC_TITLE_H
#include "alldefine.h"


class wlc_title : public QGraphicsItem
{
public:
    wlc_title();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QPixmap* pixmap;
};

class game_over_title_item : public QGraphicsItem
{
public:
    game_over_title_item();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QPixmap* pixmap;
};

#endif // WLC_TITLE_H
