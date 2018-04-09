#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() 
{
    // this vector will hold all of the lines in a file 
    vector<string> lines;

    // ask the user which file they want to sort
    cout << "Which file would you like to sort?\n";
    string fileToSort;
    cin >>fileToSort;
    
    ifstream file(fileToSort);

    string word;
    
    while(getline(file, word))
    {
        lines.push_back(word);
    }
    
    //begins the algorithm to sort the vector
    sort(lines.begin(), lines.end());

    // Loop to print names
    for (int i = 0; i < lines.size(); i++)
    {
        cout << lines[i] << '\n';
    }
}