#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <ctime>

using namespace std;

//The algorithm will search one by one and if there is a 13 it will return true
bool isUnlucky(vector<int> & v)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == 13)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    //this starts the clock to count how many ticks it takes for the 
    //program to run. 
    // Not coded by me, I refrenced this from the C++ website
    clock_t start, end;
    double msecs;
    start = clock();
    
    //declare the vector for testing 
    vector <int> v (5);
    v[0] = 5;
    v[1] = 9;
    v[2] = 12;
    v[3] = 13;
    v[4] = 16;
    
    
    assert(isUnlucky(v) == 1);
    
    //Display the results of the function
    if(isUnlucky(v) == 1)
    {
        cout << "The bool is unlucky!";
    }
    else cout << "The bool is not unlucky!";
    
    //Stop the clock from ticking
    //Cout that the program has ran successfully and display the time it took
    end = clock();
    msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    cout << "\nDone!\n" << "Time to completion: " << msecs <<" msecs" << endl;
}