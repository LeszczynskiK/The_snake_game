#include "obstacle.h"

Obstacle::Obstacle(int size_o, int x_window_size, int y_window_size,const Snake &snake) {//need to share snake instance
    obstacleSize = size_o;
    generate_obs(x_window_size,y_window_size,snake);//generate obstacle in random pos(pos can be equal to snake pos on resp time)
}

void Obstacle::draw(QPainter &painter) {
    if (!rect_pos.isNull() && rect_pos.width() > 0 && rect_pos.height() > 0)
    {
        painter.setBrush(Qt::yellow);//obstacle is yellow
        painter.drawRect(rect);//draw obstacle
    }
}

void Obstacle::generate_obs(int x_window_size, int y_window_size,const Snake &snake) {//random pos obstacle generator
    srand(time(NULL));//random values generator initialise
    bool validPosition = false;//check if snake dont collide with obstacle on the resp time
    int ran_x,ran_y;

    while (!validPosition) {//while pos of snake is not equal to obstacle by resp time(look for this)
        ran_x=rand()%(x_window_size-180) +50;//pos x radom
        ran_y=rand()%(y_window_size-180) +50;//pos y random
        int size_ran = rand()%175 + 30;//size random


        QRect candidateRect(ran_x, ran_y, size_ran, size_ran);//cantidate position of obstacle(to check with snake pos)

        validPosition = true;

        //check if obstacle dont cover any part of snake
        for (const auto &segment : snake.getBody()) {
            if (candidateRect.intersects(segment) || candidateRect.topLeft().manhattanLength() < 10) {
                //manhatan length is distance between 2 points : |x1-x2| + |y1-y2|
                validPosition = false;//if obstacle in generate time is too close to snake, generate new position
                break;
            }
        }

        rect = QRect(ran_x, ran_y, size_ran, size_ran);//create food : pos_x,pos_y (random) , and size
        rect_pos=rect;//actualise position of current obstacle
    }
}

QRect Obstacle::getPosition_obs() {//get pos of obstacle
    return rect_pos;
}

