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
//������ʽʵ��A������+  Ҫ�������˽�г�ԱҪ�������Ȩ�ޣ�ʹ��Ҫ��friend
A add(A& a, A& b)
{
	A x(a.id + b.id, a.name + b.name);
	return x;
}
//��operator
A operator+(A& a, A& b)
{
	A x(a.id + b.id, a.name + b.name);
	return x;
}

int main()
{
	A a(1, "������");
	A b(2, "����");
	//ȫ�ֺ���
	A c = add(a, b);
	c.show();
	//��operator ����2�ֵ��÷�ʽ
	//1����������
	A d = operator+(a, b);
	d.show();
	//2��ֱ��������
	A f=a+b;
	f.show();
	while(1)
	return 0;
}