#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
	在有定义范围的时候，不能用push_back()，这个是扩容函数。
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
	//内置迭代器
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
	//确定长度时
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

	//自定义类型
	vector<stu> student;
	student.push_back(stu("xiaoh", 1));
	student.push_back(stu("sssss", 2));	
	student.push_back(stu("sswwh", 3));
	
	vector<stu>::iterator cur;
	for (cur = student.begin(); cur != student.end(); cur++)
	{
		cout << *cur << endl;
	}
	cout << "  分   割  " << endl;
	//二维数组
	vector<vector<int>> s;//定义大小时，只能定义列。
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