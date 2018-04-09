#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

//Tested this method various times, the finishing time was cut in half from 
//1 minute in my algorithm to about 27 seconds with this method.  

int main()
{
    //this starts the clock to count how many ticks it takes for the 
    //program to run. 
    // Not coded by me, I refrenced this from the C++ website
    clock_t start, end;
    double msecs;
    start = clock();
    
    //This section initializes the psudo-random number generator
    //it will also initialize the vector and fill it with random numbers
    srand(time(NULL));
    vector <int> v (100000);
    for(int l = 0; l < 100000; l++)
    {
        v[l] = (rand() % 10);
    }
    
    //This will send the vector to the funtion
    sort(v.begin(), v.end());
    
    //Assert all the numbers are in increasing order by having the same 
    //algorithm structure as the function, only this one will check to make sure 
    //they are in increasing order. 
    for(int element_1 = 0; element_1 < v.size(); element_1++)
    {
        for(int element_2 = 0; element_2 < element_1; element_2++)
        {
            assert(v[element_2] <= v[element_1]);
        }
    }
    
    cout << "All numbers are sorted in increasing order!" << endl; 
    
    //Stop the clock from ticking
    //Cout that the program has ran successfully and display the time it took
    end = clock();
    msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    cout << "\nDone!\n" << "Time to completion: " << msecs <<" msecs" << endl;
}