#include<iostream>
#include <string>
using namespace std;
/*
	1,“operator()”必须是成员函数，重载了（）的类的对象，可以叫做可调用对象
	2,-> 成员访问运算符
*/
class A
{
public:
	A(int num = 0) :num(num) {}
	void show()
	{
		cout << num << endl;
	}

	bool operator()(int a, int b)
	{
		cout << "void operator()()" << endl;
		return a > b;
	}
private:
	int num;
};


void sort(int arr[], int len, A compare)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int k = 0; k < len - i - 1; k++)
		{
			if (compare(arr[k], arr[k + 1]))
			{
				std::swap(arr[k], arr[k + 1]);
			}
		}
	}
}

class B
{
public:
	B(int id = 0) :id(id) {}
	void show()
	{
		cout << id<< endl;
	}
	friend ostream& operator <<(ostream& out, B object)
	{
		out << object.id;
		return out;
	}
private:
	int id;
};
template<class T>
class Auto_ptr
{
public:
	Auto_ptr(T* ptr = nullptr) :ptr(ptr) {}
	T* operator->()
	{
		return ptr;
	}
	T& operator *()
	{
		return *ptr;
	}
protected:
	T* ptr;
};

int main()
{
	B* aaa = new B(66);
	Auto_ptr<B> p(aaa);
	B b(*p);
	b.show();
	cout << *p << endl;



	//使用方法仿函数
	int aa[5] = { 2,5,11,7,1 };
	sort(aa, 5, A());


	while (1);
	return 0;
}