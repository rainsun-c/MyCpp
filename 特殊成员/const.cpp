#include <iostream>
#include <string>
using namespace std;
//只能使用初始化参数列表


class stu
{
public:
	stu():id(2)
	{
		name = "nn";
	}
	int A()const
	{
		cout << "静态函数" << endl;
	}
	//等价 const  stu* const this  = const this->show()
	void show() const//可以调用但是不能该
	{
		
		cout << name << "普通函数" << endl;
	}
	int getId()
	{
		
		cout << id;
		return id;
	}

protected:
	const int id;
	string name;
};

//const对象 只能调用const
int main()
{
	stu s;
	s.getId();
	const stu c;
	c.show();
	while (1);
	return 0;
}