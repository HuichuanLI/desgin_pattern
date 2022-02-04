
#include <string>
#include <map>
#include <memory>
#include <functional>
#include <iostream>
using namespace std;

template <class T>
class IocContainer {
public:
	IocContainer(void){}
	~IocContainer()
	{

	}
	//ע����Ҫ��������Ĺ��캯����ͨ��һ��Ψһ�ı�ʶ���Ա����Ժ����
	template<class Drived>
	void RegisterType(string strKey) {
		std::function<T* ()> function = [] {return new Drived();};
		RegisterType(strKey, function);
	}

	//����Ψһ�ı�ʶȥ���Ҷ�Ӧ�Ĺ��캯��
	T* Resolve(string strKey) {
		if (m_createMap.find(strKey) == m_createMap.end())
			return nullptr;
		std::function<T* ()> function = m_createMap[strKey];
		return function();
	}

	//��������ָ��
	std::shared_ptr<T> ResolveShared(string strKey) {
		T* ptr = Resolve(strKey);
		return std::shared_ptr<T>(ptr);
	}
private:
	void RegisterType(string strKey, std::function<T* ()> creator) {
		if (m_createMap.find(strKey) != m_createMap.end()) {
			throw std::invalid_argument("�Ѿ��������key��");
		}
		m_createMap.emplace(strKey, creator);
	}

private:
	map<string, std::function<T* ()>> m_createMap;
};

struct ICar {
	virtual ~ICar(){}
	virtual void test() const = 0;
};

struct Bus: ICar
{
	Bus(){}
	void test()const { std::cout << "Bus::test()"<<endl; }
};

struct Track :ICar {
	Track() {};
	void test() const { std::cout << "Track::test" << endl; }

};

int main() {
	IocContainer<ICar> carIOC;
	carIOC.RegisterType<Bus>("bus");
	carIOC.RegisterType<Track>("track");

	std::shared_ptr<ICar> bus = carIOC.ResolveShared("bus");
	bus->test();
std::shared_ptr<ICar> track = carIOC.ResolveShared("track");
	track->test();
	system("pause");
	return 0;
}