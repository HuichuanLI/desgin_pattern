//#include <iostream>
//#include <string>
//#include <list>
//using namespace std;
//
//class Leaf {
//public:/*******************************************************************************
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

//	Leaf(string name):m_name(name){}
//	void showStruct(string preStr) {
//		cout << preStr << "-" << m_name<<endl;
//	}
//private:
//	string m_name;
//};
//
////�ļ��� 
//class Composite {
//public:
//	Composite(string name):m_name(name){}
//	//������϶���
//	void addComposite(Composite* pCom) {
//		childComposite.push_back(pCom);
//	}
//	//����Ҷ��
//	void addLeaf(Leaf* pLeaf) {
//		childLeaf.push_back(pLeaf);
//	}
//
//	void showStruct(string preStr) {
//		//������Լ�
//		cout << preStr << "+" << m_name << endl;
//		//��һ���ո�����Լ�������Ҷ�Ӷ���
//		preStr += " ";
//		for (list<Leaf*>::iterator iter = childLeaf.begin();iter != childLeaf.end();iter++) {
//			(*iter)->showStruct(preStr);
//		}
//		//�����ǰ���� 
//		for (list<Composite*>::iterator iter = childComposite.begin();iter != childComposite.end();iter++) {
//			(*iter)->showStruct(preStr);
//		}
//
//	}
//private:
//	string m_name;
//	list<Leaf*> childLeaf;
//	list<Composite*> childComposite;
//};
//
//int main(void) {
//	Composite* pRoot = new Composite("C:\\");
//	Composite* pC1 = new Composite("Program Files");
//	Composite* pC2 = new Composite("Windows");
//
//	//�����ļ��ڵ�
//	Leaf *pLeaf1 = new Leaf("a.txt");
//	Leaf *pLeaf2 = new Leaf("b.txt");
//
//	Leaf* pLeaf3 = new Leaf("1.c");
//	Leaf* pLeaf4 = new Leaf("2.c");
//
//	pRoot->addComposite(pC1);
//	pRoot->addComposite(pC2);
//	pC1->addLeaf(pLeaf1);
//	pC1->addLeaf(pLeaf2);
//
//	pC2->addLeaf(pLeaf3);
//	pC2->addLeaf(pLeaf4);
//
//	//������������µ������ļ�
//	pRoot->showStruct("");
//	system("pause");
//	return 0;
//}