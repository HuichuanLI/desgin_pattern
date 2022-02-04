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
using namespace std;

template <class T>
class Auto_Ptr;

//����ָ������ü���
template <class T>
class Ref_Ptr {
	friend class Auto_Ptr<T>;
private:
	T* m_pTtr;//ʵ�ʵ�ָ��
	size_t m_RefCount;//���ü���
	Ref_Ptr(T* p);
	virtual ~Ref_Ptr();
};

template<class T>
Ref_Ptr<T>::Ref_Ptr(T* p) {
	m_pTtr = p;
	m_RefCount = 1;
	cout << "Ref_Ptr()���캯������" << endl;
}

template<class T>
Ref_Ptr<T>::~Ref_Ptr() {
	if (m_pTtr) {
		cout << "��Ref_Ptr()������������" << endl;
		delete m_pTtr;
		m_pTtr = nullptr;
		m_RefCount = 0;
	}
	
	m_pTtr = nullptr;
}

//����ָ�����
template<class T>
class Auto_Ptr {
public:
	Auto_Ptr();
	Auto_Ptr(T* p);
	~Auto_Ptr();
	//���������
	Auto_Ptr<T> & operator = (Auto_Ptr& other);
	T& operator *();
	T* operator ->();
	//�������캯��
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
	cout << "Auto_ptr(T* p)���캯������" << endl;
}

template<class T>
Auto_Ptr<T>::Auto_Ptr(Auto_Ptr<T>& other) {
	m_pRef = ohter.m_pRef;
	++(m_pRef->m_RefCount);
	cout << "Auto_ptr(& other)�������캯������" << endl;
}

template<class T>
Auto_Ptr<T>& Auto_Ptr<T>::operator=(Auto_Ptr& other) {
	//���Ҳ�������Ӧ����+1
	++(other.m_pRef->m_RefCount);
	//�����������ָ�����¶������Խ�������-1
	//��ֹ�Ը�ֵ
	if (m_pRef) {
		if (--(m_pRef->m_RefCount) == 0) {
			delete m_pRef;
		}
	}
	m_pRef = other.m_pRef;
	printf("operator = �����ã���ǰ�����ü���:%d", m_pRef->m_RefCount);
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
	cout << "���������ڵ���" << endl;
	if ((--m_pRef->m_RefCount) == 0) {
		cout << "ɾ��" << endl;
		delete m_pRef;
		m_pRef = nullptr;
	}
}

int main(void) {
	Auto_Ptr<int>* pPtr = nullptr;
	{
		Auto_Ptr<int> g_ptr;
		{
			//����һ��ptr1������ָ��
			Auto_Ptr<int> ptr1(new int(4));
			printf("%d\n", *ptr1);
			//��������С��ptr1��ֵ�������ڸ����g_ptr;
			g_ptr = ptr1;
		}
		//new int(4)û������
		Auto_Ptr<int> ptr2(new int(3));
		g_ptr = ptr2;//g-ptr --> �µ�����ָ�� 
		Auto_Ptr<int>* pPtr = &ptr2;
		printf("%d\n", *(*pPtr));
	}
	system("pause");
	return 0;
}