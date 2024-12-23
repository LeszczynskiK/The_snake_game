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
    level_window(QString nickname,QWidget *parent = nullptr);
    QString m_playerName;//player nickname
private slots:
    void paintEvent(QPaintEvent *event);//background setter
    void exitApp();//quit app
    void menuApp();//main menu of app
    void easyApp();//create game on easy lvl
    void mediumApp();//create game on medium lvl
    void hardApp();//create game on hard lvl
    void ultraApp();//create game on ultra lvl
private:
    QPixmap background;//Background txt
    QPushButton *exit_button;//exit app
    QPushButton *menu_button;//go to menu
    MainMenu *mainWindow;//pointer to MainMenu class
    QGraphicsScene *scene;//create scene
    QGraphicsView *view;//view of app
    maingame* MainGame;//pointer to maingame class

    //buttons to choose toughness of game
    QPushButton *easy_button;//easy level
    QPushButton *medium_button;//medium level
    QPushButton *hard_button;//hard level
    QPushButton *ultra_button;//ultra hard level
};

#endif // LEVEL_WINDOW_H
