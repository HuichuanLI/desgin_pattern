
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
	LayoutApi() {}
};

//pc�ϵ�Frame
class ComputerFrame :public FrameApi {
public:
	ComputerFrame(int pins) : m_pins(pins) {

	}
	void draw() {
		cout << "������pc����Frame,�����õķֱ�����" << m_pins << endl;
	}
private:
	int m_pins;
};

class MobileFrame :public FrameApi {
public:
	MobileFrame(int pins) :m_pins(pins) {}
	void draw() {
		cout << "������Mobile��Frame,��ʹ�õķֱ�����" << m_pins << endl;
	}

private:
	int m_pins;
};

//�߷ֱ��ʵĲ���
class HighLayout :public LayoutApi {
public:
	HighLayout(int FrameAdpaterPins) :m_FrameAdpaterPins(FrameAdpaterPins) {}
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

////������Ʒ�ļ򵥹���
//class FrameFactory {
//public:
//	static FrameApi* createFrame(int type) {
//		if (type == 1)
//			return new ComputerFrame(1024);
//		if (type == 2)
//			return new MobileFrame(800);
//		return nullptr;
//	}
//};
//
//class LayoutFactory {
//public:
//	static LayoutApi* createLayout(int type) {
//		if (type == 1)
//			return new HighLayout(1024);
//		if (type == 2)
//			return new LowLayout(800);
//		return nullptr;
//	}
//};
//
//class GUIEngineer {
//public:
//	//FrameType:����������ѡ��Frame�ؼ�������
//	//LayoutType:����������ѡ�񲼾ֹ�����������
//	void prepareDraw(int FrameType, int LayoutType) {
//		this->pFrame = FrameFactory::createFrame(FrameType);
//		this->pLayout = LayoutFactory::createLayout(LayoutType);
//		pFrame->draw();
//		pLayout->installFrame();
//	}
//private:
//	FrameApi* pFrame;
//	LayoutApi* pLayout;
//};

//���󹤳����������Ʒ��
class AbstractFactory {
public:
	virtual FrameApi* createFrameApi() = 0;
	virtual LayoutApi* createLayoutApi() = 0;
protected:
    AbstractFactory(){}
};

class Schema1 : public AbstractFactory {
public:
	FrameApi* createFrameApi() {
		return new ComputerFrame(1024);

	}
	LayoutApi* createLayoutApi() {
		return new HighLayout(1024);
	}
};

class Schema2 :public AbstractFactory {
public:
	FrameApi* createFrameApi() {
		return new MobileFrame(800);
	}
	LayoutApi* createLayout() {
		return new LowLayout(800);
	}
};

class AdvancedGuiEngineer {
public:
	void prepareMaterials(AbstractFactory* pSchema) {
		this->pFrame = pSchema->createFrameApi();
		this->pLayout = pSchema->createLayoutApi();
		pFrame->draw();
		pLayout->installFrame();
	}
private:
	FrameApi* pFrame;
	LayoutApi* pLayout;
};

//��ȥ�ϵ»���ͣ�ֻҪ���ǵ���ײͣ���һ�����᲻���䡣
int main(void) {
	/*GUIEngineer* pEng = new GUIEngineer;
	pEng->prepareDraw(1, 2);*/
	AdvancedGuiEngineer* pEng = new AdvancedGuiEngineer();
	pEng->prepareMaterials(new Schema1());

	system("pause");
	return 0;
}