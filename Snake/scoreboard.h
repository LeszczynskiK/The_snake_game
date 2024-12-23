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
#include <QFile>
#include <QTextStream>

class MainMenu;

class scoreboard : public QWidget {
    Q_OBJECT
public:
    scoreboard(QWidget *parent = nullptr);
    QString playerName;//keep player nickname
    void setPlayerName(const QString &name);//share name to
private slots:
    void paintEvent(QPaintEvent *event);//background setter
    void exitApp();
    void menuApp();
    void loadScores();//load scores from last games...
private:
    QPixmap background;//Background txt
    QPushButton *exit_button;//exit app
    QPushButton *menu_button;//go to menu
    MainMenu *mainWindow;
    QGraphicsScene *scene;//create scene
    QGraphicsView *view;//view of app
    QStringList scoresList;//list for storing scores
    QStringList playerNameList;
    QVector<QLabel*> scoreLabels;//holds labels for displaying each score
};

#endif // SCOREBOARD_H
