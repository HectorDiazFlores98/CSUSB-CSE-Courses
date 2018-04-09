#include <iostream> 

using namespace std;

int main()
{

//declares the input
int input;

//asks for an input
cout << "Please enter a number between 3 and 12\n";
cout << "Input = ";
cin >> input;

//if its less than greater than 12 its a bad number
if(input > 12){
cout << "Bad number\n";
}

//if its less than 3 its a bad number
else if (input < 3){
cout << "Bad number\n";
}

//if it passes it is a good number
else{
cout << "Good Number\n";
}
}

