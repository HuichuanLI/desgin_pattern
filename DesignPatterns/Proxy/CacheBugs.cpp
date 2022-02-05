#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

map<int, vector<string>> Cache;

class BugManager {
public:
	virtual void getBug() = 0;
};

class RealBugModel {
public:
	void getBugs() {
		ifstream in("/Users/hui/Desktop/c++/desgin_pattern/DesignPatterns/Proxy/故障列表.txt");
		if (!in) {
			cerr << "文件打开错误" << endl;
		}
		string line;
		int i = 0;
		while (getline(in, line)) {
			Cache[i] = getCache(line);
			i++;
		}
		in.close();
	}
private:
	vector<string> getCache(string words) {
		vector<string> results;
		istringstream ss(words);
		while (!ss.eof())
		{
			string word;
			getline(ss, word, '|');
			results.push_back(word);
		}
		return results;
	}
};

class ProxyBugModel {
public:
	ProxyBugModel() :m_reload(false) {

	}
	void getBugs() {
		if (m_reload) {
			cout << "从内存" << endl;
			showBugs();
		}
		else {
			cout << "重新读bug" << endl;
			(new RealBugModel())->getBugs();
			m_reload = true;
			showBugs();
		}
	}
private:
	void showBugs() {
		for (int i = 0;i < Cache.size();i++) {
			cout << "第" << i << "行";
			for (vector<string>::iterator iter = Cache[i].begin();iter != Cache[i].end();iter++) {
				cout << (*iter) << " ";
			}
			cout << endl;
		}
	}
private:
	bool m_reload;//���reloadΪ�棬��ʾ������Ǵӻ��������õģ�������������������realbug����
};



int main() {
	ProxyBugModel* p = new ProxyBugModel();
	for (int i = 0;i < 5;i++) {
		cout << " 第"<< i << "问题" << endl;
		p->getBugs();
	}

	system("pause");
	return 0;
}