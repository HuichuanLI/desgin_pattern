// MyProject.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
//#include <map>
//#include <stack>
#include <vector>
#include <sstream>

#ifdef _DEBUG   //只在Debug（调试）模式下
#ifndef DEBUG_NEW
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__) //重新定义new运算符
#define new DEBUG_NEW
#endif
#endif

//#include <boost/type_index.hpp>
using namespace std;
//#pragma warning(disable : 4996) 

namespace _nmsp1
{
	//怪物父类
	class Monster
	{
	public:
		virtual ~Monster() {} //做父类时析构函数应该为虚函数
		//void Assemble(string strmodelno) //参数:模型编号，形如：“1253679201245”等。每些位的组合都有一些特别的含义，这里不需要探究。
		//{
		//	LoadTrunkModel(strmodelno.substr(4, 3)); //载入躯干模型，截取某部分字符串以表示躯干模型的编号
		//	LoadHeadModel(strmodelno.substr(7, 3)); //载入头部模型并挂接到躯干模型上
		//	LoadLimbsModel(strmodelno.substr(10, 3)); //载入四肢模型并挂接到躯干模型上
		//}

		//virtual void LoadTrunkModel(string strno) = 0; //这里也可以写成一个空函数，子类决定是否重新实现
		//virtual void LoadHeadModel(string strno) = 0;
		//virtual void LoadLimbsModel(string strno) = 0;
	};

	//亡灵类怪物
	class M_Undead :public Monster
	{
	/*public:
		virtual void LoadTrunkModel(string strno)
		{
			cout << "载入亡灵类怪物的躯干部位模型，需要调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "载入亡灵类怪物的头部模型并挂接到躯干部位，需要调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "载入亡灵类怪物的四肢模型并挂接到躯干部位，需要调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}*/
	};

	//元素类怪物
	class M_Element :public Monster
	{
	/*public:
		virtual void LoadTrunkModel(string strno)
		{
			cout << "载入元素类怪物的躯干部位模型，需要调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "载入元素类怪物的头部模型并挂接到躯干部位，需要调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "载入元素类怪物的四肢模型并挂接到躯干部位，需要调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}*/
	};

	//机械类怪物
	class M_Mechanic :public Monster
	{
	/*public:
		virtual void LoadTrunkModel(string strno)
		{
			cout << "载入机械类怪物的躯干部位模型，需要调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "载入机械类怪物的头部模型并挂接到躯干部位，需要调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "载入机械类怪物的四肢模型并挂接到躯干部位，需要调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
		}*/
	};
	//----------------------------
	//怪物构建器父类
	class MonsterBuilder
	{
	public:
		virtual ~MonsterBuilder() {} //做父类时析构函数应该为虚函数
		//void Assemble(string strmodelno) //参数:模型编号，形如：“1253679201245”等。每些位的组合都有一些特别的含义，这里不需要探究。
		//{
		//	LoadTrunkModel(strmodelno.substr(4, 3)); //载入躯干模型，截取某部分字符串以表示躯干模型的编号
		//	LoadHeadModel(strmodelno.substr(7, 3)); //载入头部模型并挂接到躯干模型上
		//	LoadLimbsModel(strmodelno.substr(10, 3)); //载入四肢模型并挂接到躯干模型上
		//}

		//返回指向Monster类的成员变量指针m_pMonster，当一个复杂的对象构建完成后，可以通过该成员函数把对象返回。
		Monster* GetResult()
		{
			return m_pMonster;
		}

		virtual void LoadTrunkModel(string strno) = 0; //这里也可以写成一个空函数，子类决定是否重新实现
		virtual void LoadHeadModel(string strno) = 0;
		virtual void LoadLimbsModel(string strno) = 0;

	protected:
		Monster* m_pMonster; //指向Monster类的成员变量指针
	};

	//----------
	//亡灵类怪物构建器类
	class M_UndeadBuilder :public MonsterBuilder
	{
	public:
		M_UndeadBuilder() //构造函数
		{
			m_pMonster = new M_Undead();
		}

		virtual void LoadTrunkModel(string strno)
		{
			cout << "载入亡灵类怪物的躯干部位模型，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//具体要做的事情其实是委托给怪物子类完成，委托指把本该自己实现的功能转给其他类实现
			//m_pMonster->......略
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "载入亡灵类怪物的头部模型并挂接到躯干部位，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "载入亡灵类怪物的四肢模型并挂接到躯干部位，需要m_pMonster指针调用M_Undead类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
	};

