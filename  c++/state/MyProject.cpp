// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成 ，内含一辈子都让你感激自己的优质视频教程，欢迎关注

#include <iostream>

#include "Monster.h"

#ifdef _DEBUG   //只在Debug（调试）模式下
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //重新定义new运算符
#define new DEBUG_NEW
#endif
#endif

//#include <boost/type_index.hpp>
using namespace std;
//#pragma warning(disable : 4996) 

namespace _nmsp1 {
    /*
    //怪物状态枚举值
    enum MonsterState
    {
        MonS_Fer,    //凶悍
        MonS_Worr,   //不安
        MonS_Fear,   //恐惧
        MonS_Dead    //死亡
    };


    //怪物类
    class Monster
    {
    public:
        //构造函数，怪物的初始状态从“凶悍”开始
        Monster(int life) :m_life(life), m_status(MonS_Fer) {}

    public:
        void Attacked(int power)  //怪物被攻击。参数power表示主角对怪物的攻击力（即怪物丢失的血量）
        {
            m_life -= power; //怪物剩余的血量
            if (m_status == MonS_Fer)
            {
                if (m_life > 400)
                {
                    cout << "怪物受到" << power << "点伤害并对主角进行疯狂的反击！" << endl;
                    //处理其他动作逻辑比如反击
                }
                else if (m_life > 100)
                {
                    cout << "怪物受到" << power << "点伤害并对主角进行反击，怪物变得焦躁不安并开始呼唤支援！" << endl;
                    m_status = MonS_Worr;
                    //处理其他动作逻辑比如反击和呼唤支援
                }
                else if (m_life > 0)
                {
                    cout << "怪物受到" << power << "点伤害，怪物变得恐惧并开始逃跑！" << endl;
                    m_status = MonS_Fear;
                    //处理其他动作逻辑比如逃跑
                }
                else
                {
                    cout << "怪物受到" << power << "点伤害，已经死亡！" << endl;
                    m_status = MonS_Dead;
                    //处理怪物死亡后事宜比如怪物尸体定时消失等
                }
            }
            else if (m_status == MonS_Worr)//目前怪物已经处于不安状态，这说明怪物的血量 <=400 并且 >100
            {
                if (m_life > 100)
                {
                    cout << "怪物受到" << power << "点伤害并对主角进行反击，并继续急促的呼唤支援！" << endl;
                    //处理其他动作逻辑比如反击和呼唤支援
                }
                else if (m_life > 0)
                {
                    cout << "怪物受到" << power << "点伤害，怪物变得恐惧并开始逃跑！" << endl;
                    m_status = MonS_Fear;
                    //处理其他动作逻辑比如逃跑
                }
                else
                {
                    cout << "怪物受到" << power << "点伤害，已经死亡！" << endl;
                    m_status = MonS_Dead;
                    //处理怪物死亡后事宜比如怪物尸体定时消失等
                }
            }
            else if (m_status == MonS_Fear)
            {
                if (m_life > 0)
                {
                    cout << "怪物受到" << power << "点伤害，怪物继续逃跑！" << endl;
                    //处理其他动作逻辑比如逃跑
                }
                else
                {
                    cout << "怪物受到" << power << "点伤害，已经死亡！" << endl;
                    m_status = MonS_Dead;
                    //处理怪物死亡后事宜比如怪物尸体定时消失等
                }
            }
            else //怪物已经处于死亡状态
            {
                cout << "怪物已死亡，不能再被攻击！" << endl;
            }
        }
    private:
        int            m_life;    //血量（生命值）
        MonsterState   m_status;  //初始状态
    };
    */
}

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口

    /*
    _nmsp1::Monster monster(500);
    cout << "怪物出生，当前处于凶悍状态，500点血！" << endl;
    monster.Attacked(20);
    monster.Attacked(100);
    monster.Attacked(200);
    monster.Attacked(170);
    monster.Attacked(100);
    monster.Attacked(100);
    */

    Monster monster(500);
    cout << "怪物出生，当前处于凶悍状态，500点血！" << endl;
    monster.Attacked(20);
    monster.Attacked(100);
    monster.Attacked(200);
    monster.Attacked(170);
    monster.Attacked(100);
    monster.Attacked(100);

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

