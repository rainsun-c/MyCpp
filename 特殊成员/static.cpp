#include <iostream>
#include <string>
using namespace std;

class stu
{
public:
	stu()
	{
		name="nn";
	}
	static int A()
	{
		id = 666;
		return id;
	}
	int& getId()
	{
		A();
		id = 7;
		return id;
	}
protected:
	static int id;
	string name;
};
//类内声明，类外初始化（在构造函数中也不行）
int stu::id=1;
int main()
{
	stu s;
	cout <<s.getId()<< endl;

	
	cout << s.A << endl;		//以对象调用
	cout << stu::A << endl;		//以类名限定调用
	system("pause");
	return 0;
}