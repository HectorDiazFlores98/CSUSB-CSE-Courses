#include <iostream>
#include <cassert>

using namespace std;

//Declares the bool that will return the index
bool binarySearch(int a[], int size, int k)
  {
      //This algorithm will split the array in two and then search based on which side it is in
      int low = 0;
      int high = size - 1; // This function has some indentation issues. A good standard to follow is 4 spaces.
      while (low <= high)  // You can adjust the settings in the lower right-hand corner of this editor to automatically
      {                    // make the tab turn into 4 spaces.
          int middle = (low + high) / 2;
          if (a[middle] == k)
           {
             return true;
           }
           else if (a[middle] < k)
           {
               low  = middle + 1;
               
           }
           else high = middle - 1;
            
        }
        return false;
   }
   
int main()
{
    //Declares the needed array as well as the size and the ints storing the 
    //aray index
    int a[]= {-2, 4, 5, 6, 8};
    const int size = 6;
    int first_search = 1;
    int second_search = 5;
    
    //Sets the first output = to the returning number of the function
    //Displays the answer or fails and returns where the error is
    int output_one = binarySearch(a,size,first_search);
    if(output_one == 0)
    {
        cout << "The binary search for 1 returned false" << endl;
    }
    else assert(false);
    
    //Sets the second output = to the returning number of the function
    //Displays the answer or fails and returns where the error is
    int output_two = binarySearch(a,size,second_search);
    if(output_two == 1)
    {
        cout << "The binary search for 5 returned true" << endl;
    }
    else assert(false);
}