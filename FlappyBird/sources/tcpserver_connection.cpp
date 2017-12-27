#include "tcpserver_connection.h"
#include "tcpserver_scene.h"


tcpserver_connection::tcpserver_connection(QObject* parent):
    QThread(parent)
{
}

void tcpserver_connection::run()
{

}

void tcpserver_connection::connectClient()
{
    client = server->nextPendingConnection();
    disconnect(server,
               SIGNAL(newConnection()),
               this,
               SLOT(connectClient()));

    connect(client,
            SIGNAL(readyRead()),
            this,
            SLOT(readMessage()));
}

void tcpserver_connection::readMessage()
{
    QByteArray bytes = client->readAll();
    qDebug() << bytes;
    if(bytes == QString("space"))
    {

    }
}
