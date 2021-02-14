#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
		push
		pop
		empty
		size
		top: »ñÈ¡Õ»¶¥ÔªËØ
*/
int main()
{
	stack<string> myStack;
	myStack.push("vector");
	myStack.push("stack");
	myStack.push("list");
	while (!myStack.empty())
	{
		cout<<myStack.top()<<endl;
		myStack.pop();
	}
	stack<int> ejz;
	int num = 5;
	while (num)
	{
		ejz.push(num % 2) ;
		num = num / 2;
	}
	while (!ejz.empty())
	{
		cout << ejz.top() << "\t";
		ejz.pop();
	}
	system("pause");
	return 0;
}