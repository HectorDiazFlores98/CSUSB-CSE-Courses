#include <iostream>

using namespace std;

int main(){
//declare variables
int input;

//asks for an input
cout << "Please enter the temperature outside\n";

cin >> input;

//if the input is within the range, the appropriatemessage will be displayed
if(input > 40 && input <= 60){
cout << "It is cold\n";
}

else if(input > 60 && input <= 85){
cout << "It is warm\n";
}
//if it is out of range, a warning will be displayed. 
else cout << "Do not go outside\n";

} 
