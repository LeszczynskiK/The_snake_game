#include "obstacle.h"

Obstacle::Obstacle(int size_o, int x_window_size, int y_window_size) {
    obstacleSize = size_o;
    rect = QRect(x_window_size, y_window_size, size_o, size_o);//create rectangle
}

void Obstacle::draw(QPainter &painter) {
    painter.setBrush(Qt::yellow);//obstacle is yellow
    painter.drawRect(rect);//draw obstacle
}
