#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;
//�ṹ��������ں���������ʹ��ʱ���Բ�ʹ��struct
struct A
{
	int id;
	void p(int a)
	{
		cout << "ˮ�ײ�" << a<<endl;
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