#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <ctime>

using namespace std;

//This algorithm will test to see if they are the same size first, if not return false
//if they are, go through a[i] & b[i] and if they are not the same return false
//if all test passed, return true
bool areIdentical(const vector<int> & a, const vector<int> & b)
{
    if(a.size() != b.size())
    {
        return false;
    }
    else for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i])
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
    
    //declare both of the vectors the function will test
    vector <int> a(10);
    a[0] = 0;
    a[1] = 4;
    a[2] = 6;
    a[3] = 5;
    a[4] = 4;
    a[5] = 5;
    a[6] = 9;
    a[7] = 5;
    a[8] = 8;
    a[9] = 7;
    
    vector <int> b(10);
    b[0] = 0;
    b[1] = 4;
    b[2] = 6;
    b[3] = 5;
    b[4] = 4;
    b[5] = 5;
    b[6] = 9;
    b[7] = 5;
    b[8] = 8;
    b[9] = 7;
    
    //assert(areIdentical(a,b) == 1);
    
    //display the results 
    if(areIdentical(a,b) == 1)
    {
        cout << "They are identical!";
    }
    else cout << "They are not identical!";
    
    //Stop the clock from ticking
    //Cout that the program has ran successfully and display the time it took
    end = clock();
    msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    cout << "\nDone!\n" << "Time to completion: " << msecs <<" msecs" << endl;
    
}