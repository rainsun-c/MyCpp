#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string str1 = "A";//string���͸�ֵ�ǳ����ͱ���������
	string str2 = str1;
	str1 = "a";
	cout << str1 << '\n' << str2 << endl;
	int r = (str1 < str2);//ֻҪ0,1
	cout << r<< endl;
	while (1);
	return 0;
}