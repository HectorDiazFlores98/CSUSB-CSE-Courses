#include <iostream>
#include <cassert>

using namespace std;

//Declare two bools that will test both of the given arrays
bool isStrictlyIncreasing1(int a[], int len);
bool isStrictlyIncreasing2(int b[], int len);

int main()
{
    //Declare the arrays that will be sent to the functions
    const int size = 5;
    int x[size] = {-2, 4, 5, 6, 8};
    int y[size] = { 3, 4, 6, 6, 9};
    
    //send the values to the functions
    isStrictlyIncreasing1(x,size);  // NOT NEEDED
    isStrictlyIncreasing2(y,size);  // NOT NEEDED
    
    //store the results of the functions in an int
    int output1 = isStrictlyIncreasing1(x,size);
    int output2 = isStrictlyIncreasing2(y,size);
    //assert that they are the correct answer or there is a bug in the algorithm
    assert(output1 == 1);
    assert(output2 == 0);
    
    //display appropriate message
    if(output1 == 0)
    {
        cout << "Array 1 is not increasing" << endl;
    }
    else cout << "Array 1 is increasing!" << endl;
    
    if(output2 == 0)
    {
        cout << "Array 2 not increasing" << endl;
    }
    else cout << "Array 2 is increasing!" << endl;
    
}

//If the numberi in a position is less than the one before, it is not 
//increasing 
bool isStrictlyIncreasing1(int a[], int len)
{
    for(int i = 1; i < len; i++)
    {
        if(a[i] <= a[i-1])
        return false;
    }
    return true; 
}

bool isStrictlyIncreasing2(int b[], int len) // THIS FUNCTION NOT CORRECT
{
    for(int i = 1; i < len; i++) // SHOULD START WITH I = 1
    {
        if(b[i] <=b[i-1])
        return false;
    }
    return true; 
}
