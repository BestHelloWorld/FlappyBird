#ifndef GAMESCENE_H
#define GAMESCENE_H
#include "alldefine.h"
#include "birditem.h"
#include "obstacle.h"
#include "scoreitem.h"
#include "wlcscene.h"
#include "game_buttom.h"
#include <QGraphicsView>

class game_over_scene;
class game_background;

class gameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    gameScene(QObject* parent = 0);
    ~gameScene();
    inline void setView(QGraphicsView* view);

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //bird control
    inline void birdFly();
    void stop();

public slots:
    void birdFall();
    void obstacleMove();
    void InitObstacle();
    void updateScore();
    void GameBkTransition();

private:
    QGraphicsView* view;
    birdItem* bird;
    QTimer* birdFallTimer;
    QTimer* obstacleMoveTimer;
    QTimer* addObstacleTimer;
    QTimer* scoreUpdateTimer;
    QTimer* gameBkTimer;
    double birdMoveCount;
    QList<GROUP*>* obstacleList;
    bool isCollides;
    scoreItem* score;
    game_buttom* gameButtom;
    game_over_scene* gameOver;
    int gameButtomCount;
    int nScore;
    game_background* gameBk;
    int gameBkCount;
    QSound* sound;
};

inline void gameScene::birdFly()
{
    birdMoveCount = -5;
}

inline void gameScene::setView(QGraphicsView *view)
{
    this->view = view;
}

#endif // GAMESCENE_H
