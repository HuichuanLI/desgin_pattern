

/*
#ifndef __MONSTERSTATUS__
#define __MONSTERSTATUS__
class Monster; //类前向声明	
//怪物状态类的父类
class MonsterStatus
{
public:
	virtual void Attacked(int power, Monster* mainobj) = 0;
	virtual ~MonsterStatus() {}
};

//凶悍状态类
class MonsterStatus_Feroc :public MonsterStatus
{
public:
	//传递进来的参数是否有必要使用，开发者自行斟酌
	virtual void Attacked(int power, Monster* mainobj)
	{
		std::cout << "怪物处于凶悍状态中，对主角进行疯狂的反击！" << std::endl;
		//处理其他动作逻辑比如反击
	}
};

//不安状态类
class MonsterStatus_Worr :public MonsterStatus
{
public:
	virtual void Attacked(int power, Monster* mainobj)
	{
		std::cout << "怪物处于不安状态中，对主角进行反击并呼唤支援！" << std::endl;
		//处理其他动作逻辑比如反击和不停的呼唤支援
	}
};

//恐惧状态类
class MonsterStatus_Fear :public MonsterStatus
{
public:
	virtual void Attacked(int power, Monster* mainobj)
	{
		std::cout << "怪物处于恐惧状态中，处于逃跑之中！" << std::endl;
		//处理其他动作逻辑比如逃跑
	}
};

//死亡状态类
class MonsterStatus_Dead :public MonsterStatus
{
public:
	virtual void Attacked(int power, Monster* mainobj)
	{
		std::cout << "怪物死亡！" << std::endl;
		//处理怪物死亡后事宜比如怪物尸体定时消失等
	}
};
#endif

*/

#ifndef __MONSTERSTATUS__
#define __MONSTERSTATUS__

class Monster; //类前向声明
//怪物状态类的父类
class MonsterStatus {
public:
    virtual void Attacked(int power, Monster *mainobj) = 0;

    virtual ~MonsterStatus() {}
};

//凶悍状态类
class MonsterStatus_Feroc : public MonsterStatus {
public:
    virtual void Attacked(int power, Monster *mainobj);


public:
    static MonsterStatus_Feroc *getInstance() {
        static MonsterStatus_Feroc instance;
        return &instance;
    }

};

//不安状态类
class MonsterStatus_Worr : public MonsterStatus {
public:
    virtual void Attacked(int power, Monster *mainobj);

public:
    static MonsterStatus_Worr *getInstance() {
        static MonsterStatus_Worr instance;
        return &instance;
    }

};

//恐惧状态类
class MonsterStatus_Fear : public MonsterStatus {
public:
    virtual void Attacked(int power, Monster *mainobj);

public:
    static MonsterStatus_Fear *getInstance() {
        static MonsterStatus_Fear instance;
        return &instance;
    }

};

//死亡状态类
class MonsterStatus_Dead : public MonsterStatus {
public:
    virtual void Attacked(int power, Monster *mainobj);

public:
    static MonsterStatus_Dead *getInstance() {
        static MonsterStatus_Dead instance;
        return &instance;
    }

};

#endif
