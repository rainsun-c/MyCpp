#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

struct A
{
	int id;
	string name;
	A(int id, string name)
	{
		this->id = id;//this指针指向自身
		this->name = name;
	}
	void p()
	{
		cout << this->id << "" << this->name << endl;
	}
};
int main()
{
	/*A a = { 2, "afaf" };*/
	//两种方式
	A a (2,"sad");//c++形态强调函数形态
	a.p();
	A* b = new A(3,"fsd");//创建一个类型为A的无名对象，将它的地址给b
	delete b;
	while (1);
	return 0;
}