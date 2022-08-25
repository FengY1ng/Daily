#include <iostream>
#include <string>
#include <conio.h>
#include <cstring>

using namespace std;

int main()
{
	int a[10] = { 17,12,5,36,55,19,3,9,25,41 },*p1=a;
	for (int i = 0; i < 10; i++)
	{
		int *max = p1+i;
		for (int j = i; j < 10; j++)
			if (*(p1+j) > *max)
				max = p1+j;
		int t = *max;
		*max = *(p1+i);
		*(p1+i) = t;
	}
	for (int i = 0; i < 10; i++)
		cout << a[i]<<"\t";
	return 0;
}