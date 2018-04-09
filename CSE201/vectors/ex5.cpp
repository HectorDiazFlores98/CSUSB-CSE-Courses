#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <ctime>


using namespace std;

//the loop will go through each element in the array,
//if it matches up to k, it will increase output by one
//output will be returned as the number of times the number occurs
int countOccurrences(const vector<int> & v, int k)
{
    int output = 0;
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == k)
        {
            output++;
        }
    }
    return output;
}

int main()
{
    //this starts the clock to count how many ticks it takes for the 
    //program to run. 
    // Not coded by me, I refrenced this from the C++ website
    clock_t start, end;
    double msecs;
    start = clock();
    
    //declare the vector and add elements to the vector, as well as the number that will be questioned  
    vector <int> v(10);
    v[0] = 0;
    v[1] = 5;
    v[2] = 6;
    v[3] = 5;
    v[4] = 4;
    v[5] = 5;
    v[6] = 9;
    v[7] = 5;
    v[8] = 8;
    v[9] = 7;
    int number_in_question = 5;
    
    //send the elements to the function
    countOccurrences(v, number_in_question);
    
    //asserts that the answer is 4
    assert(countOccurrences(v,number_in_question) == 4);
    //displays the result
    cout << "The number of occurances is: " << countOccurrences(v,number_in_question);
    
    //Stop the clock from ticking
    //Cout that the program has ran successfully and display the time it took
    end = clock();
    msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    cout << "\nDone!\n" << "Time to completion: " << msecs <<" msecs" << endl;
}