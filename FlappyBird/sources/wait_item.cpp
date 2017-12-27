#include "wait_item.h"

wait_item::wait_item()
{
    QHostInfo info = QHostInfo::fromName(QHostInfo::localHostName());
    QList<QHostAddress> list = info.addresses();
    for(QHostAddress ip : list)
    {
        if(ip.protocol() == QAbstractSocket::IPv4Protocol)
            addr = ip.toString();
    }

}

QRectF wait_item::boundingRect() const
{

    return QRectF(-85 - 0.5,
                  -100 - 0.5,
                  250 + 1,
                  110 + 1);
}

void wait_item::paint(QPainter *painter,
                      const QStyleOptionGraphicsItem *option,
                      QWidget *widget)
{
    painter->drawText(QRectF(-85,
                            -100,
                            250,
                            50),
                      "wait for client join ...",
                      QTextOption(Qt::AlignVCenter|Qt::AlignHCenter));
    painter->drawText(QRectF(-85,
                            -40,
                            250,
                            50),
                      QString("your LAN IP : "+addr),
                      QTextOption(Qt::AlignVCenter|Qt::AlignHCenter));
}
