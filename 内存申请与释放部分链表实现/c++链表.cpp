#include<iostream>
#include <string>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	//���캯��
	Node(int data, Node*next);
	Node(int data);
};
Node::Node(int data)
{
	this->data = data;
	this->next = nullptr;
}
Node::Node(int data, struct Node* next)
{
	this->data = data;
	this->next = next;
}
struct List
{
	int size;
	Node*list;
	List()
	{
		this->list = nullptr;
		this->size = 0;
	}
	void insertFront( int data);
	void print();
};

void List::insertFront( int data)
{
	this->list = new Node(data,list);
	this->size++;
}
void List::print()
{
	Node* pMove = list;//Ҫ���޲ι��캯��û�г�ʼ�����ᱨ��û��ָ��nullptr�ĵط�
	while (pMove!=nullptr)
	{
		cout << pMove->data << "\t";
		pMove = pMove->next;
	}
}
int main()
{
	List* list = new List;
	list->insertFront(1);
	list->insertFront(7);
	list->insertFront(4);
	list->insertFront(3);
	list->insertFront(998);
	list->insertFront(3);
	list->print();
	system("pause");
	return 0;
}