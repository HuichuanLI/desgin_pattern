#include <iostream>
using namespace std;
class ThreePhaseOutlet {
public:
	void doThreePhasePlug() {
		cout << "三叉" << endl;
	}
};

class TwoPhaseOutlet {
public:
	virtual void doPlug() = 0;
};

class OutletConverter :public TwoPhaseOutlet, public ThreePhaseOutlet {
public:
	void doPlug() {
		doConvertor();
		doThreePhasePlug();
	}
	void doConvertor() {
		cout << "变化" << endl;
	}
};
// 对象适配
class OutletObjConvertor :public TwoPhaseOutlet {
public:
	OutletObjConvertor(ThreePhaseOutlet* pOut) :m_pOut(pOut) {

	}
	void doPlug() {
		doConvert();
		m_pOut->doThreePhasePlug();
	}
	void doConvert() {
		cout << "转化" << endl;
	}
private:
	ThreePhaseOutlet* m_pOut;
};

int main() {
	TwoPhaseOutlet* pOutlet = new OutletConverter();
	pOutlet->doPlug();
//	TwoPhaseOutlet* pOutlet = new OutletObjConvertor(new ThreePhaseOutlet);
//	pOutlet->doPlug();
//	system("pause");
	return 0;
}