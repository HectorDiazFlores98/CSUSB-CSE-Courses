/*
    Hector Diaz Flores
    004854001
    Lab 3
    compiled using c++ 11
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <iterator>

using namespace std;

template <typename T>
class priorityQ
{
	public:
		priorityQ();
		priorityQ(vector<T>);
		int size();
		T front();
		void print();
		void addOrdered(T);
		void removeFront(T);
	private:
		vector<T> queue;
        void selection_sort(vector<T> queue);
};

//this constructor will create an empty vector
template <typename T>
priorityQ<T>::priorityQ()
{

}

//this constructor will take a vector and put it in order 
template <typename T>
priorityQ<T>::priorityQ(vector <T> q)
{   
    selection_sort(q);
}

//the selection sort function will sort the vectors
template <typename T>
void priorityQ<T>::selection_sort(vector<T> q)
{
    queue = q;
    for (int i = queue.size()-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
           if(queue[j] > queue[j+1])
           {
               swap(queue[j], queue[j+1]);                                   
           }
        } 
    }
}

//this function will return the size of the vector
template <typename T>
int priorityQ<T>::size()
{
    return queue.size();
}

//this will front of the vector
template <typename T>
T priorityQ<T>::front()
{
    return queue[0];
}

//prints all of the vector 
template <typename T>
void priorityQ<T>::print()
{
    for(typename vector<T>::iterator it= queue.begin(); it != queue.end(); it++)
    {
        cout << *it << " ";
    }    
    cout << endl;
}

//adds an element to the vector while keeping it ordered
template <typename T>
void  priorityQ<T>::addOrdered(T x)
{  
    if( x < queue.back())
    {
        for(typename vector<T>::iterator it= queue.begin(); it != queue.end(); it++)
        {4
            //cout << "test 1 \n";
            if(*it > x)
            {
                //cout << "test 2\n";
                queue.insert(it, x);
                //cout << "test 3\n"; 
                break;
            }
        }
    }
    else queue.push_back(x);
}

//removes the front
template <typename T>
void priorityQ<T>::removeFront(T x)
{
    queue.erase(queue.begin());
}

/* need to test
   constructor - 
   constructor with vector - X
   size - X
   front - 
   print - X
   add ordered - X
   remove front -
*/ 
int main()
{
    //this block sets up a vector with random numbers
    //The constructor will also sort it
    cout << "\nSetting up the queue\n";
    cout << "\nUnordered queue...\n";
    srand(time(NULL));
    vector<int> testingV;
    for(int i = 0; i <= 10; i++)
    {
        int temp = rand() % 100;
        testingV.push_back(temp);
        cout << temp << " ";
    }
    
    //This block organizes the queue
    cout << "\n\nOrganizing queue...\n";
    priorityQ<int> queueTest(testingV);
    queueTest.print();

    //this block adds numbers
    cout << "\nAdding random numbers in order...\n";
    for(int i = 0; i <= 8; i++)
    {
        int temp = rand() % 100;
        queueTest.addOrdered(temp);
    }
    
    //this block prints the new vector and size
    cout << "\nNew queue...\n";
    queueTest.print();
    cout << "\nQueue Size: " << queueTest.size() << "\n\n";

    //this vector will remove the front of the queue
    cout << "Removing the front...\n";
    queueTest.removeFront(1);
    queueTest.print();

    cout << "\nNew Size...\n" << queueTest.size() << endl;
}
