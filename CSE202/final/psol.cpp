/*
test wrong input: left, right, up, down, outside boundries, full spot, one over, 
far away, diagnal----all test passed.
test victory -- Passed
test no more moves--Passed

*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>
#include <utility>
using namespace std;

class Board {
    friend ostream& operator<<(ostream& os, const Board& board);
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



class Psol : public Board
{
    public:
        Psol() : Board(7)
        {
            (*this)(0,0) = ' ';
            (*this)(0,1) = ' ';
            (*this)(1,0) = ' ';
            (*this)(1,1) = ' ';
            (*this)(5,0) = ' ';
            (*this)(5,1) = ' ';
            (*this)(6,0) = ' ';
            (*this)(6,1) = ' ';
            (*this)(0,5) = ' ';
            (*this)(1,5) = ' ';
            (*this)(0,6) = ' ';
            (*this)(1,6) = ' ';
            (*this)(5,5) = ' ';
            (*this)(5,6) = ' ';
            (*this)(6,5) = ' ';
            (*this)(6,6) = ' ';
            (*this)(3,3) = 'o';
        }
        bool move(int userMoveX, int userMoveY, int targetX, int targetY)
        {
            /*Common out of bound user errors
            1. user chooses peg outside playing area
            2. player tries to place peg outside playing area
            3. player tries to place peg in a occupied space 
            4. player tries to pick up empty peg peice
            5. player tries to move more than two spaces 
            *5 is implimented in the swap 'if' statments
            */
            
            //Common error 1
            if((*this)(userMoveX,userMoveY) == ' ')
            {
                cout << "//ERROR//\nPlease choose a peg thats in the board parameters\n";
                return false;
            }
            //Common error 2
            else if((*this)(targetX,targetY) == ' ')
            {
                cout << "//ERROR//\nPlease place the peg in a spot within the board parameters\n";
                return false;
            }
            //common error 3
            else if((*this)(targetX,targetY) == '.')
            {
                cout << "//ERROR//\nPlease place the peg in an empty spot\n";
                return false;
            }
            //common error 4
            else if((*this)(userMoveX,userMoveY) == 'o')
            {
                cout << "//ERROR//\nYou cannot pick up an empty board piece\n";
                return false;
            }
            
            //if the user is trying to move a peg horizontally
            if(userMoveX == targetX)
            {
                //common error 5
                if(userMoveY - targetY > 2 )
                {
                    cout << "//ERROR//\nUnable to complete that move, try again!\n";
                    return false;
                }
                else if(userMoveY-targetY < -2)
                {
                    cout << "//ERROR//\nUnable to complete that move, try again!\n";
                    return false;
                }
                else  if(userMoveY - targetY == 1 )
                {
                    cout << "//ERROR//\nUnable to complete that move, try again!\n";
                    return false;
                }
                else if(userMoveY-targetY == -1)
                {
                    cout << "//ERROR//\nUnable to complete that move, try again!\n";
                    return false;
                }
                //this will check if it is a swap to the left or to the right
                else if(userMoveY - targetY == 2)
                {
                    (*this)(targetX,targetY+1) = 'o';
                    swap((*this)(userMoveX,userMoveY), (*this)(targetX,targetY));
                    return true;
                }
                else if(userMoveY - targetY == -2)
                {
                    (*this)(targetX,targetY-1) = 'o';
                    swap((*this)(userMoveX,userMoveY), (*this)(targetX,targetY));
                    return true;
                }
            }
            //this uses the same mechanics as the top functions, except its for a verticle move
            else if(userMoveY == targetY)
            {
                if(userMoveX - targetX > 2)
                {
                    cout << "//ERROR//\nUnable to complete that move, try again!\n";
                    return false;
                }
                else if(userMoveX - targetX < -2)
                {
                    cout << "//ERROR//\nUnable to complete that move, try again!\n";
                    return false;
                }
                else if(userMoveX - targetX == 1)
                {
                    cout << "//ERROR//\nUnable to complete that move, try again!\n";
                    return false;
                }
                else if(userMoveX - targetX == -1)
                {
                    cout << "//ERROR//\nUnable to complete that move, try again!\n";
                    return false;
                }
                else if(userMoveX - targetX == 2)
                {
                    
                    (*this)(targetX+1,targetY) = 'o';
                    swap((*this)(userMoveX,userMoveY), (*this)(targetX,targetY));
                    return true;
                }
                else if(userMoveX - targetX == -2)
                {
        
                    (*this)(targetX-1,targetY) = 'o';
                    swap((*this)(userMoveX,userMoveY), (*this)(targetX,targetY));
                    return true;
                }
            }
            else
            {
                cout << "//ERROR//\nUnable to complete that move, try again!\n";
                return false;
            }
        }
        //The bool will test to see if the game is over
        //if there are two board pieces there 
        bool gameOver()
        {
            int movesAvailable = 0;
            for(int i = 0; i <= 6; i++)
            {
                for(int k = 0; k<= 6; k++)
                {
                    if(i == 0)
                    {
                        if((*this)(i,k) == '.')
                        {
                            if((*this)(i+1,k) == '.')
                            {
                                movesAvailable++;
                            }
                            else if((*this)(i,k+1)=='.')
                            {
                                movesAvailable++;
                            }
                        }
                    }
                    else if(i == 6)
                    {
                        if((*this)(i,k) == '.')
                        {
                            if((*this)(i-1,k) == '.')
                            {
                                movesAvailable++;
                            }
                            else if((*this)(i,k-1)=='.')
                            {
                                movesAvailable++;
                            }
                        }
                    }
                    else if((*this)(i,k) == '.')
                    {
                        if((*this)(i-1,k) == '.')
                        {
                                movesAvailable++;
                        }
                        else if((*this)(i+1,k)== '.')
                        {
                            movesAvailable++;
                        }
                        else if((*this)(i,k-1)=='.')
                        {
                            movesAvailable++;
                        }
                        else if ((*this)(i,k+1)== '.')
                        {
                            movesAvailable++;
                        }
                    }
                }
            }
            
            if(movesAvailable < 1)
            {
                cout << "\n\nGAME OVER!\n\n";
                return true;
            }
            else return false;
        }
};

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
    Psol P;
    int moveX, moveY,targetX,targetY = 0;
    int plays = 0;
    while(!P.gameOver())
    {
        cout << P << endl;
        cout << "Enter a horizontal and verticle coordinate to move a peg\n";
        cin >> moveX >> moveY;
        while(moveX > 6 || moveY > 6)
        {
            cout << "Please choose a peg within board limits\n";
            cout << "X: ";
            cin >> moveX;
            cout << "Y: ";
            cin >> moveY;
        }
        cout << "Enter a horizontal and verticle coordinate to target\n";
        cin >> targetX >> targetY;
        while(targetX > 6 || targetY > 6)
        {
            cout << "Please choose a peg within board limits\n";
            cout << "Target X: ";
            cin >> targetX;
            cout << "Target Y: ";
            cin >> targetY;
        }
        P.move(moveX,moveY,targetX,targetY);
        plays++;
        
    }
    
    cout << "\n\nTotal moves: " << plays << "\n\n\n";
}
