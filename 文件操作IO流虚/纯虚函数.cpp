#include<iostream>
#include <string>
using namespace std;
class A
{
public:
	virtual void print() = 0;
	virtual void xxx() = 0;
protected:

};
class Aa :public A
{
public:
	Aa(int a) :x(a){}
	void print()
	{
		cout << x << "����" << endl;
	}
	void xxx()
	{
		cout << "����ʵ��" << endl;
	}
protected:
	int x;
};
int main()
{
	Aa tryy(3);
	tryy.print();
	tryy.xxx();
	system("pause");
	return 0;
}