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
    
    bool isXNorm = false;
    bool isYNorm = false;
    if ((minX <= startPoint.x) && (maxX >= startPoint.x)) {
        isXNorm = true;
    }
    if ((abs(minX - startPoint.x) <= radius) || (abs(startPoint.x - maxX) <= radius)) {
        isXNorm = true;
    }
    if ((minY <= startPoint.y) && (maxY >= startPoint.y)) {
        isYNorm = true;
    }
    if ((abs(minY - startPoint.y) <= radius) || (abs(startPoint.y - maxY) <= radius)) {
        isYNorm = true;
    }
    
    
    //учитыаем то, что с одной стороны Земли можем попасть на другую
    
    float parallelLength = 2*M_PI*startPoint.EarthRadius*cos(startPoint.y/startPoint.EarthRadius);
    float newX;
    if (startPoint.x > 0) {
        newX = startPoint.x - parallelLength;
    } else {
        newX = startPoint.x + parallelLength;
    }
    
    if ((minX <= newX) && (maxX >= newX)) {
        isXNorm = true;
    }
    if ((abs(minX - newX) <= radius) || (abs(newX - maxX) <= radius)) {
        isXNorm = true;
    }
    
    if (isXNorm && isYNorm) {
        return true;
    }
    return false;
}

float Area::toCenter(Point point) {
    //для примерной оценки близости точки к области
    float x = (maxX + minX)/2;
    float y = (maxY + minY)/2;
    return sqrt((x - point.x)*(x - point.x) + (y - point.y)*(y - point.y));
}


//if ((minX <= startPoint.x) && (maxX >= startPoint.x) && (minY <= startPoint.y) && (maxY >= startPoint.y)) {
//    return true;
//}
//if ((startPoint.distanceTo(minX, minY) <= radius) || (startPoint.distanceTo(maxX, minY) <= radius) || (startPoint.distanceTo(minX, maxY) <= radius) || (startPoint.distanceTo(maxX, maxY) <= radius)) {
//    return true;
//}


//if ((minX <= newX) && (maxX >= newX) && (minY <= startPoint.y) && (maxY >= startPoint.y)) {
//    return true;
//}
//if ((sqrt((minX - newX)*(minX - newX) + (minY - startPoint.y)*(minY - startPoint.y)) <= radius) || (sqrt((maxX - newX)*(maxX - newX) + (minY - startPoint.y)*(minY - startPoint.y)) <= radius) || (sqrt((minX - newX)*(minX - newX) + (maxY - startPoint.y)*(maxY - startPoint.y)) <= radius) || (sqrt((maxX - newX)*(maxX - newX) + (maxY - startPoint.y)*(maxY - startPoint.y)) <= radius)) {
//    return true;
//}
