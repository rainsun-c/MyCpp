#include <set>
#include <iostream>
#include <string>
using namespace std;
/*
		����:
		insert
		����:
		iterator
*/

int main()
{
	//1.����--->ֵ��
	//1.1 ��������ظ�������
	//1.2 �Դ�����: ��С����
	//ȥ�ؼ�������   QQ��Ϸ ͬһ��ip�ǲ��ܽ���ͬһ����Ϸ��
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
	//2.���ؼ���
	//ֻ��������
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