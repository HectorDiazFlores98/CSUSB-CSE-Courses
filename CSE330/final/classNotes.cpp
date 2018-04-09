/*
    things to know
        1. Time Complexity
        2. mVector Class
        3. mList class
        4. mTree class
*/

//Problem #1 vector

//in class 
bool operator==(Mvector<T>v2);

//in operator definitions
template<typename T>
bool mVector<T>::operator==(Mvector<T>v2)
{
    if(this->size()!= v2.size())
    {
        return false;
    }
    
    for(int i = 0; i <= v2.size();i++)
    {
        if(v[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}
//in main
mVector<int>v;
mVector<int>v2;
if(v==v2)
{
    cout << "true\n";
}

/**********************************************************************/

//Problem #2 

int younameit(int n)
{
    int sum=0; // runs once
    for (int i=0; i< n; i++) // runs == n
    {
        for (int j=0; j < n*n; j++) //runs == n^3
        { 
            sum++; //runs == n^3
        }
    }
    return sum; // runs once
}

//total time complexity == 2N^3 + N + 2 == O(n^3)

/*********************************************************************/
//Problem 3
//Write a function for the Mlist class which erases the list. Be sure to
//delete every Lnode in the list.

//interface
void erase();

//definition
template <typename T>
void mList<T>::erase()
{
    if(lsize==0)return;

    Lnode<T> *ptr = first;
    while(ptr != 0)
    {
        Lnode<T> *next = ptr->rptr;
        delete ptr;
        ptr = next;
    }

    front = 0;
    last = 0;
    lsize=0;

}

template <typename T>
void mList<T>::erase()
{
    front = 0;
    last = 0;
    lsize=0;
}

template <typename T>
void mList<T>::erase(Lnode<T> *ptr)
{
    if(ptr==0)
    {
        return;
    }
    else
    {
        erase(ptr->rptr);
        delete ptr;
        return;
    }
}

/*******************************************************************/
//problem #4
//Add a function to the Mtree class delete(x) which deletes the node
//from the Mtree with value x if the node with value x is a leaf - a node without any children.

void mTree<T>::delete(x)
{
    delete(root, x);
    
}

void mTree<T>::delete(Tnode<T>*ptr)
{
    if(ptr == root and ptr->data==x and ptr->lptr==0 and ptr->rptr==0)
    {
        delete ptr;
        tsize--;
        root=0;
        return
    }

    if(ptr->lptr->data==x and ptr->lptr->lptr==0 and ptr->ltpr->rptr==0)
    {
        delete ptr->lptr;
        tsize--;
        return;
    }

    if(ptr->rptr->data==x and ptr->rptr->lptr==0 and ptr->rptr->rptr==0)
    {
        delete ptr->rptr;
        ptr->rptr=0;
        tsize--;
        return;
    }

    if(x<= ptr->data and ptr->lptr!=0)
    {
        delete(ptr->lptr, x);
    }
    else if(ptr->rptr!=0)
    {
        delete(ptr->rptr, x);
    }
}

/*************************************************************/
//Give the Mtree for the integers added in the following order : 10
//18 5 14 2 16 3 12 8.
//(b) List the values from the tree after a pre-order search

                            /10\
                        /5\       \18
                      2/   \8     /14\
                       \3        /12  \16
            
preorder == root left right
10,5,2,3,8,18,14,12,16
post == left right root
3,2,8,5,12,16,14,18,10

/*****************************************************************/
/*
Assume you have an implementation of the Mvector class with the
== operator of Problem 1 and the Mtree class. Write a main program segment that will check
if two Mtrees t1 and t2 have exactly the same content. You can assume that the Mtree inorder
function returns an Mvector.
*/

Mtree<int> t1 == Mtree<int>;
Mtree<int> t2 == Mtree<int>;

Mvector<int>v1 = t1.inorder();
Mvector<int>v2 = t2.inorder();

if(v1 == v2)
{
    cout << "equal";
}
else cout << "not equal";