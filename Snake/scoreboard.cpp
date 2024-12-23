#include "scoreboard.h"

scoreboard::scoreboard(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Scoreboard");

    const int x =1920*0.8;//x window size
    const int y=1080*0.8;//y window size

    setFixedSize(x, y);//Set window size

    //Background image
    background = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/The_snake_game/scoreboard_photo.png").scaled(x, y,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    font.setPointSize(24);//Font size -all font size
    best_font.setPointSize(36);

    //buttons sizes and coordinates
    const int x_start = 30;
    const int y_start=420;
    const int x_size=330;
    const int y_size=90;
    const int gap=20;

    //buttons
    menu_button = new QPushButton("Menu...", this);//go to menu
    menu_button->setFont(font);
    menu_button->setStyleSheet("color: yellow;");
    menu_button->setGeometry(x_start, y_start+3*gap+3*y_size, x_size, y_size);
    connect(menu_button, &QPushButton::clicked, this, &scoreboard::menuApp);

    exit_button = new QPushButton("Exit app...", this);//leave from app
    exit_button->setFont(font);
    exit_button->setStyleSheet("color: yellow;");
    exit_button->setGeometry(x_start+x_size+gap, y_start+3*gap+3*y_size, x_size, y_size);
    connect(exit_button, &QPushButton::clicked, this, &scoreboard::exitApp);

    reset_button = new QPushButton("Reset scores...", this);//leave from app
    reset_button->setFont(font);
    reset_button->setStyleSheet("color: yellow;");
    reset_button->setGeometry(x_start+2*x_size+2*gap, y_start+3*gap+3*y_size, x_size, y_size);
    connect(reset_button, &QPushButton::clicked, this, &scoreboard::resetRanking);

    //Create graphics scene and view
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, x, y);//scene size and pos
    view = new QGraphicsView(scene, this);
    view->setGeometry(0, 0, x, y);
    view->setStyleSheet("background: transparent;");//to show background
    view->setAttribute(Qt::WA_TransparentForMouseEvents);//the view transparent for mouse events(WA - widget atributes)
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    loadScores();//load last scores...   
    txt_show();
}

void scoreboard::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.drawPixmap(0, 0, background);//first draw background, later added elements on the background
}

void scoreboard::setPlayerName(const QString &name) {
    playerName = name;
}

void scoreboard::exitApp()
{
    this->close();//turn off app...
}

void scoreboard::menuApp()
{
    this->close();
    mainWindow = new MainMenu(nullptr);
    mainWindow->show();
}


void scoreboard::loadScores() {
    QFile file("scores.txt");//from QFile named scores.txt
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {//open in read mode based on text
        QTextStream in(&file);//keep values in "in" variable on type of QTextStream
        while (!in.atEnd()) {//while not end
            QString line = in.readLine();//put line to line variable
            QStringList parts = line.split(":");//separate nickname and score by :
            if (parts.size() == 2) {//if nickname and score exist
                QString name = parts[0].trimmed();//trim nick part and put this to variable
                QString score = parts[1].trimmed();//trim score part and put this to variable
                if (!name.isEmpty() && !score.isEmpty()) {//if parts not empty
                    playerNameList.append(name);//add player name to proper list
                    scoresList.append(score);//add score of player to proper list
                }
            } else {
                qDebug() << "Invalid line format in scores.txt:" << line;
            }
        }
        file.close();
    } else {
        qDebug() << "Failed to open scores.txt for reading!";
    }

    qDebug() << "Loaded scores:" << scoresList;
    qDebug() << "Loaded player names:" << playerNameList;
}

void scoreboard::txt_show()
{
    //add a QTextEdit for displaying the scores
    scoreDisplay = new QTextEdit(this);
    scoreDisplay->setFont(font);
    scoreDisplay->setStyleSheet("color: yellow; background: transparent;");
    scoreDisplay->setGeometry(800, 350, 520, 400);
    scoreDisplay->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scoreDisplay->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scoreDisplay->setReadOnly(true);//read only

    scoreBestDisplay = new QTextEdit(this);
    scoreBestDisplay->setFont(best_font);//bigger font fot the best score
    scoreBestDisplay->setStyleSheet("color: yellow; background: transparent;");
    scoreBestDisplay->setGeometry(210, 190, 470, 350);
    scoreBestDisplay->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scoreBestDisplay->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scoreBestDisplay->setReadOnly(true);//Make it read-only

    //display 10 last scores
    QString scoreText = ""; // Start text
    int rank=1;//number of element in list
    for (int i = scoresList.size() - 1; i >= 0 && i >= scoresList.size() - 10; --i) {//Show 10 last(iterate from last and show 10 elements if exist)
        scoreText += QString("%1. %2 - %3\n").arg(rank).arg(playerNameList[i]).arg(scoresList[i]);
        rank++;//increase number of element in list
    }
    scoreDisplay->setPlainText(scoreText);//Set score in text area

    //getting the best score from all games
    QString scoreTextBest = "";//Start best text
    if (!scoresList.isEmpty()) {//if list not empty
        int maxScoreIndex = 0;//max score value(so far - beginning initialisation)
        int maxScore = scoresList[0].toInt();
        for (int i = 0; i < scoresList.size(); ++i) {//iterate throw scores
            int currentScore = scoresList[i].toInt();//type to temp variable score from list by i index
            if (currentScore > maxScore) {//if current score is bigger than max score so fat
                maxScore = currentScore;//make it new biggest score
                maxScoreIndex = i;//and put current index to variable that hold max score index
            }
        }
        scoreTextBest = QString("Best: %1 - %2\n").arg(playerNameList[maxScoreIndex]).arg(maxScore);
    }
    scoreBestDisplay->setPlainText(scoreTextBest);//Set best score in text area
}

void scoreboard::resetRanking()
{

    //clear variables with scores
    scoreDisplay->clear();//all scores
    scoreBestDisplay->clear();//best score

    //delete data from player and scores list
    playerNameList.clear();
    scoresList.clear();

    //put empty data to .txt file to reset scores set permanently
    QFile file("scores.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << ""; //save empty file
        file.close();
    } else {
        qDebug() << "Failed to open scores.txt for writing!";
    }

    txt_show();
}


