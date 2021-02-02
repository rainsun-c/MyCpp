#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;
//结构体允许存在函数，定义使用时可以不使用struct
struct A
{
	int id;
	void p(int a)
	{
		cout << "水白菜" << a<<endl;
	}
};

int main()
{
	A a = { 2 };
	a.id = 5;
	a.p(a.id);
	while (1);
	return 0;
}