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
	left = new bool[squares * 2 - 1];//副对角线可放置皇后的布尔数组
	right = new bool[squares * 2 - 1];//主对角线可放置皇后的布尔数组
	for (i = 0; i < squares; ++i)	//皇后所在位置的行位置
		position[i] = -1;
	for (i = 0; i < squares; ++i)	//将每一列，每一主副对角线设为可以放置皇后的状态
		column[i] = avaliable;
	for (i = 0; i < squares * 2 - 1; ++i)
		left[i] = right[i] = avaliable;
	howmany = 0;
}
void ChessBoard::printBoard()
{
	howmany++;
	cout << howmany << "解法有：" << endl;
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
		if (column[col] == avaliable && left[row+col] == avaliable && right[row-col+norm] == avaliable)//若此位置可以放置皇后
		{
			position[row] = col;	//皇后位置存入数组
			column[col] = !avaliable;
			left[row + col] = !avaliable;	//皇后所在的副对角线都不可用
			right[row - col + norm] = !avaliable;//皇后所在的主对角线都不可用
			if (row < squares - 1)
				putQueen(row + 1);//没放到最后一行，则对下一行递归进行放棋子操作
			else printBoard();
			column[col] = avaliable;
			left[row + col] = avaliable;
			right[row - col + norm] = avaliable;//将棋盘所有位置 设为可以放置
		}
	}
}
void ChessBoard::findSolutions()
{
	putQueen(0);
	cout << howmany << "个找到了" << endl;

}
int main()
{
	ChessBoard chess(7);
	chess.findSolutions();
	return 0;
}