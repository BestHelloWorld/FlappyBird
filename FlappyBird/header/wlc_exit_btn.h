#ifndef WLC_EXIT_BTN_H
#define WLC_EXIT_BTN_H
#include "alldefine.h"


class wlc_exit_btn : public QGraphicsItem
{
public:
    wlc_exit_btn();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QPixmap* pixmap;
    QFont* font;
};

class game_over_exit_item : public QGraphicsItem
{
public:
    game_over_exit_item();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QPixmap* pixmap;
    QFont* font;
};

#endif // WLC_EXIT_BTN_H
