#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class mystring
{
public:
	mystring(char* str) 
	{
		this->str = new char[sizeof(str)+1];
		strcpy(this->str,str);
	}
	mystring(mystring& str)
	{
		this->str = new char[sizeof(str)+1];
		strcpy(this->str, str.str);
	}
	void show()
	{
		cout << str<< endl;
	}
	mystring operator+(mystring A)
	{
		mystring mystr(strcat(this->str, A.str));
		return mystr;
	}
protected:

	char* str;
};
int main()
{
	mystring str("������");
	mystring str2("˳�ᵽ����");
	str.show();
	mystring mystr(str);
	mystr = str;
	mystring str3=str2+str;
	str3.show();
	system("pause");
	return 0;
}