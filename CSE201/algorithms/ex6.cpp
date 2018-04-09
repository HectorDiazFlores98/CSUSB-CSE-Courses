#include <iostream>
#include <cmath>

using namespace std;

//Declares the bool that will return if it is prime or not
bool is_prime(int n)
{
    
    //I used the same algorithm as my ex2
    //If n % k has no remainder, it is not prime
    //return true for prime numbers
    for(int k = 2; k < n; k++) 
    {
        if (n % k == 0) 
        {
            return false;
        }
        
        else if(n == k + 1)
        {
            return true;
        }
    }
}

int main()
{
    
    //Declares variable and asks user for an input
    int input;
    cout << "Please enter a number" << endl;
    cin >> input;
    
    //Catches to make sure that input is not less than 0
    while(input < 0)
     
    {
        cout << "Please enter a number greater than 0" << endl;
        cin >> input;
    }
   
   for(int i = 2; i < input; i++)
    {
        //send the input to the bool function to continue the algorithm
        is_prime(i);
        
        //if it is prime, display the number
        if(is_prime(i) == true)
        {
            cout << i << " , ";
        }
    }
    
    cout << "\n";
}