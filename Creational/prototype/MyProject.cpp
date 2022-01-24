// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成 ，内含一辈子都让你感激自己的优质视频教程，欢迎关注

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

namespace _nmsp1
{
	//工厂方法模式(代码放到这里，方便比较)----------------------------------------
	//怪物父类
	class Monster
	{
	public:
		//构造函数
		Monster(int life, int magic, int attack) :m_life(life), m_magic(magic), m_attack(attack) {}
		virtual ~Monster() {} //做父类时析构函数应该为虚函数

	protected://可能被子类访问的成员，所以用protected修饰
		//怪物属性
		int m_life; //生命值
		int m_magic; //魔法值
		int m_attack; //攻击力
	};
	//亡灵类怪物
	class M_Undead :public Monster
	{
	public:
		//构造函数
		M_Undead(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一个亡灵类怪物来到了这个世界" << endl;
		}
		//其他代码略......
	};
	//元素类怪物
	class M_Element :public Monster
	{
	public:
		//构造函数
		M_Element(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一个元素类怪物来到了这个世界" << endl;
		}
		//其他代码略......
	};
	//机械类怪物
	class M_Mechanic :public Monster
	{
	public:
		//构造函数
		M_Mechanic(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一个机械类怪物来到了这个世界" << endl;
		}
		//其他代码略......
	};
		
	//所有工厂类的父类
	class M_ParFactory
	{
	public:
		virtual Monster* createMonster() = 0; //具体的实现在子类中进行
		virtual ~M_ParFactory() {} //做父类时析构函数应该为虚函数
	};
	//M_Undead怪物类型的工厂，生产M_Undead类型怪物
	class M_UndeadFactory : public M_ParFactory
	{
	public:
		virtual Monster* createMonster()
		{
			//return  new M_Undead(300, 50, 80); //创建亡灵类怪物
			Monster* ptmp = new M_Undead(300, 50, 80); //创建亡灵类怪物
			//这里可以增加一些其他业务代码
			//......
			return ptmp;
		}
	};

	//M_Element怪物类型的工厂，生产M_Element类型怪物
	class M_ElementFactory : public M_ParFactory
	{
	public:
		virtual Monster* createMonster()
		{
			return  new M_Element(200, 80, 100); //创建元素类怪物
		}
	};

	//M_Mechanic怪物类型的工厂，生产M_Mechanic类型怪物
	class M_MechanicFactory : public M_ParFactory
	{
	public:
		virtual Monster* createMonster()
		{
			return  new M_Mechanic(400, 0, 110); //创建机械类怪物
		}
	};
}

namespace _nmsp2
{
	//怪物父类
	class Monster
	{
	public:
		//构造函数
		Monster(int life, int magic, int attack) :m_life(life), m_magic(magic), m_attack(attack) {}
		virtual ~Monster() {} //做父类时虚构函数应该为虚函数

	public:
		virtual Monster* clone() = 0; //具体的实现在子类中进行

	protected: //可能被子类访问的成员，所以用protected修饰
		//怪物属性
		int m_life;  //生命值
		int m_magic; //魔法值
		int m_attack;  //攻击力
	};

	//亡灵类怪物
	class M_Undead :public Monster
	{
	public:
		//构造函数
		M_Undead(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一只亡灵类怪物来到了这个世界" << endl;
		}

		//拷贝构造函数
		//..........留给大家自己写

		virtual Monster* clone()
		{
			//return new M_Undead(300, 50, 80); //创建亡灵类怪物
			return new M_Undead(*this); //触发拷贝构造函数的调用来创建亡灵类怪物
		}
		//...其他代码略
	};

	//元素类怪物
	class M_Element :public Monster
	{
	public:
		//构造函数
		M_Element(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一只元素类怪物来到了这个世界" << endl;
		}

		//拷贝构造函数
		M_Element(const M_Element& tmpobj) :Monster(tmpobj) //初始化列表中注意对父类子对象的初始化
		{
			cout << "调用了M_Element::M_Element(const M_Element& tmpobj)拷贝构造函数创建了一只元素类怪物" << endl;
		}

		virtual Monster* clone()
		{
			//return new M_Element(200, 80, 100); //创建元素类怪物
			return new M_Element(*this);
		}
		//...其他代码略
	};

	//机械类怪物
	class M_Mechanic :public Monster
	{
	public:
		//构造函数
		M_Mechanic(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一只机械类怪物来到了这个世界" << endl;
		}

		//拷贝构造函数
		M_Mechanic(const M_Mechanic& tmpobj) :Monster(tmpobj) //初始化列表中注意对父类子对象的初始化
		{
			cout << "调用了M_Mechanic::M_Mechanic(const M_Mechanic& tmpobj)拷贝构造函数创建了一只机械类怪物" << endl;
		}

		virtual Monster* clone()
		{
			//return new M_Mechanic(400, 0, 110); //创建机械类怪物
			return new M_Mechanic(*this);
		}
		//...其他代码略
	};
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
		

	//第二节  原型（Prototype）模式
		//原型模式：通过一个对象（原型对象）克隆出多个一模一样的对象。
	//（1）通过工厂方法模式演变到原型模式
	  //克隆对象自身实际上是需要调用类的拷贝构造函数。《C++新经典：对象模型》:深拷贝，浅拷贝
	  //克隆对象意味着复制出一个全新的对象，所以设计到深浅拷贝时都要实现深拷贝


	_nmsp2::M_Mechanic myPropMecMonst(400, 0, 110); //创建一只机械类怪物对象作为原型对象以用于克隆目的
	_nmsp2::Monster* pmyPropEleMonster = new _nmsp2::M_Element(200, 80, 100); //创建一只元素类怪物对象作为原型对象以用于克隆目的，
	                  //这里可以直接new，也可以通过工厂模式创建原型对象，取决于程序员自己的洗好。
	//.....
	_nmsp2::Monster* p_CloneObj1 = myPropMecMonst.clone(); //使用原型对象克隆出新的机械类怪物对象
	_nmsp2::Monster* p_CloneObj2 = pmyPropEleMonster->clone(); //使用原型对象克隆出新的元素类怪物对象

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

