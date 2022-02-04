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
//#include <vector>
//using namespace std;
//
////棋子的颜色
//enum PieceColor{BLACK,WHTIE};
////棋子的位置
//struct PiecePos {
//	int m_x;
//	int m_y;
//	PiecePos(int a,int b):m_x(a),m_y(b){}
//};
//
//class Piece {
//
//public:
//	Piece(PieceColor color, PiecePos pos) : m_color(color), m_pos(pos) {
//
//	}
//	~Piece(){}
//	virtual void draw(){}
//protected:
//	PieceColor m_color;
//	PiecePos m_pos;
//};
//
//class BlackPiece :public Piece {
//public:
//	BlackPiece(PieceColor color,PiecePos pos):Piece(color,pos){}
//	~BlackPiece(){}
//	void draw() { cout << "绘制一个黑棋 " << endl; }
//};
//class WhitePiece :public Piece {
//public:
//	WhitePiece(PieceColor color, PiecePos pos) :Piece(color, pos) {}
//	~WhitePiece() {}
//	void draw() { cout << "绘制一个白棋 " << endl; }
//};
//
//class PieceBoard {
//public:
//	PieceBoard(string black,string white):m_blackName(black),m_WhiteName(white){}
//	~PieceBoard()
//	{
//		clear();
//	}
//	void setPiece(PieceColor color, PiecePos pos) {
//		Piece *pPiece=nullptr;
//		if (color == BLACK) {
//			pPiece = new BlackPiece(color, pos);
//			cout << m_blackName << "在" << pos.m_x << "," << pos.m_y <<"下了一步"<< endl;
//		}
//		else {
//			pPiece = new WhitePiece(color, pos);
//			cout << m_WhiteName << "在" << pos.m_x << "," << pos.m_y << "下了一步" << endl;
//		}
//		m_vecPiece.push_back(pPiece);
//	}
//	void clear() {
//		for (auto iter = m_vecPiece.begin();iter != m_vecPiece.end();iter++) {
//			delete (*iter);
//	}
//	}
//private:
//	vector<Piece*> m_vecPiece;//棋盘上的棋子,
//	string m_blackName;
//	string m_WhiteName;
//};
