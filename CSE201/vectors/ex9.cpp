#include <iostream>
#include <vector> 
#include <ctime>
#include <cstdlib>

using namespace std;

//The algorithm will go into each cell of the array
//it will then push back to the vector 'output'
//finally it will return the vector into 'flatten'
vector<int> flatten(int a[100][200])
{
    vector<int> output;
    for(int i = 0; i < 100; i++)
        for(int k = 0; k < 200; k++)
        {
            output.push_back(a[i][k]);
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
    
    //creates the array that will be sent to the vector function
    int b[100][200];
    
    //initializes the srand function to create random numbers
    srand(time(NULL));
    
    //creates the ints that will represent the rows and columns of the array
    int row, column;
    
    //This algorithm will fill each cell in the array with a number ranging from
    //0 - 5
    for(row = 0; row < 100; row++)
        for(column = 0; column < 200; column++)
        {
            b[row][column] = rand() % 5;
        }
    
    //This will send the filled array to the function
    flatten(b);
    
    //Stop the clock from ticking
    //Cout that the program has ran successfully and display the time it took
    end = clock();
    msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    cout << "Done!\n" << "Time to completion: " << msecs <<" msecs" << endl;
}