#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>


using namespace std;

//The algorithm will
void append(vector<int> & v, int n)
{
    for(int i = 0; i < n; i++)
    {
        v.push_back(i);
    }
}

int main()
{
    //this starts the clock to count how many ticks it takes for the 
    //program to run. 
    // Not coded by me, I refrenced this from the C++ website
    clock_t start, end;
    double msecs;
    start = clock();
    
    //This will create the vector and the target number that will be appended
    vector<int> v;
    int target_number = 10;
    
    //This will send the vector and the target number to the function
    append(v,target_number);
    
    //Asserts that a[k] is incrimenting by 1
    assert(v[0] == 0);
    assert(v[1] == 1);
    assert(v[2] == 2);
    assert(v[3] == 3);
    assert(v[4] == 4);
    assert(v[5] == 5);
    assert(v[6] == 6);
    assert(v[7] == 7);
    assert(v[8] == 8);
    assert(v[9] == 9);
    
    //This loop will display the results 
    for(int k = 0; k < v.size(); k++)
    {
        
        cout << v[k] << " ";
    }
    
    //Stop the clock from ticking
    //Cout that the program has ran successfully and display the time it took
    end = clock();
    msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    cout << "\nDone!\n" << "Time to completion: " << msecs <<" msecs" << endl;
}