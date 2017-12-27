#ifndef TCPSERVER_SCENE_H
#define TCPSERVER_SCENE_H
#include "alldefine.h"
#include "birditem.h"
#include "obstacle.h"
#include "scoreitem.h"
#include "wlcscene.h"
#include "game_buttom.h"
#include "tcpserver_connection.h"
#include <QGraphicsView>


class tcpserver_scene : public QGraphicsScene
{
    Q_OBJECT
public:
    tcpserver_scene(QObject* parent = 0);

    inline void setView(QGraphicsView* view);
    inline void setSocket(QTcpSocket* socket);

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    //bird control
    inline void birdFly();
    inline void clientBirdFly();
    void sendMsg(qint32 x, qint32 y, qint32 deg, qint32 score);

public slots:
    void birdFall();
    void clientBirdPlay(qint32 x, qint32 y, qint32 deg);
    void readMsg();
    void stop();
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
    birdItem* client_bird;
    bool clientIsCollides;
    QTcpSocket* socket;
    bool keyClose;
    double clientBirdCount;
    QTimer* clientBirdFallTimer;
    int clientBirdScore;
};

inline void tcpserver_scene::birdFly()
{
    birdMoveCount = -5;
}

inline void tcpserver_scene::clientBirdFly()
{
    clientBirdCount = -5;
}

inline void tcpserver_scene::setView(QGraphicsView *view)
{
    this->view = view;
}

inline void tcpserver_scene::setSocket(QTcpSocket *socket)
{
    this->socket = socket;
    QByteArray bytes;
    QDataStream stream(&bytes, QIODevice::ReadWrite);
    int srand = QTime(0, 0, 0).secsTo(QTime::currentTime());
    qsrand(srand);
    stream << (qint32)1 << (qint32)0 << (qint32)srand << (qint32)0;
    socket->write(bytes);
    connect(socket,
            SIGNAL(error(QAbstractSocket::SocketError)),
            this,
            SLOT(displayError(QAbstractSocket::SocketError)));
    connect(socket,
            SIGNAL(readyRead()),
            this,
            SLOT(readMsg()));

}

#endif // TCPSERVER_SCENE_H
