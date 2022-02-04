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
using namespace std;

//class OriginalWord {
//public:
//	//setMsg�����ĳ��ԣ�Ϊ��������Ϣ������
//	void setMsg(string msg) {
//		this->m_strWrod = msg;
//	}
//
//	//������Ϣ:msg������ʲô����Ӧ�����ҵ�ǰ��OrigianlWordһ��ʵ��
//	//�����ʵ�������msgȥ����Ŀ��OrgianlWord��ʵ����msg
//	void retreatMsg(string msg) {
//		this->m_strWrod = msg;
//	}
//
//private:
//	string m_strWrod;
//};

class OriginalWord;
class Memento {
public:
	Memento(string strWord):m_strWord(strWord){}
private:
	friend class OriginalWord;
	string GetWords() {
		return m_strWord;
	}
	string m_strWord;
};

class OriginalWord {
public:
	OriginalWord(string myWord):m_strWord(myWord){}
	//�浵
	Memento* saveWords() {
		return new Memento(m_strWord);
	}

	//�ָ��浵
	void recycleWords(Memento *pMemento) {
		m_strWord = pMemento->GetWords();
		cout << "�浵�ָ��ɹ�" << endl;
	}

	//�������
	void showWords() {
		cout << m_strWord << endl;
	}
private:
	string m_strWord;
};

//�������ÿ��գ���ÿ���
class Caretake {
public:
	void setMemento(Memento* pMem) {
		m_pMemento = pMem;
	}
	Memento* GetMemento() {
		return m_pMemento;
	}
private:
	Memento* m_pMemento;
};
int main() {
	OriginalWord *pWordFst = new OriginalWord("��������ѧ����");
	//��һ����Ϣ
	cout << "��һ��msg" << endl;
	pWordFst->showWords();

	Caretake *pCT = new Caretake;
	pCT->setMemento(pWordFst->saveWords());
	//�����˵�ǰFst�Ŀ���
	cout << "�����˵�ǰFst�Ŀ���" << endl;
	OriginalWord *pWordSec = new OriginalWord("��ֵ��н������");
	cout << "�ڶ���Msg" << endl;
	pWordSec->showWords();
	OriginalWord* pWordThd = new OriginalWord("����ʦ����Ҳ����,");
	cout << "������Msg" << endl;
	pWordThd->showWords();
	cout << "�������ڶ࿴�����ĺ��϶����¿γ̣��һ����뿴������ʦ���¿γ�"<<endl;
	//��������Ҫ���ݵ�ĳһ��״̬��ʱ��������Ҫ��CareTake�����õ��Ŀ���
	pWordFst->recycleWords(pCT->GetMemento());
	pWordFst->showWords();
	system("pause");
	return 0;
}