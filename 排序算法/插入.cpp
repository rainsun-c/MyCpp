#include <iostream>
using namespace std;

int main()
{
	int a[10] = { 3,21,5,32,65,43,7,11,89,4 };
	int j = 0;
	int temp = 0;
	for (int i = 1; i < 10; i++)
	{
		temp = a[i];
		j = i - 1;
		while (j >= 0 && temp < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	while (1);
	return 0;
}