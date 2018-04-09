#include <iostream>
#include <vector>

using namespace std;

//This is the function that holds the possible words to play with in hangman 
string createWord(int &userChoice)
{
    //vector with possible words
    vector<string>Dictionary(5);
    Dictionary[0] = "hello";
    Dictionary[1] = "jazz";
    Dictionary[2] = "computer";
    Dictionary[3] = "program";
    Dictionary[4] = "school";
    
    //it will return the word based on the number the user chose
    return Dictionary[userChoice];
}

//This will show the clean board with the appropriate amount of spaces
string Board(string &playedWord)
{
    //this will be the board
    string board = "";
    //it will append a number of underscores based on the amount of letters the word has
    for(int i = 0; i <= playedWord.size()-1;i++)
    {
        board.append("_");
    }
    //return the game board
    return board;
}

//this will compare the guessed letter to the 
void checkGuess(string &playedWord, string &currentBoard, char &guessedLetter, int &wrongGuesses)
{
    //this will count the number of times the board changes
    int numberOfChanges = 0;
    //this loop will check if the inputed char matches a char in the string
    for(int i = 0; i <= playedWord.size();i++)
    {
        //this will compare the char to the char of index i
        char currentLetter = playedWord[i];
        //if they are equal then the blank space will be replaced 
        if(guessedLetter == currentLetter)
        {
            //replaces the blank space with the char and increases the number of changes made
            currentBoard[i] = guessedLetter;
            numberOfChanges++;
        }
    }
    //if no changes were made, it will register as a wrong guess
    if(numberOfChanges == 0)
    {
        wrongGuesses++;
    }
}

//this function will check if the player has correctly guessed the word 
bool checkWin(string &currentBoard, string &playedWord)
{
    //compares
    if(currentBoard == playedWord)
    {
        return true;
    }
    else return false; 
}
//this function will check to see if the player has run out of turns
bool checkLoss(int &wrongGuesses,string &playedWord)
{
    if(wrongGuesses == playedWord.size()-1)
    {
        return true;
    }
    else return false;
}

int main()
{
    
    int userChoice = 0;
    string activeGuesses;
    cout << "Please choose a number from 0-4 to get started\n";
    cin >> userChoice;
    
    //this loop will run as long as the user inputs an invalid choice
    while( userChoice >=5 || userChoice <= -1)
    {
        cout << "Please choose a number between 0 and 4\n";
        cin >> userChoice;
    }
    
    //stores the chosen word, game board, chosen letter and number of wrong guesses
    string playedWord = createWord(userChoice);
    string currentBoard = Board(playedWord);
    char guessedLetter;
    int wrongGuesses = 0;
    
    //this loop will run as long as the player has not guessed the word correctly or has not run out of guesses
    bool gameOver = false;
    while(gameOver == false)
    {
        //display the current board as well as the number of guesses left
        cout << currentBoard <<"\n" << "You have " << (playedWord.size() - 1)-wrongGuesses << " guesses left\n";
        //takes in the players guess
        cin >> guessedLetter;
        //checks to see if it was a correct guess 
        checkGuess(playedWord,currentBoard,guessedLetter,wrongGuesses);
        
        //runs the functions to test for a win or loss
        if(checkLoss(wrongGuesses,playedWord) == true)
        {
            cout << "You have lost, the word was: " << playedWord << "\n";
            gameOver = true;
        }
        else if(checkWin(currentBoard,playedWord) == true)
        {
            cout << "You won!!!!\n" << "The word was: " << playedWord << "\n";
            gameOver = true;
        }
        
    }
}