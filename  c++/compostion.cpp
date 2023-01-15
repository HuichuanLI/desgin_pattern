//
// Created by lhc456 on 2023/1/15.

#include <iostream>
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
    //文件相关类
    class File {
    public:
        //构造函数
        File(string name) : m_sname(name) {}

        //显示文件名
        void ShowName(string lvlstr) {
            cout << lvlstr << "-" << m_sname << endl; //显示"-"代表是一个文件，属末端节点（不会再有子节点）
        }

    private:
        string m_sname;  //文件名
    };

    //目录相关类
    class Dir {
    public:
        //构造函数
        Dir(string name) : m_sname(name) {}

    public:
        //目录中可以增加其他文件
        void AddFile(File *pfile) {
            m_childFile.push_back(pfile);
        }

        //目录中可以增加其他目录
        void AddDir(Dir *pdir) {
            m_childDir.push_back(pdir);
        }

        //显示目录名，同时也要负责其下面的文件和目录名的显示工作
        void ShowName(string lvlstr) //lvlstr：为了显示层次关系的缩进字符串内容
        {
            //（1）输出本目录名
            cout << lvlstr << "+" << m_sname << endl;//显示"+"代表是一个目录，其中会包含其他内容
            //（2）输出所包含的文件名
            lvlstr += "    "; //本目录中的文件和目录的显示，要缩进一些来显示
            for (auto iter = m_childFile.begin(); iter != m_childFile.end(); ++iter) {
                (*iter)->ShowName(lvlstr); //显示文件名
            }
            //（3）输出所包含的目录名
            for (auto iter = m_childDir.begin(); iter != m_childDir.end(); ++iter) {
                (*iter)->ShowName(lvlstr); //显示目录名，这里涉及到了递归调用
            }
        }

    private:
        string m_sname;       //目录名
        list<File *> m_childFile;   //目录中包含的文件列表，记得在源文件上面增加代码 #include <list>
        list<Dir *> m_childDir;    //目录中包含的子目录列表
    };

}
namespace _nmsp2 {
    //抽象父类FileSystem（抽象接口）
    class FileSystem {
    public:
        virtual void ShowName(int level) = 0; //显示名字，参数level用于表示显示的层级，用于显示对齐
        virtual int Add(FileSystem *pfilesys) = 0; //向当前目录中增加文件或子目录
        virtual int Remove(FileSystem *pfilesys) = 0;//从当前目录中移除文件或子目录
        virtual ~FileSystem() {} //做父类时析构函数应该为虚函数
    };

    //文件相关类
    class File : public FileSystem {
    public:
        //构造函数
        File(string name) : m_sname(name) {}

        //显示名字
        void ShowName(int level) {
            for (int i = 0; i < level; ++i) { cout << "    "; } //显示若干个空格用与对齐
            cout << "-" << m_sname << endl;
        }

        virtual int Add(FileSystem *pfilesys) {
            //文件中其实是不可以增加其他文件或者目录的，所以这里直接返回-1，无奈的是父类中定义了该接口，所以子类中也必须实现该接口
            return -1;
        }

        virtual int Remove(FileSystem *pfilesys) {
            //文件中不包含其他文件或者目录，所以这里直接返回-1
            return -1;
        }

    private:
        string m_sname;  //文件名
    };

    //目录相关类
    class Dir : public FileSystem {
    public:
        //构造函数
        Dir(string name) : m_sname(name) {}

        //显示名字
        void ShowName(int level) {
            //（1）显示若干个空格用与对齐
            for (int i = 0; i < level; ++i) { cout << "    "; }
            //（2）输出本目录名
            cout << "+" << m_sname << endl;
            //（3）显示的层级向下走一级
            level++;
            //（4）输出所包含的子内容（可能是文件，也可能是子目录）
            //遍历目录中的文件和子目录
            for (auto iter = m_child.begin(); iter != m_child.end(); ++iter) {
                (*iter)->ShowName(level);
            }//end for
        }

        virtual int Add(FileSystem *pfilesys) {
            m_child.push_back(pfilesys);
            return 0;
        }

        virtual int Remove(FileSystem *pfilesys) {
            m_child.remove(pfilesys);
            return 0;
        }

    private:
        string m_sname;             //文件名
        list<FileSystem *> m_child;  //目录中包含的文件或其他目录列表
    };

}
namespace _nmsp3 {
    class Dir;

    //抽象父类FileSystem（抽象接口）
    class FileSystem {
    public:
        virtual void ShowName(int level) = 0; //显示名字，参数level用于表示显示的层级，用于显示对齐
        virtual ~FileSystem() {}//做父类时析构函数应该为虚函数

