#ifndef TCPSERVER_WAIT_SCENE_H
#define TCPSERVER_WAIT_SCENE_H
#include "alldefine.h"
#include "game_background.h"
#include "game_over_return_home.h"

class game_buttom;
class tcpserver_connection;


class tcpserver_wait_scene : public QGraphicsScene
{
    Q_OBJECT
public:
    tcpserver_wait_scene();

    inline void setView(QGraphicsView* view);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

protected slots:
    void GameBkTransition();
    void GameButtomTransition();
    void connectSuccess();

private:
    QGraphicsView* view;
    game_buttom* gameButtom;
    int gameButtomCount;
    game_over_return_home* home_btn;
    QTimer* gameButtomTimer;
    QTimer* gameBkTimer;
    int transitionCount;
    game_background* gameBk;
    int gameBkCount;
    QSound* effect;
    QGraphicsOpacityEffect* home_effect;

    QTcpServer* server;
};

inline void tcpserver_wait_scene::setView(QGraphicsView *view)
{
    this->view = view;
}

#endif // TCPSERVER_WAIT_SCENE_H
