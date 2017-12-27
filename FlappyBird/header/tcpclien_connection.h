#ifndef TCPCLIEN_CONNECTION_H
#define TCPCLIEN_CONNECTION_H
#include "alldefine.h"


class tcpclien_connection : public QThread
{
    Q_OBJECT
public:
    tcpclien_connection(QObject* parent = 0);

protected:
    void run();

private:
    QTcpSocket* client;
};

#endif // TCPCLIEN_CONNECTION_H
