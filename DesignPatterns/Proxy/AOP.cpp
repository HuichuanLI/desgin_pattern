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
///*
//AOP:�������棨���棩���
//�����ǵ��ճ������У����Ǿ���������������һ����ҵ���߼��޹�
//�Ŀ�����������
//��log����log����֯�����ǵ�ҵ�񳡾�
//*/
//#include <memory>
//#include <string>
//#include <iostream>
//using namespace std;
//
//class IHello {
//public:
//	IHello(){}
//	virtual ~IHello()
//	{
//
//	}
//	virtual void Output(const string& str){}
//};
//
//class Hello :public IHello {
//public:
//	void Output(const string& str) override {
//		cout << str << endl;
//	}
//};
//
//class HelloProxy :public IHello {
//public:
//	HelloProxy(IHello *p) :m_ptr(p) {
//
//	}
//	~HelloProxy(){
//		delete m_ptr;
//		m_ptr = nullptr;
//	}
//
//	void Output(const string& str) final {
//		cout << "�������Ķ���ִ��֮ǰ����������" << endl;
//		m_ptr->Output(str);
//		cout << "�������Ķ���ִ��֮�󣬽�������" << endl;
//	}
//private:
//	IHello* m_ptr;
//};
//
//int main(void) {
//	std::shared_ptr<IHello> hello = std::make_shared<HelloProxy>(new Hello());
//	hello->Output("AOP ����");
//	system("pause");
//	return 0;
//}