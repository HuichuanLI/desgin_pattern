
#include <iostream>
#include <string>
using namespace std;
class ExportFileApi {
public:
	virtual bool exportData(string data) = 0;
protected:
	ExportFileApi(){}
};

//���廯������
class ExportTxtFile : public ExportFileApi {
public:
	bool exportData(string data) {
		cout << "���ڵ�������" << data << "��csv�ļ�" << endl;
		return true;
	}
};

//�������ݵ����ݿ�
class ExportDB :public ExportFileApi {
public:
	bool exportData(string data) {
		cout << "���ڵ�������" << data << "�����ݿ�" << endl;
		return true;
	}
};

//ʵ��һ��ExportOperate,����е������ݵ�ҵ���ܶ���
class ExportOperate {//��Ҳ�ǽӿ�
public:
	bool exportData(string data) {
		ExportFileApi* pApi = factoryMethod();
		return pApi->exportData(data);
	}
protected:
	virtual ExportFileApi* factoryMethod() = 0;
};

//�����ʵ�ֶ�����ɵ�������
class ExportTxtFileOperate : public ExportOperate {
protected:
	ExportFileApi* factoryMethod() {
		return new ExportTxtFile();
	}
};

class ExportDBOperate :public ExportOperate {
protected:
	ExportFileApi* factoryMethod() {
		return new ExportDB;
	}
};

int main() {
	ExportOperate* pOperate = new ExportTxtFileOperate();
	pOperate->exportData("Haha");
	system("pause");
	return 0;
}