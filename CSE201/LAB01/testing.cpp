#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
vector<int> append(vector<int> a, vector<int> b)
{
    vector<int> c;
    int i;

    for (i = 0; i < a.size(); i++)
        c.push_back(a[i]);

    for (i = 0; i < b.size(); i++)
        c.push_back(b[i]);

    return c;
}
*/
vector<int> append(vector<int> a, vector<int> b)
{
    int n = a.size();
    int m = b.size();
    vector<int> c(n + m);
    int i;

    for (i = 0; i < n; i++)
        c[i] = a[i];

    for (i = 0; i < m; i++)
        c[n + i] = b[i];

    return c;
}


vector<int> merge(vector<int> a, vector<int> b)
{
    vector<int> c;
    //int i;


    for ( int i = 0; i < a.size(); i++)
        c.push_back(a[i]);

    for ( int i = 0; i < b.size(); i++)
        c.push_back(b[i]);

    return c;
}

vector<int> merge_sorted(vector<int> a, vector<int> b)
{
    vector<int> c;

    int i = 0, j = 0;
    while (i < a.size() and j < b.size())
        if (a[i] < b[j])
            c.push_back(a[i++]);
        else
            c.push_back(b[j++]);

    for ( ; i < a.size(); i++)
        c.push_back(a[i]);

    for ( ; j < b.size(); j++)
        c.push_back(b[j]);

    return c;
}

main()
{
    vector<int> a, b, c;
    int value;

    cout << "Enter values for a until -1: ";
    cin >> value;
    while (value >= 0) {
        a.push_back(value);
        cin >> value;
    }

    cout << "Enter values for b until -1: ";
    cin >> value;
    while (value >= 0) {
        b.push_back(value);
        cin >> value;
    }

    c = append(a, b);

    cout << "c append: ";
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " ";
    cout << endl;

    c = merge(a, b);

    cout << "c merge: ";
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " ";
    cout << endl;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    c = merge_sorted(a, b);

    cout << "c merge_sorted: ";
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " ";
    cout << endl;
}