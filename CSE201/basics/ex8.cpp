#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

int main()
{
srand(time(0));

for(int i = 0; i < 100; ++i){
   
    //(highest range - lowest range) + lowest range = # in range
    double k = (double) rand()/INT_MAX ;
    cout << k  << endl;
}
}
