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
    
//    if (((minX - startPoint.x)*(minX - startPoint.x) + (minY - startPoint.y)*(minY - startPoint.y)) <= radius*radius) {
//        return true;
//    }
//    if (((maxX - startPoint.x)*(maxX - startPoint.x) + (minY - startPoint.y)*(minY - startPoint.y)) <= radius*radius) {
//        return true;
//    }
//    if (((minX - startPoint.x)*(minX - startPoint.x) + (maxY - startPoint.y)*(maxY - startPoint.y)) <= radius*radius) {
//        return true;
//    }
//    if (((maxX - startPoint.x)*(maxX - startPoint.x) + (maxY - startPoint.y)*(maxY - startPoint.y)) <= radius*radius) {
//        return true;
//    }
    if (((minX - startPoint.x) <= radius+0.0001) && ((startPoint.x - maxX) <= radius+0.0001) && ((minY - startPoint.y) <= radius+0.0001) && ((startPoint.y - maxY) <= radius+0.0001)) {
        return true;
    }
    return false;
}

float Area::toCenter(Point point) {
    return sqrt((maxX + minX)*(maxX + minX)/4 + (maxY + minY)*(maxY + minY)/4);
}


