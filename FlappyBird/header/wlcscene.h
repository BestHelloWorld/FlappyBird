#ifndef WLCSCENE_H
#define WLCSCENE_H
#include "alldefine.h"
#include "wlc_title.h"
#include "wlc_begin_btn.h"
#include "wlc_exit_btn.h"
#include "gamescene.h"
#include "game_background.h"


class game_buttom;
class game_over_return_home;
class wlc_2p_start_btn;

class wlcScene : public QGraphicsScene
{
    Q_OBJECT
public:
    wlcScene(QObject* parent = 0);
    ~wlcScene();
    inline void setView(QGraphicsView* view);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

protected slots:
    void ExitTransition();
    void WlcTransition();
    void BeginTransition();
    void GameButtomTransition();
    void GameBkTransition();

private:
    QGraphicsView* view;
    wlc_title* title;
    wlc_begin_btn* begin_btn;
    wlc_exit_btn* exit_btn;
    wlc_2p_start_btn* tcpbegin_btn;
    game_buttom* gameButtom;
    game_background* gameBk;
    QTimer* gameBkTimer;
    QTimer* transitionTimer;
    QTimer* exitTransitionTimer;
    QTimer* beginTransitionTimer;
    QTimer* gameButtomTimer;
    int gameBkCount;
    int transitionCount;
    int gameButtomCount;
    QGraphicsOpacityEffect* begin_effect;
    QGraphicsOpacityEffect* tcpstart_effect;
    QGraphicsOpacityEffect* exit_effect;
    QSound* effect;
};

inline void wlcScene::setView(QGraphicsView* view)
{
    this->view = view;
}


class game_over_scene : public QGraphicsScene
{
    Q_OBJECT
public:
    game_over_scene(QObject* parent = 0);
    ~game_over_scene();
    inline void setView(QGraphicsView* view);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

protected slots:
    void ExitTransition();
    void WlcTransition();
    void BeginTransition();
    void GameButtomTransition();
    void GameBkTransition();
    void ReturnHomeTransition();

private:
    QGraphicsView* view;
    game_buttom* gameButtom;
    game_over_return_home* home_btn;
    QTimer* transitionTimer;
    QTimer* returnHomeTimer;
    QTimer* gameBkTimer;
    int transitionCount;
    game_background* gameBk;
    int gameBkCount;
    QSound* effect;
    QGraphicsOpacityEffect* home_effect;

    int gameButtomCount;
    game_over_title_item* title;
    game_over_restart_item* begin_btn;
    game_over_exit_item* exit_btn;
    QGraphicsOpacityEffect* begin_effect;
    QGraphicsOpacityEffect* exit_effect;
    QTimer* exitTransitionTimer;
    QTimer* beginTransitionTimer;
    QTimer* gameButtomTimer;
};

inline void game_over_scene::setView(QGraphicsView* view)
{
    this->view = view;
}

#endif // WLCSCENE_H
