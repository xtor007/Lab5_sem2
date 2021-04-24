//
//  Area.hpp
//  lab5
//
//  Created by Anatoliy Khramchenko on 24.04.2021.
//

#ifndef Area_hpp
#define Area_hpp

#include <stdio.h>
#include <iostream>
#include "Point.hpp"
using namespace std;

class Area {
    float maxX;
    float maxY;
    float minX;
    float minY;
public:
    int numberOfPoints = 0;
    void addPoint(Point newPoint);
    bool isInArea(Point startPoint, float radius);
    float toCenter(Point point);
};

#endif /* Area_hpp */
