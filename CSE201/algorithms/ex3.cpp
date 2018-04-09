/*
   n       result
  ---    ------------
    40    3 5 7 1 13 17 19 23 29 31 37
    5     3
    17    3 5 7 11 13
    25    3 5 7 11 13 17 19 23
    -17   "enter number greater than 0"
...
*/ 
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	
	//declares the intiger the user will input
	int input;
	cout << "Please input a number, and I will list all the prime numbers in between\n";
	cin >> input;
	
	while(input < 0)
	{
		cout << "Please enter a number greater than 0" << endl;
		cin >> input;
	}
	
	//this for loop will count all the numbers up to the input
	for(int i = 2; i < input; ++ i)
	
	   //this loop will count all the prime numbers leading up to the input
		for(int k = 2; k < i; ++k)
		{
			//if no remainder, it is not prime
			if(i % k == 0)
			{
				break;
			}
			
			else if(i == k+1)
			{
				cout << i << ", ";
			}
		}
	cout << endl;           
	return 0;
 
}
