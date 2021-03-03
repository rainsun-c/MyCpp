#include<iostream>
#include <string>
using namespace std;

class A
{
public:
	A(int num = 0) :num(num) {}
	void show()
	{
		cout << num << endl;
	}
	bool operator|(A& b)
	{
		return (this->num | b.num);
	}
	bool operator||(A& b)
	{
		return (this->num | b.num);
	}

private:
	int num;
};


int main()
{
	A a(2);
	A b;
	if (a || b)
	{
		cout << "a | bÕæ"<<endl;
	}
	if (b || a)
	{
		cout << "b | a¼Ù" << endl;
	}

	if (a | b)
	{
		cout << "a | bÕæ" << endl;
	}
	if (b | a)
	{
		cout << "b | a¼Ù" << endl;
	}

	while (1);
	return 0;
}