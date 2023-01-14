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
    //怪物父类
    class Monster {
    public:
        //构造函数
        Monster(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack) {}

        virtual ~Monster() {} //做父类时析构函数应该为虚函数

    protected: //可能被子类访问的成员，用protected修饰
        //怪物属性
        int m_life;    //生命值
        int m_magic;   //魔法值
        int m_attack;  //攻击力
    };

    //亡灵类怪物
    class M_Undead : public Monster {
    public:
        //构造函数
        M_Undead(int life, int magic, int attack) : Monster(life, magic, attack) {
            cout << "一只亡灵类怪物来到了这个世界" << endl;
        }
        //其他代码略....
    };

    //元素类怪物
    class M_Element : public Monster {
    public:
        //构造函数
        M_Element(int life, int magic, int attack) : Monster(life, magic, attack) {
            cout << "一只元素类怪物来到了这个世界" << endl;
        }
        //其他代码略....
    };

    //机械类怪物
    class M_Mechanic : public Monster {
    public:
        //构造函数
        M_Mechanic(int life, int magic, int attack) : Monster(life, magic, attack) {
            cout << "一只机械类怪物来到了这个世界" << endl;
        }
        //其他代码略....
    };

    //--------------------------------
    //简单工厂模式
    //怪物工厂类
    class MonsterFactory {
    public:
        Monster *createMonster(string strmontype) {
            Monster *prtnobj = nullptr;
            if (strmontype == "udd")  //udd代表要创建亡灵类怪物
            {
                prtnobj = new M_Undead(300, 50, 80);
            } else if (strmontype == "elm") //ele代表要创建元素类怪物
            {
                prtnobj = new M_Element(200, 80, 100);
            } else if (strmontype == "mec") //mec代表要创建机械类怪物
            {
                prtnobj = new M_Mechanic(400, 0, 110);
            }
            return prtnobj;
        }
    };

    //--------------------------------
    //工厂方法模式
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
            return new M_Undead(300, 50, 80); //创建亡灵类怪物
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

    //全局的用于创建怪物对象的函数，注意形参的类型是工厂父类类型的指针，返回类型是怪物父类类型的指针
    Monster *Gbl_CreateMonster(M_ParFactory *factory) {
        return factory->createMonster();//createMonster虚函数扮演了多态new的行为，factory指向的具体怪物工厂类不同，创建的怪物对象也不同
    }

    //--------------------------------
    //创建怪物工厂子类模板
    template<typename T>
    class M_ChildFactory : public M_ParFactory {
    public:
        virtual Monster *createMonster() {
            return new T(300, 50, 80);//如果需要不同的值则可以考虑通过createMonster的形参将值传递进来
        }
    };
}
namespace _nmsp2 {
    //--------------------------------
    //抽象工厂模式

    //怪物父类
    class Monster {
    public:
        //构造函数
        Monster(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack) {}

        virtual ~Monster() {} //做父类时析构函数应该为虚函数

    protected: //可能被子类访问的成员，用protected修饰
        //怪物属性
        int m_life;    //生命值
        int m_magic;   //魔法值
        int m_attack;  //攻击力
    };

    //-----------------------------------------------
    //沼泽亡灵类怪物
    class M_Undead_Swamp : public Monster {
    public:
        M_Undead_Swamp(int life, int magic, int attack) : Monster(life, magic, attack) {
            cout << "一个沼泽的亡灵类怪物来到了这个世界" << endl;
        }
    };

    //沼泽元素类怪物
    class M_Element_Swamp : public Monster {
    public:
        M_Element_Swamp(int life, int magic, int attack) : Monster(life, magic, attack) {
            cout << "一个沼泽的元素类怪物来到了这个世界" << endl;
        }
    };

    //沼泽机械类怪物
    class M_Mechanic_Swamp : public Monster {
    public:
        M_Mechanic_Swamp(int life, int magic, int attack) : Monster(life, magic, attack) {
            cout << "一个沼泽的机械类怪物来到了这个世界" << endl;
        }
    };

