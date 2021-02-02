#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int* p = nullptr;//NULL=nullptr;
	//对于动态内存分配malloc free等变成了new delete
	p = new int(6);//开辟一个int大小的空间,用（）可以初始化
	int* p1 = new int[3]{1, 2, 3};//开辟一个int[3]的数组，用{}可以初始化
		//对于c++来说可以对已经分配好的空间，进行再分配(类型要一致)
	int* ptr = new int[66];
	int* t = new (ptr) int[5];//再ptr上分配int[5]大小给t
	int* r = new(t + 5)int;//再t的后面分配一个char，因为前面20个已经分好了，所以只能从后面开始
	delete[66]ptr;//释放空间
	while (1);
	return 0;
}