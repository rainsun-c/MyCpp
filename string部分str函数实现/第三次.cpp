#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

class myString
{
public:
	myString()
	{
		this->str = new char[100];
		strcpy(str, "\0");
	}
	//拷贝构造
	myString(const char* str)
	{
		this->str = new char[strlen(str) + 1];
		strcpy(this->str, str);
	}

	myString(const myString& object)
	{
		this->str = new char[strlen(object.str) + 1];
		strcpy(str, object.str);
	}
	~myString()
	{
		if (str)
		{
			delete[]str;
			str = nullptr;
			cout << "调用析构函数" << endl;
		}
	}
	//拼接
	myString mystrCat(const char* object)
	{
		myString t;  
		strcat(t.str, this->str);
		strcat(t.str, object);
		return t;
	}
	//比较
	int compare(myString& object)
	{
		int n = strcmp(str, object.str);
		return n;
	}

	//反转
	char* revel()
	{
		return strrev(str);
	}
	//求大小
	int size()
	{
		return strlen(str);
	}
	//打印
	void show()
	{
		cout << this->str << endl;
	}
	char* getStr()
	{
		return str;
	}
protected:
	char* str;
};

int main()
{
	
	myString str1("sdfggh");
	myString str2("哈哈哈哈");
	//拷贝
	myString str3(str2);
	cout << "拷贝显示：   ";
	str3.show();
	myString xx = str1.mystrCat(str2.getStr());
	cout << "拼接显示：   ";
	xx.show();
	cout << "反转显示：   ";
	str1.revel();
	str1.show();
	int n=str1.size();

	cout << "长度：      ";
	cout << n << endl;
	cout << "大小比较:   ";
	int m = str1.compare(str2);
	cout << m << endl;
	return 0;
}