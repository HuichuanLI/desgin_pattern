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
//#include <string>
//using namespace std;
//
//class AbstractServer {
//public:
//	virtual void Request() = 0;
//protected:
//	AbstractServer(){}
//};
//
////�����ķ�����
//class RealServer :public AbstractServer {
//public:
//	void Request() {
//		cout << "����������" << endl;
//	}
//};
//
//class ProxyServer :public AbstractServer {
//public:
//	ProxyServer(string name, string pwd) :m_name(name), m_pwd(pwd) {
//		m_pServer = new RealServer;
//	}
//
//	//�Һ������RealProxyͬ���Ľӿ�
//	void Request() {
//		if ("admin" == m_name && "123" == m_pwd) {
//			cout << "����ɹ�" << endl;
//			cout << "�����������������" << endl;
//			m_pServer->Request();
//			cout << "�������������" << endl;
//		}
//
//		else {
//			cout << "�û����������" << endl;
//		}
//
//	}
//private:
//	string m_name;
//	string m_pwd;
//private:
//	AbstractServer* m_pServer;
//}; 
//
//int main(void) {
//	AbstractServer* pProxy = new ProxyServer("admin", "123");
//	pProxy->Request();
//	system("pause");
//	return 0;
//}