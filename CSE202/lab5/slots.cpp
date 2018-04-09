#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

void displaySlotMachine(vector<int>&slotArray)
{
    cout << "       ---Slot Machine----\n";
    cout << "Line 1 |- " << slotArray[0] << "  |  " << slotArray[1] << "  |  " << slotArray[2] << " -|\n";
    cout << "       -------------------\n";
    cout << "Line 2 |- " << slotArray[3] << "  |  " << slotArray[4] << "  |  " << slotArray[5] << " -|\n";
    cout << "       -------------------\n";
    cout << "Line 3 |- " << slotArray[6] << "  |  " << slotArray[7] << "  |  " << slotArray[8] << " -|\n";
    
}

void checkWinorLoss(vector<int>&slotArray, int &userBet, int &userCoins)
{
    if(slotArray[3] == slotArray[4] && slotArray[4] == slotArray[5])
    {
        cout << "\nLine 2 win!\nYou won " << userBet*100 << " coins!\n";
        userCoins += (userBet * 100);
    }
    else if(slotArray[0] == slotArray[1] && slotArray[1] == slotArray[2])
    {
        cout << "\nLine 1 win!\nYou won " << userBet*50 << " coins!\n";
        userCoins += (userBet * 50);
    }
    else if(slotArray[6] == slotArray[7] && slotArray[7] == slotArray[8])
    {
        cout << "\nLine 3 win!\nYou won " << userBet*50 << " coins!\n";
        userCoins += (userBet * 50);
    }
    else if(slotArray[0] == slotArray[4] && slotArray[4] == slotArray[8])
    {
        cout << "\nDiagonal down win!\nYou won " << userBet*25 << " coins!\n";
        userCoins += (userBet * 25);
    }
    else if(slotArray[6] == slotArray[4] && slotArray[4] == slotArray[2])
    {
        cout << "\nDiagonal up win!\nYou won " << userBet*25 << " coins!\n";
        userCoins += (userBet * 25);
    }
    else
    {
        cout << "Bad luck, you lost: " << userBet << " coins!";
        userCoins -=userBet;
    }
}
    
void checkBet(int &userCoins, int &userBet, bool &gameOver)
{
    if(userCoins == 0)
    {
        gameOver = true;
    }
    else if(userBet == 99)
    {
        gameOver = true;
    }
}

int main()
{
    srand(time(NULL));
    
    //This block is for users coins
    bool gameOver = false;
    int userCoins = 100;
    int userBet = 0;
    vector<int>slotArray;
    
    for(int i = 0; i <= 9; i++)
    {
        slotArray.push_back(rand() % 9 + 1);
    }
    
    //intro message
    cout << "Welcome to the slot machine\n"
            << "You start with 100 coins to bet with.\n"
                << "The game ends when you run out of coins, or you type in 99 in the coin selection\n";
                

    while(userBet != 99 && userCoins >= 1)
    {
        cout << "\nPlease choose to bet 1, 2 or 3 coins, or enter 99 to cash out: ";
        cin >> userBet;
        while(userBet != 99 && userCoins >= 1)
        {    
            displaySlotMachine(slotArray);
            checkWinorLoss(slotArray,userBet,userCoins);
            
            for(int k = 0; k <=slotArray.size()-1;k++)
            {
                slotArray[k] = rand() % 9 + 1; 
            }
            cout << "\nCoins: " << userCoins << endl;
            cout << "\nPlease choose to bet 1, 2 or 3 coins, or enter 99 to cash out: ";
        cin >> userBet;
        }
        
        if(userCoins <= 1)
        {
            cout << "You've lost all your coins!\n"
                    << "Better luck next time!\n";
        }
        else if(userBet == 99)
        {
            cout << "Thanks for playing\n"
                    << "You're cashing out with " << userCoins << " coins!\n";
        }
    }
    
}