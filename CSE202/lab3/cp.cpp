#include <fstream>
#include <iostream>
#include <string>


using namespace std;


int main()
{
    //This will ask the user which file to copy
    cout << "Please enter the name of the file you want to copy, along with the type extention (.txt, .cpp, etc)\n";
    string toBeCopied;
    cin >> toBeCopied;
    
    //This will ask the user which file to copy to
    cout <<"Please enter the name of the file you want to copy it to, along with the type extention\n";
    string toBeCopiedTo;
    cin >> toBeCopiedTo;
    
    //This string will hold the temporary line
    string Temp;
    
    //ifstream as it will be an input to Temp
    ifstream fileToBeCopied(toBeCopied);
    
    //ofstream as this file will be written to
    ofstream fileToBeCopiedTo;
    
    //Opens the file that will be copied to
    fileToBeCopiedTo.open(toBeCopiedTo);
    
    //Counts how many lines it has copied
    int line = 1;
    
    //While this loop is running it will let the user know which line it is copying and then writes it to the file chosen
    while(getline(fileToBeCopied, Temp))
    {
        fileToBeCopiedTo << Temp << "\n";
        cout << "Copying line " << line << "...\n";
        line++;
        
    }
    //closes both files to prevent any leaks
    fileToBeCopiedTo.close();
    fileToBeCopied.close();
    
    //display the process is done
    cout << "Done!" << endl;
}