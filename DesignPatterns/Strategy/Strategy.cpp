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
//#include <iostream>
//using namespace std;
//
////���˼�룺���Ǹ�����������һ����չ�Ĺ�ϵ���ǲ��Ǻ���
////���ϴ���ԭ����������Ӧ������ȫ����������Ϊ
////���ڼ̳�������ƣ��ر�С�ģ����ǣ���ϴ��ڼ̳�
////��quack��fly�����Ϊһ��������ô���������˽������
//class Duck {
//public:
//	virtual void Quack() = 0;
//	virtual void Display() = 0;
//	virtual void fly() = 0;//fly(int), fly(object)......
//
//protected:
//private:
//};
//
//class DonaladDuck :public Duck {
//public:
//	void Quack() {
//		cout << "��������Ѽ" << endl;
//	}
//	void Display() {
//		Quack();
//	}
//	void fly(int param) {
//		cout << "��������Ѽ����Ȼ������ɣ������ҿ������ɻ����������" << endl;
//	}
//};
////��һ�������������ƺ���̫��ô���ࡣ����
//class RuberDuck : public Duck {
//public:
//	void Quack() {
//		
//	}
//	void Display() {
//		Quack();
//	}
//};
//
//class WigeonDuck : public Duck {
//public:
//	void Quack() {
//		cout << "����СҰѼ" << endl;
//	}
//	void Display() {
//		Quack();
//	}
//	void fly() {
//		cout << "������������ɰ���" << endl;
//	}
//};