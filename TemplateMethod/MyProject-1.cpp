// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
	//定义一个“战士”类
	class Warrior
	{
	public:
		//构造函数
		Warrior(int life, int magic, int attack) :m_life(life), m_magic(magic), m_attack(attack)
		{
		}
		//...一些其他成员函数,不重要，不深究

	public:
		void JN_Burn() //技能“燃烧”
		{
			cout << "让所有敌人每人失去500点生命，相关逻辑代码这里略......" << endl;
			cout << "主角自身失去300点生命值" << endl;
			m_life -= 300;
			cout << "播放技能\"燃烧\"的技能特效给玩家看" << endl;
		}
	private:
		//角色属性
		int m_life; //生命值
		int m_magic; //魔法值
		int m_attack;  //攻击力
	};

}
namespace _nmsp2
{
	//战斗者父类
	class Fighter
	{
	public:
		Fighter(int life, int magic, int attack) :m_life(life), m_magic(magic), m_attack(attack) {}
		virtual ~Fighter() {} //做父类时析构函数应该为虚函数

		//对主角自身会产生影响，对敌人会产生影响。
		//分析：对敌人产生影响，有函数effect_enemy。对主角自身产生影响，有函数effect_self。播放技能play_effect函数。
		void JN_Burn() //技能“燃烧” 模板方法，动态制定虚函数
		{
			effect_enemy(); //对敌人产生的影响
			effect_self(); //对主角自身产生的影响
			play_effect(); //播放技能“燃烧”的技能特效
		}
	private:
		virtual void effect_enemy() {} //函数体为空，表示啥也不做，如果要求必须在子类中重新实现该虚函数，则可以将该函数写成纯虚函数。
		virtual void effect_self() {}
		void play_effect()
		{
			cout << "播放技能\"燃烧\"的技能特效给玩家看" << endl; //所有主角播放的技能特效都相同，因此不用写成一个虚函数并在子类中实现技能特效的播放。
		}
	protected: //可能被子类访问，所以用protected修饰
		//角色属性
		int m_life; //生命值
		int m_magic; //魔法值
		int m_attack;  //攻击力
	};

	//-------------------------
	//“战士”类，父类为Fighter
	class F_Warrior :public Fighter
	{
	public:
		F_Warrior(int life, int magic, int attack) :Fighter(life,magic,attack) {}

	private:
		//对敌人产生的影响
		virtual void effect_enemy() 
		{
			cout << "战士主角_让所有敌人每人失去500点生命，相关逻辑代码这里略......" << endl;
		} 
		//对主角自身产生的影响
		virtual void effect_self()
		{
			cout << "战士主角_自身失去300点生命值" << endl;
			m_life -= 300;			
		}
	};
	//-------------------------
	//“法师”类，父类为Fighter
	class F_Mage :public Fighter
	{
	public:
		F_Mage(int life, int magic, int attack) :Fighter(life, magic, attack) {}

	private:
		//对敌人产生的影响
		virtual void effect_enemy()
		{
			cout << "法师主角_让所有敌人每人失去650点生命，相关逻辑代码这里略......" << endl;
		}
		//对主角自身产生的影响
		virtual void effect_self()
		{
			cout << "法师主角_自身失去100点魔法值" << endl;
			m_magic -= 100;
		}
	};

}


int main()
{ 	

	//第二章 模板方法（Template Method）模式
	//饭馆吃饭： 点餐（粤菜，鲁菜）->食用->结账（现金，信用卡，微信），因为这几个步骤是固定的所以作为以样板。
	//在固定步骤确定的情况下，通过多态机制在多个子类中对每个步骤的细节进行差异化实现，这就是模板方法模式能够达到的效果。
	//模板方法模式：行为型模式。

	//（1）一个具体实现范例的逐步重构
	//A公司有一个小游戏项目组——开发单机闯关打斗类游戏（类似街机打拳类游戏）。
	//一个游戏项目组最少需要三名担任不同角色的员工组成：游戏策划，游戏程序，游戏美术。
	  //a)游戏策划：简称策划 ，负责提出游戏的各种玩法需求，确定游戏中各种数值比如人物（敌人）的生命值、魔法值。
	  //b)游戏程序：简称程序，需要与游戏策划紧密配合通过代码来实现游戏策划要求的各种游戏功能。
	  //c)游戏美术：角色设计，道具设计，游戏特效等等。
	
	//游戏策划需求：游戏主角是个战士（攻击力不够强，生命值比较多，抗揍），主角通过不断的往前走来闯关，遇到敌人就进行攻击，
	     //敌人也会反击，敌人也会距离近时主动攻击主角。
	     //主角：生命值——1000（为0时主角死亡，游戏结束），魔法值——0（暂时用不上，保留），攻击力——200（打敌人一下敌人失去多少点声明值） 三个属性。
	     //技能“燃烧”——使用该技能可以使附近所有敌人每人失去500点生命值，但是主角自身也会损失掉300点生命值。

	//增加 法师 作为主角（攻击力很强，生命值比较少，不抗揍）
		//主角：生命值——800，魔法值——200（暂时用不上，保留），攻击力——300  三个属性。 
		//技能“燃烧”——使用该技能可以使附近所有敌人每人失去650点生命值，但是主角自身会损失掉100点魔法值。

	//将要增加 牧师 作为主角
	//每个主角都有一个叫做 燃烧 的技能。每个主角释放 燃烧技能时效果各不相同。有两点是肯定不变的：对主角自身会产生影响，对敌人会产生影响。

	//战士和法师释放 燃烧 技能表现是不同的，这种不同的表现主要是通过F_Warrior和F_Mage子类中的effect_enemy和effect_self虚函数来体现的。


//
//
//	_nmsp1::Warrior mroleobj(1000, 0, 200); //创建主角
//	mroleobj.JN_Burn(); //主角释放“燃烧”技能

	_nmsp2::Fighter* prole_war = new _nmsp2::F_Warrior(1000, 0, 200); //创建战士主角，注意这里是父类指针指向子类对象以利用多态特性。
	prole_war->JN_Burn(); //战士主角释放“燃烧”技能
	
	cout << "---------------------------" << endl; //分割线，以便更醒目的显示信息
	_nmsp2::Fighter* prole_mag = new _nmsp2::F_Mage(800,200, 300); //创建法师主角，注意这里是父类指针指向子类对象以利用多态特性。
	prole_mag->JN_Burn(); //法师主角释放“燃烧”技能

	//释放资源
	delete prole_war;
	delete prole_mag;
	



	return 0;
}

