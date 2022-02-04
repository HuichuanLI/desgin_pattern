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
using namespace std;

//PC机，手机，平板
class MakeOrder {
public:
	//virtual void startOrder() =0;第一版
	//钩子函数的模板方法
	virtual void startOrder() {
		cout << "下订单了" << endl;
	}
	virtual void replyStart()=0;
	//.....
	virtual void finishOrder()=0;
	virtual void replyFinish()=0;
	//模板模式
	void make() {
		startOrder();
		replyStart();
		finishOrder();
		replyFinish();
	}
protected:
	MakeOrder(){}
};

class Fanuc :public MakeOrder {
public:
	void startOrder() {
		cout << "Fanuc开始接受订单" << endl;
	}
	void replyStart() {
		cout << "Fanuc做好预备，请将后继订单进入排队" << endl;
	}
	//.....
	 void finishOrder() {
		 cout << "本次Fanuc订单已经完成，请推进下个订单进入生产" << endl;
	}
	 void replyFinish() {
		 cout << "Fanuc订单信号已经送达，即将推进下个订单进入生产" << endl;
	 }
};

class Sims :public MakeOrder {
public:
	void startOrder() {
		cout << "Sims开始接受订单" << endl;
	}
	void replyStart() {
		cout << "Sims做好预备，请将后继订单进入排队" << endl;
	}
	//.....
	void finishOrder() {
		cout << "本次Sims订单已经完成，请推进下个订单进入生产" << endl;
	}
	void replyFinish() {
		cout << "Sims订单信号已经送达，即将推进下个订单进入生产" << endl;
	}
};

class Mits :public MakeOrder {
public:
	
	void replyStart() {
		cout << "Sims做好预备，请将后继订单进入排队" << endl;
	}
	//.....
	void finishOrder() {
		cout << "本次Sims订单已经完成，请推进下个订单进入生产" << endl;
	}
	void replyFinish() {
		cout << "Sims订单信号已经送达，即将推进下个订单进入生产" << endl;
	}
};

int main(void) {
	//MakeOrder* pMakeOrder = new Fanuc;
	//pMakeOrder->make();
	MakeOrder* pMakeOrder = new Mits;
	pMakeOrder->make();
	system("pause");
	return 0;
}