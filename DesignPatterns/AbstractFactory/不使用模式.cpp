
#include <iostream>
using namespace std;

class FrameApi {
public:
	virtual void draw() = 0;
protected:
	FrameApi() {};
};

class LayoutApi {//�ֱ��ʵĲ�����
public:
	virtual void installFrame() = 0;
protected:
	LayoutApi(){}
};

//pc�ϵ�Frame
class ComputerFrame :public FrameApi {
public:
	ComputerFrame(int pins) : m_pins(pins) {

	}
	void draw() {
		cout << "������pc����Frame,�����õķֱ�����" << m_pins<<endl;
	}
private:
	int m_pins;
};

class MobileFrame :public FrameApi {
public:
	MobileFrame(int pins):m_pins(pins){}
	void draw() {
		cout << "������Mobile��Frame,��ʹ�õķֱ�����" << m_pins<<endl;
	}

private:
	int m_pins;
};

//�߷ֱ��ʵĲ���
class HighLayout :public LayoutApi {
public:
	HighLayout(int FrameAdpaterPins):m_FrameAdpaterPins(FrameAdpaterPins){}
	void installFrame() {
		cout << "��������PC�����£�����ʹ�õĸ߷ֱ��ʲ���" << m_FrameAdpaterPins << endl;
	}

private:
	int m_FrameAdpaterPins;
};

//�ͷֱ��ʵĲ���
class LowLayout :public LayoutApi {
public:
	LowLayout(int FrameAdpaterPins) :m_FrameAdpaterPins(FrameAdpaterPins) {}
	void installFrame() {
		cout << "��������Mobile�����£�����ʹ�õĵͷֱ��ʲ���" << m_FrameAdpaterPins << endl;
	}

private:
	int m_FrameAdpaterPins;
};

//������Ʒ�ļ򵥹���
class FrameFactory {
public:
	static FrameApi* createFrame(int type) {
		if (type == 1)
			return new ComputerFrame(1024);
		if (type == 2)
			return new MobileFrame(800);
		return nullptr;
	}
};

class LayoutFactory {
public:
	static LayoutApi* createLayout(int type) {
		if (type == 1)
			return new HighLayout(1024);
		if (type == 2)
			return new LowLayout(800);
		return nullptr;
	}
};

class GUIEngineer {
public:
	void prepareDraw(int FrameType, int LayoutType) {
		this->pFrame = FrameFactory::createFrame(FrameType);
		this->pLayout = LayoutFactory::createLayout(LayoutType);
		pFrame->draw();
		pLayout->installFrame();
	}
private:
	FrameApi* pFrame;
	LayoutApi* pLayout;
};

int main(void) {
	GUIEngineer* pEng = new GUIEngineer;
	pEng->prepareDraw(1, 2);
	system("pause");
	return 0;
}