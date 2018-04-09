#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <ctime>


using namespace std;

//The first for loop will go through and select an element in the vector
//The second for loop will compare the number ahead to the first number
//if the second number is bigger, the function will switch the numbers
void vector_insertion(vector<int> & v, int k)
{
    v.push_back(k);
    
    for(int i = 0; i < v.size() - 1; i++)
        for(int k = i + 1; k < v.size(); k++)
        {
            if (v[i] > v[k]) swap(v[i],v[k]);
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
    
    //declare the vector and add elements to the vector 
    vector <int> v(4);
    v[0] = 3;
    v[1] = 6;
    v[2] = 7;
    v[3] = 12;
    
    //This is the number that will be added to the vector
    int inserted_number = 5;
    
    //send the vector and int to the function and check to see if they are in 
    //the right place
    vector_insertion(v,inserted_number);
    assert(v[0] == 3);
    assert(v[1] == 5);
    assert(v[2] == 6);
    assert(v[3] == 7);
    assert(v[4] == 12);
    
    //display the results
    for(int j = 0; j < v.size(); j++)
    {
        cout << v[j] << " ";
    }
    
    //Stop the clock from ticking
    //Cout that the program has ran successfully and display the time it took
    end = clock();
    msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    cout << "\nDone!\n" << "Time to completion: " << msecs <<" msecs" << endl;
}