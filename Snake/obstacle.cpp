#include "obstacle.h"

Obstacle::Obstacle(int size_o, int x_window_size, int y_window_size) {
    obstacleSize = size_o;
    generate_obs(x_window_size,y_window_size);//generate obstacle in random pos
}

void Obstacle::draw(QPainter &painter) {
    if (!rect_pos.isNull() && rect_pos.width() > 0 && rect_pos.height() > 0)
    {
        painter.setBrush(Qt::yellow);//obstacle is yellow
        painter.drawRect(rect);//draw obstacle
    }
}

void Obstacle::generate_obs(int x_window_size, int y_window_size) {//random pos obstacle generator
    srand(time(NULL));//random values generator initialise
    int ran_x=rand()%(x_window_size-180) +50;//pos x radom
    int ran_y=rand()%(y_window_size-180) +50;//pos y random
    int size_ran = rand()%175 + 30;//size random
    rect = QRect(ran_x, ran_y, size_ran, size_ran);//create food : pos_x,pos_y (random) , and size
    rect_pos=rect;//actualise position of current obstacle
}

QRect Obstacle::getPosition_obs() {//get pos of obstacle
    return rect_pos;
}

