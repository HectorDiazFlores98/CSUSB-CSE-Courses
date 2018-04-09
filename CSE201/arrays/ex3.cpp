#include <iostream> 
#include <cassert>

using namespace std; 


int main()
{
    //Declares the size of the array
    const int size1 = 50;
    const int size2 = 100;
    
    //declares the array that will be sent to the function
    int x[size1][size2] = {{0}};
    
    //sends the array to the function
    bool isAllZeros(int x[size1][size2]);  // THIS IS A FUNCTION DECLARATION; IT SHOULD GO ABOVE MAIN.
    
    //sets the int that will store the result = to what the function returns
    bool output = isAllZeros(x);  // THIS FUNCTION RETURNS A BOOL; YOU SHOULD STORE RESULT IN A BOOL.

// YOUR TEST CASES ARE INADEQUATE; YOU SHOULD ALSO TEST FOR THE CASE WHEN THE FUNCTION 
// RETURNS FALSE.  YOU WOULD HAVE FOUND THAT YOUR FUNCTION DOESN'T WORK.
    
    //asserts that output is = 1, if not there is a bug in the code
    assert(output == 1);    
    
    //Displays the appropriate message to the user 
    if(output == 1)
    {
        cout << "It is all zeros!" << endl;
    }
    else cout << "It is not all zeros" << endl;
}

//This function will test each cell
//one by one and if it is nothing but 0 in all cells it will return true
bool isAllZeros(int a[50][100])
{ 
    for(int i = 0; i < 50; ++i)
    { 
        for(int j = 0; j < 100; ++j)
        { 
            if(a[i][j] == 0)
            { 
                return true; // THIS BREAKS THE LOOP ON THE FIRST ZERO ENCOUNTERED. 
            }
        
        }
        return false;
    }
}

