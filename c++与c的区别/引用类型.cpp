#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;
//һ���ں�����ʹ��
//��������(��ȡ����)&�Ǳ�־�������ͣ���������ָ��ķ�װ
void p( /*const */int &ooxx)//��ֹ�����Ĳ����������ڲ���һ���ڴ棩
//��Ҫ����������const,���߼��ټ�һ��&�����ǲ����Դ�����������
{
	if (ooxx)
	{
		ooxx = 666;
		cout << "�ɹ�" << endl;
	}
}
//�����ڽṹ������е�ʹ��
struct A
{
	int age;
	int& reage()
	{
		return age;
	}
};
int main()
{
	//int num = 3;
	//int &ooxx = num;//��numȡ��һ����ooxx������
	//cout << ooxx << endl;
	//cout << num << endl;
 //   //�ڶԺ����������ǿ���˵ʹ��,��ָ��һ�����Ը�ԭ����ֵ�����ǲ����Դ�������
	//p(num);//����ڰ�ʵ��ֱ�ӷ���
	//cout << num << endl;
	A a = {5};
	cout << a.age << endl;
	a.reage() = 7;//����ֵage���൱�ڸ�ageȡ��һ��reage������
	cout << a.age << endl;

	while (1);
	return 0;
}