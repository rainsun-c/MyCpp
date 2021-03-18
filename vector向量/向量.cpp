#include<iostream>
#include <exception>
using namespace std;
class Out_Range : public exception
{
public:
	explicit Out_Range(const string& _Message) : exception(_Message.c_str()) {}
	explicit Out_Range(const char* _Message) : exception(_Message) {}
};


template<typename Data>
struct Vector
{
	Vector(int capacity) :_capacity(capacity), _size(0), _base(nullptr)
	{
		if (_capacity == 0)
			_capacity = 1;
		_base = new Data[_capacity]{ Data() };//Data()匿名对象，调用默认构造函数
	}
	//拷贝构造
	Vector(const Vector& a)
	{
		this->_size =a._size ;
		this->_capacity= a._capacity ;
		this->_base = new Data[a._capacity];
		memcpy(_base,a._base, sizeof(Data) * a._capacity);
	}
	//重载[]
	Data& operator[](int index)
	{
		return _base[index];
	}
	//插入数据
	void insert(int x)
	{
		if (_size >= _capacity)
		{
			bool x = krong();
			if (x != true)
			{
				throw Out_Range("扩容失败");
			}
		}
		_base[_size++] = x;
	}
	//交换数据
	void echange(Vector& a)
	{
		Vector A(*this);
		this->_capacity = a._capacity ;
		this->_size = a._size;
		this->_base = new Data[this->_capacity]{ 0 };
		memcpy(_base , a._base , sizeof(Data) * this->_capacity);

		a._capacity = A._capacity;
		a._size = A._size;
		a._base = new Data[a._capacity]{ 0 };
		memcpy( a._base, A._base ,sizeof(Data) * A._capacity);
	}
	//扩容
	bool krong()
	{
		Data* temp = _base;
		_base = new Data[_capacity + 5]{0};
		_capacity = _capacity + 5;
		memcpy(_base, temp, sizeof(Data) * _capacity);
		delete[]temp;
		temp = nullptr;
		return true;
	}
	//transform()函数
	using pf = void(*)( Data*);
	void transform(pf f)
	{
		for (int i = 0; i < _size; i++)
		{
			f(_base+i);
		}
	}
protected:
	Data* _base;
	int _size;
	int _capacity;
};
template<class Data>
void print(Data* p)
{
	cout << *p << endl;
}
int main()
{
	Vector<int> v(5);
	for (int i = 0; i < 10; i++)
	{
		v.insert(i+4);
	}
	//Vector<int> a(v);
	//cout << "----------------" << endl;
	//a.transform(print);
	//cout <<"----------------"<<endl;
	Vector<int> s(6);
	for (int i = 0; i < 6; i++)
	{
		s.insert(i);
	}
	v.echange(s);
	v.transform(print);
	cout << "----------------" << endl;
	s.transform(print);
	cout << "----------------" << endl;
	while (1);
	return 0;
}
