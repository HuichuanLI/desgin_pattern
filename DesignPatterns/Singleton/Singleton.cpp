
#include <afxwin.h>
#include <iostream>
#include <stdio.h>
using namespace std;

CRITICAL_SECTION g_cs;
class Singleton {
private:
	Singleton() {
		m_singer = NULL;
		cout << "����һ��Singleton����" << endl;
	}
public:
	static Singleton* getInstance() { //����ʽ:�ӳټ���
		if (m_singer == NULL) {
			::EnterCriticalSection(&g_cs);
			if(m_singer == NULL)
			m_singer = new Singleton;
			::LeaveCriticalSection(&g_cs);
		}
		return m_singer;
	}
private:
	static Singleton* m_singer;
};

UINT Func(LPVOID) {
	printf("%x\n", Singleton::getInstance());
	return 0;
}
Singleton *Singleton::m_singer = NULL;//new Singleton; ��C++�й��캯�������̰߳�ȫ��
int main(void) {
	//Singleton *p = new Singleton;
	/*Singleton* p1 = Singleton::getInstance();
	Singleton* p2 = Singleton::getInstance();
	printf("p1=%x,p2=%x", p1, p2);*/
	::InitializeCriticalSection(&g_cs);
	for (int i = 0;i < 10;i++) {
		AfxBeginThread(Func, NULL);
	}
	::DeleteCriticalSection(&g_cs);
	system("pause");
	return 0;
}