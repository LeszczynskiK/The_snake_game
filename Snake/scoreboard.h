#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "mainmenu.h"

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QTextEdit>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsView>

class MainMenu;

class scoreboard : public QWidget {
    Q_OBJECT
public:
    scoreboard(QWidget *parent = nullptr);
private slots:
    void paintEvent(QPaintEvent *event);//background setter
    void exitApp();
    void menuApp();
private:
    QPixmap background;//Background txt
    QPushButton *exit_button;//exit app
    QPushButton *menu_button;//go to menu
    MainMenu *mainWindow;
    QGraphicsScene *scene;//create scene
    QGraphicsView *view;//view of app
};

#endif // SCOREBOARD_H
