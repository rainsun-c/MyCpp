#include <iostream>
#include <list>//˫������
#include <string>
using namespace std;
/*ush_back();	β��
	push_front();	ͷ��
	pop_back();		βɾ
	pop_front();	ͷɾ
	back();			��ȡβԪ��
	front();		��ȡͷԪ��
	size();			��ȡ��С
	empty();		�ж��Ƿ�Ϊ��
*/


int main()
{
	list<int> ist;
	for (int i = 0; i < 3; i++)
	{
		ist.push_back(i);
	}
	//��ӡ
	list<int>::iterator iter;
	for (iter=ist.begin(); iter != ist.end(); iter++)
	{
		cout << *iter << "\t";
	}
	cout << endl;
	cout << ist.size() << endl;
	if (!ist.empty())
	{
		cout << " �� Ϊ �� " << endl;
	}
	system("pause");
	return 0;
}