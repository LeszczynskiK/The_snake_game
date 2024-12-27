#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "snake.h"

#include <QRect>
#include <QPainter>
#include <QList>

class Obstacle {
public:
    Obstacle(int size_o, int x_window_size, int y_window_size,const Snake &snake);
    void generate_obs(int x_window_size,int y_window_size,const Snake &snake);//generate new obstacle
    void draw(QPainter &painter);
    QRect getPosition_obs();//position of obstacle (get)

private:
    int obstacleSize;
    QRect rect;//obstacle is being represented by rectangle
    QRect rect_pos;//position of obstacle
};

#endif // OBSTACLE_H
