//
//  RTree.hpp
//  lab5
//
//  Created by Anatoliy Khramchenko on 24.04.2021.
//

#ifndef RTree_hpp
#define RTree_hpp

#include <stdio.h>
#include <iostream>
#include "Area.hpp"
#include <vector>

using namespace std;

// тут тоже нужно будет поразмыслить над инкапсуляцией
class Node {
public:
    Point *point;
    Area area;
    Node *left;
    Node *right;
};

class RTree {
    void addToNode(Node *node, Point *point);
    void checkNode(Node *node, vector<Point*> *forRes, Point nowPoint, float radius);
public:
    Node root;
    void addPoint(Point *point);
    vector<Point*> findNear(Point nowPoint, float radius);
};

#endif /* RTree_hpp */
