#include<iostream>
#include <string>
using namespace std;

class A
{
public:
	A(int num = 0) :num(num) {}
	void show()
	{
		cout << num << endl;
	}
	//����++����+���ٸ�
	A operator++()
	{
		++this->num;
		return (*this);
	}
	//����++���ȸ�����+,��ռλ����int ��ǣ�ֻ����int��
	A operator++(int)
	{
		//����ԭ����ֵ
		A mm = *this;
		//��++
		this->num++;
		//����ԭ����ֵ
		return mm;
	}
private:
	int num;
};


int main()
{
	A a(5);
	++a;
	a.show();

	A x=a++;
	cout << "x  :";
	x.show();
	cout << "a  :";
	a.show();
	while (1);
	return 0;
}