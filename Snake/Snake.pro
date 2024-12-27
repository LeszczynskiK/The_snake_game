QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    food.cpp \
    level_window.cpp \
    main.cpp \
    maingame.cpp \
    mainmenu.cpp \
    manual.cpp \
    obstacle.cpp \
    scoreboard.cpp \
    scoreboard_obstacle.cpp \
    snake.cpp

HEADERS += \
    food.h \
    level_window.h \
    maingame.h \
    mainmenu.h \
    manual.h \
    obstacle.h \
    scoreboard.h \
    scoreboard_obstacle.h \
    snake.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
