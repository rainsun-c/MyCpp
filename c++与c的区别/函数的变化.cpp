#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
/*
函数多了内联函数：(以二进制代码存在（牺牲空间提高效率）常在 修饰符inline ,结构体与类中的函数使用)
函数重载：(同名不同参)只与参数顺序有关
函数缺省：（只能从右往左缺省）实现同一函数的不同调用（函数重载的集合）
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
	//内联函数
	cout << M(2, 3) << endl;
	//函数缺省
	fun(2);
	fun(2,3);
	fun(2,5,4);
	//重载
	cout << add(2, 3) << endl;
	cout << add(2, 3,4) << endl;
	while (1);
	return 0;
}