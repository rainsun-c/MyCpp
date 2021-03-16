#include <iostream>
using namespace std;

int main()
{
	int a[10] = { 3,21,5,32,65,43,7,11,89,4 };
	int temp = 0;
	for (int i = 0; i < 9; i++)
	{
		temp = i;
		for (int j = i + 1; j < 10; j++)
		{
			temp =(a[temp] > a[j] ? j : temp);
		}
		if(a[temp]<a[i])
		{
			int x = a[temp];
			a[temp] = a[i];
			a[i] = x;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	while (1);
	return 0;
}