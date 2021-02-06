#include<iostream>
#include <string>
using namespace std;

namespace mswap
{
	void swap(int& a,int& b)
	{
		int temp = 0;
		temp = a;
		a = b;
		b = temp;
	}
	void swap(char& a, char& b)
	{
		char temp = 0;
		temp = a;
		a = b;
		b = temp;
	}
	void swap(float& a, float& b)
	{
		float temp = 0;
		temp = a;
		a = b;
		b = temp;
	}
	void swap(double& a, double& b)
	{
		double temp = 0;
		temp = a;
		a = b;
		b = temp;
	}
}
int main()
{
	int b = 9;
	int a = 10;
	char c = 'A';
	char d = 'B';
	mswap::swap(a,b);
	cout << b << " " << a << endl;
	mswap::swap(c, d);
	cout << c << " " << d << endl;
	while (1);
	return 0;
}