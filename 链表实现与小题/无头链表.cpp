#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int data=-1, Node*node = nullptr)
	{
		this->data = data;
		this->next = node;
	}
};
class List
{
public:
	List();
	~List();
	void FrontNode(int data);
	void printList();//打印
	void TailNode(int data);//尾插
	void deleteFront();//头删除
	int Size();//求尺寸
	void deleteTail();//尾删除
	void insertNode(int data, int index);//指定插入
	void insertDelete(int index);//指定删除
	Node* find(int index);//查找指定元素
	void clsList();//清空链表
protected:
	Node* Front;
	Node* Tail;
	int size;
};
List::List()
{
	Front = Tail=new Node;
	size = 0;
}
List::~List()
{
	if (Front == Tail&&Front != nullptr)
	{
		delete Front;
		Front = nullptr;
	}
	else
	{
		Node* ppMove = Front;
		while (ppMove)
		{
			Front= ppMove->next;
			delete ppMove;
			ppMove = nullptr;
			ppMove = Front;
		}
		cout << "我是析构" << endl;
	}
}
void List::FrontNode(int data)
{	Node* newNode = new Node(data);
	if (size == 0)
	{
		Front = newNode;
		Tail = newNode;
	}
	else
	{
		newNode->next = Front;
		Front = newNode;
	}
	size++;
}
void List::printList()
{
	if (size == 0)
	{
		return;
	}
	Node* pMove = Front;
	while (pMove)
	{
		cout << pMove->data << endl;
		pMove = pMove->next;
	}
}
int List::Size()
{
	return this->size;
}
void List::TailNode(int data)
{
	Node* newNode = new Node(data);
	if (Size() == 0)
	{
		Front = newNode;
		Tail = newNode;
	}
	else
	{
		Tail->next = newNode;
		Tail = newNode;
	}
	size++;
}
void List::deleteFront()
{
	if (Size() == 0)
	{
		cout << "链表为空，无法删除" << endl;
		return;
	}
	Node* pMove = Front;
	Front = pMove->next;
	delete pMove;
	pMove = nullptr;
	size--;
}
void List::deleteTail()
{
	if (Size() == 0)
	{
		cout << "链表为空，无法删除" << endl;
		return;
	}
	Node*pMove = Front;
	Node*ppMove = pMove->next;
	while (ppMove->next)
	{
		pMove = ppMove;
		ppMove = pMove->next;
	}
	pMove->next = nullptr;
	Tail = pMove;
	delete ppMove;
	ppMove = nullptr;
	size--;
}
void List::insertNode(int data, int index)
{
	if (Size() == 0)
	{
		cout << "链表为空,无法指定插入" << endl;
		return;
	}
	Node*pMove = Front;
	Node*ppMove = pMove->next;
	while (ppMove)
	{
		if (ppMove->data == index)
		{
			break;
		}
		pMove = ppMove;
		ppMove = pMove->next;
	}
	if (ppMove == nullptr)
	{
		cout << "没有找到" << endl;
		return;
	}
	else
	{
		pMove->next = new Node(data, pMove->next);
		size++;
	}
}
void List::insertDelete(int index)
{
	if (Size() == 0)
	{
		cout << "链表为空,无法指定删除" << endl;
		return;
	}
	Node*pMove = Front;
	Node*ppMove = pMove->next;
	while (ppMove)
	{
		if (ppMove->data == index)
		{
			break;
		}
		pMove = ppMove;
		ppMove = pMove->next;
	}
	if (ppMove == nullptr)
	{
		cout << "没有找到" << endl;
		return;
	}
	else
	{
		pMove->next = ppMove->next;
		delete ppMove;
		ppMove = nullptr;
		size--;
	}
}
Node* List::find(int index)
{
	if (Size() == 0)
	{
		cout << "链表为空,无法指定删除" << endl;
		return nullptr;
	}
	Node*pMove = Front;
	Node*ppMove = pMove->next;
	while (ppMove)
	{
		if (ppMove->data == index)
		{
			break;
		}
		pMove = ppMove;
		ppMove = pMove->next;
	}
	if (ppMove == nullptr)
	{
		cout << "没有找到" << endl;
		return nullptr;
	}
	else
	{
		return ppMove;
	}
}
void List::clsList()
{

	while (size)
	{
		deleteTail();
	}
}

int main()
{
	List* list = new List;
	for (int i = 0; i < 10; i++)
	{
		list->FrontNode(i);
	}
	list->TailNode(333);
	list->deleteFront();
	list->deleteTail();
	list->insertNode(666, 7);
	list->insertDelete(5);
	list->printList();
	list->~List();
	system("pause");
	return 0;
}