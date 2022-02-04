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
#include <windows.h>
using namespace std;

class CView {
public:
	virtual void Draw(void){}
};

//����װ����
class CDecorate :public CView {
public:
	CDecorate(CView *pView):m_pView(pView){}
	virtual void Draw(void) {
		m_pView->Draw();
	}

private:
	CView* m_pView;
};

class CScrollBars :public CDecorate {
public:
	CScrollBars(CView *pView):CDecorate(pView){}
protected:
	//���ƹ�����
	void DrawScrollBars() {
		cout << ">������һ��������" << endl;
	}
public:
	virtual void Draw() {
		CDecorate::Draw();
		DrawScrollBars();
	}
};

class CBorder :public CDecorate {
public:
	CBorder(CView *pView) :CDecorate(pView) {}
protected:
	//���ƹ�����
	void DrawBorder() {
		cout << ">������һ���߿�" << endl;
	}
public:
	virtual void Draw() {
		CDecorate::Draw();
		DrawBorder();
	}
};

//context->��Ҫ�ı�װ�ζ���
class CTextView :public CView {
public:
	CTextView(char* s) {
		SetWindowText(s);
	}
protected:
	virtual void DrawTextView() {
		cout << ">������һ���ı���ͼ,�ı�������Ϊ" << m_Text;
	}
protected:
	char m_Text[MAX_PATH];

public:
	virtual void Draw() {
		CView::Draw();
		DrawTextView();
	}

	void SetWindowText(char* s) {
		strcpy_s(m_Text, _countof(m_Text), s);
	}

	char* GetWindowText() {
		return m_Text;
	}
};

class CWindows {
public:
	CWindows() {
		ZeroMemory(m_arrWindow, sizeof(CView*) * 10);
	}
	void Draw(){
		for (int i = 0;i < 10;i++) {
			if (m_arrWindow[i] != NULL)
				m_arrWindow[i]->Draw();
		}
	}

	void AddControl(CView* pView) {
		for (int i = 0;i < 10;i++) {
			if (m_arrWindow[i] == NULL){
				m_arrWindow[i] = pView;
				break;
			}
		}
	}

	void RemoveControl(CView* pView) {
		for (int i = 0;i < 10;i++) {
			if (m_arrWindow[i] == pView) {
				m_arrWindow[i] = NULL;
				break;
			}
		}
	}
protected:
	CView* m_arrWindow[10];

};

int main(void) {
	//����һ�����ڶ���
	CWindows windowsObj;
	//����һ����ͨ���ı���ͼ
	CTextView TextView("����һ���ı���ͼ");

	windowsObj.AddControl(&TextView);
	windowsObj.Draw();
	cout << "*****************" << endl;
	windowsObj.RemoveControl(&TextView);
	CScrollBars* pScroll = new CScrollBars(&TextView);
	windowsObj.AddControl(pScroll);
	windowsObj.Draw();
	cout << "*****************" << endl;
	windowsObj.RemoveControl(pScroll);
	CBorder *pBorder = new CBorder(&TextView);
	windowsObj.AddControl(pBorder);
	windowsObj.Draw();
	system("pause");
	return 0;
}