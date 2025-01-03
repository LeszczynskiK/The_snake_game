
#ifndef MAINGAME_H
#define MAINGAME_H

#include "mainmenu.h"
#include "snake.h"
#include "food.h"
#include "obstacle.h"

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
#include <QApplication>
#include <QFile>
#include <QTextStream>

class MainMenu;

class maingame : public QWidget{
    Q_OBJECT
public:
    maingame(const QString& name,int speed,QWidget *parent = nullptr,bool mode_st=false);
private slots:
    void paintEvent(QPaintEvent *event);//background setter
    void exitApp();//quic app
    void menuApp();//go to menu
    void displayDeathMessage();//message after death
    void resetGame();//new game initialisation
    void moveSnake();//snake movement
    void generateObstacle();//create obstacle by timer period
    void pauseGame();//if clicked - then game is paused(unpaused if clicked again)
    void updateCountdown();//count down from 3 to 1 (and display this on the screen)
    void clearPauseText();//delete text from pause displaying
private:
    void keyPressEvent(QKeyEvent *event);
    QPixmap background;//Background txt
    QPushButton *exit_button;//exit app
    QPushButton *menu_button;//go to menu
    QPushButton *pause_button;//go to pause
    bool is_paused;//if game paused?
    MainMenu *mainWindow;
    int score;//points
    QGraphicsTextItem *scoreTextItem;//score object
    QGraphicsTextItem *deathTextItem;//death message object
    QGraphicsTextItem *pauseTextItem;//pause status text on the screen
    QTimer* countdownTimer;//counter to count 3...2...1
    int countdownValue;//value to count down from
    QTimer *deathTimer;//time to message after death display
    QTimer *obstacleTimer;//period by which new obstacle generate in new place
    bool gameOver;//game is lost?
    bool isGameOver();//if lost, return that game is lost
    void updateDisplay();//show points
    QGraphicsScene *scene;//create scene
    QGraphicsView *view;//view of app
    QTimer *moveTimer;//snake movement timer

    Snake *snake;//pointer to snake object
    Food *food;//pointer to food object
    Obstacle *obstacle;//pointer to obstacle object
    level_window *lvl_window;//pointer to level_window object

    void saveScoreToFile(const QString& playerName);//save score to txt if player die
    void saveScoreToFileObstacles(const QString& playerName);//save score to txt if player die(obstacle version)
    QString playerName;//nickname storage variable

    bool obstacle_resp;//obstacle mode contidion
};

#endif // MAINGAME_H
