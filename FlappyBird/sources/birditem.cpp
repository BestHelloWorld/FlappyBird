#include "birditem.h"

birdItem::birdItem(bool isClientBird)
{
    this->setZValue(10);
    this->isClientBird = isClientBird;
    if(!isClientBird)
        pixmap = new QPixmap(":/game/bird.png");
    else
        pixmap = new QPixmap(":/game/client_bird.png");
}

QRectF birdItem::boundingRect() const
{
    QRectF rect;

    if(!isClientBird)
    {
        rect.setRect((-BIRDWIDTH/2)-0.5,
                     (-BIRDHEIGHT/2)-0.5,
                     (BIRDWIDTH)+1,
                     (BIRDHEIGHT)+1);
    }
    else
    {
        rect.setRect((-28/2)-0.5,
                     (-21/2)-0.5,
                     (28)+1,
                     (21)+1);
    }
    return rect;
}

void birdItem::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
//    if(!isClientBird)
//    {
//        painter->drawPixmap(QRect((-BIRDWIDTH/2),
//                                  (-BIRDHEIGHT/2),
//                                  (BIRDWIDTH),
//                                  (BIRDHEIGHT)),
//                            *pixmap);
//    }
//    else
//    {
//        painter->drawPixmap(QRect((-28/2),
//                                  (-21/2),
//                                  (28),
//                                  (21)),
//                            *pixmap);
//    }
    painter->drawPixmap(QRect((-BIRDWIDTH/2),
                              (-BIRDHEIGHT/2),
                              (BIRDWIDTH),
                              (BIRDHEIGHT)),
                        *pixmap);
}

QPainterPath birdItem::shape() const
{
    QPainterPath path;
    path.addEllipse((-BIRDWIDTH/2),
                    (-BIRDHEIGHT/2),
                    (BIRDWIDTH),
                    (BIRDHEIGHT));
    return path;
}
