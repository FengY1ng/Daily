//BinartSortTree.h
#pragma once
#include "basis.h"

template<class Type>
class BinarySortTreeNode
{
public:
	Type data;
	BinarySortTreeNode<Type>* leftChild;
	BinarySortTreeNode<Type>* rightChild;
public:
	BinarySortTreeNode();
	BinarySortTreeNode(const Type& val, BinarySortTreeNode<Type>* lChild = NULL, BinarySortTreeNode* rChild = NULL);
	Type GetData();
};

template<class ElemType,class KeyType>
class BinarySortTree
{
protected:
	BinarySortTreeNode<ElemType>* root;//根节点
	void PreOrderAssist(const BinarySortTreeNode<ElemType>* r);
	void InOrderAssist(const BinarySortTreeNode<ElemType>* r);
	void PostOrderAssist(const BinarySortTreeNode<ElemType>* r);
	int HeightAssist(const BinarySortTreeNode<ElemType>* r)const;
	BinarySortTreeNode<ElemType>* SearchAssist(const KeyType& key, BinarySortTreeNode<ElemType>*& f);
	void DeleteAssist(BinarySortTreeNode<ElemType>*& p);//删除p指向的节点
	void DisplayBTWithTreeShapeAssit(BinarySortTreeNode<ElemType>* r, int level);
public:
	BinarySortTree();//无参的构造函数
	BinarySortTree(const ElemType& e);//建立以e为根的二叉排序树
	BinarySortTree(BinarySortTreeNode<ElemType>* r);//建立以r为根的二叉排序树
	BinarySortTree(const BinarySortTree<ElemType, KeyType>& copy);//复制构造函数
	BinarySortTreeNode<ElemType>* GetRoot();//返回二叉树的根
	bool Empty()const;//判断二叉排序树是否为空
	bool GetElem(const BinarySortTreeNode<ElemType>* cur, ElemType& e)const;//用e返回结点数据元素值
	bool SetElem(BinarySortTreeNode<ElemType>* cur, const ElemType& e);//将结点cur的值置为e
	void InOrder();//二叉排序树的中序遍历
	void PreOrder();//二叉排序树的先序遍历
	void PostOrder();//二叉排序树的后序遍历
	//void LevelOrder()const;//二叉排序树的层次遍历
	//int NodeCount()const;//求二叉排序树的节点个数
	BinarySortTreeNode<ElemType>* LeftChild(const BinarySortTreeNode<ElemType>* cur)const;//返回cur节点的左孩子节点
	BinarySortTreeNode<ElemType>* RightChild(const BinarySortTreeNode<ElemType>* cur)const;//返回cur节点的右孩子节点
	BinarySortTreeNode<ElemType>* Parent(const BinarySortTreeNode<ElemType>* cur)const;//返回cur节点的双亲
	int Height()const;//返回二叉排序树的高
	BinarySortTreeNode<ElemType>* Search(KeyType& key);//查找关键字为key的数据元素
	bool Insert(const ElemType  & e);//插入数据元素e
	bool Delete(const KeyType& key);//删除关键字为key的数据元素
	void DisplayBTWithTreeShape(BinarySortTree<ElemType,KeyType>& bt);
};

template<class ElemType,class KeyType>
bool BinarySortTree<ElemType,KeyType>::GetElem(const BinarySortTreeNode<ElemType>* cur, ElemType& e)const
{
	if (cur != NULL)
	{
		e = cur->data;
		return true;
	}
	else
	{
		return false;
	}
}

template<class ElemType,class KeyType>
BinarySortTreeNode<ElemType>* BinarySortTree<ElemType, KeyType>::RightChild(const BinarySortTreeNode<ElemType>* cur)const
{
	return cur->rightChild;
}

template<class ElemType,class KeyType>
BinarySortTreeNode<ElemType>* BinarySortTree<ElemType, KeyType>::LeftChild(const BinarySortTreeNode<ElemType>* cur)const
{
	return cur->leftChild;
}

template<class Type>
Type BinarySortTreeNode<Type>::GetData()
{
	return this->data;
}

template<class ElemType,class KeyType>
int BinarySortTree<ElemType, KeyType>::Height()const
{
	return HeightAssist(root);
}

template<class ElemType,class KeyType>
int BinarySortTree<ElemType, KeyType>::HeightAssist(const BinarySortTreeNode<ElemType>* r)const
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
		return (lHeight > rHeight ? lHeight : rHeight) + 1;
	}
}

template<class ElemType,class KeyType>
BinarySortTree<ElemType, KeyType>::BinarySortTree(const BinarySortTree<ElemType, KeyType>& copy)
{
	this->root = copy->root;
}

template<class ElemType,class KeyType>
BinarySortTree<ElemType, KeyType>::BinarySortTree(BinarySortTreeNode<ElemType>* r)
{
	this->root = r;
}

template<class ElemType,class KeyType>
BinarySortTree<ElemType, KeyType>::BinarySortTree(const ElemType& e)
{
	BinarySortTreeNode<ElemType> node = new BinarySortTreeNode<ElemType>(e);
	this->root = node;
}

template<class ElemType,class KeyType>
BinarySortTree<ElemType, KeyType>::BinarySortTree()
{
	this->root = NULL;
}

template<class Type>
BinarySortTreeNode<Type>::BinarySortTreeNode()
{
	this->leftChild = NULL;
	this->rightChild = NULL;
}

template<class Type>
BinarySortTreeNode<Type>::BinarySortTreeNode(const Type& val, BinarySortTreeNode<Type>* lChild, BinarySortTreeNode<Type>* rChild)
{
	this->data = val;
	this->leftChild = lChild;
	this->rightChild = rChild;
}

