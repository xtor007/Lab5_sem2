//
//  Area.cpp
//  lab5
//
//  Created by Anatoliy Khramchenko on 24.04.2021.
//

#include "Area.hpp"

void Area::addPoint(Point newPoint) {
    if (numberOfPoints == 0) {
        maxX = newPoint.x;
        minX = newPoint.x;
        maxY = newPoint.y;
        minY = newPoint.y;
    } else {
        if (newPoint.x > maxX) {
            maxX = newPoint.x;
        }
        if (newPoint.x < minX) {
            minX = newPoint.x;
        }
        if (newPoint.y > maxY) {
            maxY = newPoint.y;
        }
        if (newPoint.y < minY) {
            minY = newPoint.y;
        }
    }
}

bool Area::isInArea(Point startPoint, float radius) {
    //тут я опишу поддходит ли эта область для наших данных
    //эта функция нужна будет при поиске точек
    return false;
}
