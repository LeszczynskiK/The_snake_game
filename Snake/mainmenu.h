#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QTextEdit>
#include <QPainter>
#include <QPaintEvent>

//Forward declarations - to enable pointers working in windows instances(1st ->2nd , 2nd->1st class)
class maingame;
class manual;
class scoreboard;
//if one class has pointer to 2nd class and 2nd class has pointer to 1st class wee need forward declaration

class MainMenu : public QWidget {
    Q_OBJECT
public:
    MainMenu(QWidget *parent = nullptr);
private slots:
    void paintEvent(QPaintEvent *event);//background setter
    void exitApp();//quit app
    void startGame();
    void manualGame();
    void scoreGame();
private:
    QPixmap background;//Background txt
    QPushButton *exit_button;//exit app
    QPushButton *manual_button;//go to information about game
    QPushButton *start_button;//start game button
    QPushButton *score_button;//scoreboard button

    //window instances
    maingame* MainGame;
    manual* ManualGame;
    scoreboard* ScoreBoard;

};

#endif // MAINMENU_H
