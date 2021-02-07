#include <iostream>
using namespace std;

int main()
{

	for (int a = 0; a < 10; a++)
	{
		for (int b = 0; b < 10; b++)
		{
			for (int c = 0; c < 10; c++)
			{
				if (a * 100 + b * 10 + c + c * 100 + b * 10 + a == 1333)
				{
					cout << a << " " << b << " " << c << endl;
				}
			}
		}
	}
	system("pause");
	return 0;
}