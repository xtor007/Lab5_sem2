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
    numberOfPoints++;
}

bool Area::isInArea(Point startPoint, float radius) {
    
    if ((minX <= startPoint.x) && (maxX >= startPoint.x) && (minY <= startPoint.y) && (maxY >= startPoint.y)) {
        return true;
    }
    if ((startPoint.distanceTo(minX, minY) <= radius) || (startPoint.distanceTo(maxX, minY) <= radius) || (startPoint.distanceTo(minX, maxY) <= radius) || (startPoint.distanceTo(maxX, maxY) <= radius)) {
        return true;
    }
    return false;
}

float Area::toCenter(Point point) {
    float x = (maxX + minX)/2;
    float y = (maxY + minY)/2;
    return sqrt((x - point.x)*(x - point.x) + (y - point.y)*(y - point.y));
}


