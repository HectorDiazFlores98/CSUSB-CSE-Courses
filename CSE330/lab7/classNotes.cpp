#include<iostream>
#include <vector>

using namespace std;

template <typename T1, T2>
class Tnode
{
  public :
  T1 data1;
  T2 data2;
  Tnode<T> *lptr;
  Tnode<T> *rptr;
};

/*template <typename T>
class Tnode
{
  public :
  T data;
  Tnode *lptr;
  Tnode *rptr;
};*/

template <typename T>
class Mtree
{ public :
  Mtree();
  void add(T1 x, T2 y);
  bool find(T x);
  T2 operator[](T1 x);
  private :
  void add(Tnode<T> *ptr, T x);
  Tnode<T> *root; // = 0
  int tsize; // = 0
  vector<T> v;
};
/*  visit left
    visit node
    visit right
*/
template <typename T>
void Mtree<T>::Mtree()
{
    *root = 0;
    tsize = 0;
}

template <typename T>
void Mtree<T>::add(T x)
{
    if(tsize == 0)
    {
        Tnode<T> *ptr = new Tnode<T>;
        ptr->lptr=0;
        ptr->rptr=0;
        ptr->data=x;
        root=ptr;
        tsize++;
    }
    else add(root,x);
}

template <typename T>
void Mtree<T>::add( Tnode<T> *ptr, T x)
{
    if( ptr-> lptr == 0 and x<= ptr->data)
    {
        Tnode<T> *nptr = new Tnode<T>;
        ptr->lptr=nptr;
        nptr->data=x;
        nptr->lptr=0;
        nptr->rptr=0;
        return;
    }
    
    if( ptr-> lptr == 0 and x<= ptr->data)
    {
        Tnode<T> *nptr = new Tnode<T>;
        ptr->rptr=nptr;
        nptr->data=x;
        nptr->lptr=0;
        nptr->rptr=0;
        return;
    }
    
    if(x<=ptr->data)
    {
        add(ptr->lptr, x);
    }

    else 
    {
        add(ptr->rptr,x);
    }
}

int main()
{
    Mtree<int> testTree;
    
}