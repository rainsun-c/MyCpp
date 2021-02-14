#include <set>
#include <iostream>
#include <string>
using namespace std;
/*
		插入:
		insert
		遍历:
		iterator
*/

int main()
{
	//1.集合--->值域
	//1.1 不会出现重复的数据
	//1.2 自带排序: 从小到大
	//去重加上排序   QQ游戏 同一个ip是不能进入同一个游戏厅
	set<int> str;
	for (int i = 0; i < 4; i++)
	{
		str.insert(i);
	}
	str.insert(3);
	set<int>::iterator iter;
	for (iter = str.begin(); iter != str.end(); iter++)
	{
		cout << *iter<<"\t";
	}
	cout << endl;
	//2.多重集合
	//只带排序功能
	multiset<int> xx;
	for (int i = 0; i < 5; i++)
	{
		xx.insert(i);
	}
	xx.insert(3);
	multiset<int>::iterator i;
	for (i = xx.begin(); i != xx.end(); i++)
	{
		cout << *i;
	}
	cout << endl;
	system("pause");
	return 0;
}