

#include <iostream>
#include "Monster.h"
#include "MonsterStatus.h"

using namespace std;

//构造函数，怪物的初始状态从“凶悍”开始
Monster::Monster(int life) :m_life(life), m_pState(nullptr)
{
	//m_pState = new MonsterStatus_Feroc();
	m_pState = MonsterStatus_Feroc::getInstance();
}

//析构函数
Monster::~Monster()
{
	//delete m_pState;
}

//怪物被攻击

void Monster::Attacked(int power)
{
	/*
	int orglife = m_life; //暂存原来的怪物血量值用于后续比较
	m_life -= power;      //怪物剩余的血量
	if (orglife > 400)    //怪物原来处于凶悍状态
	{
		if (m_life > 400) //状态未变
		{
			//cout << "怪物受到" << power << "点伤害并对主角进行疯狂的反击！" << endl;
			m_pState->Attacked(power, this); //其他的逻辑代码被本Monster类委托给了具体状态类来处理
		}
		else if (m_life > 100) //状态从凶悍改变到不安
		{
			//cout << "怪物受到" << power << "点伤害并对主角进行反击，怪物变得焦躁不安并开始呼唤支援！" << endl;
			delete m_pState; //释放原有的状态对象
			m_pState = new MonsterStatus_Worr(); //怪物转到不安状态
			m_pState->Attacked(power, this);
		}
		else if (m_life > 0)//状态从凶悍状态改变到恐惧状态，主角的攻击太恐怖了
		{
			//cout << "怪物受到" << power << "点伤害，怪物变得恐惧并开始逃跑！" << endl;
			delete m_pState; //释放原有的状态对象
			m_pState = new MonsterStatus_Fear(); //怪物转到恐惧状态
			m_pState->Attacked(power, this);
		}
		else//状态从凶悍改变到死亡
		{
			//cout << "怪物受到" << power << "点伤害，已经死亡！" << endl;
			delete m_pState; //释放原有的状态对象
			m_pState = new MonsterStatus_Dead(); //怪物转到死亡状态
			m_pState->Attacked(power, this);
		}
	}
	else if (orglife > 100) //怪物原来处于不安状态
	{
		if (m_life > 100) //状态未变
		{
			//cout << "怪物受到" << power << "点伤害并对主角进行反击，并继续急促的呼唤支援！" << endl;
			m_pState->Attacked(power, this);
		}
		else if (m_life > 0)//状态从不安改变到恐惧
		{
			//cout << "怪物受到" << power << "点伤害，怪物变得恐惧并开始逃跑！" << endl;
			delete m_pState; //释放原有的状态对象
			m_pState = new MonsterStatus_Fear(); //怪物转到恐惧状态
			m_pState->Attacked(power, this);
		}
		else//状态从不安改变到死亡
		{
			//cout << "怪物受到" << power << "点伤害，已经死亡！" << endl;
			delete m_pState; //释放原有的状态对象
			m_pState = new MonsterStatus_Dead(); //怪物转到死亡状态
			m_pState->Attacked(power, this);
		}
	}
	else if (orglife > 0) //怪物原来处于恐惧状态
	{
		if (m_life > 0)//状态未变
		{
			//cout << "怪物受到" << power << "点伤害，怪物继续逃跑！" << endl;
			m_pState->Attacked(power, this);
		}
		else//状态从恐惧改变到死亡
		{
			//cout << "怪物受到" << power << "点伤害，已经死亡！" << endl;
			delete m_pState; //释放原有的状态对象
			m_pState = new MonsterStatus_Dead(); //怪物转到死亡状态
			m_pState->Attacked(power, this);
		}
	}
	else //怪物已经死亡
	{
		//已经死亡的怪物，状态不会继续发生改变
		//cout << "怪物已死亡，不能再被攻击！" << endl;
		m_pState->Attacked(power, this);
	}*/

	m_pState->Attacked(power, this);
}


