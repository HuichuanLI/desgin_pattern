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
#include <vector>
using namespace std;

class Light {
public:
	void on() {
		cout << "灯亮了" << endl;
	}
	void off() {
		cout << "灯灭了" << endl;
	}
};
//turn on the light
//turn off the light

//抽象出一个类，专门记录，这个动作
class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
protected:
	Command(){}
};

//具体的命令对象：就是用来开灯
//持有一个Receiver的实例，让这个Receiver自己去处理自己的运行
class LightOnCommand :public Command{
//突出的一个特点：我们问题聚焦的是如何规划“请求这个动作”
//而这个动作的真正执行，是通过我们将真实设备组合进入这个ConcreteCommand里面来的（LightOnCommand）
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

//添加一个undo的命令
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
//增加一个空的命令状态
class NoCommand :public Command {
public:
	void execute() {}
	void undo() {}
};

//invoker可以触发任意的命令对象，invoker可以发任何命令
class SimpleRemoteControl {
public:
	void setCommand(Command *pCommand) {
		m_pCommand = pCommand;

		//增加Undo的能力
		m_pUndoCommand = new NoCommand;

	}

	//////现在当前的这个命令对象，既可以关闭，也可以打开，所以我们进一步细化buttonPress
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
	//增加Undo撤销的能力
	Command* m_pUndoCommand;
};

//宏命令
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
//为了演示，再次加入若干命令
class Sound {
public:
	void on() {
		cout << "声音设备打开了" << endl;
	}
	void off() {
		cout << "声音设备关闭了" << endl;
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

//能够批量执行命令的loader
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
	LightOnCommand* pLightOn = new LightOnCommand(pLight);//首先将设备组合进入命令对象
	pRemote->setCommand(pLightOn);//通过Invoker触发，“请求”动作
	pRemote->onButonWasPushed();//按下开启
	pRemote->undoButtonWasPushed();//实现Undo
	//加载关灯命令
	LightOffCommand* pLightOff = new LightOffCommand(pLight);
	pRemote->setCommand(pLightOff);
	pRemote->offButtonWasPushed();
	pRemote->undoButtonWasPushed();

	//宏命令的演示
	cout << "**************宏命令的演示" << endl;
	vector<Command*> myCommands;
	Sound* pSound = new Sound;
	SoundOnCommand* pSoundOn = new SoundOnCommand(pSound);
	myCommands.push_back(pLightOn);
	myCommands.push_back(pSoundOn);

	MacroCommands* pMacroCommands = new MacroCommands(myCommands);
	//pRemote->setCommand(pMacroCommands);现在我们需要批量的执行宏命令,新增一个RemoteInvoker的宏命令执行方法
	SimpleRemoteControlLoader *pRemoteCommands = new SimpleRemoteControlLoader;
	pRemoteCommands->setCommand(pMacroCommands);
	pRemoteCommands->onCommandsStart();
	//pRemote->buttonPressed();
	//灯亮了被我们的invoker：SimpleRemote隐藏起来了，（封装了设备）
	//接下来，只要我们关注invoker，并且invoker进行控制，就能把一系列的“动作”记录下来
	system("pause");
	return 0;
}