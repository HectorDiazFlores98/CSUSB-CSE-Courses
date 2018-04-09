#include <iostream>
#include <cmath>

using namespace std;

int main()
{

float meters;

cout << "Please enter the number of meters you have\n";
cout << "Meters = ";
cin >> meters;

// Converts  meter -> centimeter -> inch -> foot


float centimeter = meters * 100;

float inch = centimeter * 0.39370;

float feet = inch/12;

//Turn the float into a int

int output_feet = feet;

//finds the remaining inches after the feet have been determened

float roundedinches = inch - (output_feet * 12);

//rounds the inches for output

int output_inches = round(roundedinches);

if(output_inches == 12){
output_inches = 0;
output_feet = feet + 1;
}


//Display the feet and inches

cout << output_feet << " ft " << output_inches << " in\n";
}
