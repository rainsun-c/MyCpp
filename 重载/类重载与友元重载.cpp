#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	A(int a, int b=0 ) :n1(a), n2(b){}
	A(){}
	A operator+(A object)//类重载
	{
		A a(this->n1 + object.n1, this->n2 + object.n2);
		return a;
	}
	friend A operator-(A a, A b)
	{
		A c;
		c.n1 = a.n1 - b.n1;
		c.n2 = a.n2 - a.n2;
		return c;
	}
	void print()
	{
		cout << this->n1 << " " << this->n2 << endl;
	}
protected:
	int n1;
	int n2;
};

struct AA
{
	int n;
	int b;
	AA(int a,int b = 0) :n(a), b(b){}
	AA(){}
	void print()
	{
		cout << n << " " << b << endl;
	}
	
};
//结构体的运算符重载相当于友元重载
AA operator-(AA a, AA b)
{
	AA c;
	c.b = a.b + b.b;
	c.n = a.n - b.n;
	return c;
}
int main()
{
	A aa(2,3);
	A bb(2, 3);

	A cc = 1 - aa;
	cc.print();
	AA a(2, 3);
	AA b(2, 3);

	AA ad ;
	ad = a - b;
	ad.print();
	system("pause");
	return 0;
}