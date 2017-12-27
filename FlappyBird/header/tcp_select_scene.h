#ifndef TCP_SELECT_SCENE_H
#define TCP_SELECT_SCENE_H
#include "alldefine.h"
#include "game_buttom.h"
#include "game_background.h"

class tcp_select_search_item;
class tcp_select_server_item;


class tcp_select_scene : public QGraphicsScene
{
    Q_OBJECT
public:
    tcp_select_scene();
    inline void setView(QGraphicsView* view);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

protected slots:
    void ExitTransition();
    void WlcTransition();
    void ClientBeginTransition();
    void ServerBeginTransition();
    void GameButtomTransition();
    void GameBkTransition();

private:
    QGraphicsView* view;

    game_buttom* gameButtom;
    game_background* gameBk;
    QTimer* gameBkTimer;
    QTimer* transitionTimer;
    QTimer* exitTransitionTimer;
    QTimer* clientBeginTransitionTimer;
    QTimer* serverBeginTransitionTimer;
    QTimer* gameButtomTimer;
    int gameBkCount;
    int transitionCount;
    int gameButtomCount;
    tcp_select_search_item* search_btn;
    tcp_select_server_item* server_btn;
    QGraphicsOpacityEffect* client_effect;
    QGraphicsOpacityEffect* server_effect;
    QGraphicsOpacityEffect* home_effect;
    QSound* effect;
};

inline void tcp_select_scene::setView(QGraphicsView* view)
{
    this->view = view;
}

#endif // TCP_SELECT_SCENE_H
