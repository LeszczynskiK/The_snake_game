#ifndef FOOD_H
#define FOOD_H

#include <QRect>
#include <QPainter>

class Food {
public:
    Food(int size, int screenWidth, int screenHeight);
    void generate(int screenWidth, int screenHeight);
    QRect getPosition() const;
    void draw(QPainter &painter) const;//add food

private:
    QRect food;
    QRect foodPosition;
    int foodSize;
};

#endif // FOOD_H
