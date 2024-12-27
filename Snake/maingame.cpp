#include "maingame.h"


maingame::maingame(const QString& name,int speed,QWidget *parent,bool mode_st) : QWidget(parent),playerName(name),obstacle_resp(mode_st)
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

    is_paused = false;//game is not paused in the beginning
    pause_button = new QPushButton("Pause game...", this);//leave from app
    pause_button->setFont(font);
    pause_button->setStyleSheet("color: yellow;");
    pause_button->setGeometry(x_start+60+2*x_size, y_start, x_size, y_size);
    connect(pause_button, &QPushButton::clicked, this, &maingame::pauseGame);

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

    //Create text about game pause (if paused), if unpaused then inform and delete text from scene
    pauseTextItem = new QGraphicsTextItem();
    pauseTextItem->setDefaultTextColor(Qt::red);//pause message colour
    pauseTextItem->setFont(QFont("Arial", 125));//pause message font size
    pauseTextItem->setPlainText("");//initially empty - fill with text after paused
    scene->addItem(pauseTextItem);//Add to scene
    pauseTextItem->setPos(75, y / 2 - 130);//Center position

    countdownValue = 3;//if game is unpaused... count 3.2.1...
    countdownTimer = nullptr;

    gameOver = false;//game is not lost in the moment of initialisation
    deathTimer = new QTimer(this);//initialize on the beginning
    connect(deathTimer, &QTimer::timeout, this, &maingame::menuApp);

    snake = new Snake(30, x/2, y/2);//create new snake object(2nd and 3rd argument is start position

    food = new Food(30, x, y);//create new food object//2nd and 3rd argument is window size (random pos is resp place)
    qDebug() << "Obstacle mode: " << obstacle_resp;

    if(obstacle_resp == true)//if obstacle mode is on
    {
        obstacle = new Obstacle(20,x,y,*snake);//create new obstacle//2nd and 3rd argument is window size (random pos is resp place)
    }
    moveTimer = new QTimer(this);//snake timer move
    connect(moveTimer, &QTimer::timeout, this, &maingame::moveSnake);
    moveTimer->start(speed);

    obstacleTimer = new QTimer(this);//obstacle timer generate
    connect(obstacleTimer, &QTimer::timeout, this, &maingame::generateObstacle);
    obstacleTimer->start(3500);//new obstacle by each 3.5 sec

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

    if (snake) {//if object exist, draw it
        snake->draw(painter);
    }

    if (food) {//if object exist, draw it
        food->draw(painter);
    }

    if(obstacle_resp == true)//if obstacle mode is on
    {
        if (obstacle) {//if object exist, draw it
            obstacle->draw(painter);
        }
    }
}

void maingame::exitApp()
{
    deathTimer->stop();
    moveTimer->stop();
    obstacleTimer->stop();
    this->close();//turn off app...
    delete this;
}

void maingame::menuApp()
{
    deathTimer->stop();//stop timer counting to death operation display
    moveTimer->stop();
    obstacleTimer->stop();
    this->close();
    auto *mainWindow = new MainMenu();//create mainWindow
    mainWindow->show();
    delete this;
}

void maingame::pauseGame()
{
    is_paused = !is_paused;
    countdownValue = 3;//value to countdown from
    if(is_paused == false){//if game is not paused
        pause_button->setText("Pause game...");

        pauseTextItem->setPlainText("3");//start counting down (3)


        //create temporary timer to count
        if (!countdownTimer) {
            countdownTimer = new QTimer(this);
            connect(countdownTimer, &QTimer::timeout, this, &maingame::updateCountdown);//method to count from 3 to 1
        }
        countdownTimer->start(1000);//actualise pause text after each 1sec (to add proper counting)
    }
    else//if game is paused
    {
        pause_button->setText("Resume game...");

        //stop all of the actions
        deathTimer->stop();
        moveTimer->stop();
        obstacleTimer->stop();
        pauseTextItem->setPlainText("Game is paused...");
    }
}

void maingame::updateCountdown()
{
    if (countdownValue > 1) {
        countdownValue--; //decrease value to dount down
        pauseTextItem->setPlainText(QString::number(countdownValue));//display current value of countdownValue
    } else {//if finished counting
        countdownTimer->stop();//stop counting timer
        pauseTextItem->setPlainText("Game is resumed!");//give informaton tht game is again playable
        QTimer::singleShot(1000, this, &maingame::clearPauseText);//call after 1000ms function clearPauseText(only once - single shot)

        //start all of the actions
        moveTimer->start();
        if(obstacle_resp == true)
        {
            obstacleTimer->start();
        }
        pauseTextItem->setPlainText("");

        view->setFocusPolicy(Qt::NoFocus);
        this->setFocus();
    }
}

