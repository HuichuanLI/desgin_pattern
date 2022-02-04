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

//���˼�룺���Ǹ�����������һ����չ�Ĺ�ϵ���ǲ��Ǻ���
//���ϴ���ԭ����������Ӧ������ȫ����������Ϊ
//���ڼ̳�������ƣ��ر�С�ģ����ǣ���ϴ��ڼ̳�
//��quack��fly�����Ϊһ��������ô���������˽������


//////////////////////////
//����˽�������������ɡ�����
class QuackBehavior {
public:
	virtual void quack() = 0;
protected:
	QuackBehavior(){} 
};
class FlyBehavior {
public:
	virtual void fly() = 0;
protected:
	FlyBehavior(){}
};

class FlyWithRocket :public FlyBehavior {
	void fly() {
		cout << "���Ż����" << endl;
	}
};

class FlyWithWings :public FlyBehavior {
	void fly() {
		cout << "���г������Լ���" << endl;
	}
};

class FlyWithNoWay :public FlyBehavior {
	void fly() {
		cout << "�Ҹ����ͻ��" << endl;
	}
};

class ZhiZhiQuack :public QuackBehavior {
public:	void quack() {
	cout << "֨֨" << endl;
	}
};

class PersonQuack :public QuackBehavior {
public:
	void quack() {
		cout << "������������" << endl;
	}
};

class WigeonQuack :public QuackBehavior {
public:
	void quack() {
		cout << "��СѼ�����" << endl;
	}
};

/////////////////////////////////////
//Duck has a Quack 
//     has a Fly
class Duck {

public:
	
	virtual void Display() = 0;
	void setFlyBehavior(FlyBehavior* fb) {
		m_pFly = fb;
	}
	void setQuackBehavior(QuackBehavior* qb) {
		m_pQuack = qb;
	}

	virtual void perfomrFly() {
		m_pFly->fly();

		//if (is ����Ѽ�� {����Ѽ�ķ���
		//if (is С��Ѽ��{С��Ѽ�ķ���.....
	}

	virtual void performQuack() {
		m_pQuack->quack();
	}
protected:
	QuackBehavior *m_pQuack;
	FlyBehavior *m_pFly;
private:
};
//DonaladDuck is Duck
class DonaladDuck :public Duck {
public:
	DonaladDuck() {
		m_pFly = new FlyWithRocket;//ĳһ��FlyBehavior��ʵ��
		m_pQuack = new PersonQuack();
	}
	void Display() {
		perfomrFly();
		performQuack();
	}
	
};
//��һ�������������ƺ���̫��ô���ࡣ����
class RuberDuck : public Duck {
public:
	RuberDuck() {
		m_pFly = new FlyWithNoWay();
		m_pQuack = new ZhiZhiQuack();
	}
	void Display() {
		perfomrFly();
		performQuack();
	}
};

class WigeonDuck : public Duck {
public:
	WigeonDuck() {
		m_pFly = new FlyWithWings;
		m_pQuack = new WigeonQuack;
	}
	void Display() {
		perfomrFly();
		performQuack();
	}
	
};

int main() {
	DonaladDuck *pDonlad = new DonaladDuck;
	pDonlad->Display();
	system("pause");
	return 0;
}
//
class XiaoFeiXia :public Duck {
	//
	//m_pFly = new FlyWithHotPollun()
};