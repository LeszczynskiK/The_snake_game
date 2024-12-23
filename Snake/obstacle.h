#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QRect>
#include <QPainter>
#include <QList>

class Obstacle {
public:
    Obstacle(int size_o, int x_window_size, int y_window_size);
    void draw(QPainter &painter);

private:
    int obstacleSize;
    QRect rect;//obstacle is being represented by rectangle
};

#endif // OBSTACLE_H
