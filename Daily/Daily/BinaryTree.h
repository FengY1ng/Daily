//BinaryTree.h
#pragma once
#include "basis.h"

template<class Type>
class BinaryTreeNode
{
private:
	Type data;
	BinaryTreeNode<Type>* leftChild;
	BinaryTreeNode<Type>* rightChild;
public:
	BinaryTreeNode();
	BinaryTreeNode(Type data, BinaryTreeNode<Type>* leftChild = NULL, BinaryTreeNode<Type>* rightChild = NULL)
	{

		this->data = data;
		this->leftChild = leftChild;
		this->rightChild = rightChild;
	}
};

template<class Type>
class BinaryTree
{
protected:
	BinaryTreeNode<Type>* root=NULL;
	void PreOrderAssist(const BinaryTreeNode<Type>* r, void (*visit)(const Type&))const;
	void InOrderAssist(const BinaryTreeNode<Type>* r, void (*visit)(const Type&))const;
	void PostOrderAssist(const BinaryTreeNode<Type>* r, void (*visit)(const Type&))const;
	void CreateBinaryTreeAssist(BinaryTreeNode<Type>*& cur, Type pre[], Type in[], int preLeft, int preRight, int inLeft, int inRight);
	void DisplayBTWithTreeShapeAssit(BinaryTreeNode<Type>* r, int level);
	int HeightAssist(const BinaryTreeNode<Type>* r)const;
public:
	BinaryTreeNode<Type>* GetRoot()const;
	BinaryTree();
	BinaryTree(BinaryTreeNode<Type>* root);
	BinaryTree(BinaryTree& e);
	void DisplayBTWithTreeShape(const BinaryTree<Type>& bt);//显示二叉树
	virtual ~BinaryTree();
	void CopyTreeHelp(const BinaryTree<Type> e);
	void PreOrder(void(*visit)(Type&));//前序遍历
	void InOrder(void(*visit)(Type&));//中序遍历
	void PostOrder(void(*visit)(Type&));//后序遍历
	int GetHeight();//获取二叉树的高
	int GetNodeCount()const;//获取节点个数
	BinaryTreeNode<Type>* LeftChild(const BinaryTreeNode<Type>* cur)const;//返回左孩子节点
	BinaryTreeNode<Type>* RightChild(const BinaryTreeNode<Type>* cur)const;//返回右孩子节点
	BinaryTreeNode<Type>* Parent(const BinaryTreeNode<Type>* cour)const;////返回双亲结点
	void InsertLeftChild(BinaryTreeNode<Type>* cur, const Type& e);//插入左孩子
	void InsertRightChild(BinaryTreeNode<Type>* cur, const Type& e); //插入右孩子
	void DeleteBinaryTree();//删除二叉树
	BinaryTree<Type> CreateBinaryTree(Type pre[], Type in[], int n);
};

template<class Type>
int BinaryTree<Type>::HeightAssist(const BinaryTreeNode<Type>* r)const
{
	if (r == NULL)
	{
		return 0;
	}
	else
	{
		int lHeight, rHeight;
		lHeight = HeightAssist(r->leftChild);
		rHeight = HeightAssist(r->rightChild);
		return(lHeight > rHeight ? lHeight : rHeight) + 1;
	}
}

template<class Type>
BinaryTreeNode<Type>* BinaryTree<Type>::GetRoot()const
{
	return root;
}

template<class Type>
void BinaryTree<Type>::DisplayBTWithTreeShapeAssit(BinaryTreeNode<Type>* r, int level)
{
	if (r != NULL)
	{
		this->DisplayBTWithTreeShape<Type>(r->rightChild, level + 1);
		cout << endl;
		for (int i = 0; i < level - 1; i++)
			cout << " ";
		cout << r->data;
		this->DisplayBTWithTreeShape<Type>(r->leftChild, level + 1);
	}
}

template<class Type>
BinaryTree<Type> BinaryTree<Type>::CreateBinaryTree(Type pre[], Type in[], int n)
{
	BinaryTreeNode<Type>* r;
	CreateBinaryTreeAssist(r, pre, in, 0, n - 1, 0, n - 1);
	return BinaryTree<Type>(r);
}

template<class Type>
void BinaryTree<Type>::CreateBinaryTreeAssist(BinaryTreeNode<Type>*& r, Type pre[], Type in[], int preLeft, int preRight, int inLeft, int inRight)
{
	if (preLeft > preRight || inLeft > inRight)
	{
		r = NULL;
	}
	else
	{
		r = new BinaryTreeNode<Type>(pre[preLeft]);
		int mid = inLeft;
		while (in[mid] != pre[preLeft])
		{
			mid++;
		}
		CreateBinaryTreeAssist(r->LeftChild, pre, in, preLeft + 1, preLeft + mid - inLeft, inLeft, mid - 1);
		CreateBinaryTreeAssist(r->rightChild, pre, in, preLeft + mid - inLeft + 1, preRight, mid + 1, inRight);
	}
}

template<class Type>
void BinaryTree<Type>::DisplayBTWithTreeShape(const BinaryTree<Type>& bt)
{
	DisplayBTWithTreeShapeAssit(bt.GetRoot(), 1);
	cout << endl;
}


template<class Type>
BinaryTreeNode<Type>::BinaryTreeNode()
{
	this->data = NULL;
	this->leftChild = NULL;
	this->rightChild = NULL;
}

template<class Type>
BinaryTree<Type>::BinaryTree()
{
	this->root = NULL;
}

template<class Type>
int BinaryTree<Type>::GetHeight()
{
	return HeightAssist(root);
}

template<class Type>
void BinaryTree<Type>::PreOrderAssist(const BinaryTreeNode<Type>* r, void (*visit)(const Type&))const
{
	if (r != NULL)
	{
		(*visit)(r->data);
		PreOrderAssist(r->leftChild, visit);
		PreOrderAssist(r->rightChild, visit);
	}
}

template<class Type>
void BinaryTree<Type>::InOrderAssist(const BinaryTreeNode<Type>* r, void (*visit) (const Type&))const
{
	if (r != NULL)
	{
		InOrderAssist(r->leftChild, visit);
		(*visit)(r->data);
		InOrderAssist(r->rightChild, visit);
	}
}

template<class Type>
void BinaryTree<Type>::PostOrderAssist(const BinaryTreeNode<Type>* r, void (*visit) (const Type&))const
{
	if (r != NULL)
	{
		PostOrderAssist(r->leftChild);
		PostOrderAssist(r->rightChild, visit);
		(*visit)(r->data);
	}
}

template<class Type>
void BinaryTree<Type>::PreOrder(void(*visit)(Type&))
{
	PreOrderAssist(root, visit);
}

template<class Type>
void BinaryTree<Type>::InOrder(void(*visit)(Type&))
{
	InOrderAssist(root, visit);
}

template<class Type>
void BinaryTree<Type>::PostOrder(void (*visit)(Type&))
{
	PostOrderAssist(root, visit);
}