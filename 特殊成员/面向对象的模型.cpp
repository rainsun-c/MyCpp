#include <iostream>
#include <string>
using namespace std;
//类中函数和静态变量不占内存
class stu
{
public:
	stu()
	{
		name = "nn";
	}
	static int A()
	{
		cout << "静态函数" << endl;
	}
	void show()
	{
		A();
		cout << name<<"普通函数" << endl;
	}
protected:
	static int id;
	string name;
};
int stu::id=66;

////解析成C语言方式
//struct Stu
//{
//	string name="nn";
//};
//static int id=66;
//
//void show(Stu* pthis)//this，为了防止被修改所以void show(Stu*const pthis);加上const
//{
//	cout<< pthis->name;
//}
////因为静态函数中没有Stu* pthis指针，所以没有办法使用普通成员，只能使用静态变量
//static int A()
//{
//	cout << id <<endl;
//}


int main()
{
	stu s;
	/*Stu x;*/
	//c++
	s.show();
	stu::A();
	//转成c语言
	/*show(&x);
	A();*/

	system("pause");
	return 0;
}