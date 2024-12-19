#ifndef MAINGAME_H
#define MAINGAME_H

#include "mainmenu.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QTextEdit>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsTextItem>
#include <QFont>
#include <QString>
#include <QTimer>
#include <QGraphicsView>

class MainMenu;

class maingame : public QWidget{
    Q_OBJECT
public:
    maingame(QWidget *parent = nullptr);
private slots:
    void paintEvent(QPaintEvent *event);//background setter
    void exitApp();//quic app
    void menuApp();//go to menu
    void displayDeathMessage();//message after death
private:
    QPixmap background;//Background txt
    QPushButton *exit_button;//exit app
    QPushButton *menu_button;//go to menu
    MainMenu *mainWindow;
    int score;//points
    QGraphicsTextItem *scoreTextItem;//score object
    QGraphicsTextItem *deathTextItem;//death message object
    QTimer *deathTimer;//time to message after death display
    bool gameOver;//game is lost?
    bool isGameOver();//if lost, return that game is lost
    void updateDisplay();//show points
    QGraphicsScene *scene;//create scene
    QGraphicsView *view;//view of app
};

#endif // MAINGAME_H
