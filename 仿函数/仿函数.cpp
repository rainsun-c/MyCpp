
#include <iostream>
#include <functional>	//greater less
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct MM
{
	int id;
	string name;
	bool operator<(MM object) const
	{
		return this->id < object.id;
	}
	bool operator>(MM object)
	{
		return this->id > object.id;
	}
};
ostream& operator<<(ostream&out,MM object)
{
	out << object.id << "\t" << object.name << endl;
	return out;
}

class GG
{
public:
	GG(int id = 0, string name = " ") :id(id), name(name) {}
	friend ostream& operator<<(ostream& out, GG object)
	{
		out << object.id << "\t" << object.name << endl;
		return out;
	}
	bool operator<(GG object)const
	{
		return this->id < object.id;
	}
	bool operator>(GG object) 
	{
		return this->id > object.id;
	}
protected:
	int id;
	string name;
};

template <class type>
void print(type data)
{
	cout<< data<<;
}

bool myalg(MM object1, MM object2)
{
	return object1.id > object2.id;
}

template <class type>
class mySort
{
public:
	bool operator()(type object1, type object2)
	{
		return object1 < object2;//排序与重载方式有关
	}
protected:
};
int main()
{
	MM mm[5] = { 1,"qn",3,"ds",8,"sadd",89,"sad",32,"aweeqw" };
	sort(mm, mm + 5);//默认为小到大
	for_each(mm, mm + 5, print<MM>);
	cout << endl;
	cout <<"写函数排序"<< endl;
	sort(mm, mm + 5, myalg);
	for_each(mm,mm+5,print<MM>);
	cout << endl;
	cout <<"自己写的仿函数 "<<endl;
	sort(mm, mm + 5, mySort<MM>());
	for_each(mm, mm + 5, print<MM>);

	cout << "GGGGGGGG" <<endl;
	GG gg[5] = { GG(1,"qwe"),GG(3,"ngh") ,GG(8,"ascwe") ,GG(22,"qwqe") ,GG(2,"ghje") };
	sort(gg, gg + 5, mySort<GG>());
	for_each(gg, gg + 5, print<GG>);

	cout << "向量" << endl;
	vector<int> arry;
	arry.push_back(4);
	arry.push_back(2);
	arry.push_back(6);
	arry.push_back(8);
	arry.push_back(1);

	sort(arry.begin(),arry.end(),mySort<int>());
	for_each(arry.begin(), arry.end(), print<int>);

	system("pause");
	return 0;
}