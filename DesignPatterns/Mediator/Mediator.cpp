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

class Colleague;
class Mediator {
public:
	//对象在自身改变的情况下，通知Mediator进行变更
	//让我们Mediator这个总线，负责相应的同事对象的交互
	virtual void changed(Colleague* pColleague) = 0;
protected:
	Mediator() {};
};

class  Colleague
{
public:
	Colleague() {}
	Colleague(Mediator* pMediator):m_pMediator(pMediator){}
	
	Mediator* getMediator() {
		return m_pMediator;
	}

private:
	Mediator* m_pMediator;
};

class SoundCard :public Colleague {
public:
	//模拟声卡的工作
	SoundCard(Mediator* pMediator):Colleague(pMediator){}
	void soundData(string data) {
		cout << "声卡在工作" <<data<< endl;
	}
};

class VideoCard :public Colleague {
public:
	VideoCard(Mediator *pMediator):Colleague(pMediator){}
	void VideoData(string data) {
		cout << "显卡在工作" << data << endl;
	}
};

class CPU :public Colleague {
public:
	CPU(Mediator *pMediator):Colleague(pMediator){}
	void executeData(string data[]) {
		m_strVideoData = data[0];
		m_strSoundData = data[1];
		this->getMediator()->changed(this);

	}
	string getVideoData() {
		return m_strVideoData;
	}
	string getSoundData() {
		return m_strSoundData;
	}
private:
	string m_strVideoData;
	string m_strSoundData;
};

class MotherBoard :public Mediator {
public:
	void setCPU(CPU* pCpu) {
		m_pCPU = pCpu;
	}

	void setVideoCard(VideoCard* pVC) {
		m_pVideoCard = pVC;
	}
	void setSoundCard(SoundCard* pSC) {
		m_pSoundCard = pSC;
	}
	void changed(Colleague* pColleague) {
		if (pColleague == m_pCPU) {
			this->openCPU((CPU*)pColleague);
	}
	}
private:
	void openCPU(CPU* pCPU) {
		//主板开始进行各个部件的运行，首先调用CPU，将处理好的数据得到
		string strVideoData = pCPU->getVideoData();
		string strSoundData = pCPU->getSoundData();
		//将这些处理好的数据交付给SoundCard,VideoCard，让他们工作
		m_pVideoCard->VideoData(strVideoData);
		m_pSoundCard->soundData(strSoundData);
	}
private:
	CPU* m_pCPU;
	VideoCard* m_pVideoCard;
	SoundCard* m_pSoundCard;
};

int main() {
	//创建Mediator
	MotherBoard* pMediator = new MotherBoard;
	//创建同事类的对象
	CPU* pCPU = new CPU(pMediator);
	VideoCard* pVC = new VideoCard(pMediator);
	SoundCard* pSC = new SoundCard(pMediator);
	//让Mediator都知道这些Colleague的对象
	pMediator->setCPU(pCPU);
	pMediator->setSoundCard(pSC);
	pMediator->setVideoCard(pVC);
	//让我们的数据运行起来
	string arr[] = { "跟着老夏学开发","升职加薪就找他" };
	pCPU->executeData(arr);//看上去，好像CPU就在做自己的事情
	system("pause");
	return 0;
}
