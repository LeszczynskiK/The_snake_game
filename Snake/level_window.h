#ifndef LEVEL_WINDOW_H
#define LEVEL_WINDOW_H

#include "maingame.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QTextEdit>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsView>

class level_window:public QWidget {
    Q_OBJECT
public:
    level_window(QWidget *parent = nullptr);
private slots:
    void paintEvent(QPaintEvent *event);//background setter
    void exitApp();
    void menuApp();
    void easyApp();
    void mediumApp();
    void hardApp();
    void ultraApp();
private:
    QPixmap background;//Background txt
    QPushButton *exit_button;//exit app
    QPushButton *menu_button;//go to menu
    MainMenu *mainWindow;
    QGraphicsScene *scene;//create scene
    QGraphicsView *view;//view of app
    maingame* MainGame;

    //buttons to choose toughness of game
    QPushButton *easy_button;//easy level
    QPushButton *medium_button;//medium level
    QPushButton *hard_button;//hard level
    QPushButton *ultra_button;//ultra hard level
};

#endif // LEVEL_WINDOW_H
