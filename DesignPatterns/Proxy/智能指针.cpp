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
using namespace std;

template <class T>
class Auto_Ptr;

//智能指针和引用计数
template <class T>
class Ref_Ptr {
	friend class Auto_Ptr<T>;
private:
	T* m_pTtr;//实际的指针
	size_t m_RefCount;//引用计数
	Ref_Ptr(T* p);
	virtual ~Ref_Ptr();
};

template<class T>
Ref_Ptr<T>::Ref_Ptr(T* p) {
	m_pTtr = p;
	m_RefCount = 1;
	cout << "Ref_Ptr()构造函数调用" << endl;
}

template<class T>
Ref_Ptr<T>::~Ref_Ptr() {
	if (m_pTtr) {
		cout << "～Ref_Ptr()析构函数调用" << endl;
		delete m_pTtr;
		m_pTtr = nullptr;
		m_RefCount = 0;
	}
	
	m_pTtr = nullptr;
}

//智能指针对象
template<class T>
class Auto_Ptr {
public:
	Auto_Ptr();
	Auto_Ptr(T* p);
	~Auto_Ptr();
	//运算符重载
	Auto_Ptr<T> & operator = (Auto_Ptr& other);
	T& operator *();
	T* operator ->();
	//拷贝构造函数
	Auto_Ptr(Auto_Ptr<T>& other);
private:
	Ref_Ptr<T>* m_pRef;
};

template<class T>
Auto_Ptr<T>::Auto_Ptr() {
	m_pRef = nullptr;
}

template<class T>
Auto_Ptr<T>::Auto_Ptr(T* p) {
	m_pRef = new Ref_Ptr<T>(p);
	cout << "Auto_ptr(T* p)构造函数调用" << endl;
}

template<class T>
Auto_Ptr<T>::Auto_Ptr(Auto_Ptr<T>& other) {
	m_pRef = ohter.m_pRef;
	++(m_pRef->m_RefCount);
	cout << "Auto_ptr(& other)拷贝构造函数调用" << endl;
}

template<class T>
Auto_Ptr<T>& Auto_Ptr<T>::operator=(Auto_Ptr& other) {
	//将右操作数对应引用+1
	++(other.m_pRef->m_RefCount);
	//由于左操作数指向了新对象，所以将操作数-1
	//防止自赋值
	if (m_pRef) {
		if (--(m_pRef->m_RefCount) == 0) {
			delete m_pRef;
		}
	}
	m_pRef = other.m_pRef;
	printf("operator = 被调用，当前的引用计数:%d", m_pRef->m_RefCount);
	return *this;
}

template <class T>
T& Auto_Ptr<T>::operator*() {
	return *(m_pRef->m_pTtr);
}

template <class T>
T* Auto_Ptr<T>::operator->() {
	return (m_pRef->m_pTtr);
}

template <class T>
Auto_Ptr<T>::~Auto_Ptr() {
	cout << "析构函数在调用" << endl;
	if ((--m_pRef->m_RefCount) == 0) {
		cout << "删除" << endl;
		delete m_pRef;
		m_pRef = nullptr;
	}
}

int main(void) {
	Auto_Ptr<int>* pPtr = nullptr;
	{
		Auto_Ptr<int> g_ptr;
		{
			//声明一个ptr1的智能指针
			Auto_Ptr<int> ptr1(new int(4));
			printf("%d\n", *ptr1);
			//将生存期小的ptr1赋值给生存期更大的g_ptr;
			g_ptr = ptr1;
		}
		//new int(4)没有销毁
		Auto_Ptr<int> ptr2(new int(3));
		g_ptr = ptr2;//g-ptr --> 新的智能指针 
		Auto_Ptr<int>* pPtr = &ptr2;
		printf("%d\n", *(*pPtr));
	}
	system("pause");
	return 0;
}