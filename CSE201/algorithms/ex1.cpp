#include <iostream>

using namespace std;

int main(){
    
    //  THE PROGRAM SHOULD CONTINUE LOOPING UNTIL THE USER GUESSES THE NUMBER. 
    
    //declare the variables
    int user_guess;
    
    //ask user for an input/guess
    cout << "Guess-The-Number Game!\n";
    cout << "\n" << "You will have to guess the number i'm thinking of!\n";
    cout << "your guess = ";
    cin >> user_guess;

    //Loop will ask for a new input if its too small
    while(user_guess < 1776)
    {
        cout << "Your guess is too small\n" << "\n";
    	cout << "Next guess = ";
    	user_guess = 0;
    	cin >> user_guess;
    	
    }
    
    //loop will ask for a new input if it is too big    
    while(user_guess > 1776) 
    {
    	 cout << "Your guess is too big\n" << "\n";
    	 cout << "Next guess = ";
    	 user_guess = 0;
    	 cin >> user_guess;
            
    }
    
    
        //if guessed correctly it will say so
    if (user_guess == 1776)
    {
    	cout << "You guessed correctly!\n";
    }
    
    
    
    cout << "\n" << "Thanks for playing!\n";
}
