#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	A(int c) :c(c){}
	A(){}
	/*friend istream&operator>>(istream&in,A& a)
	{
		cout << "调用成功" << endl;
		in >> a.c;
		return in;
	}
	friend ostream&operator<<(ostream&out, A& a)
	{
		cout << "调用成功" << endl;
		out << a.c ;
		return out;
	}*/
	void p(istream&in)
	{
		cout << "ok" << endl;
		in >> this->c;
	}
	void pr(ostream&out)
	{
		out << this->c;
	}
	friend istream&operator>>(istream&in, A& a)
	{
		a.p(in);
		return in;
	}
	friend ostream&operator<<(ostream&out, A& a)
	{
		a.pr(out);
		return out;
	}
	void print()
	{
		cout << c << endl;
	}
protected:
	int c;
};

int main()
{
	A a(10);
	operator>>(cin, a);
	a.print();
	system("pause");
	return 0;
}
