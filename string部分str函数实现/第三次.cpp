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
	//��������
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
			cout << "������������" << endl;
		}
	}
	//ƴ��
	myString mystrCat(const char* object)
	{
		myString t;  
		strcat(t.str, this->str);
		strcat(t.str, object);
		return t;
	}
	//�Ƚ�
	int compare(myString& object)
	{
		int n = strcmp(str, object.str);
		return n;
	}

	//��ת
	char* revel()
	{
		return strrev(str);
	}
	//���С
	int size()
	{
		return strlen(str);
	}
	//��ӡ
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
	myString str2("��������");
	//����
	myString str3(str2);
	cout << "������ʾ��   ";
	str3.show();
	myString xx = str1.mystrCat(str2.getStr());
	cout << "ƴ����ʾ��   ";
	xx.show();
	cout << "��ת��ʾ��   ";
	str1.revel();
	str1.show();
	int n=str1.size();

	cout << "���ȣ�      ";
	cout << n << endl;
	cout << "��С�Ƚ�:   ";
	int m = str1.compare(str2);
	cout << m << endl;
	return 0;
}