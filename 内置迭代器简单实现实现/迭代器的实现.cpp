#include <iostream>
#include <string>
using namespace std;

template <class type>
class Node
{
public:
	type data;
	Node<type>* next;
	Node<type>()
	{
		this->data = 0;
		this->next = NULL;
	}
	Node<type>(type data, Node<type>*next)
	{
		this->data = data;
		this->next = next;
	}
};
//
//template <class type>
//class iterator
//{
//public:
//	friend class list;
//	Node<type>* operator=(Node<type>* Node)
//	{
//		pMove = Node;
//		return pMove;
//	}
//	bool operator!=(Node<type>* Node)
//	{
//		return this->pMove != Node;
//	}
//	Node<type>* operator++(int)
//	{
//		Node<type>* newNode = this->pMove;
//		this->pMove=this->pMove->next;
//		return newNode;
//	}
//	type operator*()
//	{
//		return pMove->data;
//	}
//protected:
//	Node<type>* pMove;
//};

template <class type>
class list
{
public:
	
	list<type>(Node<type>* front=nullptr, Node<type>* back=nullptr,int size=0 )
	{
		this->back = back;
		this->front = front;
		this->size = size;
	}
	void push_Front(int data);
	void show();
	Node<type>* begin()
	{
		return front;
	}
	Node<type>* end()
	{
		return nullptr;
	}
class iterator
	{
	public:
	
		iterator(Node<type>* pMove=nullptr)
		{
			this->pMove = pMove;
		}
		void operator=(Node<type>* Node)
		{
			 pMove = Node;
		}
		bool operator!=(Node<type>* Node)
		{
			return this->pMove != Node;
		}
		iterator operator++(int)
		{
			iterator x = *this;
			this->pMove = this->pMove->next;
			return x;
		}
		type operator*()
		{
			return pMove->data;
		}
	protected:
		Node<type>* pMove;
	};
protected:
	Node<type>* front;
	Node<type>* back;
	int size;
};
template <class type>
void list<type>::push_Front(int data)
{
	if (this->front == nullptr)
	{
		this->front = new Node<type>(data, this->front);
		this->back = this->front;
	}
	else
	{
		this->front = new Node<type>(data, this->front);
	}
	size++;
}
template<class type>
void list<type>::show()
{
	Node<type>* pMove = new Node<type>;
	pMove = this->front;
	while (pMove)
	{
		cout << pMove->data << endl;
		pMove = pMove->next;
	}
}
int main()
{
	list<int> mylist;
	for (int i = 0; i < 5; i++)
	{
		mylist.push_Front(i);
	}
	list<int>::iterator itr ;
	for (itr=mylist.begin() ; itr != mylist.end(); itr++)
	{
		cout << *itr << "\t";
	}


	system("pause");
	return 0;
}