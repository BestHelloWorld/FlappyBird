#ifndef TCPSERVER_CONNECTION_H
#define TCPSERVER_CONNECTION_H
#include "alldefine.h"
#include "birditem.h"


class tcpserver_scene;

class tcpserver_connection : public QThread
{
    Q_OBJECT
public:
    tcpserver_connection(QObject* parent = 0);
    inline void setClientBird(birdItem* bird);

protected:
    void run();
    void clientBirdFall();

protected slots:
    void connectClient();
    void readMessage();

private:
    QTcpServer* server;
    QTcpSocket* client;
    birdItem* client_bird;
    tcpserver_scene* scene;
};

inline void tcpserver_connection::setClientBird(birdItem * bird)
{
    client_bird = bird;
}

#endif // TCPSERVER_CONNECTION_H
