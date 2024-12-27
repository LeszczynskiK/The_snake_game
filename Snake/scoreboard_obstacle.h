#ifndef SCOREBOARD_OBSTACLE_H
#define SCOREBOARD_OBSTACLE_H

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

class scoreboard_obstacle : public QWidget {
    Q_OBJECT
public:
    scoreboard_obstacle(QWidget *parent = nullptr);
    QString playerName;//keep player nickname
    void setPlayerName(const QString &name);//share name to
private slots:
    void paintEvent(QPaintEvent *event);//background setter
    void exitApp();
    void menuApp();
    void loadScores();//load scores from last games...
    void resetRanking();//delete records from .txt file with scores
private:
    QFont font;//font type
    QFont best_font;//font for the best score
    QPixmap background;//Background txt
    QPushButton *exit_button;//exit app
    QPushButton *menu_button;//go to menu
    QPushButton *reset_button;//reset scores ranking
    MainMenu *mainWindow;//pointer to mainmenu object
    QGraphicsScene *scene;//create scene
    QGraphicsView *view;//view of app
    QStringList scoresList;//list for storing scores
    QStringList playerNameList;
    QVector<QLabel*> scoreLabels;//holds labels for displaying each score
    void txt_show();//display 10 last and best one score
    QTextEdit *scoreDisplay;//scores to display
    QTextEdit *scoreBestDisplay;//best score to display
};

#endif // SCOREBOARD_OBSTACLE_H
