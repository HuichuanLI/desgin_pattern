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
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

//抽象的表达式对象以及Context对象
//用于保存计算的中间结果以及当前执行的操作符
class Context {
public:
	int m_value;
	char m_operator;
	Context() :m_value(0), m_operator('\0') {

	}
};
//1+3-2

//表示所有表达式的抽象接口
class IExpression {
public:
	virtual void Eval(Context* p) = 0;
};

//拆分表达式的元素
class Operator :public IExpression {
public:
	Operator(char op) {
		this->m_op = op;
	}
	void Eval(Context *pContext) {
		pContext->m_operator = m_op;
	}
private:
	char m_op;
};

//拆分操作数
class Operand :public IExpression {
public:
	Operand(int num) {
		this->m_num = num;
	}
	void Eval(Context* pContext) {
		switch (pContext->m_operator)
		{
		case '\0':pContext->m_value = m_num;break;
		case '+':pContext->m_value += m_num;break;
		case '-':pContext->m_value -= m_num;break;
		default:
			break;
		}
	}
private:
	int m_num;
};

class Calculator {
public:
	int Calc(string expression) {
		Context* pCpontext = new Context;
		vector<IExpression*> tree;
		for (int i = 0;i < expression.size();i++) {
			if ((expression[i] == '+') || (expression[i] == '-')) {
				tree.push_back(new Operator(expression[i]));
				printf("第%d次压入的符号是=%c\n", i, expression[i]);
			}
			else {
				tree.push_back(new Operand((int)(expression[i] - 48)));
				printf("第%d次压入的数字是=%d\n", i,((int)( expression[i]-48)));
			}
		}
		for (vector<IExpression*>::iterator iter = tree.begin();iter != tree.end();iter++) {
			(*iter)->Eval(pCpontext);
			printf("value=%d,oper=%c\n", pCpontext->m_value, pCpontext->m_operator);
		}
		return pCpontext->m_value;
	}
};

int main(void) {
	Calculator* pc = new Calculator;
	cout << "1+4-2=" << pc->Calc("1+4-2") << endl;
	system("pause");
	return 0;
}