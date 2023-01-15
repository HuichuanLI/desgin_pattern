//
// Created by lhc456 on 2023/1/15.
//
// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <atomic> //#include的头文件加在源文件顶部位置
#include <mutex>


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
    //懒汉式
    //游戏配置相关类
    class GameConfig {
        //......
    private:
        GameConfig() {};

        GameConfig(const GameConfig &tmpobj);

        GameConfig &operator=(const GameConfig &tmpobj);

        ~GameConfig() {};
    public:
        static GameConfig *getInstance() {
            //std::lock_guard<std::mutex> gcguard(my_mutex);
            if (m_instance == nullptr) {
                //这里再加锁
                //std::lock_guard<std::mutex> gcguard(my_mutex);
                //if (m_instance == nullptr)
                //{
                m_instance = new GameConfig();
                static Garbo garboobj;
                //}
            }
            return m_instance;
        }

    public:
        //要手工调用才能释放内存
        static void freeInstance() {
            if (m_instance != nullptr) {
                delete GameConfig::m_instance;
                GameConfig::m_instance = nullptr;
            }
        }

    private:
        //手工释放单件类对象引入的GameConfig类中的嵌套类（垃圾回收）
        class Garbo {
        public:
            ~Garbo() {
                if (GameConfig::m_instance != nullptr) {
                    delete GameConfig::m_instance;
                    GameConfig::m_instance = nullptr;
                }
            }
        };

    private:
        static GameConfig *m_instance; //指向本类对象的指针
    };

    GameConfig *GameConfig::m_instance = nullptr; //在类外，某个.cpp源文件的开头位置，为静态成员变量赋值（定义并赋值）

}
namespace _nmsp2 {

    //游戏配置相关类
    class GameConfig {
    private:
        GameConfig() {};

        GameConfig(const GameConfig &tmpobj);

        GameConfig &operator=(const GameConfig &tmpobj);

        ~GameConfig() {};
    public:
        static GameConfig *getInstance() {
            GameConfig *tmp = m_instance.load(std::memory_order_relaxed);
            std::atomic_thread_fence(std::memory_order_acquire);
            if (tmp == nullptr) {
                std::lock_guard <std::mutex> lock(m_mutex);
                tmp = m_instance.load(std::memory_order_relaxed);
                if (tmp == nullptr) {
                    tmp = new GameConfig();
                    static Garbo garboobj;
                    std::atomic_thread_fence(std::memory_order_release);
                    m_instance.store(tmp, std::memory_order_relaxed);
                }
            }
            return tmp;
        }

    private:
        //手工释放单件类对象引入的GameConfig类中的嵌套类（垃圾回收）
        class Garbo {
        public:
            ~Garbo() {
                if (GameConfig::m_instance != nullptr) {
                    delete GameConfig::m_instance;
                    GameConfig::m_instance = nullptr;
                }
            }
        };

    private:
        static atomic<GameConfig *> m_instance;
        static std::mutex m_mutex;
    };

    std::atomic<GameConfig *> GameConfig::m_instance;
    std::mutex GameConfig::m_mutex;
}
namespace _nmsp3 {
    //饿汉式
    class GameConfig {
        //......
    private:
        GameConfig() {};

        GameConfig(const GameConfig &tmpobj);

        GameConfig &operator=(const GameConfig &tmpobj);

        ~GameConfig() {};
    public:
        static GameConfig *getInstance() {
            return m_instance;
        }

    private:
        static GameConfig *m_instance;     //指向本类对象的指针


    private:
        //手工释放单件类对象引入的GameConfig类中的嵌套类（垃圾回收）
        class Garbo {
        public:
            ~Garbo() {
                if (GameConfig::m_instance != nullptr) {
                    delete GameConfig::m_instance;
                    GameConfig::m_instance = nullptr;
                }
            }
        };

    private:
        static Garbo garboobj;
    };

    GameConfig *GameConfig::m_instance = new GameConfig();//趁静态成员变量定义的时机直接初始化是被允许的，即便GameConfig构造函数用private修饰
    GameConfig::Garbo GameConfig::garboobj;

}
namespace _nmsp4 {
    /*
    class GameConfig
    {
        //......
    private:
        GameConfig() {};
        GameConfig(const GameConfig& tmpobj);
        GameConfig& operator = (const GameConfig& tmpobj);
        ~GameConfig() {};
    public:
        static GameConfig* getInstance()
        {
            return &m_instance;
        }
    private:
        static GameConfig m_instance;
    };
    GameConfig GameConfig::m_instance;
    */

    class GameConfig {
    private:
        GameConfig() {};

        GameConfig(const GameConfig &tmpobj);

        GameConfig &operator=(const GameConfig &tmpobj);

        ~GameConfig() {};
    public:
        static GameConfig &getInstance() {
            static GameConfig instance;
            return instance;
        }
    };

    //-------------------------------
    int myfunc() {
        static int stcs = 100; //不需要调用myfunc函数，stcs就已经等于100了
        stcs += 180;
        return stcs;
    }

}


int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口

    /*_nmsp1::GameConfig g_config1;
    _nmsp1::GameConfig g_config2;*/

    _nmsp1::GameConfig *g_gc = _nmsp1::GameConfig::getInstance();
    _nmsp1::GameConfig *g_gc2 = _nmsp1::GameConfig::getInstance();
    //g_gc2->freeInstance();  //手工释放内存演示

    //_nmsp2::GameConfig* g_gc_2 = _nmsp2::GameConfig::getInstance();
    //_nmsp2::GameConfig* g_gc2_2 = _nmsp2::GameConfig::getInstance();

    _nmsp4::GameConfig &g_gc40 = _nmsp4::GameConfig::getInstance();
    _nmsp4::myfunc();
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

