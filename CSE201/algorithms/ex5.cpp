//Test Cases
// 8 = not prime
//5 = prime 
// 25 = not prime 
//-5 = error
// 100 = not prime
#include <iostream>
#include <cmath>

using namespace std;

//Declares the bool that will return if it is prime or not
bool is_prime(int n)
{
    if (n < 2)
    {
        return false;
    }    
    
    //I used the same algorithm as my ex2
    //If n % i has no remainder, it is not prime
    for(int i = 2; i < n; i++) 
    {
        if (n % i == 0) 
        {
            return false;
        }    
    }
    return true;
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
   
    //send the input to the bool function
    is_prime(input);
    
    //displays the results of the bool function
    if(is_prime(input) == 0)
    {
        cout << input << " is not prime" << endl;
    }
    
    else cout << input << " is prime" << endl;
}