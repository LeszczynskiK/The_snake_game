#include "manual.h"

manual::manual(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Instruction");

    const int x =1920*0.8;//x window size
    const int y=1080*0.8;//y window size

    setFixedSize(x, y);//Set window size

    //Background image
    background = QPixmap("/home/krzysiek89/Desktop/QT_aplikacje/The_snake_game/manual_page.png").scaled(x, y, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QFont font;
    font.setPointSize(24);//Font size -all font size


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
    menu_button->setGeometry(x_start, y_start+2*gap+2*y_size, x_size, y_size);
    connect(menu_button, &QPushButton::clicked, this, &manual::menuApp);

    exit_button = new QPushButton("Exit app...", this);//leave from app
    exit_button->setFont(font);
    exit_button->setStyleSheet("color: yellow;");
    exit_button->setGeometry(x_start, y_start+3*gap+3*y_size, x_size, y_size);
    connect(exit_button, &QPushButton::clicked, this, &manual::exitApp);

    //Create graphics scene and view
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, x, y);//scene size and pos
    view = new QGraphicsView(scene, this);
    view->setGeometry(0, 0, x, y);
    view->setStyleSheet("background: transparent;");//to show background
    view->setAttribute(Qt::WA_TransparentForMouseEvents);//the view transparent for mouse events(WA - widget atributes)

    //Add game instruction
    instructionsTextItem = new QGraphicsTextItem();
    instructionsTextItem->setDefaultTextColor(Qt::yellow);//Instructions color
    instructionsTextItem->setFont(QFont("Arial", 32));//Instructions font size
    instructionsTextItem->setPlainText(
        "How to Play:\n"
        "- Control the snake using arrow keys.\n"
        "- Collect the rectangles (food) to grow in size.\n"
        "- Avoid hitting the walls,obstacles or yourself.\n\n"
        );
    instructionsTextItem->setPos(60, 275);//Position at the bottom60,470
    scene->addItem(instructionsTextItem);

    //Add objective
    objectivesTextItem = new QGraphicsTextItem();
    objectivesTextItem->setDefaultTextColor(Qt::white);//Objectives color is red
    objectivesTextItem->setFont(QFont("Arial", 40));
    objectivesTextItem->setPlainText(
        "Objective:\n"
        "Grow as much as you can and score the highest points!"
        );
    objectivesTextItem->setPos(60, 120);
    scene->addItem(objectivesTextItem);
}

void manual::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.drawPixmap(0, 0, background);//first draw background, later added elements on the background
}

void manual::exitApp()
{
    this->close();//turn off app...
}

void manual::menuApp()
{
    this->close();
    mainMenu = new MainMenu(nullptr);
    mainMenu->show();
}