void maingame::clearPauseText()
{
    pauseTextItem->setPlainText("");//delete text from screen (set it empty)
}


void maingame::displayDeathMessage()//if you lose, you will see this
{
    qDebug("You lost...");
    deathTextItem->setPlainText("You lost!!!");//display this on screen

    if(obstacle_resp == true)//if obstacle are avaiable in the game
    {
        saveScoreToFileObstacles(playerName);//save score
    }

    else//no obstacles in the game
    {
        saveScoreToFile(playerName);//save score
    }

    deathTimer->start(5000);//start counting to do menuApp() method
}

void maingame::updateDisplay() {//update score on the screen
    scoreTextItem->setPlainText(QString("Score: %1").arg(score));
}

bool maingame::isGameOver()//return information about game state
{
    return gameOver;
}

void maingame::resetGame() {//put game settings to start mode
    gameOver = false;
    score = 0;


    //constand position after new game turning on
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

    if(obstacle_resp == true)//if obstacle mode is on
    {
        if (obstacle) {
            delete obstacle;//Clean up the previous food object, if any
            obstacle = nullptr;
        }
        obstacle = new Obstacle(20,300,300,*snake);
    }

    updateDisplay();
}

void maingame::moveSnake() {//snake managing
    if (gameOver)//if game is lost
    {
        displayDeathMessage();
        moveTimer->stop();
        obstacleTimer->stop();
        return;
    }


    if (snake->getHead().intersects(food->getPosition())) {//if snake head touch food before move
        food->generate(1920*0.8, 1080*0.8);//generate new food
        snake->grow();//increase snake size
        score += 10;//add points
        updateDisplay();
    }

    if(obstacle_resp == true)//if obstacle mode is on
    {
         if (snake->getHead().intersects(obstacle->getPosition_obs())) {//if snake head touch obstacle
            displayDeathMessage();//snake lose the game
            moveTimer->stop();
            obstacleTimer->stop();
            return;
         }
    }

    QRect frameRect(35, 38, width() - 85, height() - 78);
    if (!frameRect.contains(snake->getHead())) {//if snane head is behing the rectangle(main screen frame)
        gameOver = true;
        displayDeathMessage();
        moveTimer->stop();
    }

    snake->move(snake->getDirection());//move snake with the argument of choosen by keyboard direction

    if (snake->checkCollision()) {//if collided
        gameOver = true;//you lost
        displayDeathMessage();
        moveTimer->stop();
        obstacleTimer->stop();
        return;
    }
    update();//each step connected with timer neet to be actualised - update view!!!!
}

void maingame::generateObstacle()
{
    if(obstacle_resp == true)//if obstacle mode is on
    {
        if (obstacle != nullptr) {
            delete obstacle; //delete old one if exist
        }

        //with passing the snake object = *snake
        obstacle = new Obstacle(0, 0, 0,*snake);//create temp dommy values(no text or value in ...) to avoid inticating to nullptr
        obstacle->generate_obs(1920 * 0.8, 1080 * 0.8,*snake);//generate in random pos with arguments of window size..
    }
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

//to handle scores with no obstacles in game
void maingame::saveScoreToFile(const QString& playerName) {//create scores.txt and put there nickname and score
    QFile file("scores.txt");//create QFile object with name of scores.txt
    if (file.open(QIODevice::Append | QIODevice::Text)) {//open in type in text mode , and text mode
        QTextStream out(&file);//QTextStream object type from reference to file, out is name of variable
        out << playerName << ": " << score << "\n";//put data to variable called out
        file.close();//close file
    } else {
        qDebug() << "Failed to open scores.txt for writing!";
    }
}

//obstacles are avaiable in the game.. this is different file .txt
void maingame::saveScoreToFileObstacles(const QString& playerName) {//create scores_obstacles.txt and put there nickname and score
    QFile file("scores_obstacles.txt");//create QFile object with name of scores_obstacles.txt
    if (file.open(QIODevice::Append | QIODevice::Text)) {//open in type in text mode , and text mode
        QTextStream out(&file);//QTextStream object type from reference to file, out is name of variable
        out << playerName << ": " << score << "\n";//put data to variable called out
        file.close();//close file
    } else {
        qDebug() << "Failed to open scores_obstacles.txt for writing!";
    }
}
