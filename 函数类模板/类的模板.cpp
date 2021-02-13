#include <iostream>
#include <string>
using namespace std;

/*
		1.类模板必须显示调用
		2.类模板不是一个完整的类型，所以用到了类名的地方必须采用类名<>的方式使用
		3.不能采用多文件的写法，必须是再同一个.h中


		只要用template 修饰就是一个模板类，就不是一个完整的类型
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
	cout << "调用这个函数" << endl;
}
int main()
{
	AA<string> mm(4,"牛逼");
	mm.print();
	system("pause");
	return 0;
}