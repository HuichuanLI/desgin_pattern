
#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

class Singleton;
static std::map<string, Singleton*> myMap = std::map<string, Singleton*>();

class Singleton {
private:
	Singleton() {
		m_singer = NULL;
		cout <<"单例执行" << endl;
	}
public:
	static Singleton* getInstance() {
		//std::map<std::string, int>::iterator it = myMap.find(DEFAULT_KEY);
		if (myMap.find(DEFAULT_KEY) != myMap.end())
			return myMap.find(DEFAULT_KEY)->second;
		if (m_singer == NULL) {
			m_singer = new Singleton;
			myMap[DEFAULT_KEY] = m_singer;
		}
		return m_singer;
	}

private:
	static Singleton *m_singer;
	static string DEFAULT_KEY;
};
Singleton *Singleton::m_singer = NULL;
string Singleton::DEFAULT_KEY = "One";

int main() {
	Singleton* p1 = Singleton::getInstance();
	Singleton* p2 = Singleton::getInstance();
	printf("p1's addr=%x,p2's addr=%x\n", p1, p2);
//	system("pause");
	return 0;
}
