#include <iostream>
using namespace std;

//int fibonace()
//{   // 1 1 2 3 5 8 13 21
//	static int a0 = 0; 
//	static int a1 = 1;
//	int ret = a1;
//	a1 = a0 + a1;
//	a0 = ret;
//	return ret;
//}

class fibonace
{
public:
	fibonace() :_a0(0), _a1(1) {}
	fibonace(int n) :_a0(0), _a1(1)
	{
		for (int i = 0; i < n-1; i++)
		{
			int ret = _a1;
			_a1 = _a1 + _a0;
			_a0 = ret;
		}
	}
	~fibonace() {}
	int& operator()()
	{
		int ret = _a1;
		_a1 = _a1 + _a0;
		_a0 = ret;
		return ret;
	}

private:
	int _a0;
	int _a1;
};


int main()
{
	fibonace x;
	for (int i = 0; i < 10; i++)
	{
		cout << x() << "  ";
	}
	cout << endl;
	fibonace y(5);
	for (int i = 0; i < 10; i++)
	{
		cout << y() << "  ";
	}
	system("pasue");
	return 0;
}