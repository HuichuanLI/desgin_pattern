/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               ������������ �Ĳܿ����˴��������Ϊѧϰ�ο�                **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Project       : C++���ģʽ����ʵս
** Description   : DesignPatterns
** Contact       : xiacaojun@qq.com
**  ����   : http://blog.csdn.net/jiedichina
**	��Ƶ�γ� : �����ƿ���	http://study.163.com/u/xiacaojun		
			   ��Ѷ����		https://jiedi.ke.qq.com/				
			   csdnѧԺ		http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961	
**             51ctoѧԺ	http://edu.51cto.com/lecturer/index/user_id-12016059.html	
** 			   ���Ŀ���		http://www.laoxiaketang.com 
**                 
**   C++���ģʽ����ʵս �γ�Ⱥ ��726114806 ����Ⱥ���ش���ͽ���
**   ΢�Ź��ں�  : jiedi2007
**		ͷ����	 : �Ĳܿ�
**
*******************************************************************************/
//������������������ ��C++���ͱ����STL����ʵս  QQȺ��726114806���ش���ͽ���
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
		cout << "Windows ��������" << endl;
	}
};

class CLinux :public IOS {
public:
	virtual void run() {
		cout << "Linux ��������" << endl;
	}
};

class IComputer {
public:
	virtual void Install(IOS *pOS) = 0;
};

class CLenvo :public IComputer {
public:
	virtual void Install(IOS *pOS) {
		cout << "Lenvo���ڰ�װ����ϵͳ" << endl;
		pOS->run();
	}
};

class CDell :public IComputer {
public:
	virtual void Install(IOS *pOS) {
		cout << "Dell���ڰ�װ����ϵͳ" << endl;
		pOS->run();
	}
};

class CAcer:public IComputer
{
public:
public:
	virtual void Install(IOS *pOS) {
		cout << "Acer���ڰ�װ����ϵͳ" << endl;
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

