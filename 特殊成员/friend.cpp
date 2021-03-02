#include <iostream>
#include <string>
using namespace std;
//打破限定符
//友元函数，破坏了类的封装性
class A
{
public:
	A(int money = 666666) :money(money) {}
	friend class B;		     //友元类的声明
private:
	friend void mo(A mm);     //友元函数声明
	int money;
};
class B
{
public:
	void show(A m)
	{
		m.money;
	}
private:
	
};

void mo(A mm)
{
	cout<< mm.money;  
}

int main()
{
	A zhang;
	mo(zhang);

	while (1);
	return 0;
}