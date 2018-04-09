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
 typedef T* iterator;
 Mvector();
 Mvector(unsigned int n);
 void pushback(T x);
 void popback();
 void clear();
 void insert(unsigned int i, T x);
 void erase( unsigned int i);
 T operator[] (unsigned int i);
 void operator-- (int);
 int size();
 iterator begin() {return v;}
 iterator end() {return ((v+vSize)-1);}
 void insert(iterator ix, T x);
 void erase(iterator ix);
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
        //vCap is increased by reserve
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

template <typename T>
void Mvector<T>::operator--(int)
{
    this->popback();
}

template <typename T>
void Mvector<T>::erase(iterator ix)
{
    for(iterator jx = ix; jx == (v +vSize)-1; jx++)
    {
        *jx = *(++jx);
    }
    vSize--;
}

template <typename T>
void Mvector<T>::insert(iterator ix, T x)
{
    int index= ix-begin();
    insert(index,x);
    if(vSize == vCap - 1)
    {
        reserve(2 * vCap);
    }
    for(iterator jx = (v+vSize)-1; jx!= ix; jx--)
    {
        *jx = *(--jx);
    }
    //*ix=x;
    insert(index,x);
    vSize++;
}

int main()
{
    Mvector<int>testM;
    srand(time(NULL));

    /*
pop back
clear*/
    cout << "Starting List (using pushback): ";
    for(int i = 0; i < 10; i++)
    {
        testM.pushback(rand()%100);
        cout << testM[i] <<" ";
    }
    

    //Test Block
    testM.insert(1, 1234);
    cout << "\n\nInserting 1234 to index [1]\nNew List: ";

    for(int i = 0; i < testM.size(); i++)
    {
        
        cout << testM[i] <<" ";
    }
    
    cout << "\n\nErasing the End\nNew List: ";
    testM.erase(testM.begin());
    for(int i = 0; i < testM.size(); i++)
    {
        
        cout << testM[i] <<" ";
    }

    cout << "\n\nPopping back\nNew List: ";
    testM.popback();
    for(int i = 0; i < testM.size(); i++)
    {
        
        cout << testM[i] <<" ";
    }

    cout << "\n\nClearing the list\nNew List: ";
    testM.clear();
    for(int i = 0; i < testM.size(); i++)
    {
        
        cout << testM[i] <<" ";
    }

    cout << "\n\nClearing the list\nNew List: ";
    testM.insert(testM.begin(), 10);
    for(int i = 0; i < testM.size(); i++)
    {
        
        cout << testM[i] <<" ";
    }

    cout <<"\n";

    
}
