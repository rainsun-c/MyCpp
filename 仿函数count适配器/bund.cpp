#include <iostream>
#include <vector>
#include <algorithm>
#include<functional>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}
void show(int a, int b, int c)
{
	cout << a << "++++" << b << "++++" << c << endl;
}
int main()
{
	
	vector<int> A = { 1,2,3,4,5,6,7,8,9,10 };
	//ͳ�Ʊ�0������ĸ���
	auto x=count_if(A.begin(), A.end(), std::bind(compare,std::placeholders::_1,0));
	cout << x << endl;
	//�ı�λ��
	
	auto ss = std::bind(show, std::placeholders::_1, std::placeholders::_2, 0);
	ss(1, 2, 3);
	system("pause");
	return 0;
}