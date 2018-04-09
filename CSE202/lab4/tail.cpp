//Create a program that outputs only the last 10 lines of it's input. Your solution must use an array. Name your program: tail and your source file: tail.cpp. 
#include <iostream>

using namespace std;

int main()
{
    //this line will ask the user to typ as long as theyd like, it only stores the latest 10 lines 
    cout << "Please type as long as you like and I will display the last 10 lines of input, type 'EXIT' to stop the input\n";
    string lastTenLines[11];
    string tempLine;
    
    int i = 0;
    //This block will store the lines.
    //the line to end the input is 'EXIT'
    while(tempLine != "EXIT")
    {
        //this gets the users input
        getline(cin,tempLine);
        
        if(tempLine != "EXIT")
        {
            if(i < 10)
            {
                lastTenLines[i] = tempLine;
                i++;
            }
            else if(i == 10)
            {
                lastTenLines[10] = tempLine;
                for(int k = 0; k < 10; k++)
                {
                    lastTenLines[k] = lastTenLines[k+1];
                    
                }
            }
        }
    }
    
    //displays the last ten lines
    cout << "\n\nThe last ten lines you input are: \n\n";
    for(int k = 0; k < 10; k++)
    {
        cout << k+1 << ": " << lastTenLines[k] <<"\n";
    }
    
    
}