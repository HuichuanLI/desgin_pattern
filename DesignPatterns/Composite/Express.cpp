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
#include "Express.h"
#include "ValueNode.h"
#include "UnaryNode.h"
#include "BinarayNode.h"

Express::Express(int a) {
	p = new ValueNode(a);

}

Express::Express(char c, const Express e) {
	p = new UnaryNode(c, e);
}

Express::Express(char c, const Express el, const Express er) {
	p = new BinaryNode(c, el, er);
}

Express::Express(const Express& el) {
	p = el.p;
	p->setUse(p->getUse() + 1);
}
Express& Express::operator=(const Express& el) {
	(el.p)->setUse((el.p)->getUse() + 1);
	p->setUse(p->getUse() - 1);
	if (p->getUse() == 0)
		delete p;
	p = el.p;
	return *this;
}

Express::~Express() {
	p->setUse(p->getUse() - 1);
	if (p->getUse() == 0)
		delete p;
}
int Express::eval() const {
	return p->eval();
}

