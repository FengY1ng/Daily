//LinkStack.h
#pragma once

#include "basis.h"

template<class Type>
class LinkStackNode
{
public:
	Type data;
	LinkStackNode<Type>* next;
	LinkStackNode<Type>();
	LinkStackNode<Type>(Type data);
	void Output();
};

template<class Type>
class LinkStack
{
private:
	LinkStackNode<Type>* top;
	int count;
public:
	LinkStack<Type>();//�����ջ
	LinkStack<Type>(vector<Type> vec);
	LinkStack<Type>(LinkStackNode<Type>* top);//���ջ��Ԫ��
	virtual ~LinkStack();//��������
	int Length()const;//����ʽջ����
	bool Empty()const;//�ж���ʽջ�Ƿ�Ϊ��
	bool Clear();//���ջ
	bool Push(const Type& e);//��ջ
	bool Top(Type& e)const;//����ջ��Ԫ��
	bool Pop(Type& e);//��ջ
	LinkStack<Type>& operator=(const LinkStack<Type>& copy);//���ظ�ֵ��
	void Output();
};

template<class Type>
LinkStackNode<Type>::LinkStackNode()
{
	this->next = NULL;
}

template<class Type>
LinkStackNode<Type>::LinkStackNode(Type data)
{
	this->data = data;
	this->next = NULL;
}

template<class Type>
void LinkStackNode<Type>::Output()
{
	cout << this->data << "  ";
}

template<class Type>
LinkStack<Type>::LinkStack()
{
	this->top = NULL;
	this->count = 0;
}

template<class Type>
LinkStack<Type>::LinkStack(LinkStackNode<Type>* top)
{
	this->top = top;
	this->count = 1;
}

template<class Type>
bool LinkStack<Type>::Clear()
{
	if (this->Empty())
	{
		return false;
	}
	Type median;
	while (!Empty())
	{
		Pop(median);
	}
	this->count = 0;
	return true;
}

template<class Type>
LinkStack<Type>::~LinkStack()
{
	Clear();
}

template<class Type>
bool LinkStack<Type>::Empty()const
{
	return this->top == NULL ? true : false;
}

template<class Type>
bool LinkStack<Type>::Pop(Type& e)
{
	if (Empty())
	{
		return false;
	}
	else
	{
		LinkStackNode<Type>* p = this->top;
		e = p->data;
		this->top = this->top->next;
		count--;
		delete(p);
		return true;
	}
}

template<class Type>
bool LinkStack<Type>::Top(Type& e)const
{
	if (Empty())
	{
		return false;
	}
	else
	{
		e = this->top->data;
		return true;
	}
}

template<class Type>
bool LinkStack<Type>::Push(const Type& e)
{
	if (this->Empty())
	{
		this->top = new LinkStackNode<Type>(e);
		this->count++;
		return true;
	}
	else
	{
		if (e <= this->top->data)
		{
			cout << "Error��\n����ԭ���������ֲ�����ǰһ������!\n";
			return false;
		}
		LinkStackNode<Type>* median = new LinkStackNode<Type>(e);
		median->next = this->top;
		this->top = median;
		this->count++;
		return true;
	}
}

template<class Type>
LinkStack<Type>::LinkStack(vector<Type> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		this->Push(vec[i]);
	}
}

template<class Type>
void LinkStack<Type>::Output()
{
	LinkStackNode<Type>* p = new LinkStackNode<Type>();
	int i = 1;
	for (p = this->top; p != NULL; p = p->next,i++)
	{
		cout << "��" << i << "��Ԫ��Ϊ��" << p->data<<"  ";
	}
}
