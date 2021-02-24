#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Point
{
public:
	Point(int x = 0, int y = 0) :x(x), y(y) {}
	//��͵�ĳ���
	double len( Point point1)
	{
		return sqrt((point1.x - this->x) * (point1.x - this->x) + (point1.y - this->y) * (point1.y + this->y));
	}
protected:
	int x;
	int y;
};

class Circle:public Point
{
public:
	Circle(int x=0, int y=0, int r=0) :r(r), Point(x, y) {}
	friend istream& operator>>(istream& in, Circle& a)
	{
		cout << "����������Ͱ뾶" << endl;
		in >> a.x >>a.y >> a.r;
		return in;
	}
	friend ostream& operator<<(ostream& out, Circle a)
	{
		out<< "����Ϊ����"<<a.x << "," <<a.y <<")"<<"�뾶Ϊ��"<< a.r;
		return out;
	}
	//�ж��Ƿ��ཻ
	void judge(Circle a)
	{
		if (len(a) < (a.r + this->r))
		{
			cout << "�ཻ" << endl;
		}
		else if (len(a) == (a.r + this->r))
		{
			cout << "��ͬһԲ��" << endl;
		}
		else if (len(a) < (a.r + this->r))
		{
			cout << "���ཻ" << endl;
		}
	}
protected:
	int r;
};

int main()
{
	Circle one;
	cin >> one;

	Circle two;
	cin >> two;

	one.judge(two);
	
	system("pause");
	return 0;
}