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
//#include <iostream>
//using namespace std;
//class ThreePhaseOutlet {
//public:
//	void doThreePhasePlug() {
//		cout << "�����ͷ����" << endl;
//	}
//};
//
//class TwoPhaseOutlet {
//public:
//	virtual void doPlug() = 0;
//};
//
//class OutletConverter :public TwoPhaseOutlet, public ThreePhaseOutlet {
//public:
//	void doPlug() {
//		doConvertor();
//		doThreePhasePlug();
//	}
//	void doConvertor() {
//		cout << "�������ڽ������ͷתΪ�����ͷ" << endl;
//	}
//};
//
////�������䣬�����Ը������һЩ
//class OutletObjConvertor :public TwoPhaseOutlet {
//public:
//	OutletObjConvertor(ThreePhaseOutlet* pOut) :m_pOut(pOut) {
//
//	}
//	void doPlug() {
//		doConvert();
//		m_pOut->doThreePhasePlug();
//	}
//	void doConvert() {
//		cout << "�������ڶ�һ�������ͷ�������ת��" << endl;
//	}
//private:
//	ThreePhaseOutlet* m_pOut;
//};
//
//int main(void) {
//	/*TwoPhaseOutlet* pOutlet = new OutletConverter();
//	pOutlet->doPlug();*/
//	TwoPhaseOutlet* pOutlet = new OutletObjConvertor(new ThreePhaseOutlet);
//	pOutlet->doPlug();
//	system("pause");
//	return 0;
//}