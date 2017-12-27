#ifndef WLC_BEGIN_BTN_H
#define WLC_BEGIN_BTN_H
#include "alldefine.h"


class wlc_begin_btn : public QGraphicsItem
{
public:
    wlc_begin_btn();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QPixmap* pixmap;
    QFont* font;
};


class game_over_restart_item : public QGraphicsItem
{
public:
    game_over_restart_item();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QPixmap* pixmap;
    QFont* font;
};

#endif // WLC_BEGIN_BTN_H
