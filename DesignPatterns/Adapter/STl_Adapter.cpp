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
#include <deque>
#include <stack>
using namespace std;
//��STLĬ�ϵ�����������ɽ�һ��dequeת����stack
int main() {
	deque<int> myDeq(3, 100);
	stack<int> myStack;
	stack<int> myStack2(myDeq);
	cout << "myStack Size" << (int)myStack.size() << endl;
	cout << "myStack2 size" << (int)myStack2.size() << endl;
	myStack2.pop();
	cout << "myStack2 size" << (int)myStack2.size() << endl;
	cout << "myStack2 top" << (int)myStack2.top() << endl;
	
	
	system("pause");
	return 0;
}