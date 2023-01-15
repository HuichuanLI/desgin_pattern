
#ifndef __MONSTER__
#define __MONSTER__

class MonsterStatus; //类前向声明
//怪物类
class Monster {
public:
    Monster(int life);

    ~Monster();

public:
    void Attacked(int power);  //怪物被攻击

public:
    int GetLife() //获取怪物血量
    {
        return m_life;
    }

    void SetLife(int life) //设置怪物血量
    {
        m_life = life;
    }

    MonsterStatus *getCurrentState() //获取怪物当前状态
    {
        return m_pState;
    }

    void setCurrentState(MonsterStatus *pstate) //设置怪物当前状态
    {
        m_pState = pstate;
    }

private:
    int m_life;    //血量（生命值）
    MonsterStatus *m_pState;  //持有状态对象
};

#endif
