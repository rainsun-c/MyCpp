#include <iostream>
#include <string>
using namespace std;
/*
	关键词:template <typename 类型名字>  typename也可以为class
*/
template<class type>
type Max(type a, type b)
{
	return a > b ? a : b;
}
template<typename type1,typename type2>
void XXXX(type1 a, type2 b)
{
	if (a > b)
	{
		cout << a << endl;
	}
	else
	{
		cout << b << endl;
	}
}
class MM
{
public:
	MM(string name) :name(name){}
	string& getname()
	{
		return name;
	}
protected:
	string name;
};

template <class type1>
class Mm
{
public:
	Mm(type1 str, int x=0) :str(str), x(x){}
	friend ostream& operator<< (ostream&in, Mm<type1>er)
	{
		in << er.x << "   " << er.str << endl;
		return in;
	}
protected:
	type1 str;
	int x;
};
int main()
{
	//MM mm("xss");
	//string x = mm.getname();
	//XXXX<string,string>(x,"ssxc");
	Mm<string> xmm("wenqn", 66);
	cout << xmm;

	system("pause");
	return 0;
}
