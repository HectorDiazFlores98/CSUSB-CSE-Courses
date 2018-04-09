#include <iostream>
#include <cassert>

using namespace std;

//declares the bool as a function
bool areIdentical(int a[], int b[], int len);

int main()
{
    //declares all the needed ints that are going to be passed on
    const int size = 5;
    int x[size] = {5,7,9,11,13};
    int y[size] = {5,7,9,11,13};
    
    //sends the declared arrays to the function
    bool areIdentical(int x[size], int y[size], int size);
    
    //declares the int that will store the result
    int output = areIdentical(x,y,size);
    
    //outputs the appropriate result
    if(output == 1)
    {
        cout << "They are identical!" << endl;
    }
    else cout << "The are not identical" << endl;
}

bool areIdentical(int a[], int b[], int len)
{
    //if at any given [i] they are the same, then it returns true
    for(int i = 0; i < len; i++)
    {
        if(a[i] == b[i])
        {
            assert(a[i] == b[i]);
            return true;
        }
        return false;
    }
}