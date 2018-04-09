#include <iostream>
#include <cstdlib>
#include <climits>
#include <cmath>
using namespace std;

int main(){
//declare 2 limits
//upper and lower
float lower_limit;
float upper_limit;

//asks user to declare the scope of the limits
cout << "Please enter a lower limit and upper limit\n";
cout << "Lower limit = ";
cin >> lower_limit;
cout << "Upper limit = ";
cin >> upper_limit;

//calculate the range
int range;
range = upper_limit - lower_limit;

srand(time(0));

//display random number within user inputed range
for(int i = 0; i < 100; ++i){
   
    //(highest range - lowest range) + lowest range = # in range
    float k = fmod ( rand(), range) + lower_limit ;
    cout << k  << endl;
}
}