template<class ElemType, class KeyType>
bool BinarySortTree<ElemType, KeyType>::Empty()const
{
	if (this->root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class ElemType, class KeyType>
BinarySortTreeNode<ElemType>* BinarySortTree<ElemType, KeyType>::GetRoot()
{
	return this->root;
}                                                                                                                                                                                                                                                                                                                                                                 

template<class ElemType, class KeyType>
BinarySortTreeNode<ElemType>* BinarySortTree<ElemType, KeyType>::SearchAssist(const KeyType& key, BinarySortTreeNode<ElemType>*& f)
{
	BinarySortTreeNode<ElemType>* p = GetRoot();
	f = NULL;

	while (p != NULL && p->data != key)
	{
		if (key < p->data)
		{
			f = p;
			p = p->leftChild;
		}
		else
		{
			f = p;
			p = p->rightChild;
		}
	}
	return p;
}

template<class ElemType, class KeyType>
BinarySortTreeNode<ElemType>* BinarySortTree<ElemType, KeyType>::Search(KeyType& key)
{
	BinarySortTreeNode<ElemType>* f;
	return SearchAssist(key, f);
}

template<class ElemType, class KeyType>
bool BinarySortTree<ElemType, KeyType>::Insert(const ElemType& e)
{
	BinarySortTreeNode<ElemType>* f;
	if (SearchAssist(e, f) == NULL)
	{
		BinarySortTreeNode<ElemType>* p;
		p = new BinarySortTreeNode<ElemType>(e);
		if (Empty())
		{
			root = p;
		}
		else if (e < f->data)
		{
			f->leftChild = p;
		}
		else
		{
			f->rightChild = p;
		}
		return true;
	}
	else
	{
		return false;
	}
}

template<class ElemType, class KeyType>
void BinarySortTree<ElemType, KeyType>::DeleteAssist(BinarySortTreeNode<ElemType>*& p)
{
	BinarySortTreeNode<ElemType>* temPtr, * tempF;
	if (p->leftChild == NULL && p->rightChild == NULL)
	{
		delete p;
		p = NULL;
	}
	else if (p->leftChild == NULL)
	{
		temPtr = p;
		p = p->rightChild;
		delete temPtr;
	}
	else if (p->rightChild == NULL)
	{
		temPtr = p;
		temPtr = p->leftChild;
		delete temPtr;
	}
	else
	{
		tempF = p;
		temPtr = p->leftChild;
		while (temPtr->rightChild != NULL)
		{
			tempF = temPtr;
			temPtr = temPtr->rightChild;
		}
		p->data = temPtr->data;

		if (tempF->rightChild == temPtr)
		{
			DeleteAssist(tempF->rightChild);
		}
		else
		{
			DeleteAssist(tempF->leftChild);
		}
	}
}

template<class ElemType, class KeyType>
bool BinarySortTree<ElemType, KeyType>::Delete(const KeyType& key)
{
	BinarySortTreeNode<ElemType>* p, * f;
	p = SearchAssist(key, f);
	if (p == NULL)
	{
		return false;
	}
	else if (key < f->data)
	{
		DeleteAssist(f->leftChild);
	}
	else
	{
		DeleteAssist(f->rightChild);
	}
	return true;
}

template<class ElemType,class KeyType>
void BinarySortTree<ElemType,KeyType>::PreOrderAssist(const BinarySortTreeNode<ElemType>* r)
{
	if (r != NULL)
	{
		cout << r->data << " ";
		PreOrderAssist(r->leftChild);
		PreOrderAssist(r->rightChild);
	}
}

template<class ElemType, class KeyType>
void BinarySortTree<ElemType,KeyType>::InOrderAssist(const BinarySortTreeNode<ElemType>* r)
{
	if (r != NULL)
	{
		InOrderAssist(r->leftChild);
		cout << r->data << " ";
		InOrderAssist(r->rightChild);
	}
}

template<class ElemType, class KeyType>
void BinarySortTree<ElemType,KeyType>::PostOrderAssist(const BinarySortTreeNode<ElemType>* r)
{
	if (r != NULL)
	{
		PostOrderAssist(r->leftChild);
		PostOrderAssist(r->rightChild);
		cout << r->data << " ";
	}
}

template<class ElemType, class KeyType>
void BinarySortTree<ElemType,KeyType>::PreOrder()
{
	PreOrderAssist(root);
}

template<class ElemType,class KeyType>
void BinarySortTree<ElemType,KeyType>::InOrder()
{
	InOrderAssist(root);
}

template<class ElemType,class KeyType>
void BinarySortTree<ElemType,KeyType>::PostOrder()
{
	PostOrderAssist(root);
}

template<class ElemType,class KeyType>
void BinarySortTree<ElemType,KeyType>::DisplayBTWithTreeShapeAssit(BinarySortTreeNode<ElemType>* r, int level)
{
	if (r != NULL)
	{
		this->DisplayBTWithTreeShapeAssit(r->rightChild, level + 1);
		cout << endl;
		for (int i = 0; i < level - 1; i++)
			cout << " ";
		cout << r->data;
		this->DisplayBTWithTreeShapeAssit(r->leftChild, level + 1);
	}
}

template<class ElemType,class KeyType>
void BinarySortTree<ElemType,KeyType>::DisplayBTWithTreeShape(BinarySortTree<ElemType,KeyType>& bt)
{
	DisplayBTWithTreeShapeAssit(bt.GetRoot(), 1);
	cout << endl;
}