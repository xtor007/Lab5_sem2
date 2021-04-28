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
    // приходим к декартовым координатам
    //for X
    x = EarthRadius*cos(latitude*M_PI/180)*(longitude*M_PI/180);
    //for Y
    y = (latitude*M_PI/180)*EarthRadius;
}

float Point::distanceTo(float xTo, float yTo) {
    return sqrt((xTo - x)*(xTo - x) + (yTo - y)*(yTo - y));
}

string Point::forPrint(float x, float y) {
    string res = "Широта: " + to_string(latitude) + "\n" + "Довгота: " + to_string(longitude) + "\n" + "Тип: " + type + "\n" + "Вид: " + subtype + "\n" + "Назва: " + name + "\n" + "Адреса: " + adress + "\n" + "Відстань до заданої точки(км.): " + to_string(distanceTo(x, y));
    return res;
}

bool Point::isEqual(Point *otherPoint) {
    if ((latitude == otherPoint->latitude) && (longitude == otherPoint->longitude)) {
        return true;
    }
    return false;
}
