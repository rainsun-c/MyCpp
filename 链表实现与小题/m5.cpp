#include <iostream>
using namespace std;

int cur(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	return cur(n - 1) + cur(n - 2);
}

int main()
{
	int n = 4;
	int s=cur(n);
	cout << s << endl;
	system("pause");
	return 0;
}