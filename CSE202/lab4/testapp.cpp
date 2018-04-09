#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void cstr_append(char a[], const char b[])
{
    strcat(a,b);
}

int main()
{
	char cs[128] = "The quick brown ";
	cstr_append(cs, "fox");
	cout << cs << endl;
	return 0;
}