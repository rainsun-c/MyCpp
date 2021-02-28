#include <stdio.h>



//�����
template<class T>
class treeNode
{
public:
	T			data;				//����
	treeNode* Right;				//������
	treeNode* Left;					//������
	int			hieght;				//�߶�
	treeNode(const T& data)
	{
		this->data = data;
		Right = NULL;
		Left = NULL;
		hieght = 0;
	}
};

template<class T>
class AVLTREE
{
public:
	void DeleNode(T index);
	AVLTREE(treeNode<T>* root = NULL) :root(root) {}
	void insert(const T& data);							//����
	treeNode<T>* Find(const T& index);
protected:
	treeNode<T>* LRightNode();
	int getHeight(treeNode<T>* root);					//��ȡ�߶�
	treeNode<T>* RR(treeNode<T>* root);
	treeNode<T>* LL(treeNode<T>* root);
	treeNode<T>* RL(treeNode<T>* root);
	treeNode<T>* LR(treeNode<T>* root);
	treeNode<T>* _Find(treeNode<T>* root,const T& index);
	void _insert(treeNode<T>*& root, const T& data);		//����(����)
	treeNode<T>* root;
};
template<class T>
treeNode<T>* AVLTREE<T>::LRightNode()
{
	if (root == NULL)
	{
		return NULL;
	}
	treeNode<T>* pMove = this->root->Left;
	if (pMove == NULL|| pMove->Right == NULL)
	{
		return root;
	}
	else
	{
		treeNode<T>* ppMove = pMove->Right;
		while (ppMove->Right)
		{
			pMove = ppMove;
			ppMove = pMove->Right;
		}
		//�������ҵĸ��ڵ�
		return pMove;
	}

	
}
template<class T>
void AVLTREE<T>::DeleNode(T index)
{
	treeNode<T>* deletNode = Find(index);
	if (deletNode == NULL)
	{
		printf("û���������");
		return;
	}
	else
	{
		if (deletNode->Right != NULL && deletNode->Left == NULL)
		{

		}
		else if (deletNode->Right == NULL && deletNode->Left != NULL)
		{
			
		}
		else if (deletNode->Right != NULL && deletNode->Left != NULL)
		{

		}
		else
		{
			printf("cg");
			delete deletNode;
			deletNode = NULL;
			return;
		}
	}
}
template<class T>
treeNode<T>* AVLTREE<T>::Find(const T& index)
{
	return _Find(this->root, index);
}
template<class T>
treeNode<T>* AVLTREE<T>::_Find(treeNode<T>* root, const T& index)
{
	if (root)
	{
		treeNode<T>* temp = root;
		if (temp->data == index)
		{
			return temp;
		}
		else if (temp->data > index)
		{
			_Find(root->Left, index);
		}
		else
		{
			_Find(root->Right, index);
		}
	}
	else
	{
		return NULL;
	}
}

template<class T>
void AVLTREE<T>::insert(const T& data)
{
	_insert(this->root, data);
}
template<class T>
void AVLTREE<T>::_insert(treeNode<T>*& root, const T& data)
{
	//1���������ݣ�ʹ�ö�������������
	if (root == NULL)
	{
		root = new treeNode<T>(data);
	}
	else if (root->data > data)
	{
		_insert(root->Left, data);
		//�жϲ����ıߣ���>�ң�˵���ڲ�����ߣ�
		if (getHeight(root->Left) - getHeight(root->Right) > 1)
		{
			//���������RR
			if (root->Left->data > data)//RR
			{
				root = RR(root);
			}
			//���Ҷ���LR
			else//LR
			{
				root = LR(root);
			}
		}
	}
	else
	{
		_insert(root->Right, data);
		//�жϲ����ıߣ���>��˵���ڲ����ұߣ�
		if (getHeight(root->Right) - getHeight(root->Left) > 1)
		{
			//�����ұ���LL
			if (root->Right->data < data)//RR
			{
				root = LL(root);
			}
			//���Ҷ���RL
			else
			{
				root = RL(root);
			}
		}
	}
	//2���ж��Ƿ���ת
	//3�����ø߶�
	int lh = getHeight(root->Right);
	int rh = getHeight(root->Left);

	root->hieght = 1 + ((lh > rh) ? lh : rh);
}
template<class T>
int AVLTREE<T>::getHeight(treeNode<T>* root)
{
	if (root)
	{
		return root->hieght;
	}
	else
	{
		return 0;
	}
}


template<class T>
treeNode<T>* AVLTREE<T>::RR(treeNode<T>* root)
{
	//��¼root��������
	treeNode<T>* temp = root->Left;
	//temp����������root��������
	root->Left = temp->Right;
	//��root����temp���������£�
	temp->Right = root;

	root->hieght = 1 + ((getHeight(root->Left) > getHeight(root->Right))? getHeight(root->Left) : getHeight(root->Right));
	temp->hieght = 1 + ((getHeight(temp->Left) > getHeight(temp->Right))? getHeight(temp->Left) : getHeight(temp->Right));
	return temp;

}
template<class T>
treeNode<T>* AVLTREE<T>::AVLTREE::LL(treeNode<T>* root)
{


	treeNode<T>* temp = root->Right;
	root->Right = temp->Left;
	temp->Left = root;
	//��ת��ʱ�򣬶��������������˵��û�иı�߶ȣ�
	root->hieght = 1 + ((getHeight(root->Left) > getHeight(root->Right)) ? getHeight(root->Left) : getHeight(root->Right));
	temp->hieght = 1 + ((getHeight(temp->Left) > getHeight(temp->Right))? getHeight(temp->Left) : getHeight(temp->Right));
	return temp;
}
template<class T>
treeNode<T>* AVLTREE<T>::AVLTREE::RL(treeNode<T>* root)
{
	//����ת����ת
	root->Right = RR(root->Right);
	return LL(root);
}
template<class T>
treeNode<T>* AVLTREE<T>::LR(treeNode<T>* root)
{

	root->Left = LL(root->Left);
	return RR(root);
}

int main()
{
	AVLTREE<int> xx;
	xx.insert(3);
	xx.insert(1);
	xx.insert(5);
	xx.insert(2);
	xx.insert(10);
	xx.insert(9);
	treeNode<int>* t=xx.Find(10);
	if (t)
	{
		printf("%d\n", t->data);
	}
	xx.DeleNode(10);
	while (1);
	return 0;
}