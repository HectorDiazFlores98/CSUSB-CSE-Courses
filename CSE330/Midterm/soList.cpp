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

    private:
        vector<typename T> v;
};

template <typename T>
soList<T>::soList()
{

}

template <typename T>
T soList<T>::front()
{
    assert( v.size() > 0 );
    return *v.begin();
}

template <typename T>
void soList<T>::add(T x)
{
    v.push_back(x);
}

template <typename T>
void soList<T>::remove()
{
    assert(v.size() > 0);
    v.erase(v.begin());
}

template <typename T>
T soList<T>::organize(T x)
{
    typename vector<T>::iterator ix;
    ix = v.begin();

    while(ix != v.end();)
    {
        if(*ix == x)
        {
            v.erase(ix);
            v.insert(v.begin(), x);
        }
        else ix++;
    }
}

int main()
{

}