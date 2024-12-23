#ifndef FOOD_H
#define FOOD_H

#include <QRect>
#include <QPainter>

class Food {
public:
    Food(int size, int screenWidth, int screenHeight);//constructor
    void generate(int screenWidth, int screenHeight);//generate food on scene
    QRect getPosition() const;//get pos
    void draw(QPainter &painter) const;//add food

private:
    QRect food;//object based on rectangle
    QRect foodPosition;//position based on rectangle
    int foodSize;//food size
};

#endif // FOOD_H
