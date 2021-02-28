#include <stdio.h>



//树结点
template<class T>
class treeNode
{
public:
	T			data;				//数据
	treeNode* Right;				//右子树
	treeNode* Left;					//左子树
	int			hieght;				//高度
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
	void insert(const T& data);							//插入
	treeNode<T>* Find(const T& index);
protected:
	treeNode<T>* LRightNode();
	int getHeight(treeNode<T>* root);					//获取高度
	treeNode<T>* RR(treeNode<T>* root);
	treeNode<T>* LL(treeNode<T>* root);
	treeNode<T>* RL(treeNode<T>* root);
	treeNode<T>* LR(treeNode<T>* root);
	treeNode<T>* _Find(treeNode<T>* root,const T& index);
	void _insert(treeNode<T>*& root, const T& data);		//插入(保护)
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
		//返回最右的父节点
		return pMove;
	}

	
}
template<class T>
void AVLTREE<T>::DeleNode(T index)
{
	treeNode<T>* deletNode = Find(index);
	if (deletNode == NULL)
	{
		printf("没有这个数据");
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
	//1、插入数据，使用二叉搜索树插入
	if (root == NULL)
	{
		root = new treeNode<T>(data);
	}
	else if (root->data > data)
	{
		_insert(root->Left, data);
		//判断插在哪边（左>右，说明在插在左边）
		if (getHeight(root->Left) - getHeight(root->Right) > 1)
		{
			//都在左边用RR
			if (root->Left->data > data)//RR
			{
				root = RR(root);
			}
			//左右都有LR
			else//LR
			{
				root = LR(root);
			}
		}
	}
	else
	{
		_insert(root->Right, data);
		//判断插在哪边（右>左，说明在插在右边）
		if (getHeight(root->Right) - getHeight(root->Left) > 1)
		{
			//都在右边用LL
			if (root->Right->data < data)//RR
			{
				root = LL(root);
			}
			//左右都有RL
			else
			{
				root = RL(root);
			}
		}
	}
	//2、判断是否旋转
	//3、设置高度
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
	//记录root的左子树
	treeNode<T>* temp = root->Left;
	//temp的右子树给root的左子树
	root->Left = temp->Right;
	//将root插在temp的右子树下；
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
	//在转的时候，对于上面的子树来说，没有改变高度，
	root->hieght = 1 + ((getHeight(root->Left) > getHeight(root->Right)) ? getHeight(root->Left) : getHeight(root->Right));
	temp->hieght = 1 + ((getHeight(temp->Left) > getHeight(temp->Right))? getHeight(temp->Left) : getHeight(temp->Right));
	return temp;
}
template<class T>
treeNode<T>* AVLTREE<T>::AVLTREE::RL(treeNode<T>* root)
{
	//向右转在左转
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