#include<string>
#include <iostream>
#include<graphics.h>
using namespace std;

//������
class Window
{
	typedef int EW_WINDOWMODE ;					//���ڱ��
public:
	Window(int w, int h, EW_WINDOWMODE flag = 0) :_width(w), _height(h)
	{
		initgraph(w, h, flag);
	}
	~Window()
	{
		closegraph();
	}
public:
	void setWindowTitle(const char * title)
	{
		SetWindowText(GetHWnd(), title);
	}
	static int getW()
	{
		return getwidth();
	}
	static int getH()
	{
		return getheight();
	}
private:
	int _width;
	int _height;
};
//������
class Point
{
public:
	Point() {};
	Point(int x, int y) :x(x), y(y) {};
	int x;
	int y;

	static Point ZERO;
};
Point Point::ZERO = Point(0, 0);
//������
class Paint
{
public:
	static void drawRect(const Point& p, int w, int h, COLORREF color = getfillcolor())
	{
		setfillcolor(color);
		solidrectangle(p.x, p.y, p.x+w, p.y+h);
	}
	static void drawLine(const Point& p1, const Point& p2, COLORREF color = getlinecolor(),int lineSize = 1)
	{
		setlinestyle(PS_COSMETIC, lineSize);
		setlinecolor(color);
		line(p1.x, p1.y, p2.x, p2.y);
	}
	static void drawText(int x, int y, const char* text,COLORREF color = gettextcolor(),int textSize = 26)
	{
		setbkmode(TRANSPARENT);
		settextcolor(color);
		settextstyle(textSize, 0,"����");
		outtextxy(x, y, text);
	}
	static void drawText(int x, int y, int text, COLORREF color = gettextcolor(), int textSize = 26)
	{
		char lineSizeStr[10] = "";
		sprintf_s(lineSizeStr, "%d", text);
		Paint::drawText(x, y, lineSizeStr, color, textSize);
	}
	static void drawCircle(const Point& p,int w,int h, COLORREF color = getfillcolor())
	{
		setfillcolor(color);
		solidellipse(p.x, p.y, p.x + w, p.y + h);
	}
};
//���пռ�Ļ���
class Tools
{
public:
	Tools() {};
	Tools(int x, int y, int w, int h)
		:leftTop(x, y), width(w), height(h)
	{
	}
	//����Ƿ��ڿؼ���
	bool isIn(const Point& p)
	{
		if (p.x >= leftTop.x && p.x <= leftTop.x + width &&
			p.y >= leftTop.y && p.y <= leftTop.y + height)
		{
			return true;
		}
		return false;
	}

	Point leftTop;
	int width;
	int height;
};
//������
class Canvas :public Tools
{
public:
	Canvas() {}
	Canvas(int x, int y, int w, int h) 
		:Tools(x, y, w, h),color(BLACK),lineSize(1)
	{
		this->isDown = false;
		this->begPos = Point(0, 0);
	}
	bool ProcessMsg(MOUSEMSG& msg)
	{
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (isIn(Point(msg.x,msg.y)))
			{
				isDown = true;
				begPos = Point(msg.x, msg.y);
			}
			break;
		case WM_LBUTTONUP:
			isDown = false;
			break;
		case WM_MOUSEWHEEL:						//���ֵ��������С
			lineSize = msg.wheel > 0 ? lineSize + 1 : lineSize - 1;
			if (lineSize <= 0)
			{
				lineSize = 1;
			}
			break;
		case WM_MOUSEMOVE:						//����
			if (isDown)
			{
				if (isIn(begPos) && isIn(Point(msg.x, msg.y)))		// ��ʼ��ͽ����㶼��������
				{
					Paint::drawLine(begPos, Point(msg.x, msg.y), color, lineSize);
				}
				begPos = Point(msg.x, msg.y);
			}
			break;
		case WM_RBUTTONDOWN:					//����
			Paint::drawRect(Point::ZERO, Window::getW()-100, Window::getH(), WHITE);				//��ͼ����
			break;
		}
		return false;
	}
public:
	int getLineSize()
	{
		return lineSize;
	}
	void setColor(COLORREF color)
	{
		this->color = color;
	}
private:
	int lineSize;	//�������
	COLORREF color;	//������ɫ

	bool isDown;	//����Ƿ���
	Point begPos;	//��¼��һ���������
};
class Button:public Tools
{	
public:
	enum ButtonStyle { CIRCLE, RECT };
	Button():style(ButtonStyle::CIRCLE) {}
	Button(int x, int y, int w, int h, ButtonStyle style = ButtonStyle::CIRCLE)
		:Tools(x, y, w, h), style(style)
	{
		isClick = false;
	}
	bool ProcessMsg(MOUSEMSG& msg, Canvas& canvas)
	{
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (isIn(Point(msg.x,msg.y)))
			{
				printf("leftTop(%d,%d)  %#X \n",leftTop.x,leftTop.y, color);
				canvas.setColor(color);
				isClick = true;
			}
			break;
		case WM_LBUTTONUP:
			isClick = false;
			break;
		}
		if (style == ButtonStyle::CIRCLE)
		{
			Paint::drawCircle(leftTop, width, height, color);
		}
		else if (style == ButtonStyle::RECT)
		{
			Paint::drawRect(leftTop, width, height, color);
		}
		
		return false;
	}
public:
	void setPos(const Point&p)
	{
		this->leftTop = p;
	}
	void setSize(int w,int h)
	{
		this->width = w;
		this->height = h;
	}
	void setColor(COLORREF color)
	{
		this->color = color;
	}
	void setStyle(ButtonStyle style)
	{
		this->style = style;
	}
private:
	bool isClick;	//��ť�Ƿ񱻵��
	COLORREF color;	//��ť��ɫ
	ButtonStyle style;	//��ť��ʽ
};


int main()
{
	/*HWND hWnd = GetHWnd();
	if (IDOK == MessageBox(hWnd, "�Ƿ����", "��ʾ", MB_OKCANCEL))*/
	{
		Window w(1100, 768);
		w.setWindowTitle("��ͼ��");
		Paint::drawRect(Point::ZERO, w.getW(), w.getH(), WHITE);				//��ͼ����
		Paint::drawRect(Point(w.getW() - 100, 0), w.getW(), w.getH(), 0xEFEFEF);	//������
		Canvas canvas(0, 0, w.getW() - 100, w.getH());

		//��ɫ��ť
		Button btns[9];
		for (int i = 0; i < 9; i++)
		{
			btns[i].setSize(50, 50);
			btns[i].setPos(Point(Window::getW() - 100 + 26, 50 + i * 60));
			btns[i].setColor(RGB(rand() % 256, rand() % 256, rand() % 256));
			//btns[i].setStyle(Button::RECT);
		}


		BeginBatchDraw();
		while (true)
		{
			MOUSEMSG msg = GetMouseMsg();
			canvas.ProcessMsg(msg);

			Paint::drawRect(Point(1000,10), 50, 20, RED);
			
			Paint::drawRect(Point(1050, 700), 50, 50, 0xEFEFEF);
			Paint::drawText(1000, 700, "�����С:", BLACK, 15);
			Paint::drawText(1080, 700, canvas.getLineSize(), BLACK, 15);
			for (int i = 0; i < 9; i++)
			{
				btns[i].ProcessMsg(msg, canvas);
			}
			FlushBatchDraw();
		}
	}

	return 0;
}