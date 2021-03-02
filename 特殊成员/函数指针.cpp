#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	void show()
	{
		cout << "嘻嘻嘻" << endl;
	}
};
void AAA()
{
	cout << "h h h"<< endl;
}
int main()
{
	//普通函数指针
	void (*pt)();
	pt = AAA;
	pt();

	A a;
	A* n = new A;

	//成员函数指针的定义
	void (A::*xx)() = &A::show; 

	//2种调用方式
	(a.*xx)();
	(n->*xx)();
	while (1);
	return 0;
}