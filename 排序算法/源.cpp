#include<iostream>
#include <string>
using namespace std;

int main()
{
	int a[10] = { 34,4,56,2,75,43,5,7,34,9 };
	int len = sizeof(a) / sizeof(int);
	int step = 0;
	int temp;
	int j = 0;
	step =len >> 1;
	//以步长分类，对半
	while (step)
	{
		for (int i = 1; i < 10; )
		{
			temp = a[i];
			j = i - 1;
			while (j >= 0 && temp < a[j])
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = temp;
			i = i + step;
		}
		step >>= 1;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}