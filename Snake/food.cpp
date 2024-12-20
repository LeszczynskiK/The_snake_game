#include "food.h"
#include <QRect>
#include <cstdlib>

Food::Food(int size, int screenWidth, int screenHeight) {
    foodSize = size;
    generate(screenWidth, screenHeight);//1st generated food
}

void Food::generate(int screenWidth, int screenHeight) {//random pos food generator
    srand(time(NULL));
    int ran_x=rand()%1420 +50;
    int ran_y=rand()%780+50;
    foodPosition = QRect(ran_x, +ran_y, foodSize, foodSize);
}

QRect Food::getPosition() const {//get os of food
    return foodPosition;
}

void Food::draw(QPainter &painter) const {
    if (!foodPosition.isNull() && foodPosition.width() > 0 && foodPosition.height() > 0) {
        painter.setBrush(Qt::red);
        painter.drawRect(foodPosition);
    }
}
