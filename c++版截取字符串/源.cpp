#include<iostream>
#include<string>

using namespace std;

string str("632242946----chendaxue592256 \
462084800----13923917670 \
315984797----yu19880726. \
492942626----190186 \
495585175----ut36940258 \
492527893----13092446031 \
409966941----mo19841006 \
648483611----woan.kang \
497786869----wodeziyou \
847254279----198602240224 ");
struct Info
{
	long long QQ;
	string passwd;
};
struct Infos
{
	struct Info* base;
	int size;
}infos;
int getDataNum(string str);
void initInfos();
void splitStr(string str);
void showInfos();

//获取以"----"分隔的字符串数量
int getDataNum(string str)
{
	int cnt = -1;
	for (size_t i = 0; i != str.npos; i = str.find("----", i + 1))
	{
		cnt++;
	}
	return cnt;
}

void initInfos()
{
	infos.size = getDataNum(str);
	infos.base = new Info[infos.size];
}
void showInfos()
{
	cout << "QQ\t\t密码" << endl;;
	for (int i = 0; i < infos.size; i++)
	{
		cout << infos.base[i].QQ << "\t\t" << infos.base[i].passwd << endl;
	}
}

void splitStr(string str)
{
	//把所有空格都替换成'\0'
	for (size_t i = 0; i != str.npos; i = str.find(' ', i + 1))
	{
		str[i] = '\0';
	}

	int index = 0;
	for (size_t pos = 0; pos != str.npos; pos = str.find('\0', pos + 1))
	{
		string subStr(str.data() + pos + 1);	//取出子串
		size_t npos = subStr.find("----");      //分解子串
		sscanf(subStr.data(), "%lld", &infos.base[index].QQ);
		//存入结构体数组
		if (npos != str.npos)//判断是否可以截取到后面
		{
			infos.base[index].passwd = (subStr.data() + npos + 4);
		}
		//strcpy(infos.base[index].passwd, subStr.data()+nsub+4);
		index++;
	}
}

int main()
{

	initInfos();
	splitStr(str);
	showInfos();

	system("pause");
	return 0;
}