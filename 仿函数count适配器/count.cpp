#include <iostream>
#include <vector>
using namespace std;

void my_count(const vector<int>::iterator first, const vector<int>::iterator last, int&& val)
{
	vector<int>::iterator it;
	int cnt = 0;
	for (it = first; it != last; it++)
	{
		if (*it > val)
		{
			cnt++;
			cout << *it << endl;
		}
	}
	cout << "number:" << cnt << endl;
}
using pFun = bool(*)(int, int);
void my_count2(const vector<int>::iterator first, const vector<int>::iterator last, pFun cmp, int&& val)
{
	vector<int>::iterator it;
	int cnt = 0;
	for (it = first; it != last; it++)
	{
		if (cmp(*it,val))
		{
			cnt++;
			cout << *it << endl;
		}
	}
	cout << "number:" << cnt << endl;
}
bool equal(int a, int b)
{
	return a == b;
}
bool gT(int a, int b)
{
	return a > b;
}
bool le(int a, int b)
{
	return a < b;
}
int main()
{
	vector<int> A = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> B = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> c = { 1,2,3,4,5,6,7,8,9,10 };
	int n = 5;
	cout << "my_count:" << endl;
	my_count(A.begin(), A.end(),5);
	cout << endl;
	cout << "my_count2:" << endl;
	my_count2(B.begin(), B.end(), gT,5);
	//用lambda表达式
	cout << "my_count3:" << endl;
	my_count2(B.begin(), B.end(), [](int a, int b) {return a == b; }, 5);
	system("pause");
	return 0;
}