#include <iostream>
#include <string>
using namespace std;
//ֻ��ʹ�ó�ʼ�������б�


class stu
{
public:
	stu():id(2)
	{
		name = "nn";
	}
	int A()const
	{
		cout << "��̬����" << endl;
	}
	//�ȼ� const  stu* const this  = const this->show()
	void show() const//���Ե��õ��ǲ��ܸ�
	{
		
		cout << name << "��ͨ����" << endl;
	}
	int getId()
	{
		
		cout << id;
		return id;
	}

protected:
	const int id;
	string name;
};

//const���� ֻ�ܵ���const
int main()
{
	stu s;
	s.getId();
	const stu c;
	c.show();
	while (1);
	return 0;
}