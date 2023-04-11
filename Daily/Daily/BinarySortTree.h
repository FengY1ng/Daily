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
	BinarySortTreeNode<ElemType>* root;//���ڵ�
	void PreOrderAssist(const BinarySortTreeNode<ElemType>* r);
	void InOrderAssist(const BinarySortTreeNode<ElemType>* r);
	void PostOrderAssist(const BinarySortTreeNode<ElemType>* r);
	int HeightAssist(const BinarySortTreeNode<ElemType>* r)const;
	BinarySortTreeNode<ElemType>* SearchAssist(const KeyType& key, BinarySortTreeNode<ElemType>*& f);
	void DeleteAssist(BinarySortTreeNode<ElemType>*& p);//ɾ��pָ��Ľڵ�
	void DisplayBTWithTreeShapeAssit(BinarySortTreeNode<ElemType>* r, int level);
public:
	BinarySortTree();//�޲εĹ��캯��
	BinarySortTree(const ElemType& e);//������eΪ���Ķ���������
	BinarySortTree(BinarySortTreeNode<ElemType>* r);//������rΪ���Ķ���������
	BinarySortTree(const BinarySortTree<ElemType, KeyType>& copy);//���ƹ��캯��
	BinarySortTreeNode<ElemType>* GetRoot();//���ض������ĸ�
	bool Empty()const;//�ж϶����������Ƿ�Ϊ��
	bool GetElem(const BinarySortTreeNode<ElemType>* cur, ElemType& e)const;//��e���ؽ������Ԫ��ֵ
	bool SetElem(BinarySortTreeNode<ElemType>* cur, const ElemType& e);//�����cur��ֵ��Ϊe
	void InOrder();//�������������������
	void PreOrder();//�������������������
	void PostOrder();//�����������ĺ������
	//void LevelOrder()const;//�����������Ĳ�α���
	//int NodeCount()const;//������������Ľڵ����
	BinarySortTreeNode<ElemType>* LeftChild(const BinarySortTreeNode<ElemType>* cur)const;//����cur�ڵ�����ӽڵ�
	BinarySortTreeNode<ElemType>* RightChild(const BinarySortTreeNode<ElemType>* cur)const;//����cur�ڵ���Һ��ӽڵ�
	BinarySortTreeNode<ElemType>* Parent(const BinarySortTreeNode<ElemType>* cur)const;//����cur�ڵ��˫��
	int Height()const;//���ض����������ĸ�
	BinarySortTreeNode<ElemType>* Search(KeyType& key);//���ҹؼ���Ϊkey������Ԫ��
	bool Insert(const ElemType  & e);//��������Ԫ��e
	bool Delete(const KeyType& key);//ɾ���ؼ���Ϊkey������Ԫ��
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