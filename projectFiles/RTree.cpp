//
//  RTree.cpp
//  lab5
//
//  Created by Anatoliy Khramchenko on 24.04.2021.
//

#include "RTree.hpp"

void RTree::addToNode(Node *node, Point *point) {
    node->area.addPoint(*point);
    if (node->area.numberOfPoints == 1) {
        node->point = point;
    }
    if (node->area.numberOfPoints == 2) {
        node->left = new Node;
        node->right = new Node;
        addToNode(node->left, node->point);
        addToNode(node->right, point);
        node->point = NULL;
    }
    if (node->area.numberOfPoints > 2) {
        if (node->left->area.toCenter(*point) > node->right->area.toCenter(*point)) { 
            addToNode(node->right, point);
        } else {
            addToNode(node->left, point);
        }
    }
}

void RTree::addPoint(Point *point) {
    addToNode(&root, point);
}

void RTree::checkNode(Node *node, vector<Point*> *forRes, Point nowPoint, float radius) {
    //смотрим пересекается ли данная область с кругом
    if (node->point != NULL) {
        forRes->push_back(node->point);
    } else {
        if (node->left->area.isInArea(nowPoint, radius)) {
            checkNode(node->left, forRes, nowPoint, radius);
        }
        if (node->right->area.isInArea(nowPoint, radius)) {
            checkNode(node->right, forRes, nowPoint, radius);
        }
    }
}

vector<Point*> RTree::findNear(Point nowPoint, float radius) {
    vector<Point*> res;
    checkNode(&root, &res, nowPoint, radius);
    return res;
}

void RTree::delPoint(Point *pointToDel) {
    delInNode(&root, pointToDel);
}

bool RTree::delInNode(Node *node, Point *pointToDel) {
    
    if ((node->left->point != NULL) && pointToDel->isEqual(node->left->point)) {
        node->left = NULL;
        //delete node->left->point;
        node->point = node->right->point;
        
        node->area = node->right->area;
        node->right = NULL;
        return true;
    }
    if ((node->right->point != NULL) && pointToDel->isEqual(node->right->point)) {
        node->right = NULL;
        //delete node->right->point;
        node->point = node->left->point;
        
        node->area = node->left->area;
        node->left = NULL;
        return true;
    }
    bool rightCheck = false;
    bool leftCheck = false;
    if ((node->left != NULL) && (node->left->area.isInArea(*pointToDel, 0))) {
        leftCheck = delInNode(node->left, pointToDel);
    }
    if ((node->right != NULL) && (node->right->area.isInArea(*pointToDel, 0))) {
        rightCheck = delInNode(node->right, pointToDel);
    }
    if (rightCheck || leftCheck) {
        node->area.numberOfPoints--;
        return true;
    }
    return false;
}
