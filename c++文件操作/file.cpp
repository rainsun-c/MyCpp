#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
----------------------------------
	ifstream��: ���ļ�  ֻ��һ��
	ofstream��: д�ļ�
	ר��ר��
-----------------------------------
	fstream ȥ�����ļ�
		fstream file;
	1.���ļ�
		file.open(char* fileURL,int mode);
		mode:
			ios::in ��
			ios::out д	���д������Դ�ļ��Ĺ���
			ios::app ׷��ģʽ  �����д�������
			ios::trunc: �����Ѿ����ڵ��ļ�
			ios::binary  ������д��
			ios::ate  �򿪺󣬳�ʼλ�����ļ�β
		��Ϸ�ʽ  |
			ios::in|ios::out

		�ж��ļ��Ƿ��: !file ||!file.is_open
	2.��д�ļ�
		2.1 ���ķ�ʽ����д
		2.2 ��Ա�����ķ�ʽ����д  �ֽ���
		write(Դ��ַ,��С) ����
		read(Դ��ַ,��С) ����
	3.�ر��ļ�
		file.close();
	4.�ļ��ƶ�
		C����:fseek
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
		cout << "��ʧ��" << endl;
		fd.open("2.txt", ios::out | ios::in|ios::trunc);
		cout << "�����ɹ�" << endl;
	}
	const char* str2 = "������";
	fd << str2 << " " << 4 ;
	fd.seekg(0, ios::beg);	//ָ���ƶ���ȥ  һ�ֽ�ȥ��ȡ
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
		cout << "��ʧ��" << endl;
		fd.open("3.txt", ios::out | ios::in | ios::trunc);
		cout <<"�����ɹ�"<<endl;
	}
	stu s[3] = { {1,"С"},{2,"��"},{3,"��"} };
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