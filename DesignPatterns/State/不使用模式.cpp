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
//#include <map> //�û������û�������
//using namespace std;
//
//class DownloadManager {
//public:
//	void Down(string user, string DownItem) {
//		int oldDownCount = 0;
//		if (m_mapDownCount.count(user) > 0) {
//			oldDownCount = m_mapDownCount[user];
//		}
//		else {
//			m_mapDownCount[user] = 0;
//		}
//
//		oldDownCount++;
//		m_mapDownCount[user] = oldDownCount;
//
//		//�ж�����Ϊ
//		if (oldDownCount == 1) {
//			//��������
//			m_mapDown[user] = DownItem;
//			cout << "��ӭ�����ر���Դ" << endl;
//		}
//		else if(oldDownCount>1 && oldDownCount<3)
//		{
//			cout << "������Ҫ�ظ�����" << endl;
//		}
//		else if (oldDownCount >= 3 && oldDownCount < 5) {
//			//��������
//			cout << "���ж������ص����ɣ�����ȡ�����������ʸ�" << endl;
//		}
//		else if (oldDownCount >= 5) {
//			//���������
//			cout << "���ѽ������������ֹ��¼��ϵͳ" << endl;
//		}
//	}
//
//private:
//	map<string, string> m_mapDown;//<�û������û�����ѡ��>
//		map<string, int> m_mapDownCount;//<�û������û����ش���>
//};
//
//int main() {
//	DownloadManager* pDM = new DownloadManager;
//	for (int i = 0;i < 5;i++) {
//		pDM->Down("dst","���ģʽ��ȫ�ֲ�Դ����");
//	}
//	system("pause");
//	return 0;
//}