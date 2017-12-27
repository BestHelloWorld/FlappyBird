#include "tcpserver_wait_scene.h"
#include "game_buttom.h"
#include "tcpserver_connection.h"
#include "tcpserver_scene.h"
#include "wait_item.h"


tcpserver_wait_scene::tcpserver_wait_scene()
{
    server = new QTcpServer(this);
    QHostInfo info = QHostInfo::fromName(QHostInfo::localHostName());
    QList<QHostAddress> list = info.addresses();
    QHostAddress ip;
    for(QHostAddress addr:list)
    {
        if(addr.protocol() == QAbstractSocket::IPv4Protocol)
            ip = addr;
    }
    server->listen(ip,
                   45454);
    qDebug() << QHostAddress::LocalHost;
    connect(server,
            SIGNAL(newConnection()),
            this,
            SLOT(connectSuccess()));

    effect = new QSound(":/music/pa.wav", this);

    gameBkCount = 0;
    transitionCount = 0;
    gameBkTimer = new QTimer(this);

    gameBk = new game_background;
    this->addItem(gameBk);

    connect(gameBkTimer,
            SIGNAL(timeout()),
            this,
            SLOT(GameBkTransition()));
    gameBkTimer->start(20);

    this->setSceneRect(QRectF(-110,
                              -150,
                              290,
                              390));
//    this->setBackgroundBrush(QBrush(Qt::yellow));
    gameButtomTimer = new QTimer(this);
    connect(gameButtomTimer,
            SIGNAL(timeout()),
            this,
            SLOT(GameButtomTransition()));

    gameButtom = new game_buttom;
    this->addItem(gameButtom);
    gameButtomCount = 0;
    home_btn = new game_over_return_home;
    this->addItem(home_btn);
    gameButtomTimer->start(8);
    home_effect = new QGraphicsOpacityEffect(this);
    home_effect->setOpacity(0.7);
    home_btn->setGraphicsEffect(home_effect);

    wait_item* wait = new wait_item;
    addItem(wait);

}

void tcpserver_wait_scene::connectSuccess()
{
    tcpserver_scene* scene = new tcpserver_scene;
    QTcpSocket* socket = server->nextPendingConnection();
    scene->setSocket(socket);
    server->disconnect(gameBkTimer,
                       SIGNAL(timeout()),
                       this,
                       SLOT(GameBkTransition()));
    view->setScene(scene);
    scene->setView(view);
    gameButtomTimer->stop();
    gameBkTimer->stop();

    server->close();
//    server->deleteLater();

}

void tcpserver_wait_scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    QGraphicsScene::mousePressEvent(event);
}

void tcpserver_wait_scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF point = event->scenePos();
    int rx = -110;
    int ry = 210;
    if(point.x() > rx && point.y() > ry && point.x() < (rx + 80) && point.y() < (ry + 80))
    {
        home_effect->setOpacity(1);
    }
    else
        home_effect->setOpacity(0.7);

    QGraphicsScene::mouseMoveEvent(event);
}

void tcpserver_wait_scene::GameBkTransition()
{
    gameBkCount++;
    gameBk->moveBy(-1, 0);
    if(gameBkCount == 292)
    {
        gameBkCount = 0;
        gameBk->moveBy(292, 0);
    }
}

void tcpserver_wait_scene::GameButtomTransition()
{
    gameButtomCount++;
    gameButtom->moveBy(-1, 0);
    if(gameButtomCount == 95)
    {
        gameButtomCount = 0;
        gameButtom->moveBy(95, 0);
    }
}