    public:
        virtual Dir *ifCompositeObj() { return nullptr; }

    public:
        virtual int countNumOfFiles() = 0;  //统计目录下包含的文件个数

    };

    //文件相关类
    class File : public FileSystem {
    public:
        //构造函数
        File(string name) : m_sname(name) {}

        //显示名字
        void ShowName(int level) {
            for (int i = 0; i < level; ++i) { cout << "    "; } //显示若干个空格用与对齐
            cout << "-" << m_sname << endl;
        }

    public:
        virtual int countNumOfFiles() {
            return 1; //文件节点，做数量统计时按1计算
        }

    private:
        string m_sname;  //文件名
    };

    class Dir : public FileSystem {
        //该类内容基本没变，把Add和Remove成员函数前面的virtual修饰符去掉即可。
    public:
        //构造函数
        Dir(string name) : m_sname(name) {}

        //显示名字
        void ShowName(int level) {
            //（1）显示若干个空格用与对齐
            for (int i = 0; i < level; ++i) { cout << "    "; }
            //（2）输出本目录名
            cout << "+" << m_sname << endl;
            //（3）显示的层级向下走一级
            level++;
            //（4）输出所包含的子内容（可能是文件，也可能是子目录）
            //遍历目录中的文件和子目录
            for (auto iter = m_child.begin(); iter != m_child.end(); ++iter) {
                (*iter)->ShowName(level);
            }//end for
        }

        /*virtual*/ int Add(FileSystem *pfilesys) {
            m_child.push_back(pfilesys);
            return 0;
        }

        /*virtual*/ int Remove(FileSystem *pfilesys) {
            m_child.remove(pfilesys);
            return 0;
        }

    public:
        virtual Dir *ifCompositeObj() { return this; }

    public:
        virtual int countNumOfFiles() {
            int iNumOfFiles = 0;
            for (auto iter = m_child.begin(); iter != m_child.end(); ++iter) {
                iNumOfFiles += (*iter)->countNumOfFiles();//递归调用
            }
            return iNumOfFiles;
        }


    private:
        string m_sname;             //文件名
        list<FileSystem *> m_child;  //目录中包含的文件或其他目录列表
    };

}


