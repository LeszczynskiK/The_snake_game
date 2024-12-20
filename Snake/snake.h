#ifndef SNAKE_H
#define SNAKE_H

#include <QRect>
#include <QList>
#include <QTimer>
#include <QPainter>
#include <QDebug>

class Snake {
public:
    Snake(int size, int startX, int startY);
    void move(int direction);//move method
    void grow();//increase snake by segment
    void reset();//reset snake
    QList<QRect> getBody() const;
    QRect getHead() const; //get head pos
    bool checkCollision() const;//cossision ?
    int getDirection() const;//get position
    void setDirection(int dir);//set position
    void draw(QPainter &painter) const;//add snake

private:
    QList<QRect> body;//list of body segments
    int snakeSize;//size of each segment
    int direction;//direction of movement(0 - left, 1 - up, 2 - right, 3 - down)
};

#endif // SNAKE_H
