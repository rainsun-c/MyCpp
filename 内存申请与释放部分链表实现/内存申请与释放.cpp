#include<iostream>
#include <string>
using namespace std;

int** myMolloc(int**&p, int col, int row)
{
	p = new int*[col];
	for (int i = 0; i < col; i++)
	{
		p[i] = new int[row];
	}
	return p;
}
void myFree(int**&p, int col)
{
	for (int i = 0; i < col; i++)
	{
		delete[col] p[i];
	}
	delete[]p;
}
int main()
{
	int**a = myMolloc(a, 3, 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0;j < 3; j++)
		{
			a[i][j] = i;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << a[i][j] << " ";
		}
	}
	myFree(a,3);
	while (1);
	return 0;
}