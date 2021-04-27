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
#include <cmath>
using namespace std;

class Point {
public:
    float latitude;
    float longitude;
    float x;
    float y;
    const int EarthRadius = 6371;
    string type;
    string subtype;
    string name;
    string adress;
    
    Point (float latitude, float longitude, string type, string subtype, string name, string adress);
    Point () {}
    
    float distanceTo(float xTo, float yTo);
    string forPrint();
};

#endif /* Point_hpp */
