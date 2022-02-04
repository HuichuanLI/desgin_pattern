//#include <iostream>
//#include <string>
//#include <list>
//using namespace std;
//
//class Leaf {
//public:/*******************************************************************************
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

//	Leaf(string name):m_name(name){}
//	void showStruct(string preStr) {
//		cout << preStr << "-" << m_name<<endl;
//	}
//private:
//	string m_name;
//};
//
////文件夹 
//class Composite {
//public:
//	Composite(string name):m_name(name){}
//	//加入组合对象
//	void addComposite(Composite* pCom) {
//		childComposite.push_back(pCom);
//	}
//	//加入叶子
//	void addLeaf(Leaf* pLeaf) {
//		childLeaf.push_back(pLeaf);
//	}
//
//	void showStruct(string preStr) {
//		//先输出自己
//		cout << preStr << "+" << m_name << endl;
//		//加一个空格，输出自己包含的叶子对象
//		preStr += " ";
//		for (list<Leaf*>::iterator iter = childLeaf.begin();iter != childLeaf.end();iter++) {
//			(*iter)->showStruct(preStr);
//		}
//		//输出当前对象 
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
//	//定义文件节点
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
//	//输出根对象以下的所有文件
//	pRoot->showStruct("");
//	system("pause");
//	return 0;
//}