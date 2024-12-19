#include "maingame.h"


maingame::maingame(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("The snake game");

    const int x =1920*0.8;//x window size
    const int y=1080*0.8;//y window size

    setFixedSize(x, y);//Set window size

    //Background image
    background = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/The_snake_game/game_page.png").scaled(x, y, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QFont font;
    font.setPointSize(20);//Font size -all font size

    const int x_start =225;
    const int y_start=1;
    const int x_size=200;
    const int y_size=45;

    menu_button = new QPushButton("Menu...", this);//go to menu
    menu_button->setFont(font);
    menu_button->setStyleSheet("color: yellow;");
    menu_button->setGeometry(x_start, y_start, x_size, y_size);
    connect(menu_button, &QPushButton::clicked, this, &maingame::menuApp);

    exit_button = new QPushButton("Exit app...", this);//leave from app
    exit_button->setFont(font);
    exit_button->setStyleSheet("color: yellow;");
    exit_button->setGeometry(x_start+30+x_size, y_start, x_size, y_size);
    connect(exit_button, &QPushButton::clicked, this, &maingame::exitApp);

    score =0;//start score

    //Create graphics scene and view
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, x, y);//scene size and pos
    view = new QGraphicsView(scene, this);
    view->setGeometry(0, 0, x, y);
    view->setStyleSheet("background: transparent;");//to show background

    //Create score text item
    scoreTextItem = new QGraphicsTextItem();
    scoreTextItem->setDefaultTextColor(Qt::yellow);//points colour
    scoreTextItem->setFont(QFont("Arial", 27));//points font size
    scoreTextItem->setPos(40, 5);//Set position on the screen
    scoreTextItem->setPlainText("Score: 0");
    scene->addItem(scoreTextItem);//Add to scene

    //Create death text item
    deathTextItem = new QGraphicsTextItem();
    deathTextItem->setDefaultTextColor(Qt::red);//death message colour
    deathTextItem->setFont(QFont("Arial", 185));//death message font size
    deathTextItem->setPlainText("");//initially empty - fill with text after losing
    scene->addItem(deathTextItem);//Add to scene
    deathTextItem->setPos(x / 2 - 300, y / 2 - 100);//Center position

    updateDisplay();

    deathTimer = new QTimer(this);//initialize on the beginning
    connect(deathTimer, &QTimer::timeout, this, &maingame::menuApp);
}

void maingame::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.drawPixmap(0, 0, background);//first draw background, later added elements on the background
}

void maingame::exitApp()
{
    this->close();//turn off app...
}

void maingame::menuApp()
{
    this->close();
    auto *mainWindow = new MainMenu(); // Tworzenie dynamiczne
    mainWindow->show();
}

void maingame::displayDeathMessage()
{
    qDebug("You lost...");
    deathTimer->start(3000);
}

void maingame::updateDisplay() {
    scoreTextItem->setPlainText(QString("Score: %1").arg(score));
}

bool maingame::isGameOver()
{
    return gameOver;
}
