//#include<iostream>
//#include <string>
//using namespace std;
//typedef unsigned int ms;
////�ԡ���Ϊ��ͷ
//
//
//typedef unsigned int ms;
//ms operator""_h(long long time)
//{
//
//}
//int main()
//{
//
//	while (1);
//	return 0;
//}


#include<iostream>
using namespace std;
//�û��Զ���������(���غ�׺)
//����  unsigned long long 
//������ long double
//�ַ���  cosnt  char *str
//�û��Զ���ĺ�׺�����ʹ��_��ʼ������������ᾯ��


void displayTime(int ms)
{
	cout << "������: " << ms << endl;
}
typedef unsigned int ms;
ms operator"" _h(unsigned long long time)
{
	return time * 60 * 60;
}
ms operator"" _m(unsigned long long time)
{
	return time * 60;
}
//len �Ǳ������Զ������Ǵ��Ĳ������������ַ����ĳ���
ms operator"" _ref(const char* str, size_t len)
{
	cout << len << endl;
	return len;
}
int main()
{
	//2 Ĭ����int����
	int a = 2;
	long int b = 2L;

	int hover = 1_h;	//1Сʱ
	int min = 1_m;	//1����

	cout << "hello world"_ref << endl;

	displayTime(1_h);
	displayTime(1_m);
	while (1);
	return 0;
}