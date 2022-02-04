/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               ������������ �Ĳܿ����˴��������Ϊѧϰ�ο�                **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Project       : C++���ģʽ����ʵս
** Description   : DesignPatterns
** Contact       : xiacaojun@qq.com
**  ����   : http://blog.csdn.net/jiedichina
**	��Ƶ�γ� : �����ƿ���	http://study.163.com/u/xiacaojun		
			   ��Ѷ����		https://jiedi.ke.qq.com/				
			   csdnѧԺ		http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961	
**             51ctoѧԺ	http://edu.51cto.com/lecturer/index/user_id-12016059.html	
** 			   ���Ŀ���		http://www.laoxiaketang.com 
**                 
**   C++���ģʽ����ʵս �γ�Ⱥ ��726114806 ����Ⱥ���ش���ͽ���
**   ΢�Ź��ں�  : jiedi2007
**		ͷ����	 : �Ĳܿ�
**
*******************************************************************************/
//������������������ ��C++���ͱ����STL����ʵս  QQȺ��726114806���ش���ͽ���
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

//����ĳ�����,�淶�˻��Ĵ������������
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
			strTemp = "��Ŀ����ͬ��" + MyConvertToString(fee) + "����";
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
			strTemp = "���ž���ͬ��" + MyConvertToString(fee) + "����";
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
			strTemp = "CEO����ͬ��" + MyConvertToString(fee) + "����";
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
	//��Ҫ��װ���ǵ�������
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
