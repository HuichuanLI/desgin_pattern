#include <iostream>
#include <sstream>
#include <vector>


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
		//void Assemble(string strmodelno) //参数：模型编号，形如“1253679201245”等，每些位的组合都有一些特别的含义，这里无需深究
		//{
		//	LoadTrunkModel(strmodelno.substr(4, 3));  //载入躯干模型，截取某部分字符串以表示躯干模型的编号
		//	LoadHeadModel(strmodelno.substr(7, 3));   //载入头部模型并挂接到躯干模型上
		//	LoadLimbsModel(strmodelno.substr(10, 3)); //载入四肢模型并挂接到躯干模型上
		//}

		//virtual void LoadTrunkModel(string strno) = 0; //这里也可以写为空函数体，子类决定是否重新实现
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


	//-----------------
	//怪物构建器父类
	class MonsterBuilder
	{
	public:
		virtual ~MonsterBuilder() {} //做父类时析构函数应该为虚函数
		//void Assemble(string strmodelno) //参数：模型编号，形如“1253679201245”等，每些位的组合都有一些特别的含义，这里无需深究
		//{
		//	LoadTrunkModel(strmodelno.substr(4, 3));  //载入躯干模型，截取某部分字符串以表示躯干模型的编号
		//	LoadHeadModel(strmodelno.substr(7, 3));   //载入头部模型并挂接到躯干模型上
		//	LoadLimbsModel(strmodelno.substr(10, 3)); //载入四肢模型并挂接到躯干模型上
		//}
		//返回指向Monster类的成员变量指针m_pMonster，当一个复杂的对象构建完成后，可以通过该成员函数把对象返回
		Monster* GetResult()
		{
			return m_pMonster;
		}

		virtual void LoadTrunkModel(string strno) = 0;//这里也可以写为空函数体，子类决定是否重新实现
		virtual void LoadHeadModel(string strno) = 0;
		virtual void LoadLimbsModel(string strno) = 0;

	protected:
		Monster* m_pMonster;  //指向Monster类的成员变量指针
	};

	//---------------
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
			//具体要做的事情其实是委托给怪物子类来完成，委托指把本该自己实现的功能转给其他类实现
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
		Monster* Construct(string strmodelno) //参数：模型编号，形如“1253679201245”等，每些位的组合都有一些特别的含义，这里无需深究
		{
			m_pMonsterBuilder->LoadTrunkModel(strmodelno.substr(4, 3));  //载入躯干模型，截取某部分字符串以表示躯干模型的编号
			m_pMonsterBuilder->LoadHeadModel(strmodelno.substr(7, 3));   //载入头部模型并挂接到躯干模型上
			m_pMonsterBuilder->LoadLimbsModel(strmodelno.substr(10, 3)); //载入四肢模型并挂接到躯干模型上
			return m_pMonsterBuilder->GetResult();  //返回构建后的对象
		}
	private:
		MonsterBuilder* m_pMonsterBuilder; //指向所有构建器类的父类
	};

}
namespace _nmsp2
{
	//日报中的“标题”部分
	class DailyHeaderData
	{
	public:
		//构造函数
		DailyHeaderData(string strDepName, string strGenDate) :m_strDepName(strDepName), m_strGenDate(strGenDate) {}
		string getDepName() //获取部门名称
		{
			return m_strDepName;
		}
		string getExportDate() //获取日报生成日期
		{
			return m_strGenDate;
		}
	private:
		string m_strDepName; //部门名称
		string m_strGenDate; //日报生成日期
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
		double m_dspendTime;  //完成该项工作花费的时间（单位：小时）
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
		void doExport(DailyHeaderData& dailyheaderobj, vector<DailyContentData*>& vec_dailycontobj, DailyFooterData& dailyfooterobj) //记得#include头文件vector，因为日报的内容主体部分中的描述数据可能会有多条，所以用vector容器保存
		{
			string strtmp = "";

			//(1)拼接标题
			strtmp += dailyheaderobj.getDepName() + "," + dailyheaderobj.getExportDate() + "\n";

			//(2)拼接内容主体，内容主体中的描述数据会有多条，因此需要迭代
			for (auto iter = vec_dailycontobj.begin(); iter != vec_dailycontobj.end(); ++iter)
			{
				ostringstream oss; //记得#include头文件sstream
				oss << (*iter)->getSpendTime();
				strtmp += (*iter)->getContent() + ":(花费的时间：" + oss.str() + "小时)" + "\n";
			} //end for

			//(3)拼接结尾
			strtmp += "报告人:" + dailyfooterobj.getUserName() + "\n";

			//(4)导出到真实文件的代码略，只展示在屏幕上文件的内容
			cout << strtmp;
		}
	};

