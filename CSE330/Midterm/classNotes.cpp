/* question 1 about operator -- */
void operator--(int);//postfix
void operator--(); //prefix

template <typename T>
void Mvector<T>::operator--(int)
{
    this->popback();
}

/*question 2*/
void younameit(vector <int> v)
{
    for(int i = 0; i < v.size()-1;i++)
    {
        for(int j = i+1;j< v.size()-1;j++)
        {
            cout << v[i] << v[j] << endl;   
        }
    }
}

/* what does it do?
    if you had a vector [10 ,20, 30, 40, 50]
    then the loop will print 1020, 1030, 1040, 1050
                             2030, 2040, 2050,
                             3040, 3050
                             4050
time complexity == O(n^2) = (n^2 -n)/2

vector = 6
let n = v.size()
in first loop i goes from 0 to n-2
so you go through first loop n-2 times

0 = n-2
1 = n-3
*/

//Problem 3

//interface

