//
// Created by lhc456 on 2023/5/21.
//

#ifndef FACTORY_METHOD_NODE_H
#define FACTORY_METHOD_NODE_H

#include <string>
#include <vector>

#include <memory>

class Node {
public:
    Node(const std::string &_name);

    void addChild(std::shared_ptr<Node> &node);

    void printInfo(int level);

    std::string name;

    std::vector<std::shared_ptr<Node>> child;
};

#endif //FACTORY_METHOD_NODE_H
