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
		void JN_Burn() //技能“燃烧”,模板方法
		{
			if (canUseJN() == false) //如果不能使用该技能，则直接返回
				return; 
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
		virtual bool canUseJN() = 0; //判断是否能使用技能“燃烧”，这是个纯虚函数声明，子类中必须重新实现canUseJN。
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
		virtual bool canUseJN()
		{
			if (m_life < 300) //生命值不够300点，不能使用技能“燃烧”
				return false;
			return true;
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
		virtual bool canUseJN()
		{
			if (m_magic < 100) //魔法值不够100点，不能使用技能“燃烧”
				return false;
			return true;
		}
	};

}


int main()
{ 	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口

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

	//（2）引入模板方法（Template Method）模式
	//软件开发中需求变化频繁的，开发人员要尝试寻找变化点，把变化部分和稳定部分分离开来，在变化的地方应用设计模式。
	//学习设计模式并不难，难的是在何时何地运用该模式。
	//设计模式中往往会把 成员函数 说成是 算法。
	//晚绑定：代码执行时才知道具体要执行哪个虚函数。
	//早绑定：编译时就能确定执行的是哪个子类（F_Warrior或者F_Mage中的effect_enemy或者effect_self）。
	//模板方法模式的定义(实现意图)：定义了一个操作中的算法的骨架（稳定部分），而将一些步骤延迟到子类中去实现（父类中定义虚函数，子类中实现/重写这个虚函数），
	      //从而达到在整体稳定的情况下能够产生一些变化的目的。
	//设计模式的经典总结：设计模式的作用就是在变化和稳定中间寻找隔离点，分离稳定和变化,从而来管理变化。
	//模板方法模式也被认为导致了一种反向控制结构——这种结构被称为好莱坞法则——不要来调用我，我会去调用你。

	//（3）模板方法（Template Method）模式的UML图
	//UML：Unified Modeling Language：统一建模语言。
	//UML：一种工具，通过该工具可以绘制一个类的结构图和类与类之间的关系。这种把所编写的代码以图形方式呈现对于代码的全局理解和掌握好处巨大。

	//（4）程序代码的进一步完善及应用联想
	//钩子方法：子类勾住父类从而反向控制父类行为的意思，因此起名为钩子方法。
	//MFC框架（微软基础类库）：通过MFC创建一个基于对话框的应用程序。自动调用OnInitDialog成员函数（相当于effect_enemy或者effect_self这样的虚函数）。

	//车间能够装配很多零件。如果零件的装配工序非常固定，工序细节有微小变化，就可以
	   //针对零件创建一个父类，其中零件装配工序（成员函数）就非常适合采用模板方法模式来实现，而处理某道工序的细节可以直接放在子类（针对某个具体零件的类）虚函数中进行。











	/*
	_nmsp1::Warrior mroleobj(1000, 0, 200); //创建主角
	mroleobj.JN_Burn(); //主角释放“燃烧”技能
	*/

	/*
	_nmsp2::Fighter* prole_war = new _nmsp2::F_Warrior(1000, 0, 200); //创建战士主角，注意这里是父类指针指向子类对象以利用多态特性。
	prole_war->JN_Burn(); //战士主角释放“燃烧”技能，调用的是F_Warrior类的effect_enemy和effect_self。
	
	cout << "---------------------------" << endl; //分割线，以便更醒目的显示信息
	_nmsp2::Fighter* prole_mag = new _nmsp2::F_Mage(800,200, 300); //创建法师主角，注意这里是父类指针指向子类对象以利用多态特性。
	prole_mag->JN_Burn(); //法师主角释放“燃烧”技能

	//释放资源
	delete prole_war;
	delete prole_mag;
	*/
	
	////早绑定
	//_nmsp2::F_Warrior role_war(1000, 0, 200);
	//role_war.JN_Burn(); //早绑定


	_nmsp2::Fighter* prole_war2 = new _nmsp2::F_Warrior(50, 0, 200);//创建生命值只有50的战士主角
	prole_war2->JN_Burn(); //该战士无法成功释放“燃烧”技能，不输出任何结果。
	                       //钩子方法

	delete prole_war2;


	return 0;
}

