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
#include <typeinfo>
using namespace std;
template <class T>
string iToStr(T value) {
	stringstream ss;
	ss << value;
	return ss.str();
}
class OrderApi {
public:
	virtual int getOrderProductNum() = 0;
	virtual void setOrderProductNum(int num) = 0;
	virtual string getOrderContent() = 0;
	virtual OrderApi* cloneOrder() = 0;
protected:
	OrderApi() {}
};

class HomeOrder : public OrderApi {
public:
	int getOrderProductNum() {
		return m_orderProductNum;
	}
	void setOrderProductNum(int num) {
		m_orderProductNum = num;
	}
	string getOrderContent() {
		return "本次订单的客户是" + m_strCustomerName + "订单的id" + m_strProductId + "订单的数量是" + iToStr(m_orderProductNum);
	}

	void setCustomerName(string strCustomerName) {
		m_strCustomerName = strCustomerName;
	}

	string getCustomerName() {
		return m_strCustomerName;
	}

	void setProductId(string strProductId) {
		m_strProductId = strProductId;
	}
	string getProductId() {
		return m_strProductId;
	}

	//重构
	OrderApi* cloneOrder();
private:
	string m_strCustomerName;
	string m_strProductId;
	int m_orderProductNum;
};

OrderApi* HomeOrder::cloneOrder() {
	
	HomeOrder *pHomeOrder = new HomeOrder;
	pHomeOrder->setCustomerName(m_strCustomerName);
	pHomeOrder->setProductId(m_strProductId);
	pHomeOrder->setOrderProductNum(m_orderProductNum);
	return pHomeOrder;
}


class AboardOrder : public OrderApi {
public:
	int getOrderProductNum() {
		return m_orderProductNum;
	}
	void setOrderProductNum(int num) {
		m_orderProductNum = num;
	}
	string getOrderContent() {
		return "本次订单的客户是" + m_strCustomerName + "订单的id" + m_strProductId + "订单的数量是" + iToStr(m_orderProductNum);
	}

	void setCustomerName(string strCustomerName) {
		m_strCustomerName = strCustomerName;
	}

	string getCustomerName() {
		return m_strCustomerName;
	}

	void setProductId(string strProductId) {
		m_strProductId = strProductId;
	}
	string getProductId() {
		return m_strProductId;
	}
	//重构
	OrderApi* cloneOrder();
private:
	string m_strCustomerName;
	string m_strProductId;
	int m_orderProductNum;
};

OrderApi* AboardOrder::cloneOrder() {

	AboardOrder *pHomeOrder = new AboardOrder;
	pHomeOrder->setCustomerName(m_strCustomerName);
	pHomeOrder->setProductId(m_strProductId);
	pHomeOrder->setOrderProductNum(m_orderProductNum);
	return pHomeOrder;
}

class OrderBusiness {
public:
	void saveOrder(OrderApi* pOrder);
};

void OrderBusiness::saveOrder(OrderApi* pOrder) {
	//判读一下，工件的数量有无超过200
	while (pOrder->getOrderProductNum() > 200) {
		//新建一个订单
		OrderApi* pNewOrder = pOrder->cloneOrder();
		pNewOrder->setOrderProductNum(200);
		
		pOrder->setOrderProductNum(pOrder->getOrderProductNum() - 200);
		cout << "新订单是" << pNewOrder->getOrderContent() << endl;
	}
	//不超过200个
	cout << "最终的订单是" << pOrder->getOrderContent() << endl;
}

int main(void) {
	HomeOrder* pHome = new HomeOrder;
	pHome->setOrderProductNum(512);
	pHome->setCustomerName("xcj&dst");
	pHome->setProductId("C++设计模式精讲");
	OrderBusiness* pOb = new OrderBusiness();
	pOb->saveOrder(pHome);
	system("pause");
	return 0;
}

