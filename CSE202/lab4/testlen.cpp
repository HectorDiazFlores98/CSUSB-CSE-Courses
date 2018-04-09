#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int cstr_len(const char cstr[])
{
    int i = 0;
    int count = 0;
    while(cstr[i])
    { 
        if(isalnum(cstr[i]))
        {
            count++;
        }
        else if(isspace(cstr[i]))
        {
            count++;
        }
        i++;
    }
     return count;
}

int main()
{
	char cs[128] = "The quick brown fox";
	cout << "size of the char string: " << cstr_len(cs) << endl;
	return 0;
}