#include "wlc_title.h"
#include "scoreitem.h"

wlc_title::wlc_title()
{
    pixmap = new QPixmap(":/wlc/wlc_bk.png");
}

QRectF wlc_title::boundingRect() const
{
    return QRectF(-85-0.5,
                  -100-0.5 - 200,
                  250+0.5,
                  100+0.5);
}

void wlc_title::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem *option,
                      QWidget *widget)
{
//    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPixmap(QRect(-85,
                              -100 - 200,
                              250,
                              100),
                        *pixmap);
}


game_over_title_item::game_over_title_item()
{

}

QRectF game_over_title_item::boundingRect() const
{
    return QRectF(-85-0.5,
                  -100-0.5 - 200,
                  250+0.5,
                  250+0.5);
}

void game_over_title_item::paint(QPainter *painter,
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
                      "GameOver",
                      QTextOption(Qt::AlignVCenter|Qt::AlignHCenter));
}
