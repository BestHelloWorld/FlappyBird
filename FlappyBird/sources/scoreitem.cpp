#include "scoreitem.h"

int scoreItem::mostScore = 0;
int scoreItem::score = 0;

scoreItem::scoreItem()
{
    this->setZValue(10);
    int id = QFontDatabase::addApplicationFont(":/font/PressStart2P.ttf");
//    font = new QFont;
    font = new QFont(QFontDatabase::applicationFontFamilies(id).at(0), 15);
    score = 0;
}

QRectF scoreItem::boundingRect()const
{
    return QRectF(100-0.5,
                  -155-0.5,
                  150+0.5,
                  40+0.5);
}

void scoreItem::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem *option,
                      QWidget *widget)
{
    painter->setFont(*font);
    painter->setPen(QColor(230,
                           230,
                           230));
//    painter->setBrush(QBrush(QColor(0, 0, 0, 0)));
    painter->drawText(QRectF(100,
                             -155,
                             150,
                             40),
                      QString("%1").arg(score),
                      QTextOption(Qt::AlignBottom));
}

void scoreItem::updateScore(int score)
{
    this->score = score;
    this->update();
}
