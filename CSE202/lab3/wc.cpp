#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//this loop checks the number of chars in a string, not including the spaces
void checkChars(string &userFileTempString, int &charCount)
{
    
   for(int i = 0; i <= userFileTempString.size()-1; i++)
    {
        if(!isspace(userFileTempString[i]))
        {
            charCount++;
        }
    } 
}

//this loop will check the number of words in a string
void checkWords(string &userFileTempString, int &wordCount)
{
    
    //if the string is empty do nothing 
    if(userFileTempString.size()-1 == 0)
    {
    
    }
    //else count at least one word
    else wordCount++;
    
    //if there is a space count it as a word
    for(int i = 0; i <= userFileTempString.size()-1;i++)    
    {
        if(isspace(userFileTempString[i]))
        {
            wordCount++;
        }
        
    }
    
}


int main()
{
    //This will ask the user which file to copy
    cout << "Please enter the name of the file you want analyze, along with the type extention (.txt, .cpp, etc)\n";
    string userFile;
    cin >> userFile;
    
    //this block will hold the chars and lines and words
    int charCount = 0;
    int lineCount = 1;
    int wordCount = 0;
    string userFileTempString;
    
    ifstream file(userFile);
    
    //while this loop runs run each function
    while(getline(file,userFileTempString))
    {
        lineCount++;
        if(!userFileTempString.empty())
        {
            checkChars(userFileTempString,charCount);
            checkWords(userFileTempString,wordCount);
        }
    }
    
    //display the results
    cout << "Number of chars: " << charCount << "\n" <<"Number of words: " << wordCount << "\n" << "Number of lines: " << lineCount << "\n";
}    
    
    