#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
	���ж��巶Χ��ʱ�򣬲�����push_back()����������ݺ�����
*/

class stu
{
public:
	stu(string xx, int r = 0) :ss(xx), r(r){}
	friend ostream& operator<<(ostream&out, stu mm)
	{
		out << mm.r << "\t" << mm.ss << endl;
		return out;
	}
protected:
	string ss;
	int r;
};

int main()
{
	//���õ�����
	vector<int>* arry = new vector<int>;
	for (int i = 0; i < 3; i++)
	{
		arry->push_back(i);
	}
	vector<int>::iterator i;
	for (i = arry->begin(); i != arry->end(); i++)
	{
		cout << *i << "\t";
	}
	cout << endl;

	vector<int> a;
	for (int i = 0; i < 3; i++)
	{
		a.push_back(i);
	}
	vector<int> aa;
	for (int i = 0; i < 3; i++)
	{
		aa.push_back(i);
	}
	vector<int> bbb;
	for (int i = 0; i < 3; i++)
	{
		bbb.push_back(i);
	}
	vector<int>::iterator x;
	for (x = a.begin(); x != a.end(); x++)
	{
		cout << *x << "\t";
	}
	cout << endl;
	//ȷ������ʱ
	vector<string> str(2);
	str[0] = "jingtian";
	str[1] = "mingtian"; 
	for (int i = 0; i < 2; i++)
	{
		cout << str[i] << endl;
	}
	vector<string>::iterator iter;
	for (iter=str.begin(); iter != str.end(); iter++)
	{
		cout << *iter << "\t";
	}

	cout << endl;

	//�Զ�������
	vector<stu> student;
	student.push_back(stu("xiaoh", 1));
	student.push_back(stu("sssss", 2));	
	student.push_back(stu("sswwh", 3));
	
	vector<stu>::iterator cur;
	for (cur = student.begin(); cur != student.end(); cur++)
	{
		cout << *cur << endl;
	}
	cout << "  ��   ��  " << endl;
	//��ά����
	vector<vector<int>> s;//�����Сʱ��ֻ�ܶ����С�
	s.push_back(a);
	s.push_back(aa);
	s.push_back(bbb);
	vector<vector<int>>::iterator f;
	vector<int>::iterator F;
	for (f = s.begin(); f != s.end(); f++)
	{
		cout << endl;
		for (F = (*f).begin(); F != (*f).end(); F++)
		{
			cout << *F << "\t";
		}
	}
	system("pause");
	return 0;
}