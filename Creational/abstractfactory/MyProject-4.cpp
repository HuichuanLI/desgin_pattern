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

namespace _nmsp1
{
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
			Monster *ptmp = new M_Undead(300, 50, 80); //创建亡灵类怪物
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
	//class M_BeastFactory:public M_ParFactory{......};
	//全局的用于创建怪物对象的函数,注意形参的类型是工厂父类类型的指针，返回类型是怪物父类类型的指针
	Monster* Gbl_CreateMonster(M_ParFactory* factory)
	{
		return  factory->createMonster(); //createMonster虚函数扮演了多态new的行为，factory指向的具体怪物工厂类不同，创建的怪物对象也不同。
	}

	//-------------------
	//不想创建太多工厂类，又想封装变化
	//创建怪物工厂子类模板
	template <typename T>
	class M_ChildFactory :public M_ParFactory
	{
	public:
		virtual Monster* createMonster()
		{
			return new T(300, 50, 80); //如果需要不同的值则可以通过createMonster的形参将值传递进来
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
		virtual ~Monster() {} //做父类时析构函数应该为虚函数

	protected://可能被子类访问的成员，所以用protected修饰
		//怪物属性
		int m_life; //生命值
		int m_magic; //魔法值
		int m_attack; //攻击力
	};

	//沼泽亡灵类怪物
	class M_Undead_Swamp :public Monster
	{
	public:
		M_Undead_Swamp(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一个沼泽的亡灵类怪物来到了这个世界" << endl;
		}
	};
	//沼泽元素类怪物
	class M_Element_Swamp :public Monster
	{
	public:
		M_Element_Swamp(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一个沼泽的元素类怪物来到了这个世界" << endl;
		}
	};
	//沼泽机械类怪物
	class M_Mechanic_Swamp :public Monster
	{
	public:
		M_Mechanic_Swamp(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一个沼泽的机械类怪物来到了这个世界" << endl;
		}
	};
	//--------------------------
	//山脉亡灵类怪物
	class M_Undead_Mountain :public Monster
	{
	public:
		M_Undead_Mountain(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一个山脉的亡灵类怪物来到了这个世界" << endl;
		}
	};
	//山脉元素类怪物
	class M_Element_Mountain :public Monster
	{
	public:
		M_Element_Mountain(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一个山脉的元素类怪物来到了这个世界" << endl;
		}
	};
	//山脉机械类怪物
	class M_Mechanic_Mountain :public Monster
	{
	public:
		M_Mechanic_Mountain(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一个山脉的机械类怪物来到了这个世界" << endl;
		}
	};
	//--------------------------
	//城镇亡灵类怪物
	class M_Undead_Town :public Monster
	{
	public:
		M_Undead_Town(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一个城镇的亡灵类怪物来到了这个世界" << endl;
		}
	};
	//城镇元素类怪物
	class M_Element_Town :public Monster
	{
	public:
		M_Element_Town(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一个城镇的元素类怪物来到了这个世界" << endl;
		}
	};
	//城镇机械类怪物
	class M_Mechanic_Town :public Monster
	{
	public:
		M_Mechanic_Town(int life, int magic, int attack) :Monster(life, magic, attack)
		{
			cout << "一个城镇的机械类怪物来到了这个世界" << endl;
		}
	};

	//--------------------------
	//所有工厂类的父类
	class M_ParFactory
	{
	public:
		virtual Monster* createMonster_Undead() = 0; //创建亡灵类怪物
		virtual Monster* createMonster_Element() = 0; //创建元素类怪物
		virtual Monster* createMonster_Mechanic() = 0; //创建机械类怪物
		virtual ~M_ParFactory() {} //做父类时析构函数应该为虚函数
	};

