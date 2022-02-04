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

class Carmera {
public:
	void turnOn() {
		cout << "相机启动" << endl;
	}
	void turnOff() {
		cout << "相机关闭" << endl;
	}
};

class Light {
public:
	void turnOn() {
		cout << "照明灯开启" << endl;
	}
	void turnOff() {
		cout << "照明灯关闭" << endl;
	}
};
class Sensor {
public:
	void active() {
		cout << "传感器启动" << endl;
	}
	void deactive() {
		cout << "传感器关闭" << endl;
	}
};

class Alarm {
public:
	void active() {
		cout << "报警器启动" << endl;
	}
	void deactive() {
		cout << " 报警器关闭" << endl;
	}
};

class SecuritFacade {
public:
	SecuritFacade() {
		Carmera* m_pCarmera = new Carmera;
		Light* m_pPLight = new Light;
		Sensor* m_pSensor = new Sensor;
		Alarm* m_pAlaram = new Alarm;
	}
	void active() {
		m_pCarmera->turnOn();
		m_pPLight->turnOn();
		m_pSensor->active();
		m_pAlaram->active();
	}
	void deactive() {
		m_pCarmera->turnOff();
		m_pPLight->turnOff();
		m_pSensor->deactive();
		m_pAlaram->deactive();
	}
private:
	Carmera* m_pCarmera;
	Light* m_pPLight ;
	Sensor* m_pSensor ;
	Alarm* m_pAlaram ;
};
//LOD
int main() {
	SecuritFacade facade;
	

	cout << "-----------启动系统" << endl;
	facade.active();
	//
	cout << "----------关闭系统" << endl;
	facade.deactive();
	system("pause");
	return 0;
}