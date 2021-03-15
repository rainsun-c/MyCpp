#include <iostream>
using namespace std;

int main()
{
	int a[10] = { 3,21,5,32,65,43,7,11,89,4 };
	
	int temp = 0;
	for (int i = 1; i < 10; i++)
	{
		int j = 0;
		temp = a[i];
		for (j = i -1; j > 0; j--)
		{
			if (a[i] < a[j])
			{
				a[i] = a[j];
			}
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