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
    //for X
    x = EarthRadius*cos(latitude*M_PI/180)*(longitude*M_PI/180);
    //for Y
    y = (latitude*M_PI/180)*EarthRadius;
}

float Point::getX(){
    return x;
}

float Point::getY(){
    return x;
}
