#include <iostream>
#include <string>
using namespace std;
//�����޶���
//��Ԫ�������ƻ�����ķ�װ��
class A
{
public:
	A(int money = 666666) :money(money) {}
	friend class B;		     //��Ԫ�������
private:
	friend void mo(A mm);     //��Ԫ��������
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