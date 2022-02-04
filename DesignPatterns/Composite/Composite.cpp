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
////目录：Composite
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
//				//这是文件
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