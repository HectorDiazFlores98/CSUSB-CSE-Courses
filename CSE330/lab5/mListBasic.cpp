#include<iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>

using namespace std;

template <typename T>
class Lnode
{
  public :
  T data;
  Lnode *lptr;
  Lnode *rptr;
};

template <typename T>
class Mlist
{ public :
  typedef Lnode<T> *iterator;
  iterator front(){return first;}
  iterator back(){return last;}
  Mlist();
  void add(T x);
  void add(int i,T x);
  void insert(int i, T x);
  void del_index(int i);
  void deletefront();
  T getfront();
  T getback();
  T operator[] (unsigned int i);
  
  

  private :
  Lnode<T> *first;
  Lnode<T> *last;
  int lsize;
};

template<typename T>
Mlist<T>::Mlist()
{
  first=0;
  last=0;
  lsize=0;
}
template<typename T>
void Mlist<T>::add(T x)
{
  Lnode<T> *ptr = new Lnode<T>;
  ptr->data=x;

  if(lsize == 0)
  {
    ptr->lptr = 0;
    ptr->rptr = 0;
    first = ptr;
    last = ptr;
    lsize++;
  }
  else
  {
    ptr->lptr=last;
    ptr->rptr = 0;
    last->rptr = ptr;
    last = ptr;
    lsize++;
  }
}
template<typename T>
void Mlist<T>::insert(int i, T x)
{
  assert(lsize > 0);
  Lnode<T> *nptr = new Lnode<T>;
  Lnode<T> *ptr = first; 
  for(int j = 0; j < i; j++)
  {
    ptr = ptr -> rptr;
  }
  nptr -> data = x;
  nptr -> lptr = ptr -> lptr;
  nptr ->  rptr = ptr;
  ptr -> lptr -> rptr = nptr;
  ptr -> lptr = nptr;
  lsize++;
}
template<typename T>
void Mlist<T>::del_index(int i)
{
  assert(lsize > 0);
  Lnode<T> *ptr = first;
  for(int j = 0; j < i; j++)
  {
    ptr = ptr -> rptr;
  }
  if( ptr == first)
  {
    this->deletefront();
  }
  else if(ptr == last)
  {
    if(ptr->lptr != 0)
    {
      ptr -> lptr -> rptr = 0;
    }
    delete ptr;
    lsize--;
  }
  else
  {
    if(ptr -> lptr !=0)
    {
      ptr->lptr->rptr=ptr->rptr;
      delete ptr;
      lsize--;
    }
  }
}
template<typename T>
void Mlist<T>::deletefront()
{
  Lnode<T> *cur = first;
  first->lptr=0;
  first = first->rptr;
  delete cur;
  lsize--; 
}

template <typename T>
T Mlist<T>::getfront()
{
  Lnode<T> *ptr;
  ptr = first;
  return ptr->data;
}

template <typename T>
T Mlist<T>::getback()
{
  Lnode<T> *ptr;
  ptr = last;
  return ptr->data;
}

template<typename T>
T Mlist<T>::operator[](unsigned int i)
{
  assert(lsize > 0);
  Lnode<T> *ptr;
  ptr = first;
  for(int j = 0; j < i; j++)
  {
    ptr = ptr->rptr;
  }
  return ptr->data;
}

int main()
{

  /*need to test
  delete front
  get front 
  get back
  */
  Mlist<int> v;
  Lnode<int> *ptr;
  srand(time(NULL));
  cout << "Current List: ";
  for(int i = 0; i < 10; i++)
  {
    v.add(rand()%100);
    cout << v[i] << " ";
  }
  cout << "\n\nInserting 999 to index position [2]\n\n";
  v.insert(2,999);
  
  cout << "Current List: ";
  for(int i = 0; i < 10; i++)
  {
    cout << v[i] << " ";
  }

  cout << "\n\nDeleting 999 from index position [2]\n\n";
  v.del_index(2);
  
  cout << "Current List: ";
  for(int i = 0; i < 10; i++)
  {
    cout << v[i] << " ";
  }

  cout << "\n\nDeleting front of list\n";
  v.deletefront();
  
  cout << "\nGetting Front\n";
  cout << "\n" << v.getfront();

  cout << "\nGetting Back\n";
  cout << "\n" << v.getback() << "\n";
}