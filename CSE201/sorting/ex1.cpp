#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
#include <cstdlib>

using namespace std;

//This algorithm has two variables that will go into each element of the vector,
//int "i" will always be one ahead of "k"
// if element "i" is less than element "k", they will be swapped
void mysort(vector<int> & v)
{
    for(int i = 0; i < v.size(); i++)
    {
        for(int k = 0; k < i; k++)
        {
            if(v[i] < v[k])
            {
                swap(v[i], v[k]);
            }
        }
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
    
    //This section initializes the psudo-random number generator
    //it will also initialize the vector and fill it with random numbers
    srand(time(NULL));
    vector <int> v (10);
    for(int l = 0; l < 10; l++)
    {
        v[l] = (rand() % 10);
    }
    
    //This will send the vector to the funtion
    mysort(v);
    
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