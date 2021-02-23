#include <iostream>
#include <string>
//域运算符：：
using namespace std;
//在Struct中默认公有
namespace A	
{
	struct Gril
	{
		Gril(int num = 12, string name = " xxx") :num(num), name(name) {}
		int num;
		string name;
		void show()
		{
			cout << this->name << "  " << this->num << endl;
		}
		void show(int num);

	};

	void Gril::show(int num)
	{
		cout << num << endl;
	}
}
//在class中默认私有
namespace B		
{
	class Gril
	{
	public:
		Gril(int num = 12, string name = " xxx") :num(num), name(name) {}
		
		void show()
		{
			cout << this->name << "  " << this->num << endl;
		}
		void show(int num);

		Gril& Getgril(Gril mm)
		{
			this->name = mm.name;
			this->num = mm.num;
			return (*this);
		}
		friend ostream& operator<<(ostream& out, Gril mm)
		{
			out << mm.name << "  " << mm.num << endl;
			return out;
		}
		Gril& operator+(Gril mm)
		{
			this->name=this->name + mm.name;
			this->num = this->num + mm.num;
			return (*this);
		}
		int& getNum()
		{
			return num;
		}
	protected:
		int num;
		string name;

	};

	void Gril::show(int num)
	{
		cout << num << endl;
	}
}

int main()
{
	B::Gril gril(23,"ssss");
	gril.show();
	gril.show(5);

	B::Gril s[3] = { B::Gril(1,"qw"),B::Gril(1,"qw") ,B::Gril(1,"qw") };
	B::Gril* a = new B::Gril[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = B::Gril(23, "ds");
	}
	B::Gril c(111111,"sadasd");
	B::Gril vv;
	vv.Getgril(c);
	cout << endl;
	//vv.show();
	cout << vv;
	c=vv + s[1];
	cout << "     ---------------------    "<<endl;
	cout << c;
	cout << "     ---------------------    " << endl;
	gril.getNum() = 99999;
	cout << gril;	
	system("pause");
	return 0;
}