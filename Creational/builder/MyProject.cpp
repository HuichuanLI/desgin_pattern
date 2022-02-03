// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//公众号：程序员速成 ，内含一辈子都让你感激自己的优质视频教程，欢迎关注

#include <iostream>
#include <map>
#include <stack>

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
	//怪物父类
	class Monster
	{
	public:
		virtual ~Monster() {} //做父类时析构函数应该为虚函数
		//void Assemble(string strmodelno) //参数:模型编号，形如：“1253679201245”等。每些位的组合都有一些特别的含义，这里不需要探究。
		//{
		//	LoadTrunkModel(strmodelno.substr(4, 3)); //载入躯干模型，截取某部分字符串以表示躯干模型的编号
		//	LoadHeadModel(strmodelno.substr(7, 3)); //载入头部模型并挂接到躯干模型上
		//	LoadLimbsModel(strmodelno.substr(10, 3)); //载入四肢模型并挂接到躯干模型上
		//}

		//virtual void LoadTrunkModel(string strno) = 0; //这里也可以写成一个空函数，子类决定是否重新实现
		//virtual void LoadHeadModel(string strno) = 0;
		//virtual void LoadLimbsModel(string strno) = 0;
	};

	//亡灵类怪物
	class M_Undead :public Monster
	{
	/*public:
		virtual void LoadTrunkModel(string strno)
		{
			cout << "载入亡灵类怪物的躯干部位模型，需要调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "载入亡灵类怪物的头部模型并挂接到躯干部位，需要调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "载入亡灵类怪物的四肢模型并挂接到躯干部位，需要调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}*/
	};

	//元素类怪物
	class M_Element :public Monster
	{
	/*public:
		virtual void LoadTrunkModel(string strno)
		{
			cout << "载入元素类怪物的躯干部位模型，需要调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "载入元素类怪物的头部模型并挂接到躯干部位，需要调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "载入元素类怪物的四肢模型并挂接到躯干部位，需要调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}*/
	};

	//机械类怪物
	class M_Mechanic :public Monster
	{
	/*public:
		virtual void LoadTrunkModel(string strno)
		{
			cout << "载入机械类怪物的躯干部位模型，需要调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "载入机械类怪物的头部模型并挂接到躯干部位，需要调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "载入机械类怪物的四肢模型并挂接到躯干部位，需要调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}*/
	};
	//----------------------------
	//怪物构建器父类
	class MonsterBuilder
	{
	public:
		virtual ~MonsterBuilder() {} //做父类时析构函数应该为虚函数
		//void Assemble(string strmodelno) //参数:模型编号，形如：“1253679201245”等。每些位的组合都有一些特别的含义，这里不需要探究。
		//{
		//	LoadTrunkModel(strmodelno.substr(4, 3)); //载入躯干模型，截取某部分字符串以表示躯干模型的编号
		//	LoadHeadModel(strmodelno.substr(7, 3)); //载入头部模型并挂接到躯干模型上
		//	LoadLimbsModel(strmodelno.substr(10, 3)); //载入四肢模型并挂接到躯干模型上
		//}

		//返回指向Monster类的成员变量指针m_pMonster，当一个复杂的对象构建完成后，可以通过该成员函数把对象返回。
		Monster* GetResult()
		{
			return m_pMonster;
		}

		virtual void LoadTrunkModel(string strno) = 0; //这里也可以写成一个空函数，子类决定是否重新实现
		virtual void LoadHeadModel(string strno) = 0;
		virtual void LoadLimbsModel(string strno) = 0;

	protected:
		Monster* m_pMonster; //指向Monster类的成员变量指针
	};

	//----------
	//亡灵类怪物构建器类
	class M_UndeadBuilder :public MonsterBuilder
	{
	public:
		M_UndeadBuilder() //构造函数
		{
			m_pMonster = new M_Undead();
		}

		virtual void LoadTrunkModel(string strno)
		{
			cout << "载入亡灵类怪物的躯干部位模型，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//具体要做的事情其实是委托给怪物子类完成，委托指把本该自己实现的功能转给其他类实现
			//m_pMonster->......略
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "载入亡灵类怪物的头部模型并挂接到躯干部位，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "载入亡灵类怪物的四肢模型并挂接到躯干部位，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
	};

	//元素类怪物构建器类
	class M_ElementBuilder :public MonsterBuilder
	{
	public:
		M_ElementBuilder() //构造函数
		{
			m_pMonster = new M_Element();
		}

		virtual void LoadTrunkModel(string strno)
		{
			cout << "载入元素类怪物的躯干部位模型，需要m_pMonster指针调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;			
			//m_pMonster->......略
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "载入元素类怪物的头部模型并挂接到躯干部位，需要m_pMonster指针调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "载入元素类怪物的四肢模型并挂接到躯干部位，需要m_pMonster指针调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
	};

	//机械类怪物构建器类
	class M_MechanicBuilder :public MonsterBuilder
	{
	public:
		M_MechanicBuilder() //构造函数
		{
			m_pMonster = new M_Mechanic();
		}

		virtual void LoadTrunkModel(string strno)
		{
			cout << "载入机械类怪物的躯干部位模型，需要m_pMonster指针调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "载入机械类怪物的头部模型并挂接到躯干部位，需要m_pMonster指针调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "载入机械类怪物的四肢模型并挂接到躯干部位，需要m_pMonster指针调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
	};

	//------------------
	//指挥者类
	class MonsterDirector
	{
	public:
		MonsterDirector(MonsterBuilder* ptmpBuilder) //构造函数
		{
			m_pMonsterBuilder = ptmpBuilder;
		}

		//指定新的构建器
		void SetBuilder(MonsterBuilder* ptmpBuilder)
		{
			m_pMonsterBuilder = ptmpBuilder;
		}

		//原MonsterBuilder类中的Assemble成员函数
		Monster *Construct(string strmodelno) //参数:模型编号，形如：“1253679201245”等。每些位的组合都有一些特别的含义，这里不需要探究。
		{
			m_pMonsterBuilder->LoadTrunkModel(strmodelno.substr(4, 3)); //载入躯干模型，截取某部分字符串以表示躯干模型的编号
			m_pMonsterBuilder->LoadHeadModel(strmodelno.substr(7, 3)); //载入头部模型并挂接到躯干模型上
			m_pMonsterBuilder->LoadLimbsModel(strmodelno.substr(10, 3)); //载入四肢模型并挂接到躯干模型上
			return m_pMonsterBuilder->GetResult(); //返回构建后的对象
		}
	private:
		MonsterBuilder* m_pMonsterBuilder; //指向所有构建器类的父类
	};
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	
	//第三节 建造者（Builder）模式
	//也称：构建器/构建者/生成器模式-创建型模式。
	//通常用于创建比较复杂的对象
	//（1）一个具体实现范例的逐步重构
	//怪物：亡灵类，元素类，机械类
	//怪物组成：头部、躯干（颈部、尾巴）、肢体 三个部位组成。
	//编码步骤：将怪物躯干部模型信息读入内存。将怪物的头部和四肢模型信息读入内存。将头部和四肢模型以正确的位置和方向挂接到躯干部位。  最终装配出完整的怪物模型。
	//Assemble、LoadTrunkModel、LoadHeadModel、LoadLimbsModel称为构建过程相关的函数。
	//引入与怪物类同层次的相关构建器类，把怪物类中代码搬到相关的构建器类中。


	/*
	_nmsp1::Monster* pmonster = new _nmsp1::M_Element(); //创建一只元素类怪物
	pmonster->Assemble("1253679201254");

	//释放资源
	delete pmonster;
	*/
	
	_nmsp1::MonsterBuilder* pMonsterBuilder = new _nmsp1::M_UndeadBuilder(); //创建亡灵类怪物构建器对象
	_nmsp1::MonsterDirector* pDirector = new _nmsp1::MonsterDirector(pMonsterBuilder); 
	_nmsp1::Monster* pMonster = pDirector->Construct("1253679201254"); //这里就构建出了一个完整的怪物对象

	//释放资源
	delete pMonster;
	delete pDirector;
	delete pMonsterBuilder;

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

