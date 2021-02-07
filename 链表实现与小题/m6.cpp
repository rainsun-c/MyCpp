#include <iostream>
using namespace std;

int main()
{
	int n1 = 2.0;
	int n2 = 3.0;
	int c1 = 1.0;
	int c2 = 2.0;
	float sum = 0;
	for (int i = 0; i <=0; i++)
	{	
		int y=n1%c1 + n2%c2;
		float x = n1 / c1 + n2 / c2+y;
	
		sum += x;
		n1 = n2 + n1;
		n2 = n1 + n2;
		c1 = c1 + c2;
		c2 = c1 + c2;
	}
	cout << sum << endl;
	system("pause");
	return 0;
}