    //-----------------------------------------------
    //山脉亡灵类怪物
    class M_Undead_Mountain : public Monster {
    public:
        M_Undead_Mountain(int life, int magic, int attack) : Monster(life, magic, attack) {
            cout << "一个山脉的亡灵类怪物来到了这个世界" << endl;
        }
    };

    //山脉元素类怪物
    class M_Element_Mountain : public Monster {
    public:
        M_Element_Mountain(int life, int magic, int attack) : Monster(life, magic, attack) {
            cout << "一个山脉的元素类怪物来到了这个世界" << endl;
        }
    };

    //山脉机械类怪物
    class M_Mechanic_Mountain : public Monster {
    public:
        M_Mechanic_Mountain(int life, int magic, int attack) : Monster(life, magic, attack) {
            cout << "一个山脉的机械类怪物来到了这个世界" << endl;
        }
    };

    //-----------------------------------------------
    //城镇亡灵类怪物
    class M_Undead_Town : public Monster {
    public:
        M_Undead_Town(int life, int magic, int attack) : Monster(life, magic, attack) {
            cout << "一个城镇的亡灵类怪物来到了这个世界" << endl;
        }
    };

    //城镇元素类怪物
    class M_Element_Town : public Monster {
    public:
        M_Element_Town(int life, int magic, int attack) : Monster(life, magic, attack) {
            cout << "一个城镇的元素类怪物来到了这个世界" << endl;
        }
    };

    //城镇机械类怪物
    class M_Mechanic_Town : public Monster {
    public:
        M_Mechanic_Town(int life, int magic, int attack) : Monster(life, magic, attack) {
            cout << "一个城镇的机械类怪物来到了这个世界" << endl;
        }
    };

    //---------------------------------
    //所有工厂类的父类
    class M_ParFactory {
    public:
        virtual Monster *createMonster_Undead() = 0; //创建亡灵类怪物
        virtual Monster *createMonster_Element() = 0; //创建元素类怪物
        virtual Monster *createMonster_Mechanic() = 0; //创建机械类怪物
        virtual ~M_ParFactory() {} //做父类时析构函数应该为虚函数
    };


    //-----------------------------------------------
    //沼泽地区的工厂
    class M_Factory_Swamp : public M_ParFactory {
    public:
        virtual Monster *createMonster_Undead() {
            return new M_Undead_Swamp(300, 50, 120); //创建沼泽亡灵类怪物
        }

        virtual Monster *createMonster_Element() {
            return new M_Element_Swamp(200, 80, 110); //创建沼泽元素类怪物
        }

        virtual Monster *createMonster_Mechanic() {
            return new M_Mechanic_Swamp(400, 0, 90); //创建沼泽机械类怪物
        }
    };

    //山脉地区的工厂
    class M_Factory_Mountain : public M_ParFactory {
    public:
        virtual Monster *createMonster_Undead() {
            return new M_Undead_Mountain(300, 50, 80); //创建山脉亡灵类怪物
        }

        virtual Monster *createMonster_Element() {
            return new M_Element_Mountain(200, 80, 100); //创建山脉元素类怪物
        }

        virtual Monster *createMonster_Mechanic() {
            return new M_Mechanic_Mountain(600, 0, 110); //创建山脉机械类怪物
        }
    };

    //城镇的工厂
    class M_Factory_Town : public M_ParFactory {
    public:
        virtual Monster *createMonster_Undead() {
            return new M_Undead_Town(300, 50, 80); //创建城镇亡灵类怪物
        }

        virtual Monster *createMonster_Element() {
            return new M_Element_Town(200, 80, 100); //创建城镇元素类怪物
        }

        virtual Monster *createMonster_Mechanic() {
            return new M_Mechanic_Town(400, 0, 110); //创建城镇机械类怪物
        }
    };

}
namespace _nmsp3 {
    //--------------------------------
    //抽象工厂模式
    //身体抽象类
    class Body {
    public:
        virtual void getName() = 0;

        virtual ~Body() {}
    };

    //衣服抽象类
    class Clothes {
    public:
        virtual void getName() = 0;

