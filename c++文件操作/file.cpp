#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
----------------------------------
	ifstream类: 读文件  只能一样
	ofstream类: 写文件
	专类专事
-----------------------------------
	fstream 去操作文件
		fstream file;
	1.打开文件
		file.open(char* fileURL,int mode);
		mode:
			ios::in 读
			ios::out 写	具有创建清空源文件的功能
			ios::app 追加模式  不具有创建功能
			ios::trunc: 覆盖已经存在的文件
			ios::binary  二进制写法
			ios::ate  打开后，初始位置在文件尾
		组合方式  |
			ios::in|ios::out

		判断文件是否打开: !file ||!file.is_open
	2.读写文件
		2.1 流的方式做读写
		2.2 成员函数的方式做读写  字节流
		write(源地址,大小) 函数
		read(源地址,大小) 函数
	3.关闭文件
		file.close();
	4.文件移动
		C语言:fseek
		seekg(size_t size,int position)
		ios::beg
		ios::end
		ios::cur
*/
struct stu
{
	int id=0;
	string name=" ";

};

int main()
{
#if 0
	fstream fd;
	fd.open("2.txt", ios::out |ios::in);
	if (!fd || !fd.is_open())
	{
		cout << "打开失败" << endl;
		fd.open("2.txt", ios::out | ios::in|ios::trunc);
		cout << "创建成功" << endl;
	}
	const char* str2 = "哈哈哈";
	fd << str2 << " " << 4 ;
	fd.seekg(0, ios::beg);	//指针移动回去  一字节去截取
	int num=0;	
	char str[20] = " ";
	fd >> str>>num;
	cout << str << num << endl;
	int n = fd.tellg();
	cout << n << endl;
#endif
	fstream fd;
	fd.open("3.txt", ios::in | ios::out);
	if (!fd)
	{
		cout << "打开失败" << endl;
		fd.open("3.txt", ios::out | ios::in | ios::trunc);
		cout <<"创建成功"<<endl;
	}
	stu s[3] = { {1,"小"},{2,"中"},{3,"大"} };
	fd.write((char*)s, sizeof(stu) * 3);

	stu t[3];
	fd.seekg(0, ios::beg);
	fd.read((char*)t, sizeof(stu) * 3);
	cout << t[1].id << "\t" << t[1].name << endl;
	cout << t[2].id << "\t" << t[2].name << endl;

	cout << t[0].id << "\t" << t[0].name << endl;

	fd.close();
	system("pause"); 
	return 0;
}