int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口

    /*
    //（1）创建各种目录，文件对象
    _nmsp1::Dir* pdir1 = new _nmsp1::Dir("root");
    //-------
    _nmsp1::File* pfile1 = new _nmsp1::File("common.mk");
    _nmsp1::File* pfile2 = new _nmsp1::File("config.mk");
    _nmsp1::File* pfile3 = new _nmsp1::File("makefile");
    //-------
    _nmsp1::Dir* pdir2 = new _nmsp1::Dir("app");
    _nmsp1::File* pfile4 = new _nmsp1::File("nginx.c");
    _nmsp1::File* pfile5 = new _nmsp1::File("ngx_conf.c");
    //-------
    _nmsp1::Dir* pdir3 = new _nmsp1::Dir("signal");
    _nmsp1::File* pfile6 = new _nmsp1::File("ngx_signal.c");
    //-------
    _nmsp1::Dir* pdir4 = new _nmsp1::Dir("_include");
    _nmsp1::File* pfile7 = new _nmsp1::File("ngx_func.h");
    _nmsp1::File* pfile8 = new _nmsp1::File("ngx_signal.h");

    //（2）构造树形目录结构
    pdir1->AddFile(pfile1);
    pdir1->AddFile(pfile2);
    pdir1->AddFile(pfile3);
    //-------
    pdir1->AddDir(pdir2);
    pdir2->AddFile(pfile4);
    pdir2->AddFile(pfile5);
    //-------
    pdir1->AddDir(pdir3);
    pdir3->AddFile(pfile6);
    //-------
    pdir1->AddDir(pdir4);
    pdir4->AddFile(pfile7);
    pdir4->AddFile(pfile8);

    //（3）输出整个目录结构，只要调用根目录的ShowName方法即可，每个子目录都有自己的ShowName方法负责自己旗下的文件和目录的显示
    pdir1->ShowName("");//缩进字符刚开始可以为空

    //（4）释放资源
    delete pfile8;
    delete pfile7;
    delete pdir4;
    //-------
    delete pfile6;
    delete pdir3;
    //-------
    delete pfile5;
    delete pfile4;
    delete pdir2;
    //-------
    delete pfile3;
    delete pfile2;
    delete pfile1;
    delete pdir1;
    */

    /*
    //（1）创建各种目录，文件对象
    _nmsp2::FileSystem* pdir1 = new _nmsp2::Dir("root");
    //-------
    _nmsp2::FileSystem* pfile1 = new _nmsp2::File("common.mk");
    _nmsp2::FileSystem* pfile2 = new _nmsp2::File("config.mk");
    _nmsp2::FileSystem* pfile3 = new _nmsp2::File("makefile");
    //-------
    _nmsp2::FileSystem* pdir2 = new _nmsp2::Dir("app");
    _nmsp2::FileSystem* pfile4 = new _nmsp2::File("nginx.c");
    _nmsp2::FileSystem* pfile5 = new _nmsp2::File("ngx_conf.c");
    //-------
    _nmsp2::FileSystem* pdir3 = new _nmsp2::Dir("signal");
    _nmsp2::FileSystem* pfile6 = new _nmsp2::File("ngx_signal.c");
    //-------
    _nmsp2::FileSystem* pdir4 = new _nmsp2::Dir("_include");
    _nmsp2::FileSystem* pfile7 = new _nmsp2::File("ngx_func.h");
    _nmsp2::FileSystem* pfile8 = new _nmsp2::File("ngx_signal.h");

    //（2）构造树形目录结构
    pdir1->Add(pfile1);
    pdir1->Add(pfile2);
    pdir1->Add(pfile3);
    //-------
    pdir1->Add(pdir2);
    pdir2->Add(pfile4);
    pdir2->Add(pfile5);
    //-------
    pdir1->Add(pdir3);
    pdir3->Add(pfile6);
    //-------
    pdir1->Add(pdir4);
    pdir4->Add(pfile7);
    pdir4->Add(pfile8);

    //（3）输出整个目录结构，只要调用根目录的ShowName方法即可，每个子目录都有自己的ShowName方法负责自己旗下的文件和目录的显示
    pdir1->ShowName(0);

    //（4）释放资源
    delete pfile8;
    delete pfile7;
    delete pdir4;
    //-------
    delete pfile6;
    delete pdir3;
    //-------
    delete pfile5;
    delete pfile4;
    delete pdir2;
    //-------
    delete pfile3;
    delete pfile2;
    delete pfile1;
    delete pdir1;
    */

    //（1）创建各种目录，文件对象
    _nmsp3::Dir *pdir1 = new _nmsp3::Dir("root");
    //-------
    _nmsp3::FileSystem *pfile1 = new _nmsp3::File("common.mk");
    _nmsp3::FileSystem *pfile2 = new _nmsp3::File("config.mk");
    _nmsp3::FileSystem *pfile3 = new _nmsp3::File("makefile");
    //-------
    _nmsp3::Dir *pdir2 = new _nmsp3::Dir("app");
    if (pdir2->ifCompositeObj() != nullptr) {
        //是个组合对象，可以向其中增加单个对象和其它组合对象
    }
    if (dynamic_cast<_nmsp3::Dir *>(pdir2) != nullptr) {
        //是个组合对象，可以向其中增加单个对象和其它组合对象
    }

    _nmsp3::FileSystem *pfile4 = new _nmsp3::File("nginx.c");
    _nmsp3::FileSystem *pfile5 = new _nmsp3::File("ngx_conf.c");
    //-------
    _nmsp3::Dir *pdir3 = new _nmsp3::Dir("signal");
    _nmsp3::FileSystem *pfile6 = new _nmsp3::File("ngx_signal.c");
    //-------
    _nmsp3::Dir *pdir4 = new _nmsp3::Dir("_include");
    _nmsp3::FileSystem *pfile7 = new _nmsp3::File("ngx_func.h");
    _nmsp3::FileSystem *pfile8 = new _nmsp3::File("ngx_signal.h");

    //（2）构造树形目录结构
    //这部分内容基本没变，
    pdir1->Add(pfile1);
    pdir1->Add(pfile2);
    pdir1->Add(pfile3);
    //-------
    pdir1->Add(pdir2);
    pdir2->Add(pfile4);
    pdir2->Add(pfile5);
    //-------
    pdir1->Add(pdir3);
    pdir3->Add(pfile6);
    //-------
    pdir1->Add(pdir4);
    pdir4->Add(pfile7);
    pdir4->Add(pfile8);

    //（3）输出整个目录结构，只要调用根目录的ShowName方法即可，每个子目录都有自己的ShowName方法负责自己旗下的文件和目录的显示
    pdir1->ShowName(0);

    cout << "文件的数量为：" << pdir1->countNumOfFiles() << endl;

    //（4）释放资源
    //这部分内容基本没变，
    delete pfile8;
    delete pfile7;
    delete pdir4;
    //-------
    delete pfile6;
    delete pdir3;
    //-------
    delete pfile5;
    delete pfile4;
    delete pdir2;
    //-------
    delete pfile3;
    delete pfile2;
    delete pfile1;
    delete pdir1;


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

