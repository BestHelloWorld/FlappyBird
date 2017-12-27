#ifndef MULTI_GAME_OVER_SCENE_H
#define MULTI_GAME_OVER_SCENE_H
#include "alldefine.h"
#include "game_buttom.h"
#include "game_background.h"
#include "game_over_return_home.h"
#include "wlcscene.h"

class win_Item;
class faild_item;


class multi_game_over_scene : public QGraphicsScene
{
    Q_OBJECT
public:
    multi_game_over_scene(bool isWin, QObject* parent = 0);
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
    game_over_restart_item* begin_btn;
    game_over_exit_item* exit_btn;
    QGraphicsOpacityEffect* begin_effect;
    QGraphicsOpacityEffect* exit_effect;
    QTimer* exitTransitionTimer;
    QTimer* beginTransitionTimer;
    QTimer* gameButtomTimer;
    win_Item* win_title;
    faild_item* faild_title;
    bool isWin;
};

inline void multi_game_over_scene::setView(QGraphicsView* view)
{
    this->view = view;
}

#endif // MULTI_GAME_OVER_SCENE_H
