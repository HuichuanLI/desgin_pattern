
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

template<class T>
string ConvertToString(T value) {
	stringstream ss;
	ss << value;
	return ss.str();
}

class ExportHeaderModel {
public:
	ExportHeaderModel(string strDepId, string strExportDate) : m_strDepId(strDepId), m_strExportDate(strExportDate) {

	}
	string getDepId() {
		return m_strDepId;
	}
	string getExportDate() {
		return m_strExportDate;
	}
private:
	string m_strDepId;//���˵��Ĳ���id
	string m_strExportDate;//���˵��ĵ�������
};


class ExportDataModel {
public:
	ExportDataModel(string strTransId, double Quantity) : m_strTransId(strTransId), m_Quantity(Quantity) {

	}
	string getTransId() {
		return m_strTransId;
	}
	double getQuantity() {
		return m_Quantity;
	}
private:
	string m_strTransId;//����Id
	double m_Quantity;
};

class ExportFooterModel {
public:
	ExportFooterModel(string exportUser): m_exportUser(exportUser){}
	string getExportUser() {
		return m_exportUser;
	}
private:
	string m_exportUser;
};

//���ǵ�������һ���������ڣ������ж�ʵĽ��׼�¼��������vecter

class ExportToTxtHelper {
public:
	void doExport(ExportHeaderModel& ehm, vector < ExportDataModel*>& edmCollection, ExportFooterModel& efm);
};

void ExportToTxtHelper::doExport(ExportHeaderModel& ehm, vector < ExportDataModel*>& edmCollection, ExportFooterModel& efm) {
	//��һ���ַ���ƴ��
	string strTemp = "";
	//��һ����д�ļ�ͷ
	strTemp += ehm.getDepId() + "," + ehm.getExportDate() + "\n";
	//�ڶ�����д�ļ�������
	for (vector<ExportDataModel*>::iterator iter = edmCollection.begin();iter != edmCollection.end();iter++) {
		strTemp += (*iter)->getTransId() + ":" + ConvertToString((*iter)->getQuantity()) + "\n";
	}
	//��������ƴ���ļ�β��
	strTemp += efm.getExportUser() + "\n";
	cout << strTemp;
}

class ExportToXmlHelper {
public:
	void doExport(ExportHeaderModel& ehm, vector < ExportDataModel*>& edmCollection, ExportFooterModel& efm);

};
void ExportToXmlHelper::doExport(ExportHeaderModel& ehm, vector < ExportDataModel*>& edmCollection, ExportFooterModel& efm) {
	string strTemp = "";
	//��һ��ƴ��ͷ
	strTemp.append("<?xml version='1.0' encoding='utf-8'>\n");
	strTemp.append("<Receipt>\n");
	strTemp.append("    <Header>\n");
	strTemp.append("        <DepId>");
	strTemp.append(ehm.getDepId() + "</DepId>\n");
	strTemp.append("        <ExportDate>" + ehm.getExportDate() + "</ExportDate>\n");
	strTemp.append("    </Header>\n");
	//�ڶ�������������
	strTemp.append("    <Body>\n");
	for (vector<ExportDataModel*>::iterator iter = edmCollection.begin();iter != edmCollection.end();iter++) {
		strTemp.append("        <id>" + (*iter)->getTransId() + "</id>\n");
		strTemp.append("        <amount>" + ConvertToString((*iter)->getQuantity()) + "</amount>\n");
	}
	strTemp.append("    </Body>\n");
	//����:ƴ���ļ�β��
	strTemp.append("    <Footer>\n");
	strTemp.append("        <ExportUser>" + efm.getExportUser() + "</ExportUser>\n");
	strTemp.append("    </Footer>\n</Receipt>\n");
	cout << strTemp;
}


int main(void) {
	ExportHeaderModel* pEhm = new ExportHeaderModel("�Ͼ�1֧��", "6��1��");
	ExportDataModel* pEdm = new ExportDataModel("1", 10000.00f);
	ExportDataModel* pEdm2 = new ExportDataModel("2", 20000.00f);
	vector<ExportDataModel*> myVec;
	myVec.push_back(pEdm);
	myVec.push_back(pEdm2);
	ExportFooterModel* pEfm = new ExportFooterModel("xcj");

	//ExportToTxtHelper helper;
	ExportToXmlHelper helper;
	helper.doExport(*pEhm, myVec, *pEfm);
	system("pause");
	return 0;
}
