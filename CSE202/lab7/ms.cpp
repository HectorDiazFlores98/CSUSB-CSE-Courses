/*
	Have two vectors, one for the displayed board and a board for mine locations
	
	data vector		mineLocation vector 							updated mineLocation
	. . . . .			0 0 0 0 0									0 0 1 0 0
	. . . . .			0 0 0 0 0		random number gen			0 1 0 0 0
	. . . . .			0 0 0 0 0	->  fills coordinates		->  0 0 0 1 0
	. . . . .			0 0 0 0 0		and updates the vector      0 1 0 1 0
	. . . . .			0 0 0 0 0									0 0 0 0 0
*/ 

#include <vector>
#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

/*class board copied from lab6

 Edits to class Board, correcting mistakes i had from last week
edited the != and == operator to get rid of usless nested loops
edited the clear() function to reset the entire board instead of only partially reseting it
*/

//this random engine will serve to fill spots where mines will be
default_random_engine prng(random_device{}());
uniform_int_distribution<int> idist(0, 4);

class Board 
{
	friend ostream& operator<<(ostream& os, const Board& board);
	private:
		//this vector of vectors will store the board
		vector<vector<char>> data;
	public:
		//This constructor will initialize the object to a board of NxN with a char of '.'""
		explicit Board(int n)
		{
			//this temp vector will hold the line of dots
			vector<char>tempVector;
			int k = 0;
			for(int i = 0; i < n; i++)
			{	
				while( k < n)
				{
					tempVector.push_back('.');
					k++;
				}
				data.push_back(tempVector);
			}
		}
		
		//returns a refrence to the chosen row and coloumn
		char& operator()(int row, int col)
		{
			return data[row][col];
		}
	
		//returns a read only version of the the row and column 
		const char& operator()(int row, int col) const
		{
			return data[row][col];
		}
		
		//resets the object to hold '.'
		void clear()
		{
			for(int y = 0; y <= data.size()-1; y++)
			{
				for(int z = 0; z <= data.size()-1; z++)
				{
					data[y][z] = '.';
				}
			}
		}
		
		//overload the operator to compare the object, something the == operator could normally do
		bool operator==(const Board& other) const
		{
			if (data != other.data)
			{
				return false;
			}
			return true;
		}
		
		bool operator!=(const Board& other) const
		{
			if (data != other.data)
			{
				return true;
			}
			return false;
		}

};

//class minesweeper with inheritance of public board functions
class Minesweeper : public Board
{ 
	private:
		//this vector will hold coordinates for mine locations
		vector<vector<int>>mineLocation;
	
	public:
		//constructor will be initialized as a copy of board
		//I have it be size 5 as the default size according to lab instructions
		Minesweeper():Board(5)
		{
			//this vector will serve as a copy of the data vector, except instead of '.', 
			//it will be filled with 0 and will change to a 1 if there is a mine when random coordinates are generated 
			vector<int> tempVector;
			
			//this loop will push back the zeros 
			int k = 0;
			for(int i = 0; i <= 5;i++)
			{
				while(k <= i)
				{
					tempVector.push_back(0);
					k++;
				}
				mineLocation.push_back(tempVector);
			}
			//this will serve as a random coordinate for the mine locations 
			int randomRow = 0;
			int randomCol = 0;
			//This loop will change the random vector index to a 1 to represent a mine
			for(int k = 0; k<= 4;k++)
			{
				randomRow = idist(prng);
				randomCol = idist(prng);
				mineLocation[randomRow][randomCol] = 1;
			}
		}
		
		//changes the data vector to 'M' if coordinate of mineLocation has a mine(1) or 'C' if not(0)
		void reveal(int row, int col)
		{
			if(mineLocation[row][col] == 1)
			{
				operator()(row,col) = 'M';
				 
			}
			else if (mineLocation[row][col] == 0)
			{
				operator()(row,col) = 'C';
	
			}
		}
		
	

};

//overload the << operator to display the object
//Edited the overloaded opererator to know also label both the column and rows of the board
ostream& operator<<(ostream& os, const Board& board)
{
	int z = 0;
	//string temp = "";
	//this loop displays the outer coordinates 
	for(int i = 0; i <= board.data.size()-1;i++)
	{
		while(z <= board.data.size()-1)
		{
			if(z == 0)
			{
				os << setw(4) << z;
				z++;
			}
			else 
			{
				os << setw(3) << z;
				z++;
				if(z == board.data.size())
				{
					os << "\n";
				}
			}
		}
		//this will display the row coordinates
		os << i << setw(3);
		
		for(int k = 0; k <= board.data.size()-1; k++)
		{
			os << board(i,k) << setw(3);
			if(k == board.data.size()-1)
			{ 
				cout << "\n";
			}
		}
	}
	
	return os;
}

int main()
{ 
	//Main function provided by Mark Swoope
	Minesweeper ms;
	int row, col;
	int guesses = 0;

	while (guesses < 21) 
	{
		cout << ms << endl;
		cout << "Enter row and column: ";
		cin >> row >> col;
		ms.reveal(row, col);
		if (ms(row, col) == 'M') break;
		++guesses;
		
	}
	
	cout << ms << endl;
	return 0;
	
}
