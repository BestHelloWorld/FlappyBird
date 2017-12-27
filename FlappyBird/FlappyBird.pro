#-------------------------------------------------
#
# Project created by QtCreator 2017-07-28T11:09:49
#
#-------------------------------------------------

QT       += widgets network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlappyBird
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    gamescene.cpp \
    birditem.cpp \
    obstacle.cpp \
    scoreitem.cpp \
    wlcscene.cpp \
    wlc_title.cpp \
    wlc_begin_btn.cpp \
    wlc_exit_btn.cpp \
    game_buttom.cpp \
    game_background.cpp \
    game_over_return_home.cpp \
    wlc_2p_start_btn.cpp \
    tcpserver_connection.cpp \
    tcpclient_scene.cpp \
    tcpserver_scene.cpp \
    tcpserver_wait_scene.cpp \
    tcp_select_scene.cpp \
    tcp_select_search_item.cpp \
    tcp_select_server_item.cpp \
    multi_game_over_scene.cpp \
    win_item.cpp \
    faild_item.cpp \
    wait_item.cpp

HEADERS  += \
    gamescene.h \
    alldefine.h \
    birditem.h \
    obstacle.h \
    scoreitem.h \
    wlcscene.h \
    wlc_title.h \
    wlc_begin_btn.h \
    wlc_exit_btn.h \
    game_buttom.h \
    game_background.h \
    game_over_return_home.h \
    wlc_2p_start_btn.h \
    tcpserver_connection.h \
    tcpclient_scene.h \
    tcpserver_scene.h \
    tcpserver_wait_scene.h \
    tcp_select_scene.h \
    tcp_select_search_item.h \
    tcp_select_server_item.h \
    multi_game_over_scene.h \
    win_item.h \
    faild_item.h \
    wait_item.h

FORMS    +=

RESOURCES += \
    res.qrc

DISTFILES +=
