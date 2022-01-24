//
// Created by 李汇川 on 2022/1/24.
//

// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成 ，内含一辈子都让你感激自己的优质视频教程，欢迎关注

#include <iostream>
#include <vector>
#include <sstream>

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
//怪物父类
class Monster {
 public:
  //构造函数
  Monster(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack) {}
  virtual ~Monster() {} //做父类时析构函数应该为虚函数

 protected://可能被子类访问的成员，所以用protected修饰
  //怪物属性
  int m_life; //生命值
  int m_magic; //魔法值
  int m_attack; //攻击力
};
//亡灵类怪物
class M_Undead : public Monster {
 public:
  //构造函数
  M_Undead(int life, int magic, int attack) : Monster(life, magic, attack) {
    cout << "一个亡灵类怪物来到了这个世界" << endl;
  }
  //其他代码略......
};
//元素类怪物
class M_Element : public Monster {
 public:
  //构造函数
  M_Element(int life, int magic, int attack) : Monster(life, magic, attack) {
    cout << "一个元素类怪物来到了这个世界" << endl;
  }
  //其他代码略......
};
//机械类怪物
class M_Mechanic : public Monster {
 public:
  //构造函数
  M_Mechanic(int life, int magic, int attack) : Monster(life, magic, attack) {
    cout << "一个机械类怪物来到了这个世界" << endl;
  }
  //其他代码略......
};
//野兽类
//class M_Beast :public Monster { .... };
//-------------------------------
/*
//怪物工厂类
class MonsterFactory
{
public:
    //Monster* createMonster(string strmontype) //简单工厂模式
    static Monster* createMonster(string strmontype) //静态工厂方法模式（Static Factory Method）
    {
        Monster* prtnobj = nullptr;
        if (strmontype == "udd") //udd代表要创建亡灵类怪物
        {
            prtnobj = new M_Undead(300, 50, 80);
        }
        else if (strmontype == "elm") //elm代表要创建元素类怪物
        {
            prtnobj = new M_Element(200, 80, 100);
        }
        else if (strmontype == "mec") //mec代表要创建机械类怪物
        {
            prtnobj = new M_Mechanic(400, 0, 110);
        }
        return prtnobj;
    }
};
*/
//所有工厂类的父类
class M_ParFactory {
 public:
  virtual Monster *createMonster() = 0; //具体的实现在子类中进行
  virtual ~M_ParFactory() {} //做父类时析构函数应该为虚函数
};
//M_Undead怪物类型的工厂，生产M_Undead类型怪物
class M_UndeadFactory : public M_ParFactory {
 public:
  virtual Monster *createMonster() {
    //return  new M_Undead(300, 50, 80); //创建亡灵类怪物
    Monster *ptmp = new M_Undead(300, 50, 80); //创建亡灵类怪物
    //这里可以增加一些其他业务代码
    //......
    return ptmp;
  }
};

//M_Element怪物类型的工厂，生产M_Element类型怪物
class M_ElementFactory : public M_ParFactory {
 public:
  virtual Monster *createMonster() {
    return new M_Element(200, 80, 100); //创建元素类怪物
  }
};

//M_Mechanic怪物类型的工厂，生产M_Mechanic类型怪物
class M_MechanicFactory : public M_ParFactory {
 public:
  virtual Monster *createMonster() {
    return new M_Mechanic(400, 0, 110); //创建机械类怪物
  }
};
//class M_BeastFactory:public M_ParFactory{......};
//全局的用于创建怪物对象的函数,注意形参的类型是工厂父类类型的指针，返回类型是怪物父类类型的指针
Monster *Gbl_CreateMonster(M_ParFactory *factory) {
  return factory->createMonster(); //createMonster虚函数扮演了多态new的行为，factory指向的具体怪物工厂类不同，创建的怪物对象也不同。
}

//-------------------
//不想创建太多工厂类，又想封装变化
//创建怪物工厂子类模板
template<typename T>
class M_ChildFactory : public M_ParFactory {
 public:
  virtual Monster *createMonster() {
    return new T(300, 50, 80); //如果需要不同的值则可以通过createMonster的形参将值传递进来
  }
};

}

namespace _nmsp2 {
class Monster {
 public:
  Monster(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack) {}
  virtual ~Monster() {}
 protected:
  int m_life;
  int m_magic;
  int m_attack;
 public:
  virtual Monster *clone() = 0;
};
//亡灵类怪物
class M_Undead : public Monster {
 public:
  //构造函数
  M_Undead(int life, int magic, int attack) : Monster(life, magic, attack) {
    cout << "一只亡灵类怪物来到了这个世界" << endl;
  }

  //拷贝构造函数
  //..........留给大家自己写

