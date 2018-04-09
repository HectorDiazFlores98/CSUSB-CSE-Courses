#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int WordCount(vector<string>&LineSize)
{
    //SpaceCounter will count all of the times there is a space in the file, indicating a word before it. 
    int SpaceCounter = 0;
    //This will hold all the times the index changes indicating a new line
    int ReturnCounter = 0;
    //Will compare to i and if index i > than Icounter, add one to ReturnCounter
    int Icounter = 0;
    
    //This loop will go through each line in the vector
    for(int i = 0; i <= LineSize.size()-1;i++)    
    {
        //If i > than Icounter, that indicates a change in the index, indicating a new line
        if(Icounter <= i)
        {
            ReturnCounter+=1;
        }
        //This loop will go through each character in the index and if theres a space it will add word.
        for(int k = 0; k <= LineSize[i].size()-1; k++)
        {
            //if isspace, it indicates a word before
            if(isspace(LineSize[i].at(k)))
            {
                SpaceCounter +=1;
            }
        }
        
    }
    return SpaceCounter+ReturnCounter;
}

int main()
{
    //creates the file stream to get the data from the file 
    ifstream file("data.txt");
    //This vector will hold the file text
    vector<string>LineSize;
    
    string StoredLines;
    
    while(getline(file,StoredLines))
    {
        LineSize.push_back(StoredLines);
    }
    
    cout << WordCount(LineSize) << "\n";
    
    file.close();
}