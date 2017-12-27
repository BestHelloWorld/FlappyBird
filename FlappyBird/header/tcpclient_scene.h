#ifndef TCPCLIENT_SCENE_H
#define TCPCLIENT_SCENE_H
#include "alldefine.h"
#include "birditem.h"
#include "obstacle.h"
#include "scoreitem.h"
#include "wlcscene.h"
#include "game_buttom.h"
#include <QGraphicsView>


class tcpclient_scene : public QGraphicsScene
{
    Q_OBJECT
public:
    tcpclient_scene(QObject* parent,
                    QGraphicsView* view);

    inline void setView(QGraphicsView* view);

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //bird control
    inline void birdFly();
    void stop();
    void sendMsg(qint32 x, qint32 y, qint32 deg, qint32 score);

public slots:
    void birdFall();
    void serverBirdPlay(qint32 x, qint32 y, qint32 deg, qint32 score);
    void readMsg();
    void obstacleMove();
    void InitObstacle();
    void updateScore();
    void GameBkTransition();
    void displayError(QAbstractSocket::SocketError);

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
//    game_over_scene* gameOver;
    int gameButtomCount;
    int nScore;
    game_background* gameBk;
    int gameBkCount;
    QSound* sound;

private:
    birdItem* server_bird;
    bool serverIsCollides;
    bool keyClose;
    QTcpSocket* socket;
    double serverBirdCount;
    int serverBirdScore;
};

inline void tcpclient_scene::birdFly()
{
    birdMoveCount = -5;
}

inline void tcpclient_scene::setView(QGraphicsView *view)
{
    this->view = view;
}

#endif // TCPCLIENT_SCENE_H
