#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
/*
������������������(�Զ����ƴ�����ڣ������ռ����Ч�ʣ����� ���η�inline ,�ṹ�������еĺ���ʹ��)
�������أ�(ͬ����ͬ��)ֻ�����˳���й�
����ȱʡ����ֻ�ܴ�������ȱʡ��ʵ��ͬһ�����Ĳ�ͬ���ã��������صļ��ϣ�
*/	
inline int M(int a, int b)
{
	return a>b?a:b;
}
void fun(int a, int b=2, int c=4)
{
	cout << a << endl;
	cout << b+a << endl;
	cout << c << endl;
}
int add(int a, int b)
{
	return (a+b);
}
int add(int a, int b,int c)
{
	return (a + b+c);
}
int main()
{
	//��������
	cout << M(2, 3) << endl;
	//����ȱʡ
	fun(2);
	fun(2,3);
	fun(2,5,4);
	//����
	cout << add(2, 3) << endl;
	cout << add(2, 3,4) << endl;
	while (1);
	return 0;
}