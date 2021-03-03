#include<iostream>
#include <string>
using namespace std;

class A
{
public:
	A(int id = 0,string name=" ") :id(id),name(name) {}
	void show()
	{
		cout << id << "  " << name << endl;
	}
	friend ostream& operator<<(ostream& out, A a)
	{
		out << a.id << " " << a.name << endl;
		return out;
	}
	friend istream& operator>>(istream& in, A& b)
	{
		in >> b.id >> b.name;
		return in;
	}

private:
	int id;
	string name;
};



int main()
{
	A b;
	cout << "ÇëÊäÈëb " << endl;
	cin >> b;
	cout << "Êä³öb  " << endl;
	cout << b;
	cout << "---------"<<endl;

	system("pause");
	return 0;
}