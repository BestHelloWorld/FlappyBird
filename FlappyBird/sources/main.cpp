#include "gamescene.h"
#include "wlcscene.h"
#include "tcpserver_scene.h"
#include "tcpserver_wait_scene.h"
#include "tcp_select_scene.h"
#include <QApplication>
#include <QGraphicsView>
#include <QOpenGLWidget>

int main(int argc, char**argv)
{
    QApplication a(argc, argv);

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

    int id = QFontDatabase::addApplicationFont(":/font/PressStart2P.ttf");
    a.setFont(QFont(QFontDatabase::applicationFontFamilies(id).at(0),
                    7));
    QGraphicsView* view = new QGraphicsView;
    view->setFixedSize(300,
                       400);

    view->setMouseTracking(true);

    QCursor cursor;
    cursor.setShape(Qt::PointingHandCursor);
    view->setCursor(cursor);

    wlcScene scene;
    scene.setView(view);
    view->setScene(&scene);
    view->show();

    return a.exec();
}
