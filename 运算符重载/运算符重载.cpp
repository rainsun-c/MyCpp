#include<iostream>
#include <string>
using namespace std;

class A
{
public:
	A(int id = 0, string name = " ") :id(id), name(name) {}
	friend A add(A& a, A& b);
	friend A operator+(A& a, A& b);
	void show()
	{
		cout << id << "  " << name << endl;
	}
private:
	int id;
	string name;
};
//函数方式实现A类型相+  要访问类的私有成员要打破类的权限，使用要用friend
A add(A& a, A& b)
{
	A x(a.id + b.id, a.name + b.name);
	return x;
}
//用operator
A operator+(A& a, A& b)
{
	A x(a.id + b.id, a.name + b.name);
	return x;
}

int main()
{
	A a(1, "嘻嘻嘻");
	A b(2, "哈哈");
	//全局函数
	A c = add(a, b);
	c.show();
	//用operator 函数2种调用方式
	//1、函数调用
	A d = operator+(a, b);
	d.show();
	//2、直接正常用
	A f=a+b;
	f.show();
	while(1)
	return 0;
}