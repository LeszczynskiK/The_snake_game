#include "level_window.h"

level_window::level_window(QString playerName,QWidget *parent) : QWidget(parent),m_playerName(playerName)
{
    setWindowTitle("Scoreboard");

    const int x =1920*0.8;//x window size
    const int y=1080*0.8;//y window size

    setFixedSize(x, y);//Set window size

    //Background image
    background = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/The_snake_game/level_window.png").scaled(x, y,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QFont font;
    font.setPointSize(24);//Font size -all font size

    //sizes and start points for buttons
    const int x_start = 30;
    const int y_start=420;
    const int x_size=330;
    const int y_size=90;
    const int gap=20;
    const int level_gap=360;
    const int x_start_lvl=65;

    //buttons
    easy_button = new QPushButton("Easy level...", this);//go to menu
    easy_button->setFont(font);
    easy_button->setStyleSheet("color: yellow;");
    easy_button->setGeometry(x_start_lvl, y_start-level_gap, x_size, y_size);
    connect(easy_button, &QPushButton::clicked, this, &level_window::easyApp);

    medium_button = new QPushButton("Medium level...", this);//go to menu
    medium_button->setFont(font);
    medium_button->setStyleSheet("color: yellow;");
    medium_button->setGeometry(x_start_lvl+gap+x_size, y_start-level_gap, x_size, y_size);
    connect(medium_button, &QPushButton::clicked, this, &level_window::mediumApp);

    hard_button = new QPushButton("Hard level...", this);//go to menu
    hard_button->setFont(font);
    hard_button->setStyleSheet("color: yellow;");
    hard_button->setGeometry(x_start_lvl+2*gap+2*x_size, y_start-level_gap, x_size, y_size);
    connect(hard_button, &QPushButton::clicked, this, &level_window::hardApp);

    ultra_button = new QPushButton("Ultra level...", this);//go to menu
    ultra_button->setFont(font);
    ultra_button->setStyleSheet("color: yellow;");
    ultra_button->setGeometry(x_start_lvl+3*gap+3*x_size, y_start-level_gap, x_size, y_size);
    connect(ultra_button, &QPushButton::clicked, this, &level_window::ultraApp);

    menu_button = new QPushButton("Menu...", this);//go to menu
    menu_button->setFont(font);
    menu_button->setStyleSheet("color: yellow;");
    menu_button->setGeometry(x_start_lvl+gap+x_size-100, y_start+2*y_size, x_size, y_size);
    connect(menu_button, &QPushButton::clicked, this, &level_window::menuApp);

    exit_button = new QPushButton("Exit app...", this);//leave from app
    exit_button->setFont(font);
    exit_button->setStyleSheet("color: yellow;");
    exit_button->setGeometry(x_start_lvl+2*gap+2*x_size+100, y_start+2*y_size, x_size, y_size);
    connect(exit_button, &QPushButton::clicked, this, &level_window::exitApp);

    //Create graphics scene and view
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, x, y);//scene size and pos
    view = new QGraphicsView(scene, this);
    view->setGeometry(0, 0, x, y);
    view->setStyleSheet("background: transparent;");//to show background
    view->setAttribute(Qt::WA_TransparentForMouseEvents);//the view transparent for mouse events(WA - widget atributes)
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//donw allow to scrool
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void level_window::paintEvent(QPaintEvent *event) {//paint event
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.drawPixmap(0, 0, background);//first draw background, later added elements on the background
}

void level_window::exitApp()
{
    this->close();//turn off app...
}

void level_window::menuApp()
{
    this->close();
    mainWindow = new MainMenu(nullptr);//go to mainmenu
    mainWindow->show();
}

void level_window::easyApp()
{
    this->close();
    MainGame = new maingame(m_playerName,150,nullptr);//create game with the speed of 150
    MainGame->show();
}

void level_window::mediumApp()
{
    this->close();
    MainGame = new maingame(m_playerName,100,nullptr);//create game with the speed of 100
    MainGame->show();
}

void level_window::hardApp()
{
    this->close();
    MainGame = new maingame(m_playerName,60,nullptr);//create game with the speed of 60
    MainGame->show();
}

void level_window::ultraApp()
{
    this->close();
    MainGame = new maingame(m_playerName,30,nullptr);//create game with the speed of 30
    MainGame->show();
}
