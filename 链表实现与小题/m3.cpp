#include <iostream>
using namespace std;

int main()
{
	int a[10] = { 0 };
	int sun = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 10; i++)
	{
		if (a[i] < 0)
		{
			sun += a[i];
		}
	}
	cout << sun << endl;
	system("pause");
	return 0;
}