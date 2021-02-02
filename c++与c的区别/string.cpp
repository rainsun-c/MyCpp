#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string str1 = "A";//string类型赋值是常量和变量都可以
	string str2 = str1;
	str1 = "a";
	cout << str1 << '\n' << str2 << endl;
	int r = (str1 < str2);//只要0,1
	cout << r<< endl;
	while (1);
	return 0;
}