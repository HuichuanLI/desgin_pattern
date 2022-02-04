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
using namespace std;

//������ģʽ�����Ľ���˫�طַ���������̬��accept��visit

class XiaoMi;
class HuaWei;
class Oppo;
class CellPhoneVisitor {
public:
	virtual void visit(XiaoMi* p) = 0;
	virtual void visit(HuaWei* p) = 0;
	virtual void visit(Oppo* p) = 0;
protected:
	CellPhoneVisitor(){}
};


class CellPhone {
public:
	virtual void dial() = 0;
	virtual void sendMsg() = 0;
	virtual void hang() = 0;
	virtual void recvMsg() = 0;
	virtual void accept(CellPhoneVisitor* p) = 0;
	//Solarisϵͳ-->
	//Win7/win10
	//Mac
protected:
	CellPhone(){}
};

class XiaoMi :public CellPhone {
public:
	void dial() { cout << "С��" << "�ڲ���" << endl; }
	void sendMsg() { cout << "С��" << "�ڷ�����" << endl; }
	void hang() { cout << "С��" << "�ڹضϵ绰" << endl; }
	void recvMsg() { cout << "С��" << "���ն���" << endl; }
	void accept(CellPhoneVisitor* p) {
		p->visit(this);
	}
};

class HuaWei :public CellPhone {
public:
	void dial() { cout << "HuaWei" << "�ڲ���" << endl; }
	void sendMsg() { cout << "HuaWei" << "�ڷ�����" << endl; }
	void hang() { cout << "HuaWei" << "�ڹضϵ绰" << endl; }
	void recvMsg() { cout << "HuaWei" << "���ն���" << endl; }
	void accept(CellPhoneVisitor* p) {
		p->visit(this);
	}
};

class Oppo :public CellPhone {
public:
	void dial() { cout << "Oppo" << "�ڲ���" << endl; }
	void sendMsg() { cout << "Oppo" << "�ڷ�����" << endl; }
	void hang() { cout << "Oppo" << "�ڹضϵ绰" << endl; }
	void recvMsg() { cout << "Oppo" << "���ն���" << endl; }
	void accept(CellPhoneVisitor* p) {
		p->visit(this);
	}
};

class SolarisConfigure : public CellPhoneVisitor {
public:
	void visit(XiaoMi *p) {
		p->dial();
		p->hang();
		p->sendMsg();
		p->recvMsg();
	}

	void visit(HuaWei *p) {
		p->dial();
		p->hang();
		p->sendMsg();
		p->recvMsg();
	}
	void visit(Oppo *p) {
		p->dial();
		p->hang();
		p->sendMsg();
		p->recvMsg();
	}
};

int main(void) {
	CellPhoneVisitor* pVisitor = new SolarisConfigure;
	XiaoMi* pXiaoMi = new XiaoMi;
	HuaWei* pHuaWei = new HuaWei;
	Oppo* pOppo = new Oppo;
	cout << "��Solairs�������ø�XiaoMi" << endl;
	pXiaoMi->accept(pVisitor);
	cout << "��Solairs�������ø�HuaWei" << endl;
	pHuaWei->accept(pVisitor);
	cout << "��Solairs�������ø�Oppo" << endl;
	pOppo->accept(pVisitor);
	system("pause");
	return 0;
}