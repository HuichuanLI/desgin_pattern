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

class Colleague;
class Mediator {
public:
	//����������ı������£�֪ͨMediator���б��
	//������Mediator������ߣ�������Ӧ��ͬ�¶���Ľ���
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
	//ģ�������Ĺ���
	SoundCard(Mediator* pMediator):Colleague(pMediator){}
	void soundData(string data) {
		cout << "�����ڹ���" <<data<< endl;
	}
};

class VideoCard :public Colleague {
public:
	VideoCard(Mediator *pMediator):Colleague(pMediator){}
	void VideoData(string data) {
		cout << "�Կ��ڹ���" << data << endl;
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
		//���忪ʼ���и������������У����ȵ���CPU��������õ����ݵõ�
		string strVideoData = pCPU->getVideoData();
		string strSoundData = pCPU->getSoundData();
		//����Щ����õ����ݽ�����SoundCard,VideoCard�������ǹ���
		m_pVideoCard->VideoData(strVideoData);
		m_pSoundCard->soundData(strSoundData);
	}
private:
	CPU* m_pCPU;
	VideoCard* m_pVideoCard;
	SoundCard* m_pSoundCard;
};

int main() {
	//����Mediator
	MotherBoard* pMediator = new MotherBoard;
	//����ͬ����Ķ���
	CPU* pCPU = new CPU(pMediator);
	VideoCard* pVC = new VideoCard(pMediator);
	SoundCard* pSC = new SoundCard(pMediator);
	//��Mediator��֪����ЩColleague�Ķ���
	pMediator->setCPU(pCPU);
	pMediator->setSoundCard(pSC);
	pMediator->setVideoCard(pVC);
	//�����ǵ�������������
	string arr[] = { "��������ѧ����","��ְ��н������" };
	pCPU->executeData(arr);//����ȥ������CPU�������Լ�������
	system("pause");
	return 0;
}
