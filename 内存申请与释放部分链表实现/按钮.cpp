#include <iostream>
#include <string>
#include <graphics.h>
using namespace std;

class myCase
{
public:
	myCase(int x, int y,int r, COLORREF color) :x(x), y(y), r(r), color(color){}
	void setwenzi();
protected:

	int x;
	int y;
	int r;
	COLORREF color;
};
void myCase::setwenzi()
{
	setfillcolor(this->color);
	//��Բ
	fillcircle(this->x, this->y, this->r);//�б߿�������Բ
}
int main()
{
	initgraph(600,400);
	myCase* C = new myCase(250, 150, 50, YELLOW);
	while (1)
	{
			C->setwenzi();
	}

	system("pause");
	return 0;
}