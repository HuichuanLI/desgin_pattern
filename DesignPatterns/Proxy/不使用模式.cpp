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
//map<int, vector<string>> Logs;
////�зֵ��е����룬�ൽlogs��Ӧ�������
//vector<string> getBugs(string words) {
//	vector<string> results;
//	istringstream ss(words);
//	while (!ss.eof())
//	{
//		string word;
//		getline(ss, word, '|');
//		results.push_back(word);
//	}
//	return results;
//}
//
//bool getLogs() {
//	ifstream in("e:\\tmp\\�����б�.txt");
//	if (!in) {
//		cerr << "�ļ��򿪴���" << endl;
//		system("pause");
//		return -1;
//	}
//
//	string line;
//	int i = 0;
//	while (getline(in, line)) {
//		Logs[i]=getBugs(line);
//		i++;
//	}
//	in.close();
//
//	return 0;
//}
//
//int main(void) {
//	getLogs();//��ȡ��־�ļ�
//	for (int i = 0;i < Logs.size();i++) {
//		cout << "��" << i << "����";
//		for (vector<string>::iterator iter = Logs[i].begin();iter != Logs[i].end();iter++) {
//			cout << (*iter) << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}