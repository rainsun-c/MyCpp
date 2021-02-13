#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	A(int b = 0) :b(b){}
	void p(int a)
	{
		if (a == 0)
		{
			throw 5.77;
		}
		cout << a << endl;
	}
	int& getB()
	{
		return b;
	}
protected:
	int b;
};
int main()
{
	A* xxx = new A(999);
	try
	{
		xxx->p(0);
	}
	catch (int)
	{
		cout << "wei 0" << endl;
	}
	catch (double)
	{
		cout << xxx->getB() << endl;
	}
	catch (...)
	{
		cout << " .... " << endl;
	}
	system("pause");
	return 0;
}