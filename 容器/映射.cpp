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
	//��������pair
	//��Ӧ��ϵ
	//y:��  x:ֵ  ���飺 �����±��ӦԪ��
	pair<int, string> p(1,"wqn");
	pair<int, string > x = pair<int ,string>(2,"xxx");//make_pair<int ,string>(2,"xxx")
	cout << x.first << "\t" << x.second << endl;
	cout << endl;
	//��ӳ��
	//��ӳ���Ǵ����������
	//����һ���ļ�ֵʱ�������һ�ε�
	map<int, string> myMap;
	//���鷽ʽ
	myMap[1] = "xxxx";
	myMap[-2] = "ssss";
	//������ʽ
	myMap.insert(pair<int, string>(1, "ssws"));
	for (map<int, string>::iterator i = myMap.begin(); i != myMap.end(); i++)
	{
		cout << i->first<<"\t"<<i->second <<endl;
	}
	cout << endl;
	//��ӳ��
	//����ӳ��: �����κθ��ӹ�ϵ�ɶ����Դ���
	//�Դ�������ʹ���±귨����
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