        virtual ~Clothes() {}
    };

    //鞋子抽象类
    class Shoes {
    public:
        virtual void getName() = 0;

        virtual ~Shoes() {}
    };

    //抽象工厂类
    class AbstractFactory {
    public:
        //所创建的部件应该稳定的保持这三个部件，才适合抽象工厂模式
        virtual Body *createBody() = 0; //创建身体
        virtual Clothes *createClothes() = 0; //创建衣服
        virtual Shoes *createShoes() = 0; //创建鞋子
        virtual ~AbstractFactory() {}
    };


    //芭比娃娃类
    class BarbieDoll {
    public:
        //构造函数
        BarbieDoll(Body *tmpbody, Clothes *tmpclothes, Shoes *tmpshoes) {
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
        Body *body;
        Clothes *clothes;
        Shoes *shoes;
    };


    //中国厂商实现的三个部件
    class China_Body : public Body {
    public:
        virtual void getName() {
            cout << "中国厂商产的_身体部件" << endl;
        }
    };

    class China_Clothes : public Clothes {
    public:
        virtual void getName() {
            cout << "中国厂商产的_衣服部件" << endl;
        }
    };

    class China_Shoes : public Shoes {
    public:
        virtual void getName() {
            cout << "中国厂商产的_鞋子部件" << endl;
        }
    };

    //创建一个中国工厂
    class ChinaFactory : public AbstractFactory {
    public:
        virtual Body *createBody() {
            return new China_Body;
        }

        virtual Clothes *createClothes() {
            return new China_Clothes;
        }

        virtual Shoes *createShoes() {
            return new China_Shoes;
        }
    };

    //日本厂商实现的三个部件
    class Japan_Body : public Body {
    public:
        virtual void getName() {
            cout << "日本厂商产的_身体部件" << endl;
        }
    };

    class Japan_Clothes : public Clothes {
    public:
        virtual void getName() {
            cout << "日本厂商产的_衣服部件" << endl;
        }
    };

    class Japan_Shoes : public Shoes {
    public:
        virtual void getName() {
            cout << "日本厂商产的_鞋子部件" << endl;
        }
    };

    //创建一个日本工厂
    class JapanFactory : public AbstractFactory {
    public:
        virtual Body *createBody() {
            return new Japan_Body;
        }

        virtual Clothes *createClothes() {
            return new Japan_Clothes;
        }

        virtual Shoes *createShoes() {
            return new Japan_Shoes;
        }
    };


    //美国厂商实现的三个部件
    class America_Body : public Body {
    public:
        virtual void getName() {
            cout << "美国厂商产的_身体部件" << endl;
        }
    };

    class America_Clothes : public Clothes {
    public:
        virtual void getName() {
            cout << "美国厂商产的_衣服部件" << endl;
        }
    };

    class America_Shoes : public Shoes {
    public:
        virtual void getName() {
            cout << "美国厂商产的_鞋子部件" << endl;
        }
    };

    //创建一个美国工厂
    class AmericaFactory : public AbstractFactory {
    public:
        virtual Body *createBody() {
            return new America_Body;
        }

        virtual Clothes *createClothes() {
            return new America_Clothes;
        }

        virtual Shoes *createShoes() {
            return new America_Shoes;
        }
    };

}


int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口

    /*
    _nmsp1::Monster* pM1 = new _nmsp1::M_Undead(300, 50, 80); //产生了一只亡灵类怪物
    _nmsp1::Monster* pM2 = new _nmsp1::M_Element(200, 80, 100); //产生了一只元素类怪物
    _nmsp1::Monster* pM3 = new _nmsp1::M_Mechanic(400, 0, 110); //产生了一只机械类怪物
    //释放资源
    delete pM1;
    delete pM2;
    delete pM3;
    */

