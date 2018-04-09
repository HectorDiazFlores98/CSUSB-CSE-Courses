#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <ctime>

using namespace std;

//The algorithm will go into each element of the vector
//and compare it to the one ahead, if the current one is bigger than the one ahead
//the bool returns false 
bool isStrictlyIncreasing(const vector<int> & v)
{
    
    for(int i = 0; i < v.size() - 1; i++)
    {
        if(v[i] > v[i+1])
        {
            return false;
        }
    }
    return true;
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
    vector <int> v(5);
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    v[3] = 3;
    v[4] = 4;
    
    assert(isStrictlyIncreasing(v) == 1);
    
    //display the results
    if(isStrictlyIncreasing(v) == 1)
    {
        cout << "It is increasing!";
    }
    else cout << "It is not increasing";
    
    //Stop the clock from ticking
    //Cout that the program has ran successfully and display the time it took
    end = clock();
    msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    cout << "\nDone!\n" << "Time to completion: " << msecs <<" msecs" << endl;
}