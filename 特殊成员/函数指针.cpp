#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	void show()
	{
		cout << "������" << endl;
	}
};
void AAA()
{
	cout << "h h h"<< endl;
}
int main()
{
	//��ͨ����ָ��
	void (*pt)();
	pt = AAA;
	pt();

	A a;
	A* n = new A;

	//��Ա����ָ��Ķ���
	void (A::*xx)() = &A::show; 

	//2�ֵ��÷�ʽ
	(a.*xx)();
	(n->*xx)();
	while (1);
	return 0;
}