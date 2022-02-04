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
#pragma once
#include "ExpressNode.h"
#include <iostream>
using namespace std;
class Express {
public:
	Express(int);//ValueNode
	Express(char, const Express);//UnaryNodoe(char,int) Express('+',t,12)
	Express(char, const Express, const Express);//BinaryNode(char,int,int),("+",3,4)
	Express(const Express&);
	Express& operator=(const Express&);
	friend ostream& operator<<(ostream& os, const Express& e) {
		os << *(e.p);
		return os;
	}
	~Express(void);
	int eval()const;
private:
	class ExpressNode* p;//����Ĺ����������ʵ�֣�����������˸��ָ����ı��ʽ
};