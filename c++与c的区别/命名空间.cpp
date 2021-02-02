#include <iostream>
#include <cstdio>   //#include <stdio.h>错误
#include <cstdlib>
#include <ctime>		//C++98 11 14 17 20版本
#include <string>
//头文件与C语言不同去掉了.h,要使用C语言头文件时需要在前面加个c ,例#include <  c stdlib>
//：：作用域限定符
using namespace std; //处理命名空间：作用使2个一样的名字，在相同作用域下互不干扰

namespace 学生       //使用::来引用
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
//命名空间的嵌套
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
	//不要添加多个含有一样变量名using namespace 语法会导致系统分辨不清楚
	using namespace 学生;//可以省略学生::
	printf("%d\n",id);

	gril::id = 9;
	printf("%d\n",gril::id);

	X.id = 9;
	printf("%d\n", X.id);
#endif
	//嵌套使用

	printf("%d  %d\n",A::id,A::B::b);//常规嵌套写法
	using namespace A;//可以省略学生::    
	using namespace A::B;//省略学生::
	


	cin >> id >> b;//cin可以连续从键盘读取想要的数据，以空格、tab或换行作为分隔符
	cout << id << endl;
	cout << id << "c++"<< b << endl;

	printf("%d\n", id);
	printf("%d\n", b);

	while (1);
	return 0;
}