	//元素类怪物构建器类
	class M_ElementBuilder :public MonsterBuilder
	{
	public:
		M_ElementBuilder() //构造函数
		{
			m_pMonster = new M_Element();
		}

		virtual void LoadTrunkModel(string strno)
		{
			cout << "载入元素类怪物的躯干部位模型，需要m_pMonster指针调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;			
			//m_pMonster->......略
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "载入元素类怪物的头部模型并挂接到躯干部位，需要m_pMonster指针调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "载入元素类怪物的四肢模型并挂接到躯干部位，需要m_pMonster指针调用M_Element类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
	};

	//机械类怪物构建器类
	class M_MechanicBuilder :public MonsterBuilder
	{
	public:
		M_MechanicBuilder() //构造函数
		{
			m_pMonster = new M_Mechanic();
		}

		virtual void LoadTrunkModel(string strno)
		{
			cout << "载入机械类怪物的躯干部位模型，需要m_pMonster指针调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
		virtual void LoadHeadModel(string strno)
		{
			cout << "载入机械类怪物的头部模型并挂接到躯干部位，需要m_pMonster指针调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
		virtual void LoadLimbsModel(string strno)
		{
			cout << "载入机械类怪物的四肢模型并挂接到躯干部位，需要m_pMonster指针调用M_Mechanic类或其父类中其他诸多成员函数，逻辑代码略......" << endl;
			//m_pMonster->......略
		}
	};

	//------------------
	//指挥者类
	class MonsterDirector
	{
	public:
		MonsterDirector(MonsterBuilder* ptmpBuilder) //构造函数
		{
			m_pMonsterBuilder = ptmpBuilder;
		}

		//指定新的构建器
		void SetBuilder(MonsterBuilder* ptmpBuilder)
		{
			m_pMonsterBuilder = ptmpBuilder;
		}

		//原MonsterBuilder类中的Assemble成员函数
		Monster *Construct(string strmodelno) //参数:模型编号，形如：“1253679201245”等。每些位的组合都有一些特别的含义，这里不需要探究。
		{
			m_pMonsterBuilder->LoadTrunkModel(strmodelno.substr(4, 3)); //载入躯干模型，截取某部分字符串以表示躯干模型的编号
			m_pMonsterBuilder->LoadHeadModel(strmodelno.substr(7, 3)); //载入头部模型并挂接到躯干模型上
			m_pMonsterBuilder->LoadLimbsModel(strmodelno.substr(10, 3)); //载入四肢模型并挂接到躯干模型上
			return m_pMonsterBuilder->GetResult(); //返回构建后的对象
		}
	private:
		MonsterBuilder* m_pMonsterBuilder; //指向所有构建器类的父类
	};
}
namespace _nmsp2
{
	//日报的“标题”部分
	class DailyHeaderData
	{
	public:
		//构造函数
		DailyHeaderData(string strDepName, string strGenData) :m_strDepName(strDepName), m_strGenData(strGenData) {}
		string getDepName() //获取部门名称
		{
			return m_strDepName;
		}
		string getExportDate() //获取日报生成日期
		{
			return m_strGenData;
		}

	private:
		string m_strDepName;//部门名称
		string m_strGenData; //日报生成日期
	};

	//日报中的“内容主体”部分 中的 每一条描述数据
	class DailyContentData
	{
	public:
		//构造函数
		DailyContentData(string strContent, double dspendTime) :m_strContent(strContent), m_dspendTime(dspendTime) {}
		string getContent() //获取该项工作内容描述
		{
			return m_strContent;
		}
		double getSpendTime() //获取完成该项工作花费的时间
		{
			return m_dspendTime;
		}
	private:
		string m_strContent; //该项工作内容描述
		double m_dspendTime; //完成该项工作花费的时间（单位：小时）
	};

	//日报中的“结尾”部分
	class DailyFooterData
	{
	public:
		//构造函数
		DailyFooterData(string strUserName) :m_strUserName(strUserName) {}
		string getUserName() //获取日报所属员工姓名
		{
			return m_strUserName;
		}
	private:
		string m_strUserName; //日报所属员工姓名
	};

