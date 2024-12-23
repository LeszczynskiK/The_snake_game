#include "food.h"
#include <QRect>
#include <cstdlib>

Food::Food(int size, int screenWidth, int screenHeight) {//food size, scene width and height
    foodSize = size;//set food square size equat to size
    generate(screenWidth, screenHeight);//1st generated food
}

void Food::generate(int screenWidth, int screenHeight) {//random pos food generator
    srand(time(NULL));//random position food generation
    int ran_x=rand()%1420 +50;
    int ran_y=rand()%780+50;
    foodPosition = QRect(ran_x, +ran_y, foodSize, foodSize);//create food : pos_x,pos_y (random) , and size
}

QRect Food::getPosition() const {//get pos of food
    return foodPosition;
}

void Food::draw(QPainter &painter) const {
    if (!foodPosition.isNull() && foodPosition.width() > 0 && foodPosition.height() > 0) {//if food eqist
        painter.setBrush(Qt::red);
        painter.drawRect(foodPosition);//draw food on scene
    }
}
