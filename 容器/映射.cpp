#include <iostream>
#include <map>
#include <string>
using namespace std;

class MM
{
public:
	MM(int id, string name) :id(id), name(name){}
	friend ostream&operator<<(ostream& out,MM mm)
	{
		out << mm.id << "\t" << mm.name << endl;
		return out;
	}
protected:
	int id;
	string name;
};

int main()
{
	//数对类型pair
	//对应关系
	//y:键  x:值  数组： 数组下标对应元素
	pair<int, string> p(1,"wqn");
	pair<int, string > x = pair<int ,string>(2,"xxx");//make_pair<int ,string>(2,"xxx")
	cout << x.first << "\t" << x.second << endl;
	cout << endl;
	//单映射
	//单映射是存放数对类型
	//存在一样的键值时，保存第一次的
	map<int, string> myMap;
	//数组方式
	myMap[1] = "xxxx";
	myMap[-2] = "ssss";
	//函数方式
	myMap.insert(pair<int, string>(1, "ssws"));
	for (map<int, string>::iterator i = myMap.begin(); i != myMap.end(); i++)
	{
		cout << i->first<<"\t"<<i->second <<endl;
	}
	cout << endl;
	//多映射
	//多重映射: 允许任何复杂关系可都可以存在
	//自带排序不能使用下标法操作
	multimap<string, MM>  gril;
	gril.insert(pair<string, MM>("ttt", MM(1, "qn")));
	gril.insert(pair<string ,MM>("sss",MM(2,"nn")));
	for (multimap<string, MM>::iterator i = gril.begin(); i != gril.end(); i++)
	{
		cout << i->first << "\t" << i->second << endl;
	}
	system("pause");
	return 0;
}