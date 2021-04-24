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
