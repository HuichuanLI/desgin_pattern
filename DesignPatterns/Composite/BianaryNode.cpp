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
#include "BinarayNode.h"

BinaryNode::BinaryNode(char c, class Express left1, class Express right1):opend(c),left(left1),right(right1) {

}

BinaryNode::~BinaryNode() {

}

void BinaryNode::print(ostream& os) const {
	os << "(" << left << opend << right << ")";
}

int BinaryNode::eval() const {
	int op1 = left.eval();
	int op2 = right.eval();
	if (opend == '+') return op1 + op2;
	if (opend == '-') return op1 - op2;
	if (opend == '*') return op1*op2;
	if (opend == '/' && op2 != 0) return op1 / op2;
	throw "error,����鲢�����еĸ�����������ȷ";
}