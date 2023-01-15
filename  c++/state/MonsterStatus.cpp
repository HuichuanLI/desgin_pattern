// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成 ，内含一辈子都让你感激自己的优质视频教程，欢迎关注

#include <iostream>
#include "Monster.h"
#include "MonsterStatus.h"

using namespace std;

//各个状态子类的Attacked成员函数实现代码
void MonsterStatus_Feroc::Attacked(int power, Monster *mainobj) {
    int orglife = mainobj->GetLife();  //暂存原来的怪物血量值用于后续比较
    if ((orglife - power) > 400)       //怪物原来处于凶悍状态，现在依旧处于凶悍状态
    {
        //状态未变
        mainobj->SetLife(orglife - power); //怪物剩余的血量
        cout << "怪物处于凶悍状态中，对主角进行疯狂的反击！" << std::endl;
        //处理其他动作逻辑比如反击
    } else {
        //不管下个状态是啥，总之不会是凶悍状态，只可能是不安、恐惧、死亡状态之一，先无条件转到不安状态去（不安状态中会进行再次判断）
        //delete mainobj->getCurrentState();
        //mainobj->setCurrentState(new MonsterStatus_Worr);
        mainobj->setCurrentState(MonsterStatus_Worr::getInstance());
        mainobj->getCurrentState()->Attacked(power, mainobj);
    }
}

void MonsterStatus_Worr::Attacked(int power, Monster *mainobj) {
    int orglife = mainobj->GetLife();
    if ((orglife - power) > 100)       //怪物原来处于不安状态，现在依旧处于不安状态
    {
        //状态未变
        mainobj->SetLife(orglife - power); //怪物剩余的血量
        cout << "怪物处于不安状态中，对主角进行反击并呼唤支援！" << std::endl;
        //处理其他动作逻辑比如反击和不停的呼唤支援
    } else {
        //不管下个状态是啥，总之不会是凶悍和不安状态，只可能是恐惧、死亡状态之一，先无条件转到恐惧状态去
        //delete mainobj->getCurrentState();
        //mainobj->setCurrentState(new MonsterStatus_Fear);
        mainobj->setCurrentState(MonsterStatus_Fear::getInstance());
        mainobj->getCurrentState()->Attacked(power, mainobj);
    }
}

void MonsterStatus_Fear::Attacked(int power, Monster *mainobj) {
    int orglife = mainobj->GetLife();
    if ((orglife - power) > 0)       //怪物原来处于恐惧状态，现在依旧处于恐惧状态
    {
        //状态未变
        mainobj->SetLife(orglife - power); //怪物剩余的血量
        cout << "怪物处于恐惧状态中，处于逃跑之中！" << std::endl;
        //处理其他动作逻辑比如逃跑
    } else {
        //不管下个状态是啥，总之不会是凶悍、不安和恐惧状态，只可能是死亡状态
        //delete mainobj->getCurrentState();
        //mainobj->setCurrentState(new MonsterStatus_Dead);
        mainobj->setCurrentState(MonsterStatus_Dead::getInstance());
        mainobj->getCurrentState()->Attacked(power, mainobj);
    }
}

void MonsterStatus_Dead::Attacked(int power, Monster *mainobj) {
    int orglife = mainobj->GetLife();
    if (orglife > 0) {
        //还要把怪物生命值减掉
        mainobj->SetLife(orglife - power); //怪物剩余的血量
        //处理怪物死亡后事宜比如怪物尸体定时消失等
    }
    cout << "怪物死亡！" << std::endl;
}
