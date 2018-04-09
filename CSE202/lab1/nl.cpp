#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file("data.txt");
    string Output;
    int i = 1;
    while(getline(file,Output))
    {
        cout << i << " " << Output << "\n";
        
        i++;
    }
    file.close();
}