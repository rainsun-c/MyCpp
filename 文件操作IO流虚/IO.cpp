#include <iostream>
#include <string>
#include  <iomanip>
using namespace std;
int main()
{
	//����������������Ϊʲô���
	//string ss ;
	//string s;
	//cin >> ss;//��׼�������
	//cout << ss << endl;
	//cerr << "dd" << endl;//�����׼������Ϣ���ṩ���������������;
	//clog << "ee" << endl;//�����׼������Ϣ���ṩ�������������;
	cout << setiosflags(ios::right) << setw(4)<< 876<< endl;
	cout << setiosflags(ios::left) << setw(4) << 66 << endl;
	cout << hex << 344 << endl;
	cout << oct << 22 << endl;
	cout << dec << 0x333 << endl;

	system("pause");
	return 0; 
}