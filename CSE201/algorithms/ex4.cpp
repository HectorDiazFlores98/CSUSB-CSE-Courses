//Test Cases
//8 = 2 ,2 ,2   
//100 = 2, 2, 5, 5
//2 = 2
//4, = 2, 2
//-20 = error
// 25 = 5, 5
//60 = 2, 2 , 3, 5
//-2 = error

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Declare variables and inputs
    //ask user for an input 
    int input;
    cout << "Please input a number and I will give you all the prime factorizations"
         << endl;
    cin >> input;
    
    //This will loop as long as input < 0, so we get a positive number. 
    while (input < 0)
    {
        cout << "Please enter a number greater than 0" << endl; 
        cin >> input; 
    }

    //This loop will print all the times that 2 will go into it
    //it will also make it odd at some point
    while( input % 2 == 0)
    {
        cout << "2, ";
        input = input/2;
    }
    
    //If it is not an even number, the input will be made odd at this point
    //This loop will pull out the remaining prime factorizations
    //We can skip 2 because we already pulled it out, and I has to be less than
    // or equal to the sqrt of the input to shorten run time. 
    for(int i = 3; i <=sqrt(input); i = i + 2) 
    {
        while(input%i == 0)
        {
            cout << i << ", ";
            input = input/i;
        }
    }
    
    //This will display the last prime factor, which is what input has been reduced to
    if(input > 2)
    {
        cout << input;
    }
    
    cout << endl;
}