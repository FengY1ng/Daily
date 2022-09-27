//LinkStack.h
#pragma once

#include "basis.h"

template<class Type>
class LinkStackNode
{
private:
	Type data;
	LinkStackNode<Type>* next;
public:
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
	LinkStack<Type>(LinkStackNode<Type>* top);//���ջ��Ԫ��
	LinkStack<Type>(const LinkStack<Type>& stack);//���ƹ��캯��
	virtual ~LinkStack();//��������
	int Length()const;//����ʽջ����
	bool Empty()const;//�ж���ʽջ�Ƿ�Ϊ��
	void Clear();//���ջ
	
	bool Push(const LinkStackNode<Type>& e);//��ջ
	bool Top(LinkStackNode& e)const;//����ջ��Ԫ��
	bool Pop(LinkStackNode& e);//��ջ
	LinkStack<Type>& operator=(const LinkStack<Type>& copy);//���ظ�ֵ��
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
LinkStack<Type>::LinkStack(const LinkStack<Type>& stack)
{
	if (stack.Empty())
	{
		this->top = NULL;
		this->count = 0;
	}
	else
	{
		this->top = new LinkStackNode<Type>(stack.top->data);
		LinkStackNode<Type>* p = this->top
		this->count = stack.count;
		for (LinkStackNode<Type>* median = stack.top->next, int num = 0; num < count; p = p->next,median=median->next)
		{
			p->next = median;
		}
	}
}