	//将日报导出到XML格式文件 相关的类
	class ExportToXmlFile
	{
	public:
		//实现导出动作
		void doExport(DailyHeaderData& dailyheaderobj, vector<DailyContentData*>& vec_dailycontobj, DailyFooterData& dailyfooterobj) //记得#include头文件vector，因为日报的内容主体部分中的描述数据可能会有多条，所以用vector容器保存
		{
			string strtmp = "";

			//(1)拼接标题
			strtmp += "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n";
			strtmp += "<DailyReport>\n";
			strtmp += "    <Header>\n";
			strtmp += "        <DepName>" + dailyheaderobj.getDepName() + "</DepName>\n";
			strtmp += "        <GenDate>" + dailyheaderobj.getExportDate() + "</GenDate>\n";
			strtmp += "    </Header>\n";

			//(2)拼接内容主体，内容主体中的描述数据会有多条，因此需要迭代
			strtmp += "    <Body>\n";
			for (auto iter = vec_dailycontobj.begin(); iter != vec_dailycontobj.end(); ++iter)
			{
				ostringstream oss; //记得#include头文件sstream
				oss << (*iter)->getSpendTime();
				strtmp += "        <Content>" + (*iter)->getContent() + "</Content>\n";
				strtmp += "        <SpendTime>花费的时间：" + oss.str() + "小时" + "</SpendTime>\n";
			} //end for
			strtmp += "    </Body>\n";

			//(3)拼接结尾
			strtmp += "    <Footer>\n";
			strtmp += "        <UserName>报告人:" + dailyfooterobj.getUserName() + "</UserName>\n";
			strtmp += "    </Footer>\n";

			strtmp += "</DailyReport>\n";

			//(4)导出到真实文件的代码略，只展示在屏幕上文件的内容
			cout << strtmp;
		}
	};

	//-----------------------------
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
		virtual void buildHeader(DailyHeaderData& dailyheaderobj)//拼接标题
		{
			m_strResult += dailyheaderobj.getDepName() + "," + dailyheaderobj.getExportDate() + "\n";
		}
		virtual void buildBody(vector<DailyContentData*>& vec_dailycontobj)//拼接内容主体
		{
			for (auto iter = vec_dailycontobj.begin(); iter != vec_dailycontobj.end(); ++iter)
			{
				ostringstream oss; //记得#include头文件sstream
				oss << (*iter)->getSpendTime();
				m_strResult += (*iter)->getContent() + ":(花费的时间：" + oss.str() + "小时)" + "\n";
			} //end for
		}
		virtual void buildFooter(DailyFooterData& dailyfooterobj)//拼接结尾
		{
			m_strResult += "报告人:" + dailyfooterobj.getUserName() + "\n";
		}
	};

	//XML文件构建器类
	class XmlFileBuilder :public FileBuilder
	{
	public:
		virtual void buildHeader(DailyHeaderData& dailyheaderobj)//拼接标题
		{
			m_strResult += "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n";
			m_strResult += "<DailyReport>\n";

			m_strResult += "    <Header>\n";
			m_strResult += "        <DepName>" + dailyheaderobj.getDepName() + "</DepName>\n";
			m_strResult += "        <GenDate>" + dailyheaderobj.getExportDate() + "</GenDate>\n";
			m_strResult += "    </Header>\n";
		}
		virtual void buildBody(vector<DailyContentData*>& vec_dailycontobj)//拼接内容主体
		{
			m_strResult += "    <Body>\n";
			for (auto iter = vec_dailycontobj.begin(); iter != vec_dailycontobj.end(); ++iter)
			{
				ostringstream oss; //记得#include头文件sstream
				oss << (*iter)->getSpendTime();
				m_strResult += "        <Content>" + (*iter)->getContent() + "</Content>\n";
				m_strResult += "        <SpendTime>花费的时间：" + oss.str() + "小时" + "</SpendTime>\n";
			} //end for
			m_strResult += "    </Body>\n";
		}
		virtual void buildFooter(DailyFooterData& dailyfooterobj)//拼接结尾
		{
			m_strResult += "    <Footer>\n";
			m_strResult += "        <UserName>报告人:" + dailyfooterobj.getUserName() + "</UserName>\n";
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
			//注意，有时指挥者需要和构建器通过参数传递的方式交换数据，这里指挥者通过委托的方式把功能交给构建器完成
			m_pFileBuilder->buildHeader(dailyheaderobj);
			m_pFileBuilder->buildBody(vec_dailycontobj);
			m_pFileBuilder->buildFooter(dailyfooterobj);
			return m_pFileBuilder->GetResult();
		}

	private:
		FileBuilder* m_pFileBuilder;//指向所有构建器类的父类
	};

}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);//程序退出时检测内存泄漏并显示到“输出”窗口
	
	/*
	_nmsp1::Monster* pmonster = new _nmsp1::M_Element(); //创建一只元素类怪物
	pmonster->Assemble("1253679201245");

	//释放资源
	delete pmonster;
	*/

	/*
	_nmsp1::MonsterBuilder* pMonsterBuilder = new _nmsp1::M_UndeadBuilder(); //创建亡灵类怪物构建器类对象
	_nmsp1::MonsterDirector* pDirector = new _nmsp1::MonsterDirector(pMonsterBuilder);
	_nmsp1::Monster* pMonster = pDirector->Construct("1253679201245");//这里就构造出了一个完整的怪物对象

	//释放资源
	delete pMonster;
	delete pDirector;
	delete pMonsterBuilder;
	*/

	_nmsp2::DailyHeaderData* pdhd = new _nmsp2::DailyHeaderData("研发一部", "11月1日");
	_nmsp2::DailyContentData* pdcd1 = new _nmsp2::DailyContentData("完成A项目的需求分析工作", 3.5);
	_nmsp2::DailyContentData* pdcd2 = new _nmsp2::DailyContentData("确定A项目开发所使用的工具", 4.5);
	vector<_nmsp2::DailyContentData*> vec_dcd; //记得#include头文件vector
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
	cout << pDtr->Construct(*pdhd, vec_dcd, *pdfd) << endl;


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

