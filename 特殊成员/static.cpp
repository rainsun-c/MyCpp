#include <iostream>
#include <string>
using namespace std;

class stu
{
public:
	stu()
	{
		name="nn";
	}
	static int A()
	{
		id = 666;
		return id;
	}
	int& getId()
	{
		A();
		id = 7;
		return id;
	}
protected:
	static int id;
	string name;
};
//���������������ʼ�����ڹ��캯����Ҳ���У�
int stu::id=1;
int main()
{
	stu s;
	cout <<s.getId()<< endl;

	
	cout << s.A << endl;		//�Զ������
	cout << stu::A << endl;		//�������޶�����
	system("pause");
	return 0;
}