#include "mainmenu.h"
#include "manual.h"
#include "maingame.h"
#include "scoreboard.h"
#include "level_window.h"


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

    //Create graphics scene and view
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, x, y);
    view = new QGraphicsView(scene, this);
    view->setGeometry(0, 0, x, y);
    view->setStyleSheet("background: transparent;");
    view->setFrameStyle(QFrame::NoFrame);
    view->setAttribute(Qt::WA_TransparentForMouseEvents);//the view transparent for mouse events(WA - widget atributes)

    //payer name input field
    playerNameInput = new QLineEdit(this);
    playerNameInput->setPlaceholderText("Enter your name...");
    playerNameInput->setFont(QFont("Arial", 27));
    playerNameInput->setGeometry(30,750,420,90);
    playerNameInput->setStyleSheet("color: yellow; background-color: black; border: 2px solid yellow;");

    //Welcome text display
    welcomeTextItem = new QGraphicsTextItem();
    welcomeTextItem->setDefaultTextColor(Qt::white);
    welcomeTextItem->setFont(QFont("Arial", 52));
    welcomeTextItem->setPos(30,670);
    welcomeTextItem->setPlainText("Welcome: ");
    scene->addItem(welcomeTextItem);

    //update welcome text
    connect(playerNameInput, &QLineEdit::returnPressed, this, &MainMenu::updateWelcomeText);//after enter pressed, remember nickname
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
    LevelWindow = new level_window(playerName,nullptr);
    LevelWindow->show();
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
    ScoreBoard->setPlayerName(playerName);//share nickname to scoreboard
    ScoreBoard->show();
}

void MainMenu::updateWelcomeText() {
    playerName = playerNameInput->text();
    if (!playerName.isEmpty()) {
        welcomeTextItem->setPlainText(QString("Welcome: %1").arg(playerName));
    } else {
        welcomeTextItem->setPlainText("Welcome: ");
    }
}


