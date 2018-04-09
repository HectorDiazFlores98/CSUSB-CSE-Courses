/*
			0 	1	2
		   +---+---+---+
		0  | 0,0 | 1,0 | 2,0|
		 *  +---+---+---+
		1  | 0,1 | 1,1 | 2,1|
		 * +---+---+---+
		2  | 0,2 | 1,2 | 2,2|
		 * +---+---+---+
			
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>
#include <utility>
using namespace std;

class Board {
private:
	vector< vector<char> > data;
public:
	Board(int n)
	{
		this->resize(n);
	}
	void resize(int n)
	{
		this->data.resize(n);
		for (auto& row : this->data) {
			row.resize(n, '.');
		}
	}
	void clear()
	{
		for (auto& row : this->data) {
			for (auto& col : row) {
				col = '.';
			}
		}
	}
	char& operator()(int r, int c)
	{
		return this->data[r][c];
	}
	const char& operator()(int r, int c) const
	{
		return this->data[r][c];
	}
	int size() const
	{
		return this->data.size();
	}
};

std::ostream& operator<<(std::ostream& os, const Board& board)
{
	int s = board.size();
	for (int r = 0; r < s; ++r) {
		for (int c = 0; c < s; ++c) {
			os << board(r, c) << ' ';
		}
		os << std::endl;
	}
	return os;
}

class EightPuzzle : public Board {
public:
	EightPuzzle() : Board(3)
	{
		this->reset();
	}
	void reset()
	{
		char t = '1';
		for (int r = 0; r < 3; ++r) {
			for (int c = 0; c < 3; ++c) {
				(*this)(r, c) = t++;
			}
		}
		(*this)(2, 2) = ' ';
	}
	void shuffle()
	{
		std::default_random_engine prng(std::random_device{}());
		std::array<char, 9> a;
		char t = '1';
		std::generate_n(a.begin(), 8, [&](){ return t++; });
		a[8] = ' ';
		std::shuffle(a.begin(), a.end(), prng);
		auto it = a.begin();
		for (int r = 0; r < 3; ++r) {
			for (int c = 0; c < 3; ++c) {
				(*this)(r, c) = *it++;
			}
		}
	}
	bool move(char dir)
	{
		/* Swaps the blank tile with an adjacent 
		 * tile specified by dir. dir can be 'w',
		 * 'a', 's', or 'd' to indicate the top, 
		 * left, bottom, or right-adjacent tile 
		 * respectively.
		 *
		 * Returns true if the swap was successful
		 * or false if the blank tile cannot be 
		 * moved in the specified direction.
		 */
		 //cout << "move loop 1\n";
		 int blankXaxis = 0;
		 int blankYaxis = 0;
		 int moveXaxis = 0;
		 int moveYaxis = 0;
		 
		 for(int y = 0; y < 3; y++)
		 {
		 	for(int x = 0; x < 3; x++)
		 	{
		 		if((*this)(y,x) == ' ')
		 		{
					blankXaxis = x;
					blankYaxis = y;
		 		}
		 	}
		 }
		 
		 //This block will serve to check the moves
		 //Depending on the key, it will add one or take away one to the x or y axis
		 //The fail safe is if the blank space is already on the outer limit to the key selected, it will return fase
		 if(dir == 'w')
		 {
		 	if(blankYaxis == 0)
		 	{
		 		return false;
		 	}
		 	
		 	moveYaxis = blankYaxis - 1;
		 	moveXaxis = blankXaxis;
		 	swap((*this)(moveYaxis,moveXaxis),(*this)(blankYaxis,blankXaxis));
		 	return true;
		 }
		 else if(dir == 's')
		 {
		 	if(blankYaxis == 2)
		 	{
		 		return false;
		 	}
		 	moveYaxis = blankYaxis + 1;
		 	moveXaxis = blankXaxis;
			swap((*this)(moveYaxis,moveXaxis),(*this)(blankYaxis,blankXaxis));
		 	return true;
		 }
		 else if(dir == 'a')
		 {
		 	if(blankXaxis == 0)
		 	{
		 		return false;
		 	}
		 	moveXaxis = blankXaxis - 1;
		 	moveYaxis = blankYaxis;
		 	swap((*this)(moveYaxis,moveXaxis),(*this)(blankYaxis,blankXaxis));
		 	return true;
		 }
		 else if(dir == 'd')
		 {
		 	if(blankXaxis == 2)
		 	{
		 		return false;
		 	}
		 	moveXaxis = blankXaxis + 1;
		 	moveYaxis = blankYaxis;
		 	swap((*this)(moveYaxis,moveXaxis),(*this)(blankYaxis,blankXaxis));
		 	return true;
		 }
		 else return false;
	}
	bool completed() const
	{
		/* Returns true if the 8 puzzle 
		 * is completed. The 8 puzzle is 
		 * completed when it looks like 
		 * this:
		 *
		 * +---+---+---+
		 * | 1 | 2 | 3 |
		 * +---+---+---+
		 * | 4 | 5 | 6 |
		 * +---+---+---+
		 * | 7 | 8 |   |
		 * +---+---+---+
		 */
		 
		 //This function will have a seeded array that will then be compared to the current board
		 //if they are a match the game is won.
		 char compare[3][3];
		 
		 char t ='1';
		 
		 int timesCorrect = 0;
		 
		 for(int i = 0; i < 3; i++)
		 {
		 	for(int k = 0; k < 3;k++)
		 	{
		 		compare[i][k] = t++;
		 		compare[3][3] = ' ';
		 	}
		 }
		 
		 for(int a = 0; a < 3; a++)
		 {
		 	for(int b = 0; b < 3;b++)
		 	{
		 		if(compare[a][b] == (*this)(a,b))
		 		{
		 			timesCorrect++;
		 		}
		 	}
		 }
		 if(timesCorrect==8)
		 {
		 	cout << "You have finished the puzzle!\n";
		 	return true;
		 }
		 return false;
	
	}
};

int main()
{
	EightPuzzle ep;
	char dir;

	ep.shuffle();
	do {
		cout << ep << endl;
		if (not (cin >> dir)) break;
		if (not ep.move(dir)) {
			cout << "Invalid move." << endl;
		}
	} while (not ep.completed());
	return 0;
}