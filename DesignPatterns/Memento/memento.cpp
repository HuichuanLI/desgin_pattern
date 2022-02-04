/*******************************************************************************
**                                                                            **
**                     Jiedi(China nanjing)Ltd.                               **
**	               创建：丁宋涛 夏曹俊，此代码可用作为学习参考                **
*******************************************************************************/

/*****************************FILE INFOMATION***********************************
**
** Project       : C++设计模式开发实战
** Description   : DesignPatterns
** Contact       : xiacaojun@qq.com
**  博客   : http://blog.csdn.net/jiedichina
**	视频课程 : 网易云课堂	http://study.163.com/u/xiacaojun		
			   腾讯课堂		https://jiedi.ke.qq.com/				
			   csdn学院		http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961	
**             51cto学院	http://edu.51cto.com/lecturer/index/user_id-12016059.html	
** 			   老夏课堂		http://www.laoxiaketang.com 
**                 
**   C++设计模式开发实战 课程群 ：726114806 加入群下载代码和交流
**   微信公众号  : jiedi2007
**		头条号	 : 夏曹俊
**
*******************************************************************************/
//！！！！！！！！！ 加C++泛型编程与STL开发实战  QQ群：726114806下载代码和交流
#include <iostream>
#include <string>
using namespace std;

//class OriginalWord {
//public:
//	//setMsg方法的初衷：为了设置消息的内容
//	void setMsg(string msg) {
//		this->m_strWrod = msg;
//	}
//
//	//撤销消息:msg究竟是什么？它应该是我当前的OrigianlWord一个实例
//	//用这个实例里面的msg去设置目标OrgianlWord的实例的msg
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
	//存档
	Memento* saveWords() {
		return new Memento(m_strWord);
	}

	//恢复存档
	void recycleWords(Memento *pMemento) {
		m_strWord = pMemento->GetWords();
		cout << "存档恢复成功" << endl;
	}

	//输出文字
	void showWords() {
		cout << m_strWord << endl;
	}
private:
	string m_strWord;
};

//用来设置快照，获得快照
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
	OriginalWord *pWordFst = new OriginalWord("跟着老夏学开发");
	//第一条消息
	cout << "第一个msg" << endl;
	pWordFst->showWords();

	Caretake *pCT = new Caretake;
	pCT->setMemento(pWordFst->saveWords());
	//保存了当前Fst的快照
	cout << "保存了当前Fst的快照" << endl;
	OriginalWord *pWordSec = new OriginalWord("升值加薪就找他");
	cout << "第二个Msg" << endl;
	pWordSec->showWords();
	OriginalWord* pWordThd = new OriginalWord("丁老师好像也不错,");
	cout << "第三个Msg" << endl;
	pWordThd->showWords();
	cout << "我们是在多看看老夏和老丁的新课程，我还是想看看夏老师的新课程"<<endl;
	//当我们需要回溯到某一个状态的时候，我们需要问CareTake对象拿到的快照
	pWordFst->recycleWords(pCT->GetMemento());
	pWordFst->showWords();
	system("pause");
	return 0;
}