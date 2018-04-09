#include <iostream> 
#include <cmath>

using namespace std; 

int main(){
//declare the input
int input;

//asks for an input
cout << "Please enter a number and I will see if it is even or odd\n";
cin >> input;

// if the input / 2 has a remainder of 0 then it is even, else it is odd
if(input % 2 == 0){
    cout << "It is even\n";
}
else cout << "It is odd\n";
} 
