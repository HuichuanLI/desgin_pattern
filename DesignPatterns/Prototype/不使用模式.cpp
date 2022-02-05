//#include <iostream>
//#include <string>
//#include <sstream>
//#include <typeinfo>
//using namespace std;
//template <class T>
//string iToStr(T value) {
//	stringstream ss;
//	ss << value;
//	return ss.str();
//}
//class OrderApi {
//public:
//	virtual int getOrderProductNum() = 0;
//	virtual void setOrderProductNum(int num) = 0;
//	virtual string getOrderContent() = 0;
//protected:
//	OrderApi(){}
//};
//
//class HomeOrder : public OrderApi {
//public:
//	int getOrderProductNum() {
//		return m_orderProductNum ;
//	}
//	void setOrderProductNum(int num) {
//		m_orderProductNum = num;
//	}
//	string getOrderContent() {
//		return "���ζ����Ŀͻ���" + m_strCustomerName +"������id" + m_strProductId+ "������������" + iToStr(m_orderProductNum);
//	}
//
//	void setCustomerName(string strCustomerName) {
//		m_strCustomerName = strCustomerName;
//	}
//
//	string getCustomerName() {
//		return m_strCustomerName;
//	}
//
//	void setProductId(string strProductId) {
//		m_strProductId = strProductId;
//	}
//	string getProductId() {
//		return m_strProductId;
//	}
//private:
//	string m_strCustomerName;
//	string m_strProductId;
//	int m_orderProductNum;
//};
//
//class AboardOrder : public OrderApi {
//public:
//	int getOrderProductNum() {
//		return m_orderProductNum;
//	}
//	void setOrderProductNum(int num) {
//		m_orderProductNum = num;
//	}
//	string getOrderContent() {
//		return "���ζ����Ŀͻ���" + m_strCustomerName + "������id" + m_strProductId + "������������" + iToStr(m_orderProductNum);
//	}
//
//	void setCustomerName(string strCustomerName) {
//		m_strCustomerName = strCustomerName;
//	}
//
//	string getCustomerName() {
//		return m_strCustomerName;
//	}
//
//	void setProductId(string strProductId) {
//		m_strProductId = strProductId;
//	}
//	string getProductId() {
//		return m_strProductId;
//	}
//private:
//	string m_strCustomerName;
//	string m_strProductId;
//	int m_orderProductNum;
//};
//
//class OrderBusiness {
//public:
//	void saveOrder(OrderApi* pOrder);
//};
//
//void OrderBusiness::saveOrder(OrderApi* pOrder) {
//	//�ж�һ�£��������������޳���200
//	while (pOrder->getOrderProductNum() > 200) {
//		//�½�һ������
//		OrderApi* pNewOrder = nullptr;
//		if (dynamic_cast<HomeOrder*>(pOrder) != nullptr) {
//			//����һ���¶���ȥ�ݴ����ǵ�Ŀ��
//			HomeOrder* p2 = new HomeOrder;
//			//��ֵ����
//			HomeOrder* p1 = static_cast<HomeOrder*>(pOrder);
//			p2->setOrderProductNum(200);
//			p2->setCustomerName(p1->getCustomerName());
//			p2->setProductId(p1->getProductId());
//			pNewOrder = p2;
//		}
//		//���ⶩ��
//		if (dynamic_cast<AboardOrder*>(pOrder) != nullptr) {
//			//����һ���¶���ȥ�ݴ����ǵ�Ŀ��
//			AboardOrder* p2 = new AboardOrder;
//			//��ֵ����
//			AboardOrder* p1 = static_cast<AboardOrder*>(pOrder);
//			p2->setOrderProductNum(200);
//			p2->setCustomerName(p1->getCustomerName());
//			p2->setProductId(p1->getProductId());
//			pNewOrder = p2;
//		}
//		//ԭ���Ķ��������Ǳ����ģ�ֻ�ǣ�����Ҫ����200
//		pOrder->setOrderProductNum(pOrder->getOrderProductNum() - 200);
//		cout << "�¶�����"<<pNewOrder->getOrderContent() << endl;
//	}
//	//������200��
//	cout << "���յĶ�����" << pOrder->getOrderContent() << endl;
//}
//
//int main(void) {
//	HomeOrder* pHome = new HomeOrder;
//	pHome->setOrderProductNum(512);
//	pHome->setCustomerName("xcj&dst");
//	pHome->setProductId("C++���ģʽ����");
//	OrderBusiness* pOb = new OrderBusiness();
//	pOb->saveOrder(pHome);
//	system("pause");
//	return 0;
//}
//
