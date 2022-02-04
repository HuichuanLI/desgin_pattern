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
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <map>
//#include <vector>
//using namespace std;
//
////�зֳ�log:
/////        ������������ʱ�䣬��������
/////map<int,vector<string>>:int ���ϵ���ţ�Ȼ�����ǽ���Щ�� ������|����ʱ��|����������
//map<int, vector<string>> Cache;
//
//class BugManager {
//public:
//	virtual void getBug() = 0;
//};
//
//class RealBugModel {
//public:
//	void getBugs() {
//		//���ļ���ȡ�����ҽ�������Ϣ��װ����Cache��
//		ifstream in("e:\\tmp\\�����б�.txt");
//		if (!in) {
//			cerr << "�ļ��򿪴���" << endl;
//			system("pause");
//			
//		}
//		string line;
//		int i = 0;
//		while (getline(in, line)) {
//			Cache[i] = getCache(line);
//			i++;
//		}
//		in.close();
//	}
//private:
//	vector<string> getCache(string words) {
//		vector<string> results;
//		istringstream ss(words);
//		while (!ss.eof())
//		{
//			string word;
//			getline(ss, word, '|');
//			results.push_back(word);
//		}
//		return results;
//	}
//};
//
//class ProxyBugModel {
//public:
//	ProxyBugModel() :m_reload(false) {
//
//	}
//	void getBugs() {
//		if (m_reload) {
//			cout << "���Ǵӻ��������ȡ��" << endl;
//			showBugs();
//		}
//		else {
//			cout << "������ʵ������" << endl;
//			(new RealBugModel())->getBugs();
//			m_reload = true;
//			showBugs();
//		}
//	}
//private:
//	void showBugs() {
//		for (int i = 0;i < Cache.size();i++) {
//			cout << "��" << i << "����";
//			for (vector<string>::iterator iter = Cache[i].begin();iter != Cache[i].end();iter++) {
//				cout << (*iter) << " ";
//			}
//			cout << endl;
//		}
//	}
//private:
//	bool m_reload;//���reloadΪ�棬��ʾ������Ǵӻ��������õģ�������������������realbug����
//};
//
//
//
//int main(void) {
//	ProxyBugModel* p = new ProxyBugModel();
//	for (int i = 0;i < 5;i++) {
//		cout << "��" << i << "������" << endl;
//		p->getBugs();
//	}
//	
//	system("pause");
//	return 0;
//}