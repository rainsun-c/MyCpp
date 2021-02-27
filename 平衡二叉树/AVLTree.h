
//树结点
template<class T>
class treeNode
{
public:
	T			data;				//数据
	treeNode*	Right;				//右子树
	treeNode*	Left;				//左子树
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
	AVLTREE(treeNode<T>* root = NULL) :root(root){}
	void insert(const T& data);				//插入
	
	treeNode<T>* RR(treeNode<T>* root);	
	treeNode<T>* LL(treeNode<T>* root);
	treeNode<T>* RL(treeNode<T>* root);
	treeNode<T>* LR(treeNode<T>* root);
protected:
	int getHeight(treeNode<T>* root);					//获取高度
	void _insert(treeNode<T>*& root, const T& data);		//插入(保护)
	treeNode<T>* root;
};
template<class T>
void AVLTREE<T>::insert(const T& data)
{
	_insert(this->root,data);
}
template<class T>
void AVLTREE<T>::_insert(treeNode<T>*& root, const T& data)
{
	//1、插入数据，使用二叉搜索树插入
	if (root == NULL)
	{
		root =new treeNode<T>(data);
	}
	else if(root->data > data)
	{
		_insert(root->Left, data);
		if (getHeight(root->Left) - getHeight(root->Right) > 1)
		{

			if (root->Left->data > data)//RR
			{
				root = RR(root);
			}
			else//LR
			{
				root=LR(root);
			}
		}
	}
	else 
	{
		_insert(root->Right, data);
		if (getHeight(root->Right) - getHeight(root->Left) > 1)
		{

			if (root->Right->data < data)//RR
			{
				root = LL(root);
			}
			else//LR
			{
				root=RL(root);
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
	
		treeNode<T>* temp = root->Left;
		root->Left = temp->Right;
		temp->Right = root;

		root->hieght = 1 + (getHeight(root->Left) > getHeight(root->Right) ? getHeight(root->Left) : getHeight(root->Right));
		temp->hieght = 1 + (getHeight(temp->Left) > getHeight(temp->Right) ? getHeight(temp->Left) : getHeight(temp->Right));
		return temp;
	
}
template<class T>
treeNode<T>* AVLTREE<T>::AVLTREE::LL(treeNode<T>* root) 
{
	
	
		treeNode<T>* temp = root->Right;
		root->Right = temp->Left;
		temp->Left = root;

		root->hieght = 1 + (getHeight(root->Left) > getHeight(root->Right) ? getHeight(root->Left) : getHeight(root->Right));
		temp->hieght = 1 + (getHeight(temp->Left) > getHeight(temp->Right) ? getHeight(temp->Left) : getHeight(temp->Right));
		return temp;
	
	
}
template<class T>
treeNode<T>* AVLTREE<T>::AVLTREE::RL(treeNode<T>* root) 
{
	root->Right = RR(root->Left);
	return LL(root);
}
template<class T>
treeNode<T>* AVLTREE<T>::LR(treeNode<T>* root) 
{
	root->Left = LL(root->Right);
	return RR(root);
}