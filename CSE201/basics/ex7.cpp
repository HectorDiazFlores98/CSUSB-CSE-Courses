#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
srand(time(0));

for(int i = 0; i < 100; ++i){
   
    //(highest range - lowest range) + lowest range = # in range
    int k = rand() % 50 + 75 ;
    cout << k  << endl;
}
}
