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
//#include <string>
//using namespace std;
//
//class AbstractServer {
//public:
//	virtual void Request() = 0;
//protected:
//	AbstractServer(){}
//};
//
////真正的服务器
//class RealServer :public AbstractServer {
//public:
//	void Request() {
//		cout << "服务器启动" << endl;
//	}
//};
//
//class ProxyServer :public AbstractServer {
//public:
//	ProxyServer(string name, string pwd) :m_name(name), m_pwd(pwd) {
//		m_pServer = new RealServer;
//	}
//
//	//我和主题的RealProxy同样的接口
//	void Request() {
//		if ("admin" == m_name && "123" == m_pwd) {
//			cout << "请求成功" << endl;
//			cout << "代理服务器正在启动" << endl;
//			m_pServer->Request();
//			cout << "服务器请求完毕" << endl;
//		}
//
//		else {
//			cout << "用户名密码错误" << endl;
//		}
//
//	}
//private:
//	string m_name;
//	string m_pwd;
//private:
//	AbstractServer* m_pServer;
//}; 
//
//int main(void) {
//	AbstractServer* pProxy = new ProxyServer("admin", "123");
//	pProxy->Request();
//	system("pause");
//	return 0;
//}