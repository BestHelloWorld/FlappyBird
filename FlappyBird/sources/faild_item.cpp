#include "faild_item.h"
#include "scoreitem.h"


faild_item::faild_item()
{

}

QRectF faild_item::boundingRect() const
{
    return QRectF(-85 - 0.5,
                  -100 - 200 - 0.5,
                  250 + 1,
                  100 + 1);
}

void faild_item::paint(QPainter *painter,
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
                      "Fail",
                      QTextOption(Qt::AlignVCenter|Qt::AlignHCenter));
}
