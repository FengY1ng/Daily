//SimpleLinkList.h
#pragma once
#include "basis.h"

template<class ElemType>
struct Node
{
	ElemType data;
	Node<ElemType>* next;
	Node();
	Node(ElemType item, Node<ElemType>* link = NULL);
};

template<class ElemType>
class SimpleLinkList
{
protected:
	Node<ElemType>* head;
	SimpleLinkList<ElemType> GetElement(int position)const;

public:
	SimpleLinkList();
	SimpleLinkList(ElemType item);
	bool Insert(int position, const ElemType& e);
	bool Delete(int position, ElemType& e);
	int Length()const;
	void Output();
};

#include "SimpleLinkList.h"
#include "basis.h"

//���
template<class ElemType>
Node<ElemType>::Node()
{
	next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType>* link)
{
	data = item;
	next = link;
}

//������

//��ʼ����������
template<class ElemType>
SimpleLinkList<ElemType>::SimpleLinkList()
{
	head = NULL;
	Node<ElemType>* end = NULL;
	int length = 0, data;
	cout << "������������:";
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		cout << "�������" << i + 1 << "���ڵ������:";
		cin >> data;
		Node<ElemType>* p = new Node<ElemType>(data);
		if (head == NULL)
		{
			head = p;
			end = p;
		}
		else
		{
			end->next = p;
			end = p;
		}
	}
}

template<class ElemType>
SimpleLinkList<ElemType>::SimpleLinkList(ElemType item)
{
	Node<ElemType>* data(item);
	this->head = data;
}

//�ڵ�position���ڵ�ǰ����һ���ڵ�
template<class ElemType>
bool SimpleLinkList<ElemType>::Insert(int position, const ElemType& e)
{
	Node<ElemType>* median = new Node<ElemType>(e);
	if (position<1 || position>Length() + 1)
	{
		cout << "���뷶Χ����ȷ��" << endl;
		return false;
	}
	else if (position != 1)
	{
		Node<ElemType>* p = head;
		for (int i = 0; i < position - 2; i++)
		{
			p = p->next;
		}
		median->next = p->next;
		p->next = median;
		return true;
	}
	else
	{
		median->next = head;
		head = median;
		return true;
	}
}

//��ȡ����
template<class ElemType>
int SimpleLinkList<ElemType>::Length()const
{
	if (this->head == NULL)
	{
		return 0;
	}
	int length = 1;
	Node<ElemType>* p = head;
	for (; p->next != NULL; p = p->next, length++)
	{

	}
	return length;
}

//ɾ����position��Ԫ�ؽڵ�
template<class ElemType>
bool SimpleLinkList<ElemType>::Delete(int position, ElemType& e)
{
	if (position<1 || position>Length())
		return false;
	else if (position == 1)
	{
		Node<ElemType>* p = head;
		head = head->next;
		e = p->data;
		delete(p);
	}
	else
	{
		Node<ElemType>* p = head;
		for (int i = 0; i < position - 2; i++,p=p->next)
		{

		}
		Node<ElemType>* q = p->next;
		p->next = p->next->next;
		e = q->data;
		delete(q);
	}
}

template<class ElemType>
void SimpleLinkList<ElemType>::Output()
{
	Node<ElemType>* p = head;
	cout << "��ǰ�������������Ϊ:";
	for (int i = 0; i < Length(); i++, p = p->next)
	{
		cout << p->data<<"  ";
	}
	cout << endl;
}