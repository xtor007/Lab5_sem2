//
//  main.cpp
//  lab5
//
//  Created by Anatoliy Khramchenko on 24.04.2021.
//

#include <iostream>
#include "RTree.hpp"
#include "Reading.hpp"
#include "UserInterface.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    Point p1; p1.x=3; p1.y=4;
    Point p2; p2.x=-3; p2.y=5;
    Point p3; p3.x=3; p3.y=-4;
    Point p4; p4.x=6; p4.y=5;
    Point p5; p5.x=7; p5.y=8;
    Point p6; p6.x=1; p6.y=2;
    
    RTree tree;
    tree.addPoint(&p1);
    tree.addPoint(&p2);
    tree.addPoint(&p3);
    tree.addPoint(&p4);
    tree.addPoint(&p5);
    tree.addPoint(&p6);
    
    Point fp; fp.x=2; fp.y=2;
    vector<Point*> res = tree.findNear(fp, 4);
    
    return 0;
}
