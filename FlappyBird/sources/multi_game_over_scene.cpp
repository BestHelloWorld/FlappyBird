#include "multi_game_over_scene.h"
#include "win_item.h"
#include "faild_item.h"


multi_game_over_scene::multi_game_over_scene(bool isWin, QObject* parent):
    QGraphicsScene(parent)
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

    this->setSceneRect(QRectF(-110,
                              -150,
                              290,
                              390));
//    this->setBackgroundBrush(QBrush(Qt::yellow));

    transitionTimer = new QTimer(this);
    exitTransitionTimer = new QTimer(this);
    beginTransitionTimer = new QTimer(this);
    gameButtomTimer = new QTimer(this);
    returnHomeTimer = new QTimer(this);

    connect(gameButtomTimer,
            SIGNAL(timeout()),
            this,
            SLOT(GameButtomTransition()));

    gameButtom = new game_buttom;
    this->addItem(gameButtom);
    gameButtomCount = 0;

    connect(transitionTimer,
            SIGNAL(timeout()),
            this,
            SLOT(WlcTransition()));

    connect(exitTransitionTimer,
            SIGNAL(timeout()),
            this,
            SLOT(ExitTransition()));

    connect(beginTransitionTimer,
            SIGNAL(timeout()),
            this,
            SLOT(BeginTransition()));

    connect(returnHomeTimer,
            SIGNAL(timeout()),
            this,
            SLOT(ReturnHomeTransition()));

    if(isWin)
    {
        win_title = new win_Item;
        this->addItem(win_title);
    }
    else
    {
        faild_title = new faild_item;
        this->addItem(faild_title);
    }
    this->isWin = isWin;

    begin_btn = new game_over_restart_item;
    this->addItem(begin_btn);

    exit_btn = new game_over_exit_item;
    this->addItem(exit_btn);

    home_btn = new game_over_return_home;
    this->addItem(home_btn);

    gameButtomTimer->start(8);
    transitionTimer->start(10);

    begin_effect = new QGraphicsOpacityEffect(this);
    exit_effect = new QGraphicsOpacityEffect(this);
    home_effect = new QGraphicsOpacityEffect(this);

    begin_effect->setOpacity(0.7);
    exit_effect->setOpacity(0.7);
    home_effect->setOpacity(0.7);

    begin_btn->setGraphicsEffect(begin_effect);
    exit_btn->setGraphicsEffect(exit_effect);
    home_btn->setGraphicsEffect(home_effect);

}

void multi_game_over_scene::GameBkTransition()
{
    gameBkCount++;
    gameBk->moveBy(-1, 0);
    if(gameBkCount == 292)
    {
        gameBkCount = 0;
        gameBk->moveBy(292, 0);
    }
}

void multi_game_over_scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        QPointF point = event->scenePos();
        int bx = -40;
        int by = 80;
        if(point.x() > bx && point.y() > by && point.x() < (bx + 80) && point.y() < (by + 80))
        {
            effect->play();
            beginTransitionTimer->start(10);
            QGraphicsScene::mousePressEvent(event);
            return;
        }
        int ex = 60;
        int ey = 100;
        if(point.x() > ex && point.y() > ey && point.x() < (ex + 80) && point.y() < (ey + 80))
        {
            effect->play();
            exitTransitionTimer->start(10);
            QGraphicsScene::mousePressEvent(event);
            return;
        }
        int rx = -110;
        int ry = 210;
        if(point.x() > rx && point.y() > ry && point.x() < (rx + 80) && point.y() < (ry + 80))
        {
            effect->play();
            returnHomeTimer->start(10);
            QGraphicsScene::mousePressEvent(event);
            return;
        }

    }
    QGraphicsScene::mousePressEvent(event);
}

void multi_game_over_scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF point = event->scenePos();
    int bx = -40;
    int by = 80;
    if(point.x() > bx && point.y() > by && point.x() < (bx + 80) && point.y() < (by + 80))
    {
        begin_effect->setOpacity(1);
    }
    else
        begin_effect->setOpacity(0.7);
    int ex = 60;
    int ey = 100;
    if(point.x() > ex && point.y() > ey && point.x() < (ex + 80) && point.y() < (ey + 80))
    {
        exit_effect->setOpacity(1);
    }
    else
        exit_effect->setOpacity(0.7);
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

void multi_game_over_scene::ReturnHomeTransition()
{
    transitionCount++;
    if(isWin)
        win_title->moveBy(0, 2);
    else
        faild_title->moveBy(0, 2);
    begin_btn->moveBy(-2, 0);
    exit_btn->moveBy(2, 0);
    if(transitionCount == 100)
    {
        transitionCount = 0;
        wlcScene* wlc = new wlcScene;
        wlc->setView(view);
        view->setScene(wlc);

        transitionTimer->stop();
        exitTransitionTimer->stop();
        beginTransitionTimer->stop();
        gameButtomTimer->stop();
        returnHomeTimer->stop();
        gameBkTimer->stop();

        this->clear();
    }
}

void multi_game_over_scene::ExitTransition()
{
    transitionCount++;
    if(isWin)
        win_title->moveBy(0, -2);
    else
        faild_title->moveBy(0, -2);
    begin_btn->moveBy(-2, 0);
    exit_btn->moveBy(2, 0);
    if(transitionCount == 100)
    {
        exitTransitionTimer->stop();
        transitionCount = 0;
        this->view->close();
    }
}

void multi_game_over_scene::WlcTransition()
{
    transitionCount++;
    if(isWin)
        win_title->moveBy(0, 2);
    else
        faild_title->moveBy(0, 2);
    begin_btn->moveBy(2, 0);
    exit_btn->moveBy(-2, 0);
    if(transitionCount == 100)
    {
        transitionTimer->stop();
        transitionCount = 0;
    }
}

void multi_game_over_scene::BeginTransition()
{
    transitionCount++;
    if(isWin)
        win_title->moveBy(0, -2);
    else
        faild_title->moveBy(0, -2);
    begin_btn->moveBy(-2, 0);
    exit_btn->moveBy(2, 0);
    if(transitionCount == 100)
    {
        gameScene* scene = new gameScene;
        this->view->setScene(scene);
        transitionCount = 0;
        scene->setView(view);

        transitionTimer->stop();
        exitTransitionTimer->stop();
        beginTransitionTimer->stop();
        gameButtomTimer->stop();
        returnHomeTimer->stop();
        gameBkTimer->stop();

        this->clear();
    }
}

void multi_game_over_scene::GameButtomTransition()
{
    gameButtomCount++;
    gameButtom->moveBy(-1, 0);
    if(gameButtomCount == 95)
    {
        gameButtomCount = 0;
        gameButtom->moveBy(95, 0);
    }
}
