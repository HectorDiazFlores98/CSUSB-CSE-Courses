/*
 This program will test a number for 
 primality, if there is a remainder in a modulo operation, it is prime
   n       result
  ---    ------------
    17    prime
    23    prime
    30   not prime
    -50  error
    16	 not prime	
*/

// THIS PROGRAM FAILS FOR 27.  THE LOGIC IS INCORRECT AND THE TEST CASES ARE INADEQUATE.

#include <iostream>
#include <cmath>

using namespace std;

int main()
{

	//declare variable for input
	int input;
	
	//ask user for input
	cout << "Please input a number greater than 1, and I will tell you if it is prime or not\n";
	cin >> input;
	
	if(input <= 1)
	{
		cout << "Please input a number greater than 1\n";
		cin >> input;
	} 
	
	//The number will be divided by every number leading up to it
	//if there is a remainder the bool will be set to false
	if(input % 2 == 0)
	{
		cout << "Even";
	}
	else if(input % 3 == 0)
	{
		cout << "Even";
	}
	else 
	{
		cout << "odd";
	}
}
