#include<iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

template <typename T>
class Tnode
{
  public :
  T data;
  Tnode *lptr;
  Tnode *rptr;
};

template <typename T>
class Mtree
{ public :
  Mtree();
  void add(T x);
  bool find(T x);
  vector<T> inOrder();
  private :
  bool find(Tnode<T> *ptr, T x);
  void inOrder(Tnode<T> *ptr);
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
Mtree<T>::Mtree()
{
    root = 0;
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
    
    if( ptr-> rptr == 0 and x > ptr->data)
    {
        Tnode<T> *nptr = new Tnode<T>;
        nptr->data=x;
        nptr->lptr=0;
        nptr->rptr=0;
        ptr->rptr=nptr;
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

template <typename T>
bool Mtree<T>::find(T x)
{
    if(tsize == 0)
    {
        return false;
    }

    else return find(root, x);
}

template <typename T>
bool Mtree<T>::find(Tnode<T>*ptr, T x)
{
    if(ptr == 0)
    {
        return false;
    }

    if(ptr->data==x)
    {
        return true;
    }

    if(x<=ptr->data)
    {
        return find(ptr->lptr, x);
    }
    else
    {
        return find(ptr->rptr,x);
    }
}

template <typename T>
vector<T> Mtree<T>::inOrder()
{
    v.clear();
    if(tsize==0)
    {
        return v;
    }
    else
    {
        inOrder(root);
        return v;
    }
}

template <typename T>
void Mtree<T>::inOrder(Tnode<T> *ptr)
{
    if(ptr == 0)
    {
        return;
    }
    else
    {
        inOrder(ptr->lptr);
        v.push_back(ptr->data);
        inOrder(ptr->rptr);
    }
}
int main()
{
    Mtree<int> testTree;
    srand(time(NULL));

    cout << "Filling tree with random values\n";

    for(int i = 0; i <= 10; i++)
    {
        testTree.add(rand()%100);
    }

    vector <int> v = testTree.inOrder();
    cout << "Displaying tree in order: ";
    for(int i = 0; i <= v.size()-1; i++)
    {
        cout << v[i] << " ";
    }
    
    cout << "\nEnd\n";

}