#include "maingame.h"


maingame::maingame(const QString& name,int speed,QWidget *parent) : QWidget(parent),playerName(name)
{
    setWindowTitle("The snake game");

    const int x =1920*0.8;//x window size
    const int y=1080*0.8;//y window size

    setFixedSize(x, y);//Set window size

    //Background image
    background = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/The_snake_game/game_page.png").scaled(x, y, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QFont font;
    font.setPointSize(20);//Font size -all font size

    //sizes and coordinates for buttons
    const int x_start =225;
    const int y_start=1;
    const int x_size=200;
    const int y_size=33;

    //buttons
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
    view->setAttribute(Qt::WA_TransparentForMouseEvents);//the view transparent for mouse events(WA - widget atributes)
    menu_button->setFocusPolicy(Qt::NoFocus);
    exit_button->setFocusPolicy(Qt::NoFocus);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//dont allow to scroll
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    //Create score text item
    scoreTextItem = new QGraphicsTextItem();
    scoreTextItem->setDefaultTextColor(Qt::yellow);//points colour
    scoreTextItem->setFont(QFont("Arial", 23));//points font size
    scoreTextItem->setPos(40, 1);//Set position on the screen
    scoreTextItem->setPlainText("Score: 0");
    scene->addItem(scoreTextItem);//Add to scene

    //Create death text item
    deathTextItem = new QGraphicsTextItem();
    deathTextItem->setDefaultTextColor(Qt::red);//death message colour
    deathTextItem->setFont(QFont("Arial", 185));//death message font size
    deathTextItem->setPlainText("");//initially empty - fill with text after losing
    scene->addItem(deathTextItem);//Add to scene
    deathTextItem->setPos(x / 2 -470, y / 2 - 200);//Center position

    bool gameOver = false;
    deathTimer = new QTimer(this);//initialize on the beginning
    connect(deathTimer, &QTimer::timeout, this, &maingame::menuApp);

    snake = new Snake(30, 100, 100);//create new snake object
    food = new Food(30, 920, 680);//create new food object

    moveTimer = new QTimer(this);//snake timer move
    connect(moveTimer, &QTimer::timeout, this, &maingame::moveSnake);
    moveTimer->start(speed);

    view->setFocusPolicy(Qt::NoFocus);
    this->setFocus();
}

void maingame::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.drawPixmap(0, 0, background);

    //draw frame around
    QRect frameRect(35, 38, width() - 85, height() - 78);//60px from edge of scene
    painter.setPen(QPen(Qt::black, 4));
    painter.drawRect(frameRect);//draw frame

    if (snake) {
        snake->draw(painter);
    }

    if (food) {
        food->draw(painter);
    }
}

void maingame::exitApp()
{
    deathTimer->stop();
    this->close();//turn off app...
    delete this;
}

void maingame::menuApp()
{
    deathTimer->stop();
    this->close();
    auto *mainWindow = new MainMenu();//create mainWindow
    mainWindow->show();
    delete this;
}

void maingame::displayDeathMessage()
{
    qDebug("You lost...");
    deathTextItem->setPlainText("You lost!!!");

    saveScoreToFile(playerName);//save score

    deathTimer->start(5000);
}

void maingame::updateDisplay() {
    scoreTextItem->setPlainText(QString("Score: %1").arg(score));
}

bool maingame::isGameOver()
{
    return gameOver;
}

void maingame::resetGame() {
    gameOver = false;
    score = 0;

    if (snake) {
        delete snake;//Clean up the previous snake object, if any
        snake = nullptr;
    }
    snake = new Snake(30, 100, 100);//Create new snake object
    if (food) {
        delete food;//Clean up the previous food object, if any
        food = nullptr;
    }
    food = new Food(30, 920, 680);//create new food object

    updateDisplay();
}

void maingame::moveSnake() {
    if (gameOver)
    {
        displayDeathMessage();
        moveTimer->stop();
        return;
    }


    if (snake->getHead().intersects(food->getPosition())) {//if snake head touch food before move
        food->generate(1920*0.8, 1080*0.8);//generate new food
        snake->grow();//increase snake size
        score += 10;//add points
        updateDisplay();
    }

    QRect frameRect(35, 38, width() - 85, height() - 78);
    if (!frameRect.contains(snake->getHead())) {
        gameOver = true;
        displayDeathMessage();
        moveTimer->stop();
    }

    snake->move(snake->getDirection());//move snake with the argument of choosen by keyboard direction

    if (snake->checkCollision()) {//if collided
        gameOver = true;//you lost
        displayDeathMessage();
        moveTimer->stop();
        return;
    }

    updateDisplay();
    update();
}

void maingame::keyPressEvent(QKeyEvent *event) {//keyboard character steering
    qDebug() << "Key pressed: " << event->key();
    if (event->key() == Qt::Key_Up) {
        qDebug() << "Up key pressed";
        snake->setDirection(1);//up
    } else if (event->key() == Qt::Key_Down) {
        qDebug() << "Down key pressed";
        snake->setDirection(3);//down
    } else if (event->key() == Qt::Key_Left) {
        qDebug() << "Left key pressed";
        snake->setDirection(0);//left
    } else if (event->key() == Qt::Key_Right) {
        qDebug() << "Right key pressed";
        snake->setDirection(2);//right
    }
    event->accept();//accept event
}

void maingame::saveScoreToFile(const QString& playerName) {//create scores.txt and put there nickname and score
    QFile file("scores.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << playerName << ": " << score << "\n";
        file.close();
    } else {
        qDebug() << "Failed to open scores.txt for writing!";
    }
}
