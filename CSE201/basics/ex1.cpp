#include <iostream>
#include <cmath>
using namespace std;

int main()
{
//declare inputs
float x, y, z;

//asks for an input
cout << "Please input 3 numbers\n";
cout << "one for x, one for y, and one for z\n";

cin >> x >> y >> z;

//calculates the answer for the math question 
float sum = x + y + z;
float sine = sin (x);
float cosine = cos((x+y)/z);
float average = sum/3;
float log = log2(x);

//displays the answer
cout << "The sum is " << sum << "\n"
    << "The Sine of x is " << sine << "\n"
    << "The Cosine of (x+y)/z is " << cosine << "\n"
    << "The average is " << average << "\n"
    << "The log base 2 is " << log << "\n";

}