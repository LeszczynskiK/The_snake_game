#include "scoreboard.h"

scoreboard::scoreboard(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Scoreboard");

    const int x =1920*0.8;//x window size
    const int y=1080*0.8;//y window size

    setFixedSize(x, y);//Set window size

    //Background image
    background = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/The_snake_game/scoreboard_photo.png").scaled(x, y,Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QFont font;
    font.setPointSize(24);//Font size -all font size

    const int x_start = 30;
    const int y_start=420;
    const int x_size=330;
    const int y_size=90;
    const int gap=20;

    menu_button = new QPushButton("Menu...", this);//go to menu
    menu_button->setFont(font);
    menu_button->setStyleSheet("color: yellow;");
    menu_button->setGeometry(x_start, y_start+2*gap+2*y_size, x_size, y_size);
    connect(menu_button, &QPushButton::clicked, this, &scoreboard::menuApp);

    exit_button = new QPushButton("Exit app...", this);//leave from app
    exit_button->setFont(font);
    exit_button->setStyleSheet("color: yellow;");
    exit_button->setGeometry(x_start, y_start+3*gap+3*y_size, x_size, y_size);
    connect(exit_button, &QPushButton::clicked, this, &scoreboard::exitApp);

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

    //add a QTextEdit for displaying the scores
    QTextEdit *scoreDisplay = new QTextEdit(this);
    scoreDisplay->setFont(font);
    scoreDisplay->setStyleSheet("color: yellow; background: transparent;");
    scoreDisplay->setGeometry(800, 350, 520, 400);
    scoreDisplay->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scoreDisplay->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scoreDisplay->setReadOnly(true);//read only

    QTextEdit *scoreBestDisplay = new QTextEdit(this);
    scoreBestDisplay->setFont(font);
    scoreBestDisplay->setStyleSheet("color: yellow; background: transparent;");
    scoreBestDisplay->setGeometry(210, 190, 470, 350);
    scoreBestDisplay->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scoreBestDisplay->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scoreBestDisplay->setReadOnly(true);//Make it read-only

    //display the best score on the screen
    QString scoreText = ""; // Start text
    for (int i = 0; i < scoresList.size() && i < 10; ++i) {//Show 10 last
        scoreText += QString("%1. %2 - %3\n").arg(i + 1).arg(playerNameList[i]).arg(scoresList[i]);
    }
    scoreDisplay->setPlainText(scoreText);//Set score in text area

    //Display the best score
    QString scoreTextBest = "";//Start best text
    if (!scoresList.isEmpty()) {
        int maxScoreIndex = 0;
        int maxScore = scoresList[0].toInt();
        for (int i = 1; i < scoresList.size(); ++i) {
            int currentScore = scoresList[i].toInt();
            if (currentScore > maxScore) {
                maxScore = currentScore;
                maxScoreIndex = i;
            }
        }
        scoreTextBest = QString("Best: %1 - %2\n").arg(playerNameList[maxScoreIndex]).arg(maxScore);
    }
    scoreBestDisplay->setPlainText(scoreTextBest);//Set best score in text area
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
    QFile file("scores.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(":");
            if (parts.size() == 2) {
                QString name = parts[0].trimmed();
                QString score = parts[1].trimmed();
                if (!name.isEmpty() && !score.isEmpty()) {
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


