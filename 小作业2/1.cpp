#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Point
{
public:
	Point(int x = 0, int y = 0) :x(x), y(y) {}
	//点和点的长度
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
		cout << "请输入坐标和半径" << endl;
		in >> a.x >>a.y >> a.r;
		return in;
	}
	friend ostream& operator<<(ostream& out, Circle a)
	{
		out<< "坐标为：（"<<a.x << "," <<a.y <<")"<<"半径为："<< a.r;
		return out;
	}
	//判断是否相交
	void judge(Circle a)
	{
		if (len(a) < (a.r + this->r))
		{
			cout << "相交" << endl;
		}
		else if (len(a) == (a.r + this->r))
		{
			cout << "在同一圆心" << endl;
		}
		else if (len(a) < (a.r + this->r))
		{
			cout << "不相交" << endl;
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