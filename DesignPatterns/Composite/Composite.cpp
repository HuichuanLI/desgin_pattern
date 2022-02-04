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
//#include <list>
//#include <string>
//using namespace std;
//
////component
//class IFile {
//public:
//	virtual void displaye() = 0;
//	virtual int add(IFile* iFile) = 0;
//	virtual int remove(IFile *iFile) = 0;
//	virtual list<IFile*>* getChild() = 0;
//};
//
////Leaf
//class File :public IFile {
//public:
//	File(string name):m_name(name){}
//	virtual void displaye() {
//		cout << m_name << endl;
//	}
//
//	virtual int add(IFile* ifile) {
//		return -1;
//	}
//
//	virtual int remove(IFile* ifile) {
//		return -1;
//	}
//
//	virtual list<IFile*>* getChild() {
//		return NULL;
//	}
//private:
//	string m_name;
//
//};
//
////Ŀ¼��Composite
//class Dir :public IFile {
//public:
//	Dir(string name) :m_name(name) {
//		m_list = new list<IFile*>;
//	}
//
//	virtual void displaye() {
//		cout << m_name << endl;
//	}
//	
//	virtual int add(IFile* ifile) {
//		m_list->push_back(ifile);
//		return 0;
//	}
//
//	virtual int remove(IFile* ifile) {
//		m_list->remove(ifile);
//		return 0;
//	}
//
//	virtual list<IFile*> * getChild() {
//		return m_list;
//	}
//private:
//	string m_name;
//	list<IFile*> *m_list;
//};
//
//void showTree(IFile* root, int level) {
//	if (root == NULL)
//		return;
//	int i = 0;
//	for (i = 0;i < level;i++) {
//		printf("\t");
//	}
//
//	root->displaye();
//	list<IFile*> *list1 = root->getChild();
//	if (list1 != NULL) {
//		for (list<IFile*>::iterator iter = list1->begin();iter != list1->end();iter++) {
//			if ((*iter)->getChild() == NULL) {
//				//�����ļ�
//				for (i = 0;i < level;i++) {
//					printf("\t");
//				}
//				(*iter)->displaye();
//			}
//			else {
//				showTree(*iter, level + 1);
//			}
//		}
//	}
//}
//
//int main(void) {
//
//	Dir* root = new Dir("C:");
//	Dir* dir1 = new Dir("Program Files");
//	Dir* dir2 = new Dir("windows");
//
//	File* file1 = new File("a.txt");
//	File* file2 = new File("1.c");
//
//	root->add(dir1);
//	root->add(file1);
//	dir1->add(file2);
//	dir1->add(dir2);
//	list<IFile*> *list1 = root->getChild();
//	showTree(root, 0);
//	
//
//
//
//	system("pause");
//	return 0;
//}