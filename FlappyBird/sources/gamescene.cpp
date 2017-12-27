#include "gamescene.h"

gameScene::gameScene(QObject* parent):
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

    isCollides = false;

    obstacleList = new QList<GROUP*>;
    bird = new birdItem;
    this->addItem(bird);

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
}

gameScene::~gameScene()
{
    this->stop();
    delete bird;
}

void gameScene::GameBkTransition()
{
    gameBkCount++;
    gameBk->moveBy(-1, 0);
    if(gameBkCount == 292)
    {
        gameBkCount = 0;
        gameBk->moveBy(292, 0);
    }
}

void gameScene::updateScore()
{
    score->updateScore(++nScore);
}

void gameScene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() & Qt::Key_Space && !isCollides)
    {
//        sound->play();
        birdFly();
    }
    QGraphicsScene::keyPressEvent(event);
}

void gameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() & Qt::LeftButton && !isCollides)
    {
//        sound->play();
        birdFly();
    }
    QGraphicsScene::mousePressEvent(event);
}

void gameScene::birdFall()
{
    birdMoveCount += BIRDFALLSPEED;
    bird->moveBy(0, birdMoveCount);
    qreal by = bird->pos().y();
    if(by > 370)
        stop();
    if(bird->rotation() != -20 && birdMoveCount < 0)
    {
        bird->setRotation(-20);
    }
    else if(bird->rotation() != 20 && birdMoveCount > 0)
    {
        bird->setRotation(20);
    }
    if((!bird->collidingItems().isEmpty() && !isCollides) || by < -155)
    {
        isCollides = true;
        birdMoveCount = 0;
        obstacleMoveTimer->stop();
    }
}

void gameScene::stop()
{
    birdFallTimer->stop();
    obstacleMoveTimer->stop();
    addObstacleTimer->stop();
    scoreUpdateTimer->stop();
    gameBkTimer->stop();

    if(scoreItem::mostScore < score->score)
        scoreItem::mostScore = score->score;

    gameOver = new game_over_scene;
    this->view->setScene(gameOver);
    gameOver->setView(view);

    this->clear();
}

void gameScene::InitObstacle()
{
    GROUP* group = new GROUP;
    obstacleList->append(group);
    int n = qrand()%150;
    group->obstacleUp = new obstacle(OBSTACLEUP,
                                     60 + n);
    group->obstacleDown = new obstacle(OBSTACLEDOWN,
                                       230 - n + (qrand()%15 - 5));
    this->addItem(group->obstacleUp);
    this->addItem(group->obstacleDown);
}

void gameScene::obstacleMove()
{
    for(int i = 0; i < obstacleList->length(); i++)
    {
        GROUP* group = obstacleList->at(i);
        group->obstacleDown->MOVE();
        group->obstacleUp->MOVE();
        if(group->obstacleUp->isAddScore == false && group->obstacleUp->pos().x()+OBSTACLESTART+OBSTACLEWIDTH < bird->pos().x())
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
