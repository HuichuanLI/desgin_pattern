//
// Created by lhc456 on 2023/1/14

#include <iostream>
#include <vector>
#include <list>


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
    //抽象迭代器类模板
    template<typename T>
    class myIter {
    public:
        virtual void First() = 0;     //指向容器中第一个元素
        virtual void Next() = 0;      //指向下一个元素
        virtual bool IsDone() = 0;    //是否遍历完
        virtual T &CurrentItem() = 0; //获取当前的元素
        virtual ~myIter() {}          //做父类时析构函数应该为虚函数
    };

    //抽象容器类模板
    template<typename T>
    class myCotainer {
    public:
        virtual myIter<T> *CreateIterator() = 0; //创建迭代器
        virtual T &getItem(int index) = 0; //获取当前元素
        virtual int getSize() = 0;  //容器中元素数量
        virtual ~myCotainer() {}  //做父类时析构函数应该为虚函数
    };

    //---------
    //具体迭代器类模板，为简单起见，本迭代器针对的是大小为10个元素的数组
    template<typename T>
    class myVectorIter : public myIter<T> {
    public:
        myVectorIter(myCotainer<T> *tmpc) : myvector(tmpc) {
            m_current = 0;
        }

        virtual void First() {
            m_current = 0; //容器（数组）中的第一个元素下标为0
        }

        virtual void Next() {
            m_current++;  //下标+1，意味着数组中的下一个元素
        }

        virtual bool IsDone() {
            if (m_current >= myvector->getSize()) {
                return true;
            }
            return false;
        }

        virtual T &CurrentItem() {
            return myvector->getItem(m_current);
        }

    private:
        myCotainer<T> *myvector;
        int m_current;  //记录数组的当前下标（迭代器在当前容器中的位置）
    };

    //具体容器类模板
    template<typename T>
    class myVector : public myCotainer<T> {
    public:
        myVector() {
            //将数组中元素进行初始化
            for (int i = 0; i < 10; ++i) {
                m_elem[i] = i;
            }
        }

        virtual myIter<T> *CreateIterator() {
            //工厂模式，注意实参传递进去的是该容器的指针this
            return new myVectorIter<T>(this); //要考虑在哪里释放的问题
        }

        virtual T &getItem(int index) {
            return m_elem[index];
        }

        virtual int getSize() {
            return 10; //为简化代码，返回固定数字
        }

    private:
        //为了简化代码，将容器实现为固定装入10个元素的数组
        T m_elem[10];
    };

}


int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口

    /*
    std::vector<int> msgVector;
    msgVector.push_back(1); //末尾插入1，vector中内容：1
    msgVector.push_back(2); //开头插入2，vector中内容：1,2
    msgVector.push_back(3); //末尾插入3，vector中内容：1,2,3
    for (std::vector<int>::iterator pos = msgVector.begin(); pos != msgVector.end(); ++pos)
    {
        cout << *pos << endl;
    }
    cout << "-------------------" << endl;
    std::list<int>  msgList;
    msgList.push_back(1); //末尾插入1，list中内容：1
    msgList.push_front(2);//开头插入2，list中内容：2，1
    msgList.push_back(3); //末尾插入3，list中内容：2，1，3
    for (std::list<int>::iterator pos = msgList.begin(); pos != msgList.end(); ++pos)
    {
        cout << *pos << endl;
    }
    */

    /*
    _nmsp1::myCotainer<int>* pcontainer = new _nmsp1::myVector<int>();
    _nmsp1::myIter<int>* iter = pcontainer->CreateIterator();
    //遍历容器中的元素
    for (iter->First(); !iter->IsDone(); iter->Next()) //多态机制的遍历，效率上不好，尽量考虑栈机制
    {
        cout << iter->CurrentItem() << endl;
    }
    //释放资源
    delete iter;
    delete pcontainer;
    */

    _nmsp1::myCotainer<int> *pcontainer = new _nmsp1::myVector<int>();
    _nmsp1::myVectorIter<int> iter(pcontainer);
    //遍历容器中的元素
    for (iter.First(); !iter.IsDone(); iter.Next())//非多态机制，可以明显改善程序性能
    {
        cout << iter.CurrentItem() << endl;
    }
    //释放资源
    delete pcontainer;


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