	//将日报导出到纯文本格式文件 相关的类
	class ExportToTxtFile
	{
	public:
		//实现导出动作
		void doExport(DailyHeaderData& dailyheaderobj, vector<DailyContentData*>& vec_dailycontobj, DailyFooterData& dailyfooterobj)
		{
			string strtmp = "";
			//(1)拼接标题
			strtmp += dailyheaderobj.getDepName() + "," + dailyheaderobj.getExportDate() + "\n";

			//(2)拼接内容主体，内容主体中的描述数据会有多条，因此，需要迭代
			for (auto iter = vec_dailycontobj.begin(); iter != vec_dailycontobj.end(); ++iter)
			{
				ostringstream oss;  //#include <sstream>
				oss << (*iter)->getSpendTime();
				strtmp += (*iter)->getContent() + ":（花费的时间：" + oss.str() + "小时）" + "\n";
			} //end for

			//(3)拼接结尾
			strtmp += "报告人：" + dailyfooterobj.getUserName() + "\n";

			//(4)导出到真实文件的代码略，只展示在屏幕上文件的内容
			cout << strtmp;
		}
	};

	//将日报导出到XML格式文件 相关的类
	class ExportToXmlFile
	{
	public:
		//实现导出动作
		void doExport(DailyHeaderData& dailyheaderobj, vector<DailyContentData*>& vec_dailycontobj, DailyFooterData& dailyfooterobj)
		{
			string strtmp = "";
			//(1)拼接标题
			strtmp += "<?xml version =\"1.0\" encoding=\"UTF-8\" ?>\n";
			strtmp += "<DailyReport>\n";
			strtmp += "    <Header>\n";
			strtmp += "        <DepName>" + dailyheaderobj.getDepName() + "</DepName>\n";
			strtmp += "        <GenDate>" + dailyheaderobj.getExportDate() + "</GenDate>\n";
			strtmp += "    </Header>\n";

			//(2)拼接内容主体 ，内容主体中的描述数据会有多条，因此需要迭代
			strtmp += "    <Body>\n";
			for (auto iter = vec_dailycontobj.begin(); iter != vec_dailycontobj.end(); ++iter)
			{
				ostringstream oss;
				oss << (*iter)->getSpendTime();
				strtmp += "        <Content>" + (*iter)->getContent() + "</Content>\n";
				strtmp += "        <SpendTime>花费的时间：" + oss.str() + "小时" + "</SpendTime>\n";
			} //end for
			strtmp += "    </Body>\n";

			//(3)拼接结尾
			strtmp += "    <Footer>\n";
			strtmp += "        <UserName>报告人：" + dailyfooterobj.getUserName() + "</UserName>\n";
			strtmp += "    </Footer>\n";
			strtmp += "</DailyReport>\n";
			
			//(4)导出到真实文件的代码略，只展示在屏幕上文件的内容
			cout << strtmp;
		}
	};

	//-----------------
	//抽象构建器类（文件构建器父类）
	class FileBuilder
	{
	public:
		virtual ~FileBuilder() {} //做父类时析构函数应该为虚函数

	public:
		virtual void buildHeader(DailyHeaderData& dailyheaderobj) = 0; //拼接标题
		virtual void buildBody(vector<DailyContentData*>& vec_dailycontobj) = 0; //拼接内容主体
		virtual void buildFooter(DailyFooterData& dailyfooterobj) = 0; //拼接结尾

		string GetResult()
		{
			return m_strResult;
		}
	protected:
		string m_strResult;
	};

	//纯文本文件构建器类
	class TxtFileBuilder :public FileBuilder
	{
	public:
		virtual void buildHeader(DailyHeaderData& dailyheaderobj) //拼接标题
		{
			//(1)拼接标题
			m_strResult += dailyheaderobj.getDepName() + "," + dailyheaderobj.getExportDate() + "\n";
		}
		virtual void buildBody(vector<DailyContentData*>& vec_dailycontobj) //拼接内容主体
		{
			//(2)拼接内容主体，内容主体中的描述数据会有多条，因此，需要迭代
			for (auto iter = vec_dailycontobj.begin(); iter != vec_dailycontobj.end(); ++iter)
			{
				ostringstream oss;  //#include <sstream>
				oss << (*iter)->getSpendTime();
				m_strResult += (*iter)->getContent() + ":（花费的时间：" + oss.str() + "小时）" + "\n";
			} //end for			
		}
		virtual void buildFooter(DailyFooterData& dailyfooterobj)//拼接结尾
		{
			//(3)拼接结尾
			m_strResult += "报告人：" + dailyfooterobj.getUserName() + "\n";
		}
	};

