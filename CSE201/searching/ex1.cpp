#include <iostream>
#include <cassert>

using namespace std;

//Go through each index of the array, if it matches the k value return the index
//else it will return -1
int search(int a[], int size, int k)
{
    for(int i = 0; i < size; i++)
    {
        if(a[i] == k)
        {
            return 1;
        }
    }
    //Assert for Y failed. Had (return -1) in the loop, so it was always returning -1
    //moved return -1 to proper place. 
    return -1;
}

int main()
{
    //Declare the array that will be sent to the function
    //x and y will represent K in the function
    //len will be the length(size)
    int b[] = { -2, 4, 18, 6, -10};
    const int len = 5;
    const int x = 1;
    const int y = 4;
    
    //Store the results for K = (1) in result
    int resultX = search(b,len,x);
    
    //assert that the answer is correct, if not there is an error in the algorithm
    assert(resultX == -1);
    cout << "Search for k = 1: " << resultX << endl;
    
 
    
    //Store the results of K = (4) in result
    int resultY = search(b, len, y);
    
    //Assert that k(4) = 1 or there is a bug in the program
    assert(resultY == 1);
    cout << "Search for k = 4: " << resultY << endl;
    
}