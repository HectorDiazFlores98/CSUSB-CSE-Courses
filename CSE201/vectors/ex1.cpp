#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//The algorithm will go into each element in the vector and will compare it to 
//'output' which is = v[0], if v[i] is bigger, the value will be stored in output
int mymaximum(const vector<int> & v)
{
    int output = v[0];
    for(int i = 0; i < v.size(); i++)
    {
        if(output < v[i])
        {
            output = v[i];
        }
    }
    return output;
}


int main()
{
    clock_t start, end;
    double msecs;

    start = clock();
    //declares the vector as 'v' with (3) elements
    vector<int> v(5);
    //adds values to the vector 
    v[0] = 2;
    v[1] = 5;
    v[2] = 4;
    v[3] = 7;
    v[4] = 6;
    //send the vector to the function
    mymaximum(v);
    //asserts that the function returns 5
    assert(mymaximum(v) == 7);
    //display the results
    cout << "The max is: " << mymaximum(v) << endl; 
    
    end = clock();
    msecs = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
   cout << "Time to completion: " << msecs <<" msecs" << endl;
    return 0;
}