	//XML文件构建器类
	class XmlFileBuilder :public FileBuilder
	{
		virtual void buildHeader(DailyHeaderData& dailyheaderobj) //拼接标题
		{
			//(1)拼接标题			
			m_strResult += "<?xml version =\"1.0\" encoding=\"UTF-8\" ?>\n";
			m_strResult += "<DailyReport>\n";
			m_strResult += "    <Header>\n";
			m_strResult += "        <DepName>" + dailyheaderobj.getDepName() + "</DepName>\n";
			m_strResult += "        <GenDate>" + dailyheaderobj.getExportDate() + "</GenDate>\n";
			m_strResult += "    </Header>\n";
		}
		virtual void buildBody(vector<DailyContentData*>& vec_dailycontobj) //拼接内容主体
		{
			//(2)拼接内容主体，内容主体中的描述数据会有多条，因此，需要迭代
			m_strResult += "    <Body>\n";
			for (auto iter = vec_dailycontobj.begin(); iter != vec_dailycontobj.end(); ++iter)
			{
				ostringstream oss;
				oss << (*iter)->getSpendTime();
				m_strResult += "        <Content>" + (*iter)->getContent() + "</Content>\n";
				m_strResult += "        <SpendTime>花费的时间：" + oss.str() + "小时" + "</SpendTime>\n";
			} //end for
			m_strResult += "    </Body>\n";
		}
		virtual void buildFooter(DailyFooterData& dailyfooterobj)//拼接结尾
		{
			//(3)拼接结尾
			m_strResult += "    <Footer>\n";
			m_strResult += "        <UserName>报告人：" + dailyfooterobj.getUserName() + "</UserName>\n";
			m_strResult += "    </Footer>\n";
			m_strResult += "</DailyReport>\n";
		}
	};