	//沼泽地区的工厂
	class M_Factory_Swamp :public M_ParFactory
	{
	public:
		virtual Monster* createMonster_Undead()
		{
			return new M_Undead_Swamp(300, 50, 120); //创建沼泽亡灵类怪物
		}
		virtual Monster* createMonster_Element()
		{
			return new M_Element_Swamp(200, 80, 110); //创建沼泽元素类怪物
		}
		virtual Monster* createMonster_Mechanic()
		{
			return new M_Mechanic_Swamp(400, 0, 90); //创建沼泽机械类怪物
		}		
	};
	//--------------------------
	//山脉地区的工厂
	class M_Factory_Mountain :public M_ParFactory
	{
	public:
		virtual Monster* createMonster_Undead()
		{
			return new M_Undead_Mountain(300, 50, 80); //创建山脉亡灵类怪物
		}
		virtual Monster* createMonster_Element()
		{
			return new M_Element_Mountain(200, 80, 100); //创建山脉元素类怪物
		}
		virtual Monster* createMonster_Mechanic()
		{
			return new M_Mechanic_Mountain(600, 0, 110); //创建山脉机械类怪物
		}
	};
	//--------------------------
	//城镇的工厂
	class M_Factory_Town :public M_ParFactory
	{
	public:
		virtual Monster* createMonster_Undead()
		{
			return new M_Undead_Town(300, 50, 80); //创建城镇亡灵类怪物
		}
		virtual Monster* createMonster_Element()
		{
			return new M_Element_Town(200, 80, 100); //创建城镇元素类怪物
		}
		virtual Monster* createMonster_Mechanic()
		{
			return new M_Mechanic_Town(400, 0, 110); //创建城镇机械类怪物
		}
	};
}

namespace _nmsp3
{
	//身体抽象类
	class Body
	{
	public:
		virtual void getName() = 0;
		virtual ~Body() {}
	};

	//衣服抽象类
	class Clothes
	{
	public:
		virtual void getName() = 0;
		virtual ~Clothes() {}
	};

	//鞋子抽象类
	class Shoes
	{
	public:
		virtual void getName() = 0;
		virtual ~Shoes() {}
	};

	//---------------------------
	//抽象工厂类

    class AbstractFactory{
     public:
      virtual Body* createBody() = 0;
      virtual Clothes* createClothes() = 0;
      virtual Shoes* createShoes() = 0;
      virtual  ~AbstractFactory(){};
    };


	//---------------------------
	//芭比娃娃类
	class BarbieDoll
	{
	public:
		//构造函数
		BarbieDoll(Body* tmpbody, Clothes* tmpclothes, Shoes* tmpshoes)
		{
			body = tmpbody;
			clothes = tmpclothes;
			shoes = tmpshoes;
		}

		void Assemble() //组装芭比娃娃
		{
			cout << "成功组装了一个芭比娃娃：" << endl;
			body->getName();
			clothes->getName();
			shoes->getName();
		}

