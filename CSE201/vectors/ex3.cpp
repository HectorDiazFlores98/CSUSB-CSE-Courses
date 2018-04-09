#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <ctime>


using namespace std;

//Creates the function, the algorithm will perform a loop that will go through 
//each element of the vector and push it back into vector 'v'
void appendVector(vector<int> & v, vector<int> & w)
{
    for(int i = 0; i < w.size(); i++)
    {
        v.push_back(w[i]);
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
    
    //creates the vectors and adds values to them, they will later be sent 
    //to the function
    vector <int> v(3); 
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    vector <int> w(3);
    w[0] = 3;
    w[1] = 4;
    w[2] = 5;
    
    
    //sends the vectors to the function
    appendVector(v, w);
    
    //Creates assertions to test the consistency of the algorithm
    assert(v[0] == 0);
    assert(v[1] == 1);
    assert(v[2] == 2);
    assert(v[3] == 3);
    assert(v[4] == 4);
    assert(v[5] == 5);
    
    //Displays the appended vector
    for(int k = 0; k < v.size();k++)
    {
        cout << v[k] << " ";
    }
    
    //Stop the clock from ticking
    //Cout that the program has ran successfully and display the time it took
    end = clock();
    msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    cout << "\nDone!\n" << "Time to completion: " << msecs <<" msecs" << endl;
}