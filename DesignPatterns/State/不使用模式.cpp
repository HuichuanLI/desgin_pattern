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
//#include <iostream>
//#include <string>
//#include <map> //用户名，用户的下载
//using namespace std;
//
//class DownloadManager {
//public:
//	void Down(string user, string DownItem) {
//		int oldDownCount = 0;
//		if (m_mapDownCount.count(user) > 0) {
//			oldDownCount = m_mapDownCount[user];
//		}
//		else {
//			m_mapDownCount[user] = 0;
//		}
//
//		oldDownCount++;
//		m_mapDownCount[user] = oldDownCount;
//
//		//判读的行为
//		if (oldDownCount == 1) {
//			//正常下载
//			m_mapDown[user] = DownItem;
//			cout << "欢迎您下载本资源" << endl;
//		}
//		else if(oldDownCount>1 && oldDownCount<3)
//		{
//			cout << "请您不要重复下载" << endl;
//		}
//		else if (oldDownCount >= 3 && oldDownCount < 5) {
//			//恶意下载
//			cout << "您有恶意下载的嫌疑，即将取消您的下载资格" << endl;
//		}
//		else if (oldDownCount >= 5) {
//			//进入黑名单
//			cout << "您已进入黑名单，禁止登录本系统" << endl;
//		}
//	}
//
//private:
//	map<string, string> m_mapDown;//<用户名，用户下载选项>
//		map<string, int> m_mapDownCount;//<用户名，用户下载次数>
//};
//
//int main() {
//	DownloadManager* pDM = new DownloadManager;
//	for (int i = 0;i < 5;i++) {
//		pDM->Down("dst","设计模式完全手册源代码");
//	}
//	system("pause");
//	return 0;
//}