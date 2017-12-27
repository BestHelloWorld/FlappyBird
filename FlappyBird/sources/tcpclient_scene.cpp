#include "tcpclient_scene.h"
#include "tcp_select_scene.h"
#include "multi_game_over_scene.h"
#include <QInputDialog>

tcpclient_scene::tcpclient_scene(QObject* parent,
                                 QGraphicsView* view):
    QGraphicsScene(parent)
{
    this->view = view;
    socket = new QTcpSocket(this);

    QString IP = QInputDialog::getText(0,
                                       "message",
                                       "press server IP :");
//    qDebug() << IP;
    socket->connectToHost(IP,
                          45454);

    connect(socket,
            SIGNAL(error(QAbstractSocket::SocketError)),
            this,
            SLOT(displayError(QAbstractSocket::SocketError)));
    connect(socket,
            SIGNAL(readyRead()),
            this,
            SLOT(readMsg()));
    connect(socket,
            SIGNAL(disconnected()),
            this,
            SLOT(deleteLater()));

    sound = new QSound(":/music/pa.wav", this);

    gameBkCount = 0;
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
    this->setBackgroundBrush(QBrush(Qt::yellow));

    obstacleList = new QList<GROUP*>;

    bird = new birdItem(true);
    bird->moveBy(-70,
                 0);
    this->addItem(bird);

    server_bird = new birdItem(false);
    this->addItem(server_bird);

    score = new scoreItem;
    this->addItem(score);
    nScore = 0;

    birdFallTimer = new QTimer(this);
    connect(birdFallTimer,
            SIGNAL(timeout()),
            this,
            SLOT(birdFall()));
    birdFallTimer->start(15);
    birdMoveCount = 0;

    addObstacleTimer = new QTimer(this);
    connect(addObstacleTimer,
            SIGNAL(timeout()),
            this,
            SLOT(InitObstacle()));
    addObstacleTimer->start(OBSTACLESPACING);

    obstacleMoveTimer = new QTimer(this);
    connect(obstacleMoveTimer,
            SIGNAL(timeout()),
            this,
            SLOT(obstacleMove()));
    obstacleMoveTimer->start(8);

    scoreUpdateTimer = new QTimer(this);
    connect(scoreUpdateTimer,
            SIGNAL(timeout()),
            this,
            SLOT(updateScore()));

    gameButtom = new game_buttom;
    this->addItem(gameButtom);
    gameButtomCount = 0;

    isCollides = false;
    serverIsCollides = false;
    keyClose = false;
}

void tcpclient_scene::displayError(QAbstractSocket::SocketError)
{
    qDebug() << "error";
    tcp_select_scene* scene = new tcp_select_scene;
    scene->setView(view);
    this->view->setScene(scene);

    birdFallTimer->stop();
    obstacleMoveTimer->stop();
    addObstacleTimer->stop();
    scoreUpdateTimer->stop();
    gameBkTimer->stop();
    socket->close();
    socket->deleteLater();
}

void tcpclient_scene::serverBirdPlay(qint32 x,
                                     qint32 y,
                                     qint32 deg,
                                     qint32 score)
{
    server_bird->setPos(x, y);
    server_bird->setRotation(deg);
}

void tcpclient_scene::sendMsg(qint32 x,
                              qint32 y,
                              qint32 deg,
                              qint32 score)
{
    QByteArray bytes;
    QDataStream stream(&bytes, QIODevice::ReadWrite);
    stream << x << y << deg << score;
    socket->write(bytes);
}

void tcpclient_scene::readMsg()
{
    qint32 x = 0,
            y = 0,
            deg = 0,
            score = 0;
    QDataStream stream(socket);
    stream >> x >> y >> deg >> score;
    this->serverBirdScore = score;
    if(x == 0)
    {
        serverBirdPlay(x, y, deg, score);
    }
    else
    {
        qsrand(deg);
    }

    if(server_bird->pos().y() > 300)
    {
        serverIsCollides = true;
        serverBirdScore = score;
    }
}

void tcpclient_scene::GameBkTransition()
{
    gameBkCount++;
    gameBk->moveBy(-1, 0);
    if(gameBkCount == 292)
    {
        gameBkCount = 0;
        gameBk->moveBy(292, 0);
    }
}

void tcpclient_scene::updateScore()
{
    score->updateScore(++nScore);
}

void tcpclient_scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() & Qt::Key_Space && !keyClose)
    {
        birdFly();
    }
    QGraphicsScene::keyPressEvent(event);
}

void tcpclient_scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() & Qt::LeftButton && !keyClose)
    {
        birdFly();
    }
    QGraphicsScene::mousePressEvent(event);
}

void tcpclient_scene::birdFall()
{
    birdMoveCount += BIRDFALLSPEED;
    bird->moveBy(0, birdMoveCount);
    qreal by = bird->pos().y();
    if(bird->pos().y() > 300)
        isCollides = true;
    if(server_bird->pos().y() > 300)
        serverIsCollides = true;
    if(isCollides && serverIsCollides)
    {
        socket->disconnectFromHost();
        this->stop();
    }
    if(bird->rotation() != -20 && birdMoveCount < 0)
    {
        bird->setRotation(-20);
    }
    else if(bird->rotation() != 20 && birdMoveCount > 0)
    {
        bird->setRotation(20);
    }
    if(bird->pos().y() < 600 && socket->isValid())
        sendMsg(0, bird->pos().y(), bird->rotation(), nScore);
    if((!bird->collidingItems().isEmpty() && !isCollides) || by < -155)
    {
//        isCollides = true;
        if(!keyClose)
        {
            keyClose = true;
            birdMoveCount = 0;
        }
    }
}

void tcpclient_scene::stop()
{
//    socket->close();

    socket->deleteLater();
    birdFallTimer->stop();
    obstacleMoveTimer->stop();
//    addObstacleTimer->stop();
//    scoreUpdateTimer->stop();
    gameBkTimer->stop();

    if(scoreItem::mostScore < score->score)
        scoreItem::mostScore = score->score;

//    gameOver = new game_over_scene;
    multi_game_over_scene* gameOver = new multi_game_over_scene(serverBirdScore < nScore ? true : false);
    this->view->setScene(gameOver);
    gameOver->setView(view);

//    socket->close();
//    socket->deleteLater();
//    this->clear();
}

void tcpclient_scene::InitObstacle()
{
    int n = qrand()%150;
    int m = (qrand()%15 - 5);
    GROUP* group = new GROUP;
    obstacleList->append(group);
    group->obstacleUp = new obstacle(OBSTACLEUP,
                                     60 + n);
    group->obstacleDown = new obstacle(OBSTACLEDOWN,
                                       230 - n + m);
    this->addItem(group->obstacleUp);
    this->addItem(group->obstacleDown);
}

void tcpclient_scene::obstacleMove()
{
    for(int i = 0; i < obstacleList->length(); i++)
    {
        GROUP* group = obstacleList->at(i);
        group->obstacleDown->MOVE();
        group->obstacleUp->MOVE();
        if(group->obstacleUp->isAddScore == false && group->obstacleUp->pos().x()+OBSTACLESTART+OBSTACLEWIDTH < bird->pos().x() && !isCollides)
        {
            group->obstacleUp->isAddScore = true;
            score->updateScore(++nScore);
        }
        if(group->obstacleUp->pos().x() < -700)
        {
            obstacleList->removeAt(i);
        }
    }
    gameButtomCount++;
    gameButtom->moveBy(-1, 0);
    if(gameButtomCount == 95)
    {
        gameButtomCount = 0;
        gameButtom->moveBy(95, 0);
    }
}
