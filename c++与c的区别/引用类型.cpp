#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
//一、在函数的使用
//引用类型(即取别名)&是标志不是类型，本质上是指针的封装
void p( /*const */int &ooxx)//防止拷贝的产生（不会在产生一段内存）
//若要传常量加上const,或者加再加一个&（但是不可以传变量这样）
{
	if (ooxx)
	{
		ooxx = 666;
		cout << "成功" << endl;
	}
}
//二、在结构体和类中的使用
struct A
{
	int age;
	int& reage()
	{
		return age;
	}
};
int main()
{
	//int num = 3;
	//int &ooxx = num;//给num取了一个叫ooxx的名字
	//cout << ooxx << endl;
	//cout << num << endl;
 //   //在对函数传参数是可以说使用,与指针一样可以改原本的值（但是不可以传常量）
	//p(num);//相对于把实参直接放入
	//cout << num << endl;
	A a = {5};
	cout << a.age << endl;
	a.reage() = 7;//返回值age，相当于给age取了一个reage的名字
	cout << a.age << endl;

	while (1);
	return 0;
}