	//文件指挥者类
	class FileDirector
	{
	public:
		FileDirector(FileBuilder* ptmpBuilder) //构造函数
		{
			m_pFileBuilder = ptmpBuilder;
		}
		//组装文件
		string Construct(DailyHeaderData& dailyheaderobj, vector<DailyContentData*>& vec_dailycontobj, DailyFooterData& dailyfooterobj)
		{
			//有时指挥者需要和构建器通过参数传递的方式交换数据，这里指挥者通过委托的方式把功能交给构建器完成
			m_pFileBuilder->buildHeader(dailyheaderobj);
			m_pFileBuilder->buildBody(vec_dailycontobj);
			m_pFileBuilder->buildFooter(dailyfooterobj);
			return m_pFileBuilder->GetResult();
		}
	private:
		FileBuilder* m_pFileBuilder; //指向所有构建器类的父类
	};

}


int main()
{

	//第三节 建造者（Builder）模式
	//也称：构建器/构建者/生成器模式-创建型模式。
	//通常用于创建比较复杂的对象
	//（1）一个具体实现范例的逐步重构
	//怪物：亡灵类，元素类，机械类
	//怪物组成：头部、躯干（颈部、尾巴）、肢体 三个部位组成。
	//编码步骤：将怪物躯干部模型信息读入内存。将怪物的头部和四肢模型信息读入内存。将头部和四肢模型以正确的位置和方向挂接到躯干部位。  最终装配出完整的怪物模型。
	//Assemble、LoadTrunkModel、LoadHeadModel、LoadLimbsModel称为构建过程相关的函数。
	//引入与怪物类同层次的相关构建器类，把怪物类中代码搬到相关的构建器类中。
	//（2）引入建造者（Builder）模式
	//引入建造者（Builder）模式定义：将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。
	//MonsterBuilder类就是对象的构建，Monster类是对象的表示。
	//建造者模式包含四种角色：
	//a)Builder（抽象构建器）：这里指MonsterBuilder。
	//b)ConcreteBuilder（具体构建器）：这里指M_UndeadBuilder、M_ElementBuilder、M_MechanicBuilder类。
	//c)Product(产品）：这里指M_Undead、M_Element、M_Mechanic类。
	//d)Director（指挥者）：MonsterDirector类。
	//复杂的东西就考虑拆解，简单的东西就考虑合并。

	//（3）另一个建造者模式的范例
	//各部门员工 工作日报：标题、内容主体、结尾 三部分。
	 //a)标题部分：部门名称、日报生成日期等信息
	 //b)内容主体：具体描述可能有多条（一天可能做了多项工作）
	 //c)结尾：姓名
	//将日报导出成多种格式的文件，比如纯文本，XML格式，JSON格式。
	//（3.1）不用设计模式时程序应该如何书写
	//导出到文件的三个步骤不变：a)拼接标题； b)拼接内容主体；c)拼接结尾
	//考虑把这三个步骤（复杂对象的构建过程）提炼（抽象）出来，形成一个通用的处理过程。
	//建造者模式的初衷：将构建不同格式数据的细节实现代码与具体的构建步骤 分离 达到复用 构建步骤的目的。
	//（3.2）采用设计模式时程序应该如何改写
	//（4）建造者模式的总结：用于分步骤构建一个复杂对象，其中构建步骤是一个稳定算法（构建算法）。
	//何时使用：
	//a)产品对象内部结构复杂，产品往往由多个零件组成。
	//b)需要创建的产品对象内部属性互相依赖，需要指定创建次序。
	//c)当创建复杂对象的步骤（过程）应该独立于该对象的组成部分；
	//d)将复杂对象的创建和使用分离，使相同的创建过程可以创建不同的产品。
	//指挥者类作用：
	//a)通过部件以指定的顺序来构建整个产品（控制了构建过程）
	//b)通过提供Construct接口隔离了客户端与具体构建过程所必须要调用的类的成员函数之间的关联。
	//建造者模式优点：
	//a)产品构建和产品表现上的分离。构建算法可以被复用。
	//b)向客户端隐藏了产品内部的表现。
	//c)产品的实现可以被随时替换。
	//建造者模式缺点：
	//a)要求所创建的产品有比较多的共同点，创建步骤（组成部分）要大致相同。
	//b)该模式涉及到很多类。Director,Builder对象。对于理解和学习具有一定门槛。







	/*
	_nmsp1::Monster* pmonster = new _nmsp1::M_Element(); //创建一只元素类怪物
	pmonster->Assemble("1253679201254");

	//释放资源
	delete pmonster;
	*/
	
	/*
	_nmsp1::MonsterBuilder* pMonsterBuilder = new _nmsp1::M_UndeadBuilder(); //创建亡灵类怪物构建器对象
	_nmsp1::MonsterDirector* pDirector = new _nmsp1::MonsterDirector(pMonsterBuilder); 
	_nmsp1::Monster* pMonster = pDirector->Construct("1253679201254"); //这里就构建出了一个完整的怪物对象

	//释放资源
	delete pMonster;
	delete pDirector;
	delete pMonsterBuilder;
	*/

	_nmsp2::DailyHeaderData* pdhd = new _nmsp2::DailyHeaderData("研发一部", "11月1日");
	_nmsp2::DailyContentData* pdcd1 = new _nmsp2::DailyContentData("完成A项目的需求分析工作", 3.5);
	_nmsp2::DailyContentData* pdcd2 = new _nmsp2::DailyContentData("确定A项目开发所使用的工具", 4.5);

	vector<_nmsp2::DailyContentData*> vec_dcd;
	vec_dcd.push_back(pdcd1);
	vec_dcd.push_back(pdcd2);

	_nmsp2::DailyFooterData* pdfd = new _nmsp2::DailyFooterData("小李");
	
	//_nmsp2::ExportToTxtFile file_ettxt;
	//file_ettxt.doExport(*pdhd, vec_dcd, *pdfd);
	//_nmsp2::ExportToXmlFile file_etxml;
	//file_etxml.doExport(*pdhd, vec_dcd, *pdfd);
	//_nmsp2::FileBuilder* pfb = new _nmsp2::TxtFileBuilder();
	_nmsp2::FileBuilder* pfb = new _nmsp2::XmlFileBuilder();
	_nmsp2::FileDirector* pDtr = new _nmsp2::FileDirector(pfb);
	cout << pDtr->Construct(*pdhd, vec_dcd, *pdfd);

	//释放资源
	delete pdhd;
	for (auto iter = vec_dcd.begin(); iter != vec_dcd.end(); ++iter)
	{
		delete (*iter);
	}
	delete pdfd;

	delete pfb;
	delete pDtr;

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

