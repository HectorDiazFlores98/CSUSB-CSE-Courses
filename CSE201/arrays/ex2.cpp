#include <iostream>
#include <cassert>

using namespace std;

//Declare the provided function
int myMaximum(int a[], int len, int k);

int main()
{
    //Declare the const size of the int as 5
    const int maxSize = 10;
    
    //declare the array that will go into the function
    int x[maxSize] = {13,10,17,9,15,12,18,25,18,15};
    
    //Declare the number that will be tested for occurance
    int testNum = 15;
    
    //Display the results
    cout <<" The occurance of 15: " << myMaximum(x, maxSize, testNum) << " times" << endl;
    
}

int myMaximum(int a[], int numberofElements, int k)
{
    //Declare the int to count occurance
    int occurance = 0;
    
    //if a[i] = int k, then ++occurance
    for(int i = 0; i < numberofElements; i++)
    {
        if (a[i] == k)
        occurance = occurance + 1;
    }
    
    //assert it is == 2 or there is a bug
    assert(occurance == 2);
    //return the highest number
    return occurance; 
}