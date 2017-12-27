#ifndef WLC_2P_START_BTN_H
#define WLC_2P_START_BTN_H
#include "alldefine.h"


class wlc_2p_start_btn : public QGraphicsItem
{
public:
    wlc_2p_start_btn();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    QPixmap* pixmap;
};

#endif // WLC_2P_START_BTN_H
