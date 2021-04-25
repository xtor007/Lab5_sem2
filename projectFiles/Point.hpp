//
//  Point.hpp
//  lab5
//
//  Created by Anatoliy Khramchenko on 24.04.2021.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Point {
public:
    float latitude;
    float longitude;
    float x;
    float y;
    string type;
    string subtype;
    string name;
    string adress;
    
    Point (float latitude, float longitude, string type, string subtype, string name, string adress);
    Point () {}
    
    float distanceTo(float xTo, float yTo);
    
    //тут функция перехода на плоские координаты
    
}; //конструктор еще не описаный и мб нужно будет закинуть все в прайват и сделать геттеры, но это не точно

#endif /* Point_hpp */
