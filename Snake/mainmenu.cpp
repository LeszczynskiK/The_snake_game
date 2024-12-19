#include "mainmenu.h"
#include "manual.h"
#include "maingame.h"
#include "scoreboard.h"


MainMenu::MainMenu(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Main menu");

    const int x =1920*0.8;//x window size
    const int y=1080*0.8;//y window size

    setFixedSize(x, y);//Set window size

    //Background image
    background = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/The_snake_game/main_page.png").scaled(x, y, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QFont font;
    font.setPointSize(24);//Font size -all font size

    const int x_start = 30;
    const int y_start=200;
    const int x_size=330;
    const int y_size=90;
    const int gap=20;

    start_button = new QPushButton("Start new game...", this);//leave from app
    start_button->setFont(font);
    start_button->setStyleSheet("color: yellow;");
    start_button->setGeometry(x_start, y_start, x_size, y_size);
    connect(start_button, &QPushButton::clicked, this, &MainMenu::startGame);

    manual_button = new QPushButton("Game instruction...", this);//leave from app
    manual_button->setFont(font);
    manual_button->setStyleSheet("color: yellow;");
    manual_button->setGeometry(x_start, y_start+gap+y_size, x_size, y_size);
    connect(manual_button, &QPushButton::clicked, this, &MainMenu::manualGame);

    score_button = new QPushButton("Scoreboard...", this);//leave from app
    score_button->setFont(font);
    score_button->setStyleSheet("color: yellow;");
    score_button->setGeometry(x_start, y_start+2*gap+2*y_size, x_size, y_size);
    connect(score_button, &QPushButton::clicked, this, &MainMenu::scoreGame);

    exit_button = new QPushButton("Exit app...", this);//leave from app
    exit_button->setFont(font);
    exit_button->setStyleSheet("color: yellow;");
    exit_button->setGeometry(x_start, y_start+3*gap+3*y_size, x_size, y_size);
    connect(exit_button, &QPushButton::clicked, this, &MainMenu::exitApp);
}

void MainMenu::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.drawPixmap(0, 0, background);//first draw background, later added elements on the background
}

void MainMenu::exitApp()
{
    this->close();//turn off app...
}

void MainMenu::startGame()
{
    this->close();
    MainGame = new maingame(nullptr);
    MainGame->show();
}

void MainMenu::manualGame()//create manual window
{
    this->close();
    ManualGame = new manual(nullptr);
    ManualGame->show();
}

void MainMenu::scoreGame()
{
    this->close();
    ScoreBoard = new scoreboard(nullptr);
    ScoreBoard->show();
}


