//
// Created by lhc456 on 2023/5/21.
//
#include "Dir.h"
#include "File.h"

int main(int argc, char **argv) {
    Dir root("文件夹1");

    std::shared_ptr<Node> caiwu = std::make_shared<Dir>("文件夹2");
    std::shared_ptr<Node> kaifa = std::make_shared<Dir>("文件夹3");

    root.addChild(caiwu);
    root.addChild(kaifa);

    std::shared_ptr<Node> xiaomu = std::make_shared<File>("文件");

    kaifa->addChild(xiaomu);

    root.printInfo(0);

    return 0;
}