  virtual Monster *clone() {
    //return new M_Undead(300, 50, 80); //创建亡灵类怪物
    return new M_Undead(*this); //触发拷贝构造函数的调用来创建亡灵类怪物
  }
  //...其他代码略
};
//元素类怪物
class M_Element : public Monster {
 public:
  //构造函数
  M_Element(int life, int magic, int attack) : Monster(life, magic, attack) {
    cout << "一只元素类怪物来到了这个世界" << endl;
  }

  //拷贝构造函数
  M_Element(const M_Element &tmpobj) : Monster(tmpobj) //初始化列表中注意对父类子对象的初始化
  {
    cout << "调用了M_Element::M_Element(const M_Element& tmpobj)拷贝构造函数创建了一只元素类怪物" << endl;
  }

  virtual Monster *clone() {
    //return new M_Element(200, 80, 100); //创建元素类怪物
    return new M_Element(*this);
  }
  //...其他代码略
};
//机械类怪物
class M_Mechanic : public Monster {
 public:
  //构造函数
  M_Mechanic(int life, int magic, int attack) : Monster(life, magic, attack) {
    cout << "一只机械类怪物来到了这个世界" << endl;
  }

  //拷贝构造函数
  M_Mechanic(const M_Mechanic &tmpobj) : Monster(tmpobj) //初始化列表中注意对父类子对象的初始化
  {
    cout << "调用了M_Mechanic::M_Mechanic(const M_Mechanic& tmpobj)拷贝构造函数创建了一只机械类怪物" << endl;
  }

  virtual Monster *clone() {
    //return new M_Mechanic(400, 0, 110); //创建机械类怪物
    return new M_Mechanic(*this);
  }
  //...其他代码略
};

//void Gbl_CreateMonster2(Monster *pMonster) {
//  Monster *ptmpobj = nullptr;
//  if (dynamic_cast<M_Undead *>(pMonster) != nullptr) {
//    ptmpobj = new M_Undead(300, 50, 80); //创建亡灵类怪物
//  } else if (dynamic_cast<M_Element *>(pMonster) != nullptr) {
//    ptmpobj = new M_Element(200, 80, 100); //创建元素类怪物
//  } else if (dynamic_cast<M_Mechanic *>(pMonster) != nullptr) {
//    ptmpobj = new M_Mechanic(400, 0, 110); //创建机械类怪物
//  }
//  if (ptmpobj != nullptr) {
//    //这里就可以针对ptmpobj对象实现各种业务逻辑
//    //......
//    //不要忘记释放资源
//    delete ptmpobj;
//  }
//}
void Gbl_CreateMonster2(Monster *pMonster) {
  Monster *ptmpobj = pMonster->clone(); //根据已有对象直接创建新对象，不需要知道已有对象所属的类型
  //这里就可以针对ptmpobj对象实现各种业务逻辑
  //......
  //不要忘记释放资源
  delete ptmpobj;
}
}

int main() {
  //第二节  原型（Prototype）模式
  //原型模式：通过一个对象（原型对象）克隆出多个一模一样的对象。
  //（1）通过工厂方法模式演变到原型模式
  //克隆对象自身实际上是需要调用类的拷贝构造函数。《C++新经典：对象模型》:深拷贝，浅拷贝
  //克隆对象意味着复制出一个全新的对象，所以设计到深浅拷贝时都要实现深拷贝

  //工厂方法模式和原型模式在创建对象时的异同点：
  //a)都不需要程序员知道所创建对象所属的类名。
  //b)工厂方法模式中的createMonster仍旧属于根据类名来生成新对象。
  //c)原型模式中的clone是根据现有对象来生成新对象。
  //可以把原型模式看成是一种特殊的工厂方法模式。

  //原型模式优缺点：
  //a)如果创建的新对象内部数据比较复杂且多变，原型模式创建对象的效率可能会高很多。
  //b)原型模式不存在额外的等级结构——原型模式不需要额外的工厂类。
  //c)clone接口的实现方法有多种。
  //d)有些情况下，产品类中存在一个克隆方法也会给开发提供一些明显便利。



  _nmsp2::M_Mechanic myPropMecMonst(400, 0, 110); //创建一只机械类怪物对象作为原型对象以用于克隆目的
  _nmsp2::Monster *pmyPropEleMonster = new _nmsp2::M_Element(200, 80, 100); //创建一只元素类怪物对象作为原型对象以用于克隆目的，
  //这里可以直接new，也可以通过工厂模式创建原型对象，取决于程序员自己的洗好。
  //.....
  _nmsp2::Monster *p_CloneObj1 = myPropMecMonst.clone(); //使用原型对象克隆出新的机械类怪物对象
  _nmsp2::Monster *p_CloneObj2 = pmyPropEleMonster->clone(); //使用原型对象克隆出新的元素类怪物对象

  //可以对p_CloneObj1、p_CloneObj2所指向的对象进行各种操作（实现具体的业务逻辑）
  //......

  //释放资源
  //释放克隆出来的怪物对象
  delete p_CloneObj1;
  delete p_CloneObj2;

  //释放原型对象（堆中的）
  delete pmyPropEleMonster;

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

