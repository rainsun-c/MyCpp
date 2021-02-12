#include <iostream>
#include <string>
#include  <iomanip>
using namespace std;
int main()
{
	//便于让人区分是因为什么输出
	//string ss ;
	//string s;
	//cin >> ss;//标准输入输出
	//cout << ss << endl;
	//cerr << "dd" << endl;//处理标准出错信息，提供不带缓冲区的输出;
	//clog << "ee" << endl;//处理标准出错信息，提供带缓冲区的输出;
	cout << setiosflags(ios::right) << setw(4)<< 876<< endl;
	cout << setiosflags(ios::left) << setw(4) << 66 << endl;
	cout << hex << 344 << endl;
	cout << oct << 22 << endl;
	cout << dec << 0x333 << endl;

	system("pause");
	return 0; 
}