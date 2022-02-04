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
//#include <sstream>
//using namespace std;
//template <class T>
//string MyConvertToStr(T obj) {
//	stringstream ss;
//	ss << obj;
//	return ss.str();
//}
//
//class Beverage {
//public:
//	virtual string getDescription() = 0;
//		virtual double cost() = 0;
//protected:
//	string m_Description;
//};
//
//class CondimentDecorate :public Beverage {
//public:
//	virtual string getDescription() = 0;
//protected:
//	CondimentDecorate(){}
//};
//
////装饰类1：Soy
//class Soy :public CondimentDecorate {
//public:
//	Soy(Beverage *pBeverage):m_pBeverage(pBeverage){}
//	string getDescription() {
//		return m_pBeverage->getDescription() + ",加了酱油了";
//
//	}
//	double cost() {
//		return 0.1 + m_pBeverage->cost();
//	}
//private:
//	//持有被装饰的对象
//	Beverage *m_pBeverage;
//};
//
////装饰类2：Milk
//class Milk :public CondimentDecorate {
//public:
//	Milk(Beverage *pBeverage) :m_pBeverage(pBeverage) {}
//	string getDescription() {
//		return m_pBeverage->getDescription() + ",加了酱油了";
//
//	}
//	double cost() {
//		return 5+ m_pBeverage->cost();
//	}
//private:
//	//持有被装饰的对象
//	Beverage *m_pBeverage;
//};
//
//class Lattee :public Beverage {
//public:
//	Lattee() {
//		m_Description = "拿铁";
//	}
//	string getDescription() {
//		return m_Description;
//	}
//	double cost() {
//		return 13;
//	}
//};
//
//
//class Expresso :public Beverage {
//public:
//	Expresso() {
//		m_Description = "浓缩咖啡";
//	}
//	string getDescription() {
//		return m_Description;
//	}
//	double cost() {
//		return 13;
//	}
//};
//
//class Mocha :public Beverage {
//public:
//	Mocha() {
//		m_Description = "摩卡";
//	}
//	string getDescription() {
//		return m_Description;
//	}
//	double cost() {
//		return 13;
//	}
//};
//
//int main(void) {
//	Beverage* pBeverage = new Expresso();
//	cout << pBeverage->getDescription() << "价格是" << MyConvertToStr(pBeverage->cost()) << endl;
//
//	Beverage* pBeverage2 = new Mocha();
//	pBeverage2 = new Soy(pBeverage2);
//	pBeverage2 = new Soy(pBeverage2);
//	cout << pBeverage2->getDescription() << "价格是" << MyConvertToStr(pBeverage2->cost()) << endl;
//	system("pause");
//	return 0;
//}
