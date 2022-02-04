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
#include<iostream>
#include<vector>
#include <array>
using namespace std;

class MyVecMngr {
public:
	MyVecMngr(vector<int> myVec) :m_myVec(myVec) {

	}
	void showItems() {
		for (int i = 0;i < m_myVec.size();i++) {
			cout << m_myVec.at(i) << endl;
		}
	}
private:
	vector<int> m_myVec;
};

//
class MyArrayMngr {
public:
	MyArrayMngr(array<int,20> myArr) :m_myArr(myArr) {

	}
	void showItems() {
		for (int i = 0;i <  m_myArr.size();i++) {
			cout << m_myArr.at(i) << endl;
		}
	}
private:
	array<int,20> m_myArr;
};

int main() {
	vector<int> myVec;
	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(3);

	for (auto iter = myVec.begin();iter != myVec.end();iter++) {
		cout << *iter << endl;
	}
	cout << "////////////////" << endl;
	array<int, 3> myArr;
	myArr[0] = 1;
	myArr[1] = 2;
	myArr[2] = 3;
	for (auto iter = myArr.begin();iter != myArr.end();iter++)
		cout << *iter << endl;
	system("pause");
	return 0;
}