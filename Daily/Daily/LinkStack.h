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
	LinkStack<Type>();//构造空栈
	LinkStack<Type>(LinkStackNode<Type>* top);//获得栈顶元素
	LinkStack<Type>(const LinkStack<Type>& stack);//复制构造函数
	virtual ~LinkStack();//析构函数
	int Length()const;//求链式栈长度
	bool Empty()const;//判断链式栈是否为空
	void Clear();//清空栈
	
	bool Push(const LinkStackNode<Type>& e);//入栈
	bool Top(LinkStackNode& e)const;//返回栈顶元素
	bool Pop(LinkStackNode& e);//出栈
	LinkStack<Type>& operator=(const LinkStack<Type>& copy);//重载赋值符
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