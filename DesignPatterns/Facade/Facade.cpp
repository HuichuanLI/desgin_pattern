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

class Carmera {
public:
	void turnOn() {
		cout << "�������" << endl;
	}
	void turnOff() {
		cout << "����ر�" << endl;
	}
};

class Light {
public:
	void turnOn() {
		cout << "�����ƿ���" << endl;
	}
	void turnOff() {
		cout << "�����ƹر�" << endl;
	}
};
class Sensor {
public:
	void active() {
		cout << "����������" << endl;
	}
	void deactive() {
		cout << "�������ر�" << endl;
	}
};

class Alarm {
public:
	void active() {
		cout << "����������" << endl;
	}
	void deactive() {
		cout << " �������ر�" << endl;
	}
};

class SecuritFacade {
public:
	SecuritFacade() {
		Carmera* m_pCarmera = new Carmera;
		Light* m_pPLight = new Light;
		Sensor* m_pSensor = new Sensor;
		Alarm* m_pAlaram = new Alarm;
	}
	void active() {
		m_pCarmera->turnOn();
		m_pPLight->turnOn();
		m_pSensor->active();
		m_pAlaram->active();
	}
	void deactive() {
		m_pCarmera->turnOff();
		m_pPLight->turnOff();
		m_pSensor->deactive();
		m_pAlaram->deactive();
	}
private:
	Carmera* m_pCarmera;
	Light* m_pPLight ;
	Sensor* m_pSensor ;
	Alarm* m_pAlaram ;
};
//LOD
int main() {
	SecuritFacade facade;
	

	cout << "-----------����ϵͳ" << endl;
	facade.active();
	//
	cout << "----------�ر�ϵͳ" << endl;
	facade.deactive();
	system("pause");
	return 0;
}