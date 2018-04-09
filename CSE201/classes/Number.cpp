#include "Number.h"

using namespace std;

//Declares the constructer and sets the private variable = to the input
Number::Number(int input)
{
    number = input;
}

//sets up the isprime function
//puts the input through the algorithm and returns the appropriate status
bool Number::isPrime(void)
{
    for(int i = 2; i < number; i++)
    {
        if(number % i == 0)
        {
            return false;
        }
    }
    return true; 
}

//sets up the isDivisibleBy function 
//puts the input through the algorithm and returns the appropriate status
bool Number::isDivisibleBy(int diviser)
{
    if(number % diviser == 0)
    {
        return true;
    }
    return false; 
}