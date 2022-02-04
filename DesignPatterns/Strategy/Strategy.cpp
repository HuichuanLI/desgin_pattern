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
//#include <iostream>
//using namespace std;
//
////设计思想：我们父类和子类就是一个扩展的关系？是不是合适
////里氏代换原则：子类对象就应该能完全替代父类的行为
////对于继承这样设计，特别小心，我们：组合大于继承
////把quack和fly抽象成为一个对象，那么这个问题就了解决方案
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
//		cout << "我是唐老鸭" << endl;
//	}
//	void Display() {
//		Quack();
//	}
//	void fly(int param) {
//		cout << "我是唐老鸭，虽然自身不会飞，但是我可以做飞机，做气球飞" << endl;
//	}
//};
////第一个困境：子类似乎不太那么像父类。。。
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
//		cout << "我是小野鸭" << endl;
//	}
//	void Display() {
//		Quack();
//	}
//	void fly() {
//		cout << "我在天空中自由翱翔" << endl;
//	}
//};