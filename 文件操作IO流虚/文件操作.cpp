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
	if (!fil || !fil.is_open())//��������أ�!file �� ��Ա����
	{
		cout << "ʧ��" << endl;
	}
	string ss("�õĺ�����");
	fil << ss << endl;
	fil.seekg(0,ios::beg);
	string s;
	fil >> s;
	cout << s << endl;
	fil.close();
	A a[3] = { { 1, "ss" }, { 2,"xx" }, { 3, "ddd" } };  //A��һ����ʱ���У�AΪ�ṹ��ʱ����
	fstream F;
	F.open("2.txt", ios::trunc | ios::in | ios::out);
	if (!F || !F.is_open())
	{
		cerr << "ʧ��";
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