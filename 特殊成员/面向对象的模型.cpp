#include <iostream>
#include <string>
using namespace std;
//���к����;�̬������ռ�ڴ�
class stu
{
public:
	stu()
	{
		name = "nn";
	}
	static int A()
	{
		cout << "��̬����" << endl;
	}
	void show()
	{
		A();
		cout << name<<"��ͨ����" << endl;
	}
protected:
	static int id;
	string name;
};
int stu::id=66;

////������C���Է�ʽ
//struct Stu
//{
//	string name="nn";
//};
//static int id=66;
//
//void show(Stu* pthis)//this��Ϊ�˷�ֹ���޸�����void show(Stu*const pthis);����const
//{
//	cout<< pthis->name;
//}
////��Ϊ��̬������û��Stu* pthisָ�룬����û�а취ʹ����ͨ��Ա��ֻ��ʹ�þ�̬����
//static int A()
//{
//	cout << id <<endl;
//}


int main()
{
	stu s;
	/*Stu x;*/
	//c++
	s.show();
	stu::A();
	//ת��c����
	/*show(&x);
	A();*/

	system("pause");
	return 0;
}