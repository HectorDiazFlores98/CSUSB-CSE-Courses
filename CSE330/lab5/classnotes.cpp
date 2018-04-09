
template <typename T>
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
  Mlist();
  void add(T x);
  void add(,int i,T x);
  void del(T x);
  void delete(int i);
  T getfront();
  T getback();
  T operator[] (unsigned int i);
  typedef Lnode<T> *iterator
  iterator front(){}//returns first
  iterator back(){}//returns last
  

  private :
  Lnode<T> *first;
  Lnode<T> *last;
  int lsize;
};

int main()
mList<int> v=mList<int>();
v.add(number);

Lnode<int> *ptr;
for(prt=v.front())
{
    ptr!=0;
    ptr=ptr->rptr;
    cout << ptr->rptr;
}

template <typename T>
T mList<T>::operator[](unsigned int i)
{
    Lnode<T> *ptr;
    ptr = first
    for(int j = 0; j < i;j++)
    {
        ptr = ptr->rptr;

    }
    return ptr->data;
}
