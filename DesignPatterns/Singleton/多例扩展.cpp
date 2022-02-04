#include <string>
#include <stdio.h>
#include <map>
#include <iostream>
using namespace std;

const static int NUM_MAX = 5;
class Singleton;
static std::map<int, Singleton*> myMap = std::map<int, Singleton*>();

class Singleton {
private:
	Singleton() {
		m_singer = NULL;
		cout << "正在构建Single" << endl;
	}
public:
	static Singleton* getInstance() {
		m_singer = myMap[m_InstanceCount];

		if (m_singer == NULL) {
			m_singer = new Singleton;
			myMap[m_InstanceCount] = m_singer;
		}
		m_InstanceCount++;
		if (m_InstanceCount > NUM_MAX) {
			m_InstanceCount = 1;
		}
		return m_singer;

	}
private:
	static Singleton *m_singer;
	static int m_InstanceCount;//���ʵ���ĸ���
};

Singleton *Singleton::m_singer = NULL;
int Singleton::m_InstanceCount = 1;//��ʼ����ʵ������

int main() {
	Singleton* p1 = Singleton::getInstance();
	Singleton* p2 = Singleton::getInstance();
	Singleton* p3 = Singleton::getInstance();
	Singleton* p4 = Singleton::getInstance();
	Singleton* p5 = Singleton::getInstance();
	printf("p1=%x,p2=%x,p3=%x,p4=%x,p5=%x\n", p1, p2, p3, p4, p5);
	Singleton* p6 = Singleton::getInstance();
	Singleton* p7 = Singleton::getInstance();
	Singleton* p8 = Singleton::getInstance();
	Singleton* p9= Singleton::getInstance();
	Singleton* p10 = Singleton::getInstance();
	printf("p6=%x,p7=%x,p8=%x,p9=%x,p10=%x\n", p6, p7, p8, p9, p10);
	system("pause");
	return 0;
}