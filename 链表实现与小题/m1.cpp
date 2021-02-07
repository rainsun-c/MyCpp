#include <iostream>
using namespace std;

int main()
{
	int max = 0;
	for (int i = 0; i < 101;i++)
	{
		if (i % 17 == 0)
		{
			if (max < i)
			{
				max = i;
			}
		}
	}
	cout << max << endl;
	system("pause");
	return 0;
}