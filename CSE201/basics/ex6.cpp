#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
//sets the time to seconds passed since 1970 for a random number each time
srand(time(0));

//begins the loop to display random numbers
//it is % by 50 so numbers displayed will be smaller
for(int i = 0; i < 100; ++i){
       	
    int k = rand() % 50 ;
    cout << k  << endl;
}
}
