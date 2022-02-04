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
#include <iostream>
#include <string>
#include <map> //�û������û�������
using namespace std;

class DownloadManager;
class DownState {
public:
	virtual void Down(string User, string DownItem, DownloadManager* p) = 0;
protected:
	DownState(){}
};

class NormalDownState :public DownState{
public:
	void Down(string User, string DownItem, DownloadManager* p) {
		cout << "��ӭ�����ر���Դ" << endl;
	}
};
class RepeateDownState :public DownState {
public:
	void Down(string User, string DownItem, DownloadManager* p) {
		cout << "�벻Ҫ�ظ�����" << endl;
	}
};

class SpiteDownState :public DownState {
public:
	void Down(string User, string DownItem, DownloadManager* p) {
		cout << "���ж������ص����ɣ�����ȡ�������ʸ�" << endl;
	}
};

class BlackDownState :public DownState {
public:
	void Down(string User, string DownItem, DownloadManager* p) {
		cout << "�������ع���Ƶ�������������������ֹ��¼��ϵͳ" << endl;
	}
};

class DownloadManager {
public:
	map<string, string> getMapDown() {
		return m_mapDown;
	}
	void Down(string User, string DownItem) {
		int oldDownCount = 0;
		if (m_mapDownCount.count(User) > 0) {
			oldDownCount = m_mapDownCount[User];
		}
		else {
			m_mapDownCount[User] = 0;
		}
		oldDownCount++;
		m_mapDownCount[User] = oldDownCount;
		if (oldDownCount == 1) {
			m_pState = new NormalDownState();
		}
		else if (oldDownCount > 1 && oldDownCount < 3) {
			m_pState = new RepeateDownState();
		}
		else if (oldDownCount >= 3 && oldDownCount < 5) {
			m_pState = new SpiteDownState();
		}
		else if (oldDownCount >= 5) {
			m_pState = new BlackDownState();
		}
		m_pState->Down(User, DownItem, this);
	}
private:
	DownState* m_pState;//����״̬�������
	map<string, string> m_mapDown;
	map<string, int> m_mapDownCount;
};

int main(void) {
	DownloadManager* pVM = new DownloadManager;
	for (int i = 0;i < 5;i++) {
		pVM->Down("dst", "���ģʽ��ȫ�ֲ�C++��������");
	}
	system("pause");
	return 0;
}