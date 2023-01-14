

#include <iostream>


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
    //定义一个“战士”类
    class Warrior {
    public:
        //构造函数
        Warrior(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack) {}

        //....一些成员函数等

    public:
        void JN_Burn() //技能“燃烧”
        {
            cout << "让所有敌人每人失去500点生命值，相关逻辑代码在这里略......" << endl;
            cout << "主角自身失去300点生命值" << endl;
            m_life -= 300;
            cout << "播放技能“燃烧”的技能特效给玩家看" << endl;
        }

    private:
        //角色属性
        int m_life;    //生命值
        int m_magic;   //魔法值
        int m_attack;  //攻击力
    };

}
namespace _nmsp2 {
    //战斗者父类
    class Fighter {
    public:
        //构造函数
        Fighter(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack) {}

        virtual ~Fighter() {} //做父类时析构函数应该为虚函数

        void JN_Burn() //技能“燃烧”
        {
            if (canUseJN() == false) //如果不能使用该技能，则直接返回
                return;

            effect_enemy(); //对敌人产生的影响
            effect_self(); //对主角自身产生的影响
            play_effect(); //播放技能“燃烧”的技能特效
        }

    private:
        virtual void effect_enemy() {}//函数体为空，表示啥也不做，如果要求必须在子类中重新实现该虚函数，则可以将该函数写成纯虚函数
        virtual void effect_self() {};

        void play_effect() {
            cout << "播放技能“燃烧”的技能特效给玩家看" << endl; //所有主角播放的技能特效都相同，因此不用写成一个虚函数并在子类中实现技能特效的播放
        }

    private:
        virtual bool canUseJN() = 0; //判断是否能使用技能“燃烧”，这是纯虚函数声明，子类中必须重新实现canUseJN

    protected: //可能被子类访问的成员，用protected修饰
        //角色属性
        int m_life;    //生命值
        int m_magic;   //魔法值
        int m_attack;  //攻击力
    };

    //--------------------
    //“战士”类，父类为Fighter
    class F_Warrior : public Fighter {
    public:
        //构造函数
        F_Warrior(int life, int magic, int attack) : Fighter(life, magic, attack) {}

    private:
        //对敌人产生的影响
        virtual void effect_enemy() {
            cout << "战士主角_让所有敌人每人失去500点生命值，相关逻辑代码在这里略......" << endl;
        }

        //对主角自身产生的影响
        virtual void effect_self() {
            cout << "战士主角_自身失去300点生命值" << endl;
            m_life -= 300;
        }

    private:
        //判断是否能使用技能“燃烧”
        virtual bool canUseJN() {
            if (m_life < 300) //生命值不够300点，不能使用技能“燃烧”
                return false;
            return true;
        }

    };

    //“法师”类，父类为Fighter
    class F_Mage : public Fighter {
    public:
        //构造函数
        F_Mage(int life, int magic, int attack) : Fighter(life, magic, attack) {}

    private:
        //对敌人产生的影响
        virtual void effect_enemy() {
            cout << "法师主角_让所有敌人每人失去650点生命值，相关逻辑代码在这里略......" << endl;
        }

        //对主角自身产生的影响
        virtual void effect_self() {
            cout << "法师主角_自身失去100点魔法值" << endl;
            m_magic -= 100;
        }

    private:
        //判断是否能使用技能“燃烧”
        virtual bool canUseJN() {
            if (m_magic < 100) //魔法值不够100点，不能使用技能“燃烧”
                return false;
            return true;
        }

    };

}

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口

    //_nmsp1::Warrior  mroleobj(1000, 0, 200); //创建主角
    //mroleobj.JN_Burn(); //主角释放“燃烧”技能

    /*
    _nmsp2::Fighter* prole_war = new _nmsp2::F_Warrior(1000, 0, 200); //创建战士主角，注意这是父类指针指向子类对象以利用多态特性
    prole_war->JN_Burn();  //战士主角释放“燃烧”技能

    cout << "-------------------------" << endl; //分隔线，以更醒目的显示信息

    _nmsp2::Fighter* prole_mag = new _nmsp2::F_Mage(800, 200, 300); //创建法师主角，注意这是父类指针指向子类对象以利用多态特性
    prole_mag->JN_Burn();  //法师主角释放“燃烧”技能

    //释放资源
    delete prole_war;
    delete prole_mag;
    */

    _nmsp2::Fighter *prole_war2 = new _nmsp2::F_Warrior(50, 0, 200); //创建生命值只有50的战士主角
    prole_war2->JN_Burn();  //该战士无法成功释放“燃烧”技能，不输出任何结果
    delete prole_war2;


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