    /*
    //简单工厂模式
    _nmsp1::MonsterFactory facobj;
    _nmsp1::Monster* pM1 = facobj.createMonster("udd"); //产生了一只亡灵类怪物，当然这里必须知道"udd"代表的是创建亡灵类怪物
    _nmsp1::Monster* pM2 = facobj.createMonster("elm"); //产生了一只元素类怪物
    _nmsp1::Monster* pM3 = facobj.createMonster("mec"); //产生了一只机械类怪物
    //释放资源
    delete pM1;
    delete pM2;
    delete pM3;
    */

    /*
    //工厂方法模式
    _nmsp1::M_ParFactory* p_ud_fy = new _nmsp1::M_UndeadFactory(); //多态工厂，注意指针类型
    _nmsp1::Monster* pM1 = Gbl_CreateMonster(p_ud_fy);//产生了一只亡灵类怪物，也是多态，注意返回类型，当然也可以直接写成Monster* pM1 = p_ud_fy->createMonster();

    _nmsp1::M_ParFactory* p_elm_fy = new _nmsp1::M_ElementFactory();
    _nmsp1::Monster* pM2 = Gbl_CreateMonster(p_elm_fy);  //产生了一只元素类怪物

    _nmsp1::M_ParFactory* p_mec_fy = new _nmsp1::M_MechanicFactory();
    _nmsp1::Monster* pM3 = Gbl_CreateMonster(p_mec_fy);  //产生了一只机械类怪物

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
    //抽象工厂模式
    _nmsp2::M_ParFactory* p_mou_fy = new _nmsp2::M_Factory_Mountain(); //多态工厂，山脉地区的工厂
    _nmsp2::Monster* pM1 = p_mou_fy->createMonster_Element();  //创建山脉地区的元素类怪物

    _nmsp2::M_ParFactory* p_twn_fy = new _nmsp2::M_Factory_Town(); //多态工厂，城镇的工厂
    _nmsp2::Monster* pM2 = p_twn_fy->createMonster_Undead();   //创建城镇的亡灵类怪物
    _nmsp2::Monster* pM3 = p_twn_fy->createMonster_Mechanic();  //创建城镇的机械类怪物

    //释放资源
    //释放工厂
    delete p_mou_fy;
    delete p_twn_fy;

    //释放怪物
    delete pM1;
    delete pM2;
    delete pM3;
    */

    //创建第一个芭比娃娃------------------------------------
    //(1)创建一个中国工厂
    _nmsp3::AbstractFactory *pChinaFactory = new _nmsp3::ChinaFactory();
    //(2)创建中国产的各种部件
    _nmsp3::Body *pChinaBody = pChinaFactory->createBody();
    _nmsp3::Clothes *pChinaClothes = pChinaFactory->createClothes();
    _nmsp3::Shoes *pChinaShoes = pChinaFactory->createShoes();
    //(3)创建芭比娃娃
    _nmsp3::BarbieDoll *pbd1obj = new _nmsp3::BarbieDoll(pChinaBody, pChinaClothes, pChinaShoes);
    pbd1obj->Assemble(); //组装芭比娃娃

    //创建第二个芭比娃娃------------------------------------
    //(1)创建另外两个工厂：日本工厂，美国工厂
    _nmsp3::AbstractFactory *pJapanFactory = new _nmsp3::JapanFactory();
    _nmsp3::AbstractFactory *pAmericaFactory = new _nmsp3::AmericaFactory();
    //(2)创建中国产的身体部件，日本产的衣服部件，美国产的鞋子部件
    _nmsp3::Body *pChinaBody2 = pChinaFactory->createBody();
    _nmsp3::Clothes *pJapanClothes = pJapanFactory->createClothes();
    _nmsp3::Shoes *pAmericaShoes = pAmericaFactory->createShoes();
    //(3)创建芭比娃娃
    _nmsp3::BarbieDoll *pbd2obj = new _nmsp3::BarbieDoll(pChinaBody2, pJapanClothes, pAmericaShoes);
    pbd2obj->Assemble(); //组装芭比娃娃

    //最后记得释放内存------------------------------------
    delete pbd1obj;
    delete pChinaShoes;
    delete pChinaClothes;
    delete pChinaBody;
    delete pChinaFactory;
    //-----------
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

