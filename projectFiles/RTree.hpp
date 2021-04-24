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
public:
    Node root;
    void addPoint(Point *point);
};

#endif /* RTree_hpp */
