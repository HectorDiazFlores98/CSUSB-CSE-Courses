#include <iostream>

using namespace std; 

bool isLucky(int n)
{ 
   if(n % 2 == 0)
   {
       return true;
   }
   else return false;
}

int main()
{
    cout << isLucky(14) << endl; 
    cout << isLucky(23) << endl;

}