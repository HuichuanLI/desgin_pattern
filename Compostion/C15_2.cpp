#include <iostream>

#include "Node.h"

#include "DepartmentNode.h"
#include "HumanNode.h"

int main()
{
	DepartmentNode root("小慕公司");

	std::shared_ptr<Node> caiwu = std::make_shared<DepartmentNode>("财务部");
	std::shared_ptr<Node> kaifa = std::make_shared<DepartmentNode>("开发部");

	root.addChild(caiwu);
	root.addChild(kaifa);

	std::shared_ptr<Node> xiaomu = std::make_shared<HumanNode>("小慕");

	kaifa->addChild(xiaomu);

	root.printInfo(0);

	return 0;
}