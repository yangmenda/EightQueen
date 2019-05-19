#include<iostream>
using namespace std;
class ChessBoard
{
public:
	ChessBoard();
	ChessBoard(int);
	void findSolutions();
private:
	const bool avaliable;
	const int squares, norm;
	bool *column, *left, *right;
	int *position, howmany;
	char m[10][10];
	void putQueen(int);
	void printBoard();
	void initBoard();
	void Delete();
};
ChessBoard::ChessBoard() :avaliable(true), squares(8), norm(squares - 1)
{
	initBoard();
}
ChessBoard::ChessBoard(int n) : avaliable(true), squares(n), norm(squares - 1)
{
	initBoard();
}
void ChessBoard::initBoard()
{
	register int i;
	column = new bool[squares];
	position = new int[squares];
	left = new bool[squares * 2 - 1];//���Խ��߿ɷ��ûʺ�Ĳ�������
	right = new bool[squares * 2 - 1];//���Խ��߿ɷ��ûʺ�Ĳ�������
	for (i = 0; i < squares; ++i)	//�ʺ�����λ�õ���λ��
		position[i] = -1;
	for (i = 0; i < squares; ++i)	//��ÿһ�У�ÿһ�����Խ�����Ϊ���Է��ûʺ��״̬
		column[i] = avaliable;
	for (i = 0; i < squares * 2 - 1; ++i)
		left[i] = right[i] = avaliable;
	howmany = 0;
}
void ChessBoard::printBoard()
{
	howmany++;
	cout << howmany << "�ⷨ�У�" << endl;
	for (int i = 0; i != squares; ++i)
		for (int j = 0; j != squares; ++j)
		{
			m[i][j] = '1';
		}

	for (int row = 0; row != squares; ++row)
	{
		m[row][position[row]] = '*';
	}
	for (int i = 0; i != squares; ++i)
	{
		for (int j = 0; j != squares; ++j)
		{
			cout << m[i][j];
		}
		cout << endl;
	}
	cout << endl;

}
void ChessBoard::putQueen(int row)
{
	for (int col = 0; col != squares; ++col)
	{
		if (column[col] == avaliable && left[row+col] == avaliable && right[row-col+norm] == avaliable)//����λ�ÿ��Է��ûʺ�
		{
			position[row] = col;	//�ʺ�λ�ô�������
			column[col] = !avaliable;
			left[row + col] = !avaliable;	//�ʺ����ڵĸ��Խ��߶�������
			right[row - col + norm] = !avaliable;//�ʺ����ڵ����Խ��߶�������
			if (row < squares - 1)
				putQueen(row + 1);//û�ŵ����һ�У������һ�еݹ���з����Ӳ���
			else printBoard();
			column[col] = avaliable;
			left[row + col] = avaliable;
			right[row - col + norm] = avaliable;//����������λ�� ��Ϊ���Է���
		}
	}
}
void ChessBoard::findSolutions()
{
	putQueen(0);
	cout << howmany << "���ҵ���" << endl;

}
int main()
{
	ChessBoard chess(7);
	chess.findSolutions();
	return 0;
}