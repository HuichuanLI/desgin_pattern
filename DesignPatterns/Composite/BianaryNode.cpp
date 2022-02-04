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
	throw "error,二叉归并向上中的根操作符不正确";
}