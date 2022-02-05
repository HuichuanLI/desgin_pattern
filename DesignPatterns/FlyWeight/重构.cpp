#include <iostream>
#include <string>
#include <vector>
using namespace std;

//���ӵ���ɫ
enum PieceColor { BLACK, WHTIE };
//���ӵ�λ��
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
	void draw() { cout << "����һ������ " << endl; }
};
class WhitePiece :public Piece {
public:
	WhitePiece(PieceColor color) :Piece(color) {}
	~WhitePiece() {}
	void draw() { cout << "����һ������ " << endl; }
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
			
			cout << m_blackName << "��" << pos.m_x << "," << pos.m_y << "����һ��" << endl;
			m_pBlackPiece->draw();
		}
		else {
			if(m_pWhitePiece == nullptr)
				m_pWhitePiece = new WhitePiece(color);
			
			
			cout << m_WhiteName << "��" << pos.m_x << "," << pos.m_y << "����һ��" << endl;
			m_pWhitePiece->draw();
		}
		m_vecPiece.push_back(pos);
	}
	void clear() {
		delete m_pBlackPiece;
		delete m_pWhitePiece;
	}
private:
	vector<PiecePos> m_vecPiece;//�����ϵ�����,
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