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
///*
//AOP:叫面向方面（切面）编程
//在我们的日常开发中，我们经常会遇到这样的一类与业务逻辑无关
//的开发，正交化
//打log，将log进入织入我们的业务场景
//*/
//#include <memory>
//#include <string>
//#include <iostream>
//using namespace std;
//
//class IHello {
//public:
//	IHello(){}
//	virtual ~IHello()
//	{
//
//	}
//	virtual void Output(const string& str){}
//};
//
//class Hello :public IHello {
//public:
//	void Output(const string& str) override {
//		cout << str << endl;
//	}
//};
//
//class HelloProxy :public IHello {
//public:
//	HelloProxy(IHello *p) :m_ptr(p) {
//
//	}
//	~HelloProxy(){
//		delete m_ptr;
//		m_ptr = nullptr;
//	}
//
//	void Output(const string& str) final {
//		cout << "在真正的对象执行之前，进行拦截" << endl;
//		m_ptr->Output(str);
//		cout << "在真正的对象执行之后，进行拦截" << endl;
//	}
//private:
//	IHello* m_ptr;
//};
//
//int main(void) {
//	std::shared_ptr<IHello> hello = std::make_shared<HelloProxy>(new Hello());
//	hello->Output("AOP 测试");
//	system("pause");
//	return 0;
//}