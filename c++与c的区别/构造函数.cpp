#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

struct A
{
	int id;
	string name;
	A(int id, string name)
	{
		this->id = id;//thisָ��ָ������
		this->name = name;
	}
	void p()
	{
		cout << this->id << "" << this->name << endl;
	}
};
int main()
{
	/*A a = { 2, "afaf" };*/
	//���ַ�ʽ
	A a (2,"sad");//c++��̬ǿ��������̬
	a.p();
	A* b = new A(3,"fsd");//����һ������ΪA���������󣬽����ĵ�ַ��b
	delete b;
	while (1);
	return 0;
}