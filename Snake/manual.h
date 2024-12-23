#ifndef MANUAL_H
#define MANUAL_H

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
#include <QGraphicsView>

class MainMenu;

class manual : public QWidget {
    Q_OBJECT
public:
    manual(QWidget *parent = nullptr);
private slots:
    void paintEvent(QPaintEvent *event);//background setter
    void exitApp();
    void menuApp();
private:
    QPixmap background;//Background txt
    QPushButton *exit_button;//exit app
    QPushButton *menu_button;
    MainMenu *mainMenu;//pointer to mainmenu
    QGraphicsTextItem *instructionsTextItem;//manual - steering character
    QGraphicsTextItem *objectivesTextItem;//manual - objectives
    QGraphicsScene *scene;//create scene
    QGraphicsView *view;//view of app
};

#endif // MANUAL_H
