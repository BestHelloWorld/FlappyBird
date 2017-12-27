#include "tcp_select_scene.h"
#include "tcpclient_scene.h"
#include "tcpserver_wait_scene.h"
#include "tcp_select_search_item.h"
#include "tcp_select_server_item.h"


tcp_select_scene::tcp_select_scene()
{
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

    gameButtom = new game_buttom;
    this->addItem(gameButtom);
    gameButtomCount = 0;

    gameButtomTimer = new QTimer(this);
    connect(gameButtomTimer,
            SIGNAL(timeout()),
            this,
            SLOT(GameButtomTransition()));
    gameButtomTimer->start(8);

    this->setSceneRect(QRectF(-110,
                              -150,
                              290,
                              390));
    this->setBackgroundBrush(QBrush(Qt::yellow));

    transitionTimer = new QTimer(this);
    exitTransitionTimer = new QTimer(this);
    clientBeginTransitionTimer = new QTimer(this);
    serverBeginTransitionTimer = new QTimer(this);
    connect(transitionTimer,
            SIGNAL(timeout()),
            this,
            SLOT(WlcTransition()));

    connect(exitTransitionTimer,
            SIGNAL(timeout()),
            this,
            SLOT(ExitTransition()));

    connect(clientBeginTransitionTimer,
            SIGNAL(timeout()),
            this,
            SLOT(ClientBeginTransition()));

    connect(serverBeginTransitionTimer,
            SIGNAL(timeout()),
            this,
            SLOT(ServerBeginTransition()));

    transitionTimer->start(10);

    search_btn = new tcp_select_search_item;
    server_btn = new tcp_select_server_item;

    addItem(search_btn);
    addItem(server_btn);

    client_effect = new QGraphicsOpacityEffect(this);
    server_effect = new QGraphicsOpacityEffect(this);
    home_effect = new QGraphicsOpacityEffect(this);

    client_effect->setOpacity(0.7);
    server_effect->setOpacity(0.7);
    home_effect->setOpacity(0.7);

    search_btn->setGraphicsEffect(client_effect);
    server_btn->setGraphicsEffect(server_effect);

}

void tcp_select_scene::GameBkTransition()
{
    gameBkCount++;
    gameBk->moveBy(-1, 0);
    if(gameBkCount == 292)
    {
        gameBkCount = 0;
        gameBk->moveBy(292, 0);
    }
}

void tcp_select_scene::GameButtomTransition()
{
    gameButtomCount++;
    gameButtom->moveBy(-1, 0);
    if(gameButtomCount == 95)
    {
        gameButtomCount = 0;
        gameButtom->moveBy(95, 0);
    }
}

void tcp_select_scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        QPointF point = event->scenePos();
        int bx = -25;
        int by = 80;
        if(point.x() > bx && point.y() > by && point.x() < (bx + 120) && point.y() < (by + 25))
        {
            effect->play();
            clientBeginTransitionTimer->start(10);
        }
        int ex = -25;
        int ey = 120;
        if(point.x() > ex && point.y() > ey && point.x() < (ex + 120) && point.y() < (ey + 25))
        {
            effect->play();
            serverBeginTransitionTimer->start(10);
        }
    }
    QGraphicsScene::mousePressEvent(event);
}

void tcp_select_scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF point = event->scenePos();
    int bx = -25;
    int by = 80;
    if(point.x() > bx && point.y() > by && point.x() < (bx + 120) && point.y() < (by + 25))
    {
        client_effect->setOpacity(1);
    }
    else
    {
        client_effect->setOpacity(0.7);
    }
    int ex = -25;
    int ey = 120;
    if(point.x() > ex && point.y() > ey && point.x() < (ex + 120) && point.y() < (ey + 25))
    {
        server_effect->setOpacity(1);
    }
    else
    {
        server_effect->setOpacity(0.7);
    }
    QGraphicsScene::mouseMoveEvent(event);
}

void tcp_select_scene::ExitTransition()
{
    transitionCount++;

    search_btn->moveBy(2, 0);
    server_btn->moveBy(-2, 0);

    if(transitionCount == 100)
    {
        exitTransitionTimer->stop();
        this->view->close();

    }
}

void tcp_select_scene::WlcTransition()
{
    transitionCount++;

    search_btn->moveBy(2, 0);
    server_btn->moveBy(-2, 0);

    if(transitionCount == 100)
    {
        transitionTimer->stop();
        transitionCount = 0;
    }
}

void tcp_select_scene::ServerBeginTransition()
{
    transitionCount++;

    search_btn->moveBy(2, 0);
    server_btn->moveBy(-2, 0);

    if(transitionCount == 100)
    {
        transitionCount = 0;
        tcpserver_wait_scene* scene = new tcpserver_wait_scene;
        this->view->setScene(scene);
        scene->setView(view);

        gameBkTimer->stop();
        transitionTimer->stop();
        exitTransitionTimer->stop();
        clientBeginTransitionTimer->stop();
        serverBeginTransitionTimer->stop();
        gameButtomTimer->stop();

        this->clear();
    }
}

void tcp_select_scene::ClientBeginTransition()
{
    transitionCount++;


    if(transitionCount == 100)
    {
        transitionCount = 0;
        tcpclient_scene* scene = new tcpclient_scene(this, view);
        this->view->setScene(scene);

        gameBkTimer->stop();
        transitionTimer->stop();
        exitTransitionTimer->stop();
        clientBeginTransitionTimer->stop();
        serverBeginTransitionTimer->stop();
        gameButtomTimer->stop();

        this->clear();
    }
}

