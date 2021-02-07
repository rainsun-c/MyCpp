#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node(int data, Node*node = nullptr)
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
	void FrontNode(int data);//ͷ��
	void TailNode(int data);//β��
	void printList();//��ӡ
	void deleteFront();//ͷɾ��
	int Size();//��ߴ�
	void deleteTail();//βɾ��
	void insertNode(int data,int index);//ָ������
	void insertDelete(int index);//ָ��ɾ��
	Node* find(int index);//����ָ��Ԫ��
	void clsList();//�������
protected:
	int size;
	Node*list;
};
List::List()
{
	list = new Node(-1);
	size = 0;
}
List::~List()
{
	Node* ppMove = list->next;
	while (ppMove)
	{
		list->next = ppMove->next;
		delete ppMove;
		ppMove = nullptr;
		ppMove = list->next;
	}
	cout << "��������" << endl;
}
void List::FrontNode(int data)
{
	list->next = new Node(data, list->next);//���Ӳ���
	size++;
}

int List::Size()
{
	return this->size;
}

void List::printList()
{
	if (size == 0)
	{
		return;
	}
	Node* pMove = list->next;
	while (pMove)
	{
		cout << pMove->data << endl;
		pMove = pMove->next;
	}
}
void List::TailNode(int data)
{
	if (Size() == 0)
	{
		list->next = new Node(data, list->next);//���Ӳ���
	}
	else
	{
		Node*pMove = list->next;
		Node*ppMove = pMove->next;
		while (ppMove)
		{
			pMove = ppMove;
			ppMove = pMove->next;
		}
		pMove->next = new Node(data);
	}
	size++;
}
void List::deleteFront()
{
	if (Size() == 0)
	{
		cout << "����Ϊ�գ��޷�ɾ��" << endl;
		return;
	}
	Node* pMove = list->next;
	list->next = pMove->next;
	delete pMove;
	pMove = nullptr;
	size--;
}
void List::deleteTail()
{
	if (Size() == 0)
	{
		cout << "����Ϊ�գ��޷�ɾ��" << endl;
		return;
	}
	Node*pMove = list;
	Node*ppMove = pMove->next;
	while (ppMove->next)
	{
		pMove = ppMove;
		ppMove = pMove->next;
	}
	pMove->next = nullptr;
	delete ppMove;
	ppMove = nullptr;
	size--;
}
void List::insertNode(int data, int index)
{
	if (Size() == 0)
	{
		cout << "����Ϊ��,�޷�ָ������" << endl;
		return;
	}
	Node*pMove = list;
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
		cout << "û���ҵ�" << endl;
		return;
	}
	else
	{
		pMove->next= new Node(data, pMove->next);
		size++;
	}
}
void List::insertDelete(int index)
{
	if (Size() == 0)
	{
		cout << "����Ϊ��,�޷�ָ��ɾ��" << endl;
		return;
	}
	Node*pMove = list;
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
		cout << "û���ҵ�" << endl;
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
		cout << "����Ϊ��,�޷�ָ��ɾ��" << endl;
		return nullptr;
	}
	Node*pMove = list;
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
		cout << "û���ҵ�" << endl;
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
	{
		List* list = new List;
		list->FrontNode(2);
		list->FrontNode(5);
		list->FrontNode(4);
		list->FrontNode(7);
		list->FrontNode(3);
		list->FrontNode(1);
		list->TailNode(1111);
		list->deleteFront();
		list->deleteTail();
		list->insertNode(888, 3);
		list->insertDelete(7);
		Node* n = list->find(4);
		cout << "�ҵ��������ǣ�" << n->data << endl;
		list->clsList();
		list->printList();
		list->~List();
	}
	cout << "xxx" << endl;
	system("pause");
	return 0;
}