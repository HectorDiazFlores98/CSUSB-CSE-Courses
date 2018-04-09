#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

//Replaces the cell choice with the AI's mark
void AIturn(vector<string> & cells, int & AIMove)
{
    cells[AIMove] = "O";
}


//This will choose the correct character for whoevers turn it is.
void Replace_Text (vector<string> & cells, int & choice)
{
    
    cells[choice] = "X";
}
 

//This will print the board, it will be on a loop and will be updated constantly with player choices. 
void Print_Board(vector<string> & cells)
{
    cout << "-------------------\n";
    cout << "|     |     |     |\n";
    cout << "|  " << cells[1] << "  |  " << cells[2] << "  |  " << cells[3] << "  |\n";
    cout << "-------------------\n";
    cout << "|     |     |     |\n";
    cout << "|  " << cells[4] << "  |  " << cells[5] << "  |  " << cells[6] << "  |\n";
    cout << "-------------------\n";
    cout << "|     |     |     |\n";
    cout << "|  " << cells[7] << "  |  " << cells[8] << "  |  " << cells[9] << "  |\n";
    cout << "-------------------\n";
}




int main()
{
    //This will create the vector that holds all of the values of the board
    vector <string> cells(10);
    cells[1] = "1";
    cells[2] = "2";
    cells[3] = "3";
    cells[4] = "4";
    cells[5] = "5";
    cells[6] = "6";
    cells[7] = "7";
    cells[8] = "8";
    cells[9] = "9";
    
    //This array will hold all the used cells
    int UsedCells[10];
    UsedCells[1] = 0;
    UsedCells[2] = 0; 
    UsedCells[3] = 0; 
    UsedCells[4] = 0; 
    UsedCells[5] = 0; 
    UsedCells[6] = 0; 
    UsedCells[7] = 0; 
    UsedCells[8] = 0; 
    UsedCells[9] = 0;
    
    
    //As long as this bool is false, the game will loop
    bool game_over = false;
    //This will be the choice for the player
    int choice;
    
    srand(time(NULL));
    
    
    while(game_over == false)
    {
        //Prints the first board
        Print_Board(cells);
        
        //Asks the first player for a choice 
        cout << "\nPlease choose a cell to fill in with you mark: ";
        cin >> choice;
        
        while(choice > 9 || choice < 1)
        {
            cout << "Please choose an open number in the range of 1 - 9: ";
            cin >> choice;
        }
        
        UsedCells[choice] = 1;
        while(UsedCells[choice] == 1)
        {
            cout << "That cell is already chosen, please choose again: ";
            cin >> choice;
        }
        
        
        //Replaces the text in the vector and prints the board, then adds one to the player turn to change player mark
        Replace_Text(cells,choice);
        
        int AIMove = rand() % 8 + 1;
        
        while(UsedCells[AIMove] == 1)
        {
            AIMove = AIMove + 1;
            if(AIMove > 9)
            {
                AIMove = 0;
            }
        }
        
        AIturn(cells, AIMove);
    
    }
    cout << "\nEnd Game\n";
}