	private:
		Body* body;
		Clothes* clothes;
		Shoes* shoes;
	};
	//---------------------------
	//中国厂商实现的三个部件
	class China_Body :public Body
	{
	public:
		virtual void getName()
		{
			cout << "中国厂商产的_身体部件" << endl;
		}
	};
	class China_Clothes :public Clothes
	{
	public:
		virtual void getName()
		{
			cout << "中国厂商产的_衣服部件" << endl;
		}
	};
	class China_Shoes :public Shoes
	{
	public:
		virtual void getName()
		{
			cout << "中国厂商产的_鞋子部件" << endl;
		}
	};
	//创建一个中国工厂
	class ChinaFactory : public AbstractFactory
	{
	public:
		virtual Body* createBody()
		{
			return new China_Body;
		}
		virtual Clothes* createClothes()
		{
			return new China_Clothes;
		}
		virtual Shoes* createShoes()
		{
			return new China_Shoes;
		}		
	};
	//---------------------------
	//日本厂商实现的三个部件
	class Japan_Body :public Body
	{
	public:
		virtual void getName()
		{
			cout << "日本厂商产的_身体部件" << endl;
		}
	};
	class Japan_Clothes :public Clothes
	{
	public:
		virtual void getName()
		{
			cout << "日本厂商产的_衣服部件" << endl;
		}
	};
	class Japan_Shoes :public Shoes
	{
	public:
		virtual void getName()
		{
			cout << "日本厂商产的_鞋子部件" << endl;
		}
	};
	//创建一个日本工厂
	class JapanFactory : public AbstractFactory
	{
	public:
		virtual Body* createBody()
		{
			return new Japan_Body;
		}
		virtual Clothes* createClothes()
		{
			return new Japan_Clothes;
		}
		virtual Shoes* createShoes()
		{
			return new Japan_Shoes;
		}
	};
	//---------------------------
	//美国厂商实现的三个部件
	class America_Body :public Body
	{
	public:
		virtual void getName()
		{
			cout << "美国厂商产的_身体部件" << endl;
		}
	};
	class America_Clothes :public Clothes
	{
	public:
		virtual void getName()
		{
			cout << "美国厂商产的_衣服部件" << endl;
		}
	};
	class America_Shoes :public Shoes
	{
	public:
		virtual void getName()
		{
			cout << "美国厂商产的_鞋子部件" << endl;
		}
	};
	//创建一个美国工厂
	class AmericaFactory : public AbstractFactory
	{
	public:
		virtual Body* createBody()
		{
			return new America_Body;
		}
		virtual Clothes* createClothes()
		{
			return new America_Clothes;
		}
		virtual Shoes* createShoes()
		{
			return new America_Shoes;
		}
	};
}


int main()
{

	//第三章 工厂模式、原型（Prototype）模式、建造者（Builder）模式
	//第一节  工厂模式:创建型模式
	//new，堆对象，可以实现多态。
	//工厂模式：通过把创建对象的代码包装起来，做到创建对象的代码与具体的业务逻辑代码相隔离的目的。
	//A *pobja = new A();
	//工厂模式细分：a)简单工厂模式；b)工厂方法模式；c)抽象工厂模式。
	//面向对象程序设计一个重要原则：开闭原则。

	//（1）简单工厂（Simple Factory）模式
	//策划：亡灵类怪物，元素类怪物，机械类怪物：都有生命值，魔法值，攻击力三个属性。
	//Monster作为父类，M_Undead（亡灵类），M_Element（元素类怪物），M_Mechanic（机械类怪物）。
	//使用new +具体类名来创建对象是一种 依赖具体类型的紧耦合关系。
	//简单工厂模式的实现思路：使用工厂类可以实现创建怪物的代码  与  各个 具体怪物类对象要实现的逻辑代码隔离。
	//封装变化：把依赖范围尽可能缩小，把容易变化的代码段限制在一个小范围内，就可以在很大程度上提高代码的可维护性和可扩展性。
	//通过增加新的if else分支来达到支持新怪物增加的目的——违背了面向对象程序设计的原则：开闭原则（Open Close Principle :OCP）；
	//开闭原则：说的是代码扩展性问题——对扩展开放，对修改关闭（封闭）；
	//开闭原则详细的解释：当增加新功能，不应该通过修改已经存在的代码来进行，而是应该通过扩展代码(比如增加新类，增加新成员函数）来进行。
	//如果if,else分支不多（没有数十上百个），则适当违反开闭原则，是完全可以接受的。
	//大家要在代码的可读性和可扩展ing之间做出权衡。
	//引入“简单工厂”设计模式的定义（实现意图）：定义一个工厂类(MonsterFactory)，该类的成员函数(createMonster)可以根据不同参数
	  //创建并返回不同的类对象，被创建的对象所属的类（M_Undead，M_Element，M_Mechanic）一般都具有相同的父类（Monster），
	  //调用者（这里指main函数）无需关心创建对象的细节。
	//简单工厂方法模式：实现了创建怪物类代码（createMonster），与具体怪物类（M_Undead，M_Element，M_Mechanic）解耦合的效果。
	
	//（2）工厂方法（Factory Method）模式:简称工厂模式或者多态工厂模式。
	//与简单工厂模式比，灵活性更强，实现也更加复杂，引入更多的新类。
	//M_UndeadFactory，M_ElementFactory，M_MechanicFactory类，有一个共同的父类M_ParFactory（工厂抽象类）:
	  //符合开闭原则，付出的代价是需要新增加多个新的工厂类。
	//定义（实现意图）：定义一个用于创建对象的接口（M_ParFactory类中的createMonster成员函数，这其实就是个工厂方法，工厂方法模式的名字也是由此而来）,
	  //但由子类（M_UndeadFactory、M_ElementFactory、M_MechanicFactory）决定要实例化的类是哪一个。
	  //该模式使得某个类（M_Undead、M_Element、M_Mechanic）的实例化延迟到子类（M_UndeadFactory、M_ElementFactory、M_MechanicFactory）。
	//出现新怪物类型：M_Beast（野兽类）。
	//一般可以认为，将简单工厂模式的代码经过把工厂类进行抽象改造成符合开闭原则后的代码，就变成了工厂方法模式的代码。
	
	//把用new创建对象集中到某个或者某些工厂类的成员函数中去做，的好处：
	//a)封装变化。 prtnobj = new M_Element(200,80,100); ->new M_Element(200,80,100,300);
	//b)创建对象前需要一些额外的业务代码，可以将这些代码增加到具体的工厂类的createMonster成员函数中。

	//简单工厂模式把创建对象这件事放到了一个统一的地方来处理，弹性比较差。而工厂方法模式相当于建立了一个程序实现框架，从而让子类来决定对象如何创建。
	//工厂方法模式往往需要创建一个与产品等级结构（层次）相同的工厂等级结构，这也增加了新类的层次结构和数目。

	//（3）抽象工厂（Abstract Factory）模式
	//（3.1）战斗场景分类范例
	//怪物分类：亡灵类，元素类，机械类
	//战斗场景分类：沼泽地区，山脉地区，城镇。
	//9类怪物====>沼泽地亡灵类、元素类、机械类，山脉地区亡灵类、元素类、机械类，城镇中的亡灵类、元素类、机械类
	//工厂方法模式：一个工厂创建一种类怪物。
	//但如果一个工厂子类能够创建不止一种而是多种具有相同规则的怪物对象，那么就可以有效的减少所创建的工厂子类数量，这就是抽象工厂模式的核心思想。

	//两个概念：a)产品等级结构   b)产品族
	//抽象工厂模式是按照产品族来生产产品（产地相同的用一个工厂来生产）——一个地点有一个工厂，该工厂负责生产本产地的所有产品。

	//抽象工厂模式优缺点：
	//a)增加森林类新场景，怪物种类不变。则只需要增加一个新子工厂比如M_Factory_Forest，符合开闭原则。
	//b)增加新怪物种类比如龙类，不但要增加三个继承自Monster的子类，还要针对M_ParFactory增加新的虚函数接口比如createMonster_Dragon，
	   //同时各个子工厂类都需要实现createMonster_Dragon，这种修改代码的方式来增加新怪物种类，不符合开闭原则，所以增加新怪物的情形不适合抽象工厂模式。
	//c)只增加一个产品族则符合开闭原则，只需要增加新工厂子类，这是该模式的优点。
	      //但若增加新产品等级结构，需要修改抽象层代码，这是抽象工厂模式的缺点，所以，应避免在产品等级结构不稳定的情况下使用该模式。
	      //也就是说，如果游戏中怪物种类（亡灵类，元素类，机械类）比较固定的情况下，更适合使用抽象工厂模式。

	//（3.2） 不同厂商生产不同部件范例
	//芭比娃娃：身体（包括头、颈部、躯干、四肢）、衣服、鞋子
	//中国，日本，美国 厂商
	//要求：制作两个芭比娃娃，第一个：身体，衣服，鞋子，全部采用中国厂商制造的部件。
	                        //第二个：身体采用中国厂商，衣服部件采用日本厂商，鞋子部件采用美国厂商。
	//类的设计思路：
	//a)将身体，衣服，鞋子 这三个部件实现为抽象类。
	//b)实现一个抽象工厂，分别用来生产身体、衣服、鞋子这三个部件。
	//c)针对不同厂商的每个部件实现具体的类以及每个厂商所代表的具体工厂。

	//工厂方法模式和抽象工厂模式区别：
	//a)工厂方法模式:一个工厂生产一个产品
	//b)抽象工厂模式:一个工厂生产多个产品（产品族）

	//抽象工厂模式的定义（实现意图）：提供一个接口（AbstractFactory），
	       //让该接口负责创建一系列相关或者相互依赖的对象(Body,Clothes,Shoes)，而无需指定他们具体的类。

	//三种工厂模式的总结：
	//a)从代码实现复杂度：简单工厂< 工厂模式< 抽象工厂
	//b)从需要的工厂数量上：简单工厂<抽象工厂 <工厂模式
	//c)从实际应用上：简单工厂 （小项目）
    //                抽象工厂 （大项目）
    // 工厂模式 (总项目)



	/*
	_nmsp1::Monster* pM1 = new _nmsp1::M_Undead(300, 50, 80); //产生一只亡灵类怪物
	_nmsp1::Monster* pM2 = new _nmsp1::M_Element(200, 80, 100); //产生一只元素类怪物
	_nmsp1::Monster* pM3 = new _nmsp1::M_Mechanic(400, 0, 110); //产生一只机械类怪物

	//pM2->attack

	//释放资源
	delete pM1;
	delete pM2;
	delete pM3;
	*/

	/*_nmsp1::MonsterFactory facobj;
	_nmsp1::Monster* pM1 = facobj.createMonster("udd"); //产生了一只亡灵类怪物，当然这里必须知道“udd”代表的是创建亡灵类怪物
	_nmsp1::Monster* pM2 = facobj.createMonster("elm"); //创建一只元素类怪物
	_nmsp1::Monster* pM3 = facobj.createMonster("mec"); //创建一只机械类怪物

	//释放资源
	delete pM1;
	delete pM2;
	delete pM3;
	*/

	/*
	//此时简单工厂模式又可以称为静态工厂方法模式（Static Factory Method）
	_nmsp1::Monster* pM1 = _nmsp1::MonsterFactory::createMonster("udd"); //产生了一只亡灵类怪物，当然这里必须知道“udd”代表的是创建亡灵类怪物
	_nmsp1::Monster* pM2 = _nmsp1::MonsterFactory::createMonster("elm"); //创建一只元素类怪物
	_nmsp1::Monster* pM3 = _nmsp1::MonsterFactory::createMonster("mec"); //创建一只机械类怪物

	//释放资源
	delete pM1;
	delete pM2;
	delete pM3;
	*/

	/*
	_nmsp1::M_ParFactory* p_ud_fy = new _nmsp1::M_UndeadFactory(); //多态工厂，注意指针类型
	_nmsp1::Monster* pM1 = _nmsp1::Gbl_CreateMonster(p_ud_fy); //产生了一只亡灵类怪物，也是多态，注意返回类型
	                                                         //当然，这里也可以直接写成 Monster *pM1 = p_ud_fy->createMonster();

	_nmsp1::M_ParFactory* p_elm_fy = new _nmsp1::M_ElementFactory();
	_nmsp1::Monster *pM2 = _nmsp1::Gbl_CreateMonster(p_elm_fy); //产生了一只元素类怪物

	_nmsp1::M_ParFactory* p_mec_fy = new _nmsp1::M_MechanicFactory();
	_nmsp1::Monster* pM3 = _nmsp1::Gbl_CreateMonster(p_mec_fy); //产生了一只机械类怪物

	//释放资源
	//释放工厂
	delete p_ud_fy;
	delete p_elm_fy;
	delete p_mec_fy;

	//释放怪物
	delete pM1;
	delete pM2;
	delete pM3;
	*/
	/*
	_nmsp1::M_ChildFactory<_nmsp1::M_Undead> myFactory;
	_nmsp1::Monster* pM10 = myFactory.createMonster();

	//释放资源
	delete pM10;
	*/

	/*
	_nmsp2::M_ParFactory* p_mou_fy = new _nmsp2::M_Factory_Mountain(); //多态工厂，山脉地区的工厂
	_nmsp2::Monster* pM1 = p_mou_fy->createMonster_Element(); //创建山脉地区的元素类怪物

	_nmsp2::M_ParFactory* p_twn_fy = new _nmsp2::M_Factory_Town(); //多态工厂，城镇的工厂
	_nmsp2::Monster* pM2 = p_twn_fy->createMonster_Undead(); //创建城镇地区的亡灵类怪物
	_nmsp2::Monster* pM3 = p_twn_fy->createMonster_Mechanic(); //创建城镇地区的机械类怪物

	//释放资源
	//释放工厂
	delete p_mou_fy;
	delete p_twn_fy;

	delete pM1;
	delete pM2;
	delete pM3;
	*/

	//创建第一个芭比娃娃------------
	//(1)创建一个中国工厂
	_nmsp3::AbstractFactory* pChinaFactory = new _nmsp3::ChinaFactory();
	//(2)创建中国产的各种部件
	_nmsp3::Body* pChinaBody = pChinaFactory->createBody();
	_nmsp3::Clothes* pChinaClothes = pChinaFactory->createClothes();
	_nmsp3::Shoes* pChinaShoes = pChinaFactory->createShoes();
	//(3)创建芭比娃娃
	_nmsp3::BarbieDoll* pbd1obj = new _nmsp3::BarbieDoll(pChinaBody, pChinaClothes, pChinaShoes);
	pbd1obj->Assemble(); //组装芭比娃娃

	cout << "-------------------------------------" << endl;
	//创建第二个芭比娃娃------------
	//(1)创建另外两个工厂：日本工厂，美国工厂
	_nmsp3::AbstractFactory* pJapanFactory = new _nmsp3::JapanFactory();
	_nmsp3::AbstractFactory* pAmericaFactory = new _nmsp3::AmericaFactory();
	//(2)创建中国产的身体部件，日本产的衣服部件，美国产的鞋子部件
	_nmsp3::Body* pChinaBody2 = pChinaFactory->createBody();
	_nmsp3::Clothes* pJapanClothes = pJapanFactory->createClothes();
	_nmsp3::Shoes* pAmericaShoes = pAmericaFactory->createShoes();
	//(3)创建芭比娃娃
	_nmsp3::BarbieDoll* pbd2obj = new _nmsp3::BarbieDoll(pChinaBody2, pJapanClothes, pAmericaShoes);
	pbd2obj->Assemble(); //组装芭比娃娃

	//最后记得释放内存----------------
	delete pbd1obj;
	delete pChinaShoes;
	delete pChinaClothes;
	delete pChinaBody;
	delete pChinaFactory;
	//------------
	delete pbd2obj;
	delete pAmericaShoes;
	delete pJapanClothes;
	delete pChinaBody2;
	delete pAmericaFactory;
	delete pJapanFactory;

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

