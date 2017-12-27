#include "win_item.h"
#include "scoreitem.h"


win_Item::win_Item()
{

}

QRectF win_Item::boundingRect() const
{
    return QRectF(-85 - 0.5,
                  -100 - 200 - 0.5,
                  250 + 1,
                  100 + 1);
}

void win_Item::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    painter->drawText(QRectF(-85,
                             -100 - 80,
                             250,
                             20),
                      QString("score : %1").arg(scoreItem::score),
                      QTextOption(Qt::AlignHCenter));
    painter->drawText(QRectF(-85,
                             -100 - 50,
                             250,
                             20),
                      QString("most score : %1").arg(scoreItem::mostScore),
                      QTextOption(Qt::AlignHCenter));
    QFont font = painter->font();
    font.setPointSize(20);
    painter->setFont(font);
    painter->drawText(QRectF(-85,
                            -100 - 200,
                            250,
                            100),
                      "Win",
                      QTextOption(Qt::AlignVCenter|Qt::AlignHCenter));
}
