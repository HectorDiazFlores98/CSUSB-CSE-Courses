#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <typename T>
class soList
{
    public:
        soList();
        T front();
        void add(T x);
        void remove();
        void organize(T x);
        T operator[] (unsigned int i);
    
    private:
        vector<T> v; 
};

template <typename T>
soList<T>::soList()
{

}

template <typename T>
T soList<T>::front()
{
    return v.front();
}

template <typename T>
void soList<T>::add(T x)
{
    v.push_back(x);
}

template <typename T>
void soList<T>::remove()    
{
    v.erase(v.begin());
}

template <typename T>
void soList<T>::organize(T x)
{
    typename vector<T>::iterator ix;
    ix = v.begin();

    while(ix != v.end());
    {
        if(*ix == x)
        {
            v.erase(ix);
            v.insert(v.begin(), x);
        }
        else ix++;
    }
}

template <typename T>
T soList<T>::operator[](unsigned int i)
{
    return v[i];
}

int main()
{
    soList<int>testing;
    testing.add(5);
    testing.add(10);
    testing.add(3);
    testing.add(6);
    testing.add(10);
    testing.add(11);

    cout << "Front: " << testing.front() << endl;
    testing.remove();
    cout << "Front: " << testing.front() << endl;
    
    for(int i = 0; i <= 4; i++)
    {
        cout << testing[i] << " ";
    }
    cout << endl;
}