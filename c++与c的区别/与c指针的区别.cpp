#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int* p = nullptr;//NULL=nullptr;
	//���ڶ�̬�ڴ����malloc free�ȱ����new delete
	p = new int(6);//����һ��int��С�Ŀռ�,�ã������Գ�ʼ��
	int* p1 = new int[3]{1, 2, 3};//����һ��int[3]�����飬��{}���Գ�ʼ��
		//����c++��˵���Զ��Ѿ�����õĿռ䣬�����ٷ���(����Ҫһ��)
	int* ptr = new int[66];
	int* t = new (ptr) int[5];//��ptr�Ϸ���int[5]��С��t
	int* r = new(t + 5)int;//��t�ĺ������һ��char����Ϊǰ��20���Ѿ��ֺ��ˣ�����ֻ�ܴӺ��濪ʼ
	delete[66]ptr;//�ͷſռ�
	while (1);
	return 0;
}