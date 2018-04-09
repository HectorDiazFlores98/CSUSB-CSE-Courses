#include <iostream>

using namespace std;

bool isUnlucky(int a[], int len);

int main()
{
    //Declare the ints that will go into the function
    const int maxSize = 8;
    int x[maxSize] = {17,12, 14, 20, 13, 49, 3, 4};
    
    //send the array to the function
    isUnlucky(x, maxSize);
    
    //store the result in an int
    bool output = isUnlucky(x,maxSize);
    
    //display the apropriate message
    if(output == 1)
    {
       cout << "The array is unlucky!" << endl;
    }
    else cout << "The array is not unlucky!" << endl;
}

//The algorithm will go through each position and compate it to the #13
//If it matches then it will return true for unlucky
bool isUnlucky(int a[], int len)
{
    for(int i = 0; i < len; i++)
    {
        if(a[i] == 13)
        {
            return true;
        }
    }
    return false; 
}