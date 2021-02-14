#include <iostream>
#include <list>//双向链表
#include <string>
using namespace std;
/*ush_back();	尾插
	push_front();	头插
	pop_back();		尾删
	pop_front();	头删
	back();			获取尾元素
	front();		获取头元素
	size();			获取大小
	empty();		判断是否为空
*/


int main()
{
	list<int> ist;
	for (int i = 0; i < 3; i++)
	{
		ist.push_back(i);
	}
	//打印
	list<int>::iterator iter;
	for (iter=ist.begin(); iter != ist.end(); iter++)
	{
		cout << *iter << "\t";
	}
	cout << endl;
	cout << ist.size() << endl;
	if (!ist.empty())
	{
		cout << " 不 为 空 " << endl;
	}
	system("pause");
	return 0;
}