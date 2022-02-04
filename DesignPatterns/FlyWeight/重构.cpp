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
#include <string>
#include <vector>
using namespace std;

//棋子的颜色
enum PieceColor { BLACK, WHTIE };
//棋子的位置
struct PiecePos {
	int m_x;
	int m_y;
	PiecePos(int a, int b) :m_x(a), m_y(b) {}
};

class Piece {

public:
	Piece(PieceColor color) : m_color(color) {

	}
	~Piece() {}
	virtual void draw() {}
protected:
	PieceColor m_color;
	
};

class BlackPiece :public Piece {
public:
	BlackPiece(PieceColor color) :Piece(color) {}
	~BlackPiece() {}
	void draw() { cout << "绘制一个黑棋 " << endl; }
};
class WhitePiece :public Piece {
public:
	WhitePiece(PieceColor color) :Piece(color) {}
	~WhitePiece() {}
	void draw() { cout << "绘制一个白棋 " << endl; }
};

class PieceBoard {
public:
	PieceBoard(string black, string white) :m_blackName(black), m_WhiteName(white) {
		m_pBlackPiece = nullptr;
		m_pWhitePiece = nullptr;
	}
	~PieceBoard()
	{
		clear();
	}
	void setPiece(PieceColor color, PiecePos pos) {
		
		if (color == BLACK) {
			if(m_pBlackPiece == nullptr)
				m_pBlackPiece = new BlackPiece(color);
			
			cout << m_blackName << "在" << pos.m_x << "," << pos.m_y << "下了一步" << endl;
			m_pBlackPiece->draw();
		}
		else {
			if(m_pWhitePiece == nullptr)
				m_pWhitePiece = new WhitePiece(color);
			
			
			cout << m_WhiteName << "在" << pos.m_x << "," << pos.m_y << "下了一步" << endl;
			m_pWhitePiece->draw();
		}
		m_vecPiece.push_back(pos);
	}
	void clear() {
		delete m_pBlackPiece;
		delete m_pWhitePiece;
	}
private:
	vector<PiecePos> m_vecPiece;//棋盘上的棋子,
	string m_blackName;
	string m_WhiteName;
	Piece* m_pBlackPiece;
	Piece* m_pWhitePiece;
};


int main(void) {
	
	PieceBoard pieceBoard("laoxia", "laoding");
	pieceBoard.setPiece(BLACK, PiecePos(44, 37));
	pieceBoard.setPiece(WHTIE, PiecePos(19, 70));
	pieceBoard.setPiece(BLACK, PiecePos(1, 1));
	pieceBoard.setPiece(WHTIE, PiecePos(2, 2));
	system("pause");
	return 0;
}