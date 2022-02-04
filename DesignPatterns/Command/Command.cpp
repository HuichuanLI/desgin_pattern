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
#include <vector>
using namespace std;

class Light {
public:
	void on() {
		cout << "������" << endl;
	}
	void off() {
		cout << "������" << endl;
	}
};
//turn on the light
//turn off the light

//�����һ���࣬ר�ż�¼���������
class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
protected:
	Command(){}
};

//�����������󣺾�����������
//����һ��Receiver��ʵ���������Receiver�Լ�ȥ�����Լ�������
class LightOnCommand :public Command{
//ͻ����һ���ص㣺��������۽�������ι滮���������������
//���������������ִ�У���ͨ�����ǽ���ʵ�豸��Ͻ������ConcreteCommand�������ģ�LightOnCommand��
public:
	LightOnCommand(Light *pLight) :m_pLight(pLight) {
	}
	void execute() {
		m_pLight->on();
	}
	void undo() {
		m_pLight->off();
	}
private:
	Light *m_pLight;
};

//���һ��undo������
class LightOffCommand : public Command {
public:
	LightOffCommand(Light *pLight) : m_pLight(pLight) {

	}
	void execute() {
		m_pLight->off();
	}
	void undo() {
		m_pLight->on();
	}
private:
	Light* m_pLight;
};
//����һ���յ�����״̬
class NoCommand :public Command {
public:
	void execute() {}
	void undo() {}
};

//invoker���Դ���������������invoker���Է��κ�����
class SimpleRemoteControl {
public:
	void setCommand(Command *pCommand) {
		m_pCommand = pCommand;

		//����Undo������
		m_pUndoCommand = new NoCommand;

	}

	//////���ڵ�ǰ�����������󣬼ȿ��Թرգ�Ҳ���Դ򿪣��������ǽ�һ��ϸ��buttonPress
	/*void buttonPressed() {
		m_pCommand->execute();
	}*/

	void onButonWasPushed() {
		m_pCommand->execute();
		m_pUndoCommand = m_pCommand;
	}

	void offButtonWasPushed() {
		m_pCommand->execute();
		m_pUndoCommand = m_pCommand;
	}

	void undoButtonWasPushed() {
		m_pUndoCommand->undo();
	}
private:
	Command* m_pCommand;
	//����Undo����������
	Command* m_pUndoCommand;
};

//������
class MacroCommands :public Command {
public:
	MacroCommands(vector<Command*> Commands) :m_Commands(Commands) {

	}
	void execute() {
		for (vector<Command*>::iterator iter = m_Commands.begin();iter != m_Commands.end();iter++) {
			(*iter)->execute();
		}
	}
	void undo() {
		for (vector<Command*>::iterator iter = m_Commands.begin();iter != m_Commands.end();iter++) {
			(*iter)->undo();
		}
	}
private:
	vector<Command*> m_Commands;
};
//Ϊ����ʾ���ٴμ�����������
class Sound {
public:
	void on() {
		cout << "�����豸����" << endl;
	}
	void off() {
		cout << "�����豸�ر���" << endl;
	}
};

class SoundOnCommand : public Command {
public:
	SoundOnCommand(Sound *pSound) :m_pSound(pSound) {
	}
	void execute() {
		m_pSound->on();
	}
	void undo() {
		m_pSound->off();
	}
private:
	Sound *m_pSound;
};

//�ܹ�����ִ�������loader
class SimpleRemoteControlLoader {
public:
	void setCommand(Command *pCommand) {
		m_pCommand = pCommand;
	}

	void onCommandsStart() {
		m_pCommand->execute();
	}

	
private:
	Command* m_pCommand;
	
};


int main(void) {
	SimpleRemoteControl* pRemote = new SimpleRemoteControl;
	Light* pLight = new Light;
	LightOnCommand* pLightOn = new LightOnCommand(pLight);//���Ƚ��豸��Ͻ����������
	pRemote->setCommand(pLightOn);//ͨ��Invoker�����������󡱶���
	pRemote->onButonWasPushed();//���¿���
	pRemote->undoButtonWasPushed();//ʵ��Undo
	//���عص�����
	LightOffCommand* pLightOff = new LightOffCommand(pLight);
	pRemote->setCommand(pLightOff);
	pRemote->offButtonWasPushed();
	pRemote->undoButtonWasPushed();

	//���������ʾ
	cout << "**************���������ʾ" << endl;
	vector<Command*> myCommands;
	Sound* pSound = new Sound;
	SoundOnCommand* pSoundOn = new SoundOnCommand(pSound);
	myCommands.push_back(pLightOn);
	myCommands.push_back(pSoundOn);

	MacroCommands* pMacroCommands = new MacroCommands(myCommands);
	//pRemote->setCommand(pMacroCommands);����������Ҫ������ִ�к�����,����һ��RemoteInvoker�ĺ�����ִ�з���
	SimpleRemoteControlLoader *pRemoteCommands = new SimpleRemoteControlLoader;
	pRemoteCommands->setCommand(pMacroCommands);
	pRemoteCommands->onCommandsStart();
	//pRemote->buttonPressed();
	//�����˱����ǵ�invoker��SimpleRemote���������ˣ�����װ���豸��
	//��������ֻҪ���ǹ�עinvoker������invoker���п��ƣ����ܰ�һϵ�еġ���������¼����
	system("pause");
	return 0;
}