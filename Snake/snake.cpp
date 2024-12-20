#include "snake.h"
#include <QRect>
#include <QList>

Snake::Snake(int size, int startX, int startY) {
    snakeSize = size;
    direction = 2;//beginning direction of snake movement is right
    body.append(QRect(startX, startY, snakeSize, snakeSize));//add snake head
}

void Snake::move(int dir) {
    //If direction of movement is opposite (e.g., left on right, up on down), don't allow this move
    if ((direction == 0 && dir == 2) || //from left to right
        (direction == 2 && dir == 0) || //from right to left
        (direction == 1 && dir == 3) || //from up to down
        (direction == 3 && dir == 1))   //from down to up
    {
        return;//Ignore moving direction if change is by 180 degrees
    }

    //If moving along the X axis (left/right), only allow up or down movement
    //If moving along the Y axis (up/down), only allow left or right movement
    if ((direction == 0 || direction == 2) && (dir == 1 || dir == 3)) {
        return;//Block axis change from X axis (left/right) to Y axis (up/down)
    }
    if ((direction == 1 || direction == 3) && (dir == 0 || dir == 2)) {
        return;//Block axis change from Y axis (up/down) to X axis (left/right)
    }

    direction = dir;//Update direction based on input
    QRect head = body.first();//Get the current head of the snake

    //Move the head based on the direction
    switch (direction) {
    case 0: head.moveLeft(head.left() - snakeSize); break;//left
    case 1: head.moveTop(head.top() - snakeSize); break;//up
    case 2: head.moveLeft(head.left() + snakeSize); break;//right
    case 3: head.moveTop(head.top() + snakeSize); break;//down
    }

    //Check for collision with the body
    for (const QRect &segment : body) {
        if (head == segment) {
            return;//Stop moving if there is a collision
        }
    }

    body.push_front(head);//Add the new head at the front of the snake
    body.pop_back();//Remove the tail to simulate snake movement
}



void Snake::grow() {
    QRect tail = body.last();
    body.append(tail);//if grow- add new segment in the end
}

void Snake::reset() {
    body.clear();
    body.append(QRect(100, 100, snakeSize, snakeSize));//reset snake position
    direction = 2;//begining direction of snake movement
}

QList<QRect> Snake::getBody() const {
    return body;
}

QRect Snake::getHead() const {
    return body.first();
}

bool Snake::checkCollision() const {
    QRect head = body.first();

    //check colision with body
    for (int i = 1; i < body.size(); ++i) {
        if (head.intersects(body[i])) {
            return true;
        }
    }
    return false;
}

int Snake::getDirection() const {
    return direction;
}

void Snake::setDirection(int dir) {

    direction = dir;
}

void Snake::draw(QPainter &painter) const {
    painter.setBrush(Qt::darkBlue);
    for (const auto &segment : body) {
        if (!segment.isNull() && segment.width() > 0 && segment.height() > 0) {
            painter.drawRect(segment);
        }
    }
}

