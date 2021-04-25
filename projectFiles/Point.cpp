//
//  Point.cpp
//  lab5
//
//  Created by Anatoliy Khramchenko on 24.04.2021.
//

#include "Point.hpp"

Point::Point(float latitude, float longitude, string type, string subtype, string name, string adress){
    this->latitude = latitude;
    this->longitude = longitude;
    this->type = type;
    this->subtype = subtype;
    this->name = name;
    this->adress = adress;
}

float Point::distanceTo(float xTo, float yTo) {
    return sqrt((xTo - x)*(xTo - x) + (yTo - y)*(yTo - y));
}
