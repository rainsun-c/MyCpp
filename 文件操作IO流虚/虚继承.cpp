#include <iostream>
#include <string>
using namespace std;

//
class A
{
public:
	A(int a) :a(a){}
	 int a;
protected:

};
class B : virtual public A
{
public:
	B(int a, int b) : b(b),A(a){};
	int b;
protected:
};
class C:virtual public A
{
public:
	C(int c, int a) :c(c), A(a){}
	int c;
protected:
};
class D :public C, public B
{
public:
	D(int a, int b, int c, int d) :A(555), B(a, b), C(c, a), d(d),a(a){}
	void print()
	{
		cout << a << "\t" << b << "\t" << c << "\t" << d<<endl;
	}
protected:
	int d;
	int a;
};
int main()
{
	D ss(1, 2, 3, 4);
	ss.print();
	system("pause");
	return 0;
}