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
	//先置++，先+，再给
	A operator++()
	{
		++this->num;
		return (*this);
	}
	//后置++，先给，再+,用占位参数int 标记（只能用int）
	A operator++(int)
	{
		//保存原来的值
		A mm = *this;
		//在++
		this->num++;
		//返回原来的值
		return mm;
	}
private:
	int num;
};


int main()
{
	A a(5);
	++a;
	a.show();

	A x=a++;
	cout << "x  :";
	x.show();
	cout << "a  :";
	a.show();
	while (1);
	return 0;
}