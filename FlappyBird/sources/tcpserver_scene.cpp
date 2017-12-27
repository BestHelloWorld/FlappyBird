#include "tcpserver_scene.h"
#include "tcp_select_scene.h"
#include "multi_game_over_scene.h"


tcpserver_scene::tcpserver_scene(QObject* parent):
    QGraphicsScene(parent)
{
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

    bird = new birdItem;
    this->addItem(bird);

    client_bird = new birdItem(true);
    client_bird->moveBy(-70,
                        0);
    addItem(client_bird);

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
    clientBirdCount = 0;

    keyClose = false;
    isCollides = false;
    clientIsCollides = false;
}

void tcpserver_scene::displayError(QAbstractSocket::SocketError)
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
}

void tcpserver_scene::sendMsg(qint32 x, qint32 y, qint32 deg, qint32 score)
{
    QByteArray byte;
    QDataStream sender(&byte, QIODevice::ReadWrite);
    sender << x << y << deg << score;
//    qDebug() << "flappy bird send : " << byte;
    socket->write(byte);
}

void tcpserver_scene::readMsg()
{
    qint32 x = 0, y = 0, deg = 0, score = 0;
    QDataStream stream(socket);
    stream >> x >> y >> deg >> score;
//    qDebug() << "flappy bird receive : "<< x << y << deg << score;
    this->clientBirdPlay(0, y, deg);
    if(y >= 240)
    {
        clientIsCollides = true;
        clientBirdScore = score;
    }
}

void tcpserver_scene::birdFall()
{
    birdMoveCount += BIRDFALLSPEED;
    bird->moveBy(0, birdMoveCount);
    qreal by = bird->pos().y();
    if(bird->pos().y() > 300)
        isCollides = true;
    if(client_bird->pos().y() > 300)
        clientIsCollides = true;
    if(isCollides && clientIsCollides)
    {
//        qDebug() << "stop";
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



void tcpserver_scene::clientBirdPlay(qint32 x, qint32 y, qint32 deg)
{
    client_bird->setPos(client_bird->pos().x(), y);
    client_bird->setRotation(deg);
}

void tcpserver_scene::GameBkTransition()
{
    gameBkCount++;
    gameBk->moveBy(-1, 0);
    if(gameBkCount == 292)
    {
        gameBkCount = 0;
        gameBk->moveBy(292, 0);
    }
}

void tcpserver_scene::updateScore()
{
    score->updateScore(++nScore);
}

void tcpserver_scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() & Qt::Key_Space && !keyClose)
    {
        birdFly();
    }
    QGraphicsScene::keyPressEvent(event);
}

void tcpserver_scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() & Qt::LeftButton && !keyClose)
    {
        birdFly();
    }
    QGraphicsScene::mousePressEvent(event);
}

void tcpserver_scene::stop()
{
    socket->deleteLater();
    birdFallTimer->stop();
    obstacleMoveTimer->stop();
    addObstacleTimer->stop();
//    scoreUpdateTimer->stop();
    gameBkTimer->stop();

    if(scoreItem::mostScore < score->score)
        scoreItem::mostScore = score->score;

//    gameOver = new game_over_scene;
    multi_game_over_scene* gameOver = new multi_game_over_scene(nScore >= clientBirdScore ? true : false);
    this->view->setScene(gameOver);
    gameOver->setView(view);

//    socket->close();
//    socket->deleteLater();
//    qDebug() << "end";

}

void tcpserver_scene::InitObstacle()
{
    int n = qrand()%150;
    int m = (qrand()%15 - 5);
//    sendMsg(2, n, m, nScore);
    GROUP* group = new GROUP;
    obstacleList->append(group);

    group->obstacleUp = new obstacle(OBSTACLEUP,
                                     60 + n);
    group->obstacleDown = new obstacle(OBSTACLEDOWN,
                                       230 - n + m);
    this->addItem(group->obstacleUp);
    this->addItem(group->obstacleDown);
}

void tcpserver_scene::obstacleMove()
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
