#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//this function will check where two diffrent sized functions differ
void notEqualSizes(string &notEqualMain, string &notEqualTobeComp)
{
    //if the main file string is bigger than the secondary file string this loop runs
    if(notEqualMain.size()-1 >= notEqualTobeComp.size()-1)
    {
        for(int i = 0; i <= notEqualMain.size()-1; i++)
        {
            if(notEqualMain.at(i) != notEqualTobeComp.at(i))
            {
                cout << "\n\n" << "They are diffrent sizes\n";
                cout << "The difference is in character " << i << " of the first file \nand character " << i << " of the second file\n";
                break;
            }
            else if(i == notEqualMain.size()-2)
            {
                cout << "The diffrence is the last character in the first file\n\n";
                break;
            }
        }
    }
    //if the secondary file string is bigger than the main file string this loop runs. 
    else if (notEqualTobeComp.size()-1 >= notEqualMain.size()-1)
    {
       for(int i = 0; i <= notEqualTobeComp.size()-1; i++)
        {
            if(notEqualTobeComp.at(i) != notEqualMain.at(i))
            {
                cout << "\n\n" << "They are diffrent sizes\n";
                cout << "The difference is in character " << i << " of the second file \nand character " << i << " of the first file\n";
                break;
            }
            else if(i == notEqualTobeComp.size()-2)
            {
                cout << "The diffrence is the last character in the second file\n\n";
                break;
            }
        }
    }
    
}

//this function will check where same sized functions differ 
void notEqualStrings(string &notEqualMain,string &notEqualTobeComp)
{
    for(int i = 0; i <= notEqualMain.size()-1;i++)
    {
        if(notEqualMain.at(i) != notEqualTobeComp.at(i))
        {
            cout << "The difference is in character " << i << " of the first file \nand character " << i << " of the second file\n";
            break;
        }
    }
    
}

int main()
{
    //This will ask the user which file to copy
    cout << "Please enter the name of the file you want to compare, along with the type extention (.txt, .cpp, etc)\n";
    string mainFile;
    cin >> mainFile;
    
    //This will ask the user which file to compare the first one to
    cout <<"Please enter the name of the file you want to compare to " << mainFile << " to\n";
    string toBeCompared;
    cin >> toBeCompared;
    
     //ifstream as it will be an input to Temp
    ifstream fileMain(mainFile);
    ifstream fileToBeCompared(toBeCompared);
    
    //these vectors will be holding all of the lines in the files
    vector<string>mainFileVector;
    vector<string>toBeComparedVector;
    
    //This string will hold the temporary line
    string mainTemp;
    string toCompareTemp;
    
    //While this loop is running it will let the user know which line it is copying and then writes it to the file chosen
    while(getline(fileMain, mainTemp))
    {
        mainFileVector.push_back(mainTemp);
    }
    
    while(getline(fileToBeCompared,toCompareTemp))
    {
        toBeComparedVector.push_back(toCompareTemp);
    }
    
    //counts the current lines being tested
    int currentLine = 1;
    
    //these strings will hold the string in which they are not equal, if any
    string notEqualit;
    string notEqualIT;
    
    //these loops will check for any diffrences in the files 
    for (std::vector<string>::iterator it = mainFileVector.begin() ; it != mainFileVector.end(); ++it)
    {
        for (std::vector<string>::iterator IT = toBeComparedVector.begin();IT != toBeComparedVector.end();++IT)
        {
            
            if(*IT != *it)
            {
                //This block will display what line the diffrence is in. 
                cout << "\nNot equal!\n"; 
                cout << mainFile << ", line " << currentLine <<" says : " << *it << endl; 
                cout << toBeCompared << ", line " << currentLine << " says : " << *IT << endl;
                string notEqualMain = *it;
                string notEqualTobeComp = *IT;
                
                //checks the size of both statements
                if(notEqualMain.size() != notEqualTobeComp.size())
                {
                    
                    notEqualSizes(notEqualMain, notEqualTobeComp);
                }
                else if(notEqualMain != notEqualTobeComp)
                {
                    notEqualStrings(notEqualMain, notEqualTobeComp);
                }
                
                break;
            }
            else cout << "Line " << currentLine << " is equal\n";
            currentLine++;
            it++;
        }
        break;
    }
    
    if(currentLine-1 == mainFileVector.size())
    {
        cout << "\n\nThe files are equal\n\n";
    }
    //display the process is done
    cout << "Done!" << endl;
}
