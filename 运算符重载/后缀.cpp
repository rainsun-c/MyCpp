//#include<iostream>
//#include <string>
//using namespace std;
//typedef unsigned int ms;
////以——为开头
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
//用户自定义字面量(重载后缀)
//整型  unsigned long long 
//浮点型 long double
//字符串  cosnt  char *str
//用户自定义的后缀，最好使用_开始，否则编译器会警告


void displayTime(int ms)
{
	cout << "毫秒数: " << ms << endl;
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
//len 是编译器自动给我们串的参数，代表着字符串的长度
ms operator"" _ref(const char* str, size_t len)
{
	cout << len << endl;
	return len;
}
int main()
{
	//2 默认是int类型
	int a = 2;
	long int b = 2L;

	int hover = 1_h;	//1小时
	int min = 1_m;	//1分钟

	cout << "hello world"_ref << endl;

	displayTime(1_h);
	displayTime(1_m);
	while (1);
	return 0;
}