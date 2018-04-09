#include <vector>
#include <cassert>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

template<typename T>
class Mvector
{
 public:
 Mvector(); //
 Mvector(unsigned int n); //
 void pushback(T x);
 void popback();
 void clear();
 void insert(unsigned int i, T x);
 void erase(unsigned int i);
 T operator[] (unsigned int i);
 int size();
 typedef T *iterator;
 iterator begin();
 iterator end();

 private:
 int vSize;
 int vCap;
 T *v;
 void reserve(unsigned int n);
}; 

template <typename T>
Mvector<T>:: Mvector()
{
    //creates array with 2 elements of type T called newV
    T *newV = new T[10];
    //check to make sure new v was created
    assert(newV != NULL);

    //size of array
    vCap = 10;
    //size of vector
    vSize = 0;
    v = newV;
    
}

template <typename T>
Mvector<T>::Mvector(unsigned int i)
{
    T *newV = new T[10];
    assert(newV != NULL);
    vCap = i;
    vSize = 0;
    v = newV;
}

template <typename T>
void Mvector<T>::popback()
{
    assert(vSize > 0);
    vSize--;
}

template <typename T>
void Mvector<T>:: clear()
{
    vSize = 0;
}

template <typename T>
void Mvector<T>::pushback(T x)
{
    if( vSize < vCap)
    {
        v[vSize] = x;
        vSize++; 
    }
    else 
    {
        //reserve is going to save a certain amount of memory
        reserve(2 * vCap);
        //vcap is increased by reserve
        v[vSize] = x;
        vSize++;
    }
}

template <typename T>
void Mvector<T>:: reserve(unsigned int n)
{
    assert(n > vCap);
    T *newV = new T[n];
    assert(newV != NULL);
    for(int i = 0; i < vSize; i++)
    {
        newV[i] = v[i];
    }
    delete[] v;
    v=newV;
    vCap = n;
}

template <typename T>
int Mvector<T>::size()
{
    return vSize;
}

template <typename T>
T Mvector<T>::operator[](unsigned int i)
{
    assert(i < vSize and vSize > 0);
    return v[i];
}

template <typename T>
void Mvector<T>::insert(unsigned int i, T x)
{
    assert(i > 0 and i <= vSize);
    if( vSize == vCap)
    {
        reserve(2 * vCap);
    }
    for(int j = vSize; j > i; j--)
    {
        v[j] = v[j-1];
    }
    v[i] = x;
    vSize++;
}

template <typename T>
void Mvector<T>::erase(unsigned int i)
{
    assert(i >= 0 and i < vSize);
    for(int j = i; j < vSize; j++)
    {
        v[j] = v[j+1];
    }
    vSize--;
}

int main()
{
    Mvector<int>testM;
    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        testM.pushback(rand()%100);
        cout << "Pushing " << testM[i] <<" into testM\n";
    }

    //TEST BLOCK
    testM.popback();
    cout << "Popping back...\n";
    testM.insert(2,17);
    cout << "Inserting...\n";
    testM.erase(1);
    cout << "Erasing...\n";
    cout << "testM Size " << testM.size() << endl;
    cout << "Final size of testM\n";
    for(int i = 0; i <= testM.size()-1; i++)
    {
        cout << testM[i] << " ";
    }
    cout << "\nClearing the test vector...\n";
    testM.clear();
}