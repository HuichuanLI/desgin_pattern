#pragma once

#include <string>
#include <vector>

#include <memory>

class Node
{
public:
	Node(const std::string & _name);

	void addChild(std::shared_ptr<Node> & node);

	void printInfo(int level);

	std::string name;

	std::vector<std::shared_ptr<Node>> child;
};

