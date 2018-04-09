#include <iostream>
#include <cassert>

using namespace std;

//Declare the provided function
int myMaximum(int a[], int numberofElements);

int main()
{
    //Declare the const size of the int as 5
    const int maxSize = 5;
    
    //declare the array that will go into the function
    int x[maxSize] = {13,10,17,9,15};
    
    //Display the results
    cout <<" The max value of the array is: " << myMaximum(x, maxSize) << endl;
    
}

int myMaximum(int a[], int numberofElements)
{
    //Set int highest to first number in array
    int highest = a[0];
    
    //if highest is lower than a[i], highest will be set to a[i]
    for(int i = 0; i < numberofElements; i++)
    {
        if (a[i] > highest)
        highest = a[i];
    }
    //assert that it is 17 or else there is a bug
    assert(highest == 17);  //  THE ASSERTION SHOULD BE IN MAIN 
    //return the highest number
    return highest; 
}