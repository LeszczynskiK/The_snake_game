#include "snake.h"
#include <QRect>
#include <QList>

Snake::Snake(int size, int startX, int startY) {
    snakeSize = size;
    direction = 2;//beginning direction of snake movement is right
    body.append(QRect(startX, startY, snakeSize, snakeSize));//add snake head
}

void Snake::move(int direction) {

    QRect head = body.first();//get current head position

    //Move head to direction...
    switch (direction) {
    case 0: head.moveLeft(head.left() - snakeSize); break; //left
    case 1: head.moveTop(head.top() - snakeSize); break;   //up
    case 2: head.moveLeft(head.left() + snakeSize); break; //right
    case 3: head.moveTop(head.top() + snakeSize); break;   //down
    }

    body.push_front(head);//add head - to stimulate move
    body.pop_back();//delete tail to stimulate move (to keep the same size of snake if he did not eat food)
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

     //block movement change by 180 degree (opposite direction is denied)
    if ((direction == 0 && dir == 2) || //from left to right
        (direction == 2 && dir == 0) || //from right to left
        (direction == 1 && dir == 3) || //from up to down
        (direction == 3 && dir == 1))   //from down to up
    {
        return; //ignore if direction is opposite
    }

    //accept only direction basedon number 0-3
    if (dir >= 0 && dir <= 3) {
        direction = dir; //save current direction
    }
}

void Snake::draw(QPainter &painter) const {
    painter.setBrush(Qt::darkBlue);
    for (const auto &segment : body) {
        if (!segment.isNull() && segment.width() > 0 && segment.height() > 0) {
            painter.drawRect(segment);
        }
    }
}

