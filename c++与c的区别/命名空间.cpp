#include <iostream>
#include <cstdio>   //#include <stdio.h>����
#include <cstdlib>
#include <ctime>		//C++98 11 14 17 20�汾
#include <string>
//ͷ�ļ���C���Բ�ͬȥ����.h,Ҫʹ��C����ͷ�ļ�ʱ��Ҫ��ǰ��Ӹ�c ,��#include <  c stdlib>
//�����������޶���
using namespace std; //���������ռ䣺����ʹ2��һ�������֣�����ͬ�������»�������

namespace ѧ��       //ʹ��::������
{
	int id=2;
}
namespace gril
{
	int id;
}
struct x
{
	int id;
}X;
//�����ռ��Ƕ��
namespace A  
{
	int id = 4;
	namespace B
	{
		int b = 2;
	}
}
int main()
{
#if 0
	//��Ҫ��Ӷ������һ��������using namespace �﷨�ᵼ��ϵͳ�ֱ治���
	using namespace ѧ��;//����ʡ��ѧ��::
	printf("%d\n",id);

	gril::id = 9;
	printf("%d\n",gril::id);

	X.id = 9;
	printf("%d\n", X.id);
#endif
	//Ƕ��ʹ��

	printf("%d  %d\n",A::id,A::B::b);//����Ƕ��д��
	using namespace A;//����ʡ��ѧ��::    
	using namespace A::B;//ʡ��ѧ��::
	


	cin >> id >> b;//cin���������Ӽ��̶�ȡ��Ҫ�����ݣ��Կո�tab������Ϊ�ָ���
	cout << id << endl;
	cout << id << "c++"<< b << endl;

	printf("%d\n", id);
	printf("%d\n", b);

	while (1);
	return 0;
}