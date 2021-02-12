#include <iostream>
#include <string>
#include  <fstream>
using namespace std;

struct A
{
	int id;
	string name;
};

int main()
{
	fstream fil;
	fil.open("1.txt", ios::out | ios::in | ios::trunc);
	if (!fil || !fil.is_open())//运算符重载：!file 与 成员函数
	{
		cout << "失败" << endl;
	}
	string ss("好的豪华车");
	fil << ss << endl;
	fil.seekg(0,ios::beg);
	string s;
	fil >> s;
	cout << s << endl;
	fil.close();
	A a[3] = { { 1, "ss" }, { 2,"xx" }, { 3, "ddd" } };  //A是一个类时不行，A为结构体时可以
	fstream F;
	F.open("2.txt", ios::trunc | ios::in | ios::out);
	if (!F || !F.is_open())
	{
		cerr << "失败";
	}
	F.write((char*)a,sizeof(A)*3);
	F.seekg(0,ios::beg);
	A b[3];
	F.read((char*)b, sizeof(A)* 3);	
	for (int i = 0; i < 3; i++)
	{
		cout << b[i].id <<" "<<b[i].name << endl;
	}
	F.close();
	while (1);
	return 0;
}