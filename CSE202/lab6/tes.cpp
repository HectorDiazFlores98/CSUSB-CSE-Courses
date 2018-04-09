#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

//Exercise 1
class Board 
{
	//Exercise 4
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
		//Exercise 2
		void clear()
		{
			for(int y = 0; y <= data.size()-1; y++)
			{
				for(int z = 0; z <= y; z++)
				{
					data[y][z] = '.';
				}
			}
		}
		
		//overload the operator to compare the object, something the == operator could normally do
		//Exercise 3
		bool operator==(const Board& other) const
		{
			for(int i = 0; i <= data.size();i++)
			{
				for(int k = 0; k <= i; k++)
				{
					if (data != other.data)
					{
						return false;
					}
				}
			}
			return true;
		}
		
		//Exercise 3
		bool operator!=(const Board& other) const
		{
			for(int i = 0; i <= data.size();i++)
			{
				for(int k = 0; k <= i; k++)
				{
					if (data != other.data)
					{
						return true;
					}
				}
			}
			return false;
		}
};

//overload the << operator to display the object
// Exercise 3
ostream& operator<<(ostream& os, const Board& board)
{
	string temp = "";
	for(int i = 0; i <= board.data.size()-1;i++)
	{
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
	//this block creates object 1
	cout << "This is a class test, lab 6\n\n";
	int boardSize1 = 0;
	cout << "Enter a size for the first board\n";
	cin >> boardSize1;
	cout << "Creating an object of size " << boardSize1 << "\n\n";
	Board Board1(boardSize1);
	
	//this block creates object 2
	cout << "Enter a size for the size of the second board\n";
	int boardSize2 = 0;
	cin >> boardSize2;
	cout << "Creating an object of size " << boardSize2 << "\n\n";
	Board Board2(boardSize2);
	
	//this block will display the refrence to the column and row
	int row, col = 0;
	cout << "Enter a number for row and a number for column\n";
	cin >> row;
	while(row >= boardSize1)
	{
		cout << "That is out of bounds, chose a smaller number\n";
		cin >> row;
	}
	cin >> col;
	while(col >= boardSize1)
	{
		cout << "That is out of bounds, chose a smaller number\n";
		cin >> col;
	}
	cout << "Displaying the char in row " << row << " and col " << col << " of board 1" << endl;
	cout << Board1(row,col) << endl; 
	
	//this block will display the overloaded == operator if equal or != if not equal
	cout <<"Displaying the overload of the comparison operator\n";
	if(Board1 == Board2)
	{
		cout << "Board 1 is equal to Board 2\n\n";
	}
	else if(Board1 != Board2)
	{
		cout << "Board 1 is not equal to Board 2\n\n";
	}
	
	//displays the first board
	cout << "Displaying Board 1\n" << Board1 << "\n\n";
	
	//displays the second board
	cout << "Displaying Board 2\n" << Board2 << "\n\n";
	
	//this block runs the clear function
	cout << "Running the clear() function\n\n";
	Board1.clear();
	Board2.clear();
	cout << "Board 1 cleared....\n";
	cout << "Board 1\n" << Board1 << "\n\n";
	cout << "Board2 cleared....\n";
	cout << "Board 2\n" << Board2 << "\n\n";
}





vector<int> tempVector;
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
			
			for(int k = 0; k<= 4;k++)
			{
				int randomRow = rand() % 4;
				int randomCol = rand() % 4;
				mineLocation[randomCol][randomRow] = 1;
			}
		}
		
		
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