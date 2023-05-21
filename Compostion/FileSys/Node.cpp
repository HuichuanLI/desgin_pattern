//
// Created by lhc456 on 2023/5/21.
//
#include "Node.h"

Node::Node(const std::string &_name)
        : name(_name) {

}

void Node::addChild(std::shared_ptr<Node> &node) {
    child.push_back(node);
}

void Node::printInfo(int level) {
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("file name: %s\n", name.c_str());

    for (int i = 0; i < child.size(); i++) {
        std::shared_ptr<Node> n = child[i];

        n->printInfo(level + 1);
    }
}