#include <iostream>
#include <string>
using namespace std;

/*
		1.��ģ�������ʾ����
		2.��ģ�岻��һ�����������ͣ������õ��������ĵط������������<>�ķ�ʽʹ��
		3.���ܲ��ö��ļ���д������������ͬһ��.h��


		ֻҪ��template ���ξ���һ��ģ���࣬�Ͳ���һ������������
*/
template <class type1>
class AA
{
public:
	AA( int x,type1 b) :x(x), b(b){}
	void print()
	{
		cout << b <<endl;
	}
	void p(int a);
protected:
	int x;
	type1 b;
};
template<class type1>
void AA<type1>::p(int a)
{
	cout << "�����������" << endl;
}
int main()
{
	AA<string> mm(4,"ţ��");
	mm.print();
	system("pause");
	return 0;
}