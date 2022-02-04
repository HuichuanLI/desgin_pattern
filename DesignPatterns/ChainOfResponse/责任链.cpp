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
#include <sstream>
using namespace std;

template <class T>
string MyConvertToString(T value) {
	stringstream ss;
	ss << value;
	return ss.str();
}

//顶层的抽象类,规范了击鼓传花的组合能力
class Handle {
public:
	void setSuccessor(Handle *pSuccessor){
		this->m_pHandle = pSuccessor;
	}
	virtual string handleFeeRequest(double fee) = 0;
protected:
	Handle* m_pHandle;
};

class PrjManager :public Handle {
public:
	string handleFeeRequest(double fee) {
		string strTemp = "";
		if (fee < 500) {
			strTemp = "项目经理同意" + MyConvertToString(fee) + "费用";
			return strTemp;
		}
		else {
			if (this->m_pHandle != nullptr) {
				return m_pHandle->handleFeeRequest(fee);
			}

		}
		return strTemp;
		
	}
};

class DepManager :public Handle {
public:
	string handleFeeRequest(double fee) {
		string strTemp = "";
		if (fee>=500 &&fee < 1000) {
			strTemp = "部门经理同意" + MyConvertToString(fee) + "费用";
			return strTemp;
		}
		else {
			if (this->m_pHandle != nullptr) {
				return m_pHandle->handleFeeRequest(fee);
			}

		}
		return strTemp;

	}
};

class CEOManager :public Handle {
public:
	string handleFeeRequest(double fee) {
		string strTemp = "";
		if (fee >= 1000) {
			strTemp = "CEO经理同意" + MyConvertToString(fee) + "费用";
			return strTemp;
		}
		else {
			if (this->m_pHandle != nullptr) {
				return m_pHandle->handleFeeRequest(fee);
			}

		}
		return strTemp;

	}
};
int main(void) {
	//先要组装我们的责任链
	Handle* pH1 = new PrjManager;
	Handle* pH2 = new DepManager;
	Handle* pH3 = new CEOManager;
	pH1->setSuccessor(pH2);
	pH2->setSuccessor(pH3);
	cout << pH1->handleFeeRequest(128) << endl;
	cout << pH1->handleFeeRequest(512) << endl;
	cout << pH1->handleFeeRequest(1024) << endl;
	system("pause");
	return 0;
}
