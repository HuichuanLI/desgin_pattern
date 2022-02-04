/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               创建：丁宋涛 夏曹俊，此代码可用作为学习参考                **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Project       : C++设计模式开发实战
** Description   : DesignPatterns
** Contact       : xiacaojun@qq.com
**  博客   : http://blog.csdn.net/jiedichina
**	视频课程 : 网易云课堂	http://study.163.com/u/xiacaojun		
			   腾讯课堂		https://jiedi.ke.qq.com/				
			   csdn学院		http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961	
**             51cto学院	http://edu.51cto.com/lecturer/index/user_id-12016059.html	
** 			   老夏课堂		http://www.laoxiaketang.com 
**                 
**   C++设计模式开发实战 课程群 ：726114806 加入群下载代码和交流
**   微信公众号  : jiedi2007
**		头条号	 : 夏曹俊
**
*******************************************************************************/
//！！！！！！！！！ 加C++泛型编程与STL开发实战  QQ群：726114806下载代码和交流
#include <iostream>
using namespace std;
//
//class Computer {
//public:
//	void run();
//};
//
//class HpWindows7 :public Computer {
//
//};
//class HpWindow8 :public Computer {
//
//};
//
//class HpWindowsX :public Computer {
//
//};

class IOS {
public:
	IOS(){}
	virtual ~IOS()
	{

	}
	virtual void run() = 0;
};

class CWindows :public IOS {
public:
	virtual void run() {
		cout << "Windows 正在运行" << endl;
	}
};

class CLinux :public IOS {
public:
	virtual void run() {
		cout << "Linux 正在运行" << endl;
	}
};

class IComputer {
public:
	virtual void Install(IOS *pOS) = 0;
};

class CLenvo :public IComputer {
public:
	virtual void Install(IOS *pOS) {
		cout << "Lenvo正在安装操作系统" << endl;
		pOS->run();
	}
};

class CDell :public IComputer {
public:
	virtual void Install(IOS *pOS) {
		cout << "Dell正在安装操作系统" << endl;
		pOS->run();
	}
};

class CAcer:public IComputer
{
public:
public:
	virtual void Install(IOS *pOS) {
		cout << "Acer正在安装操作系统" << endl;
		pOS->run();
	}

private:

};





int main(void) {
	IOS* pWindows = new CWindows;
	IOS* pLinux = new CLinux;

	IComputer* pLenvo = new CLenvo;
	pLenvo->Install(pWindows);
	system("pause");
	return 0;
}

