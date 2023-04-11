////Sort.h
//#pragma once
//#include "basis.h"
//
//template<class Type>
//struct Node
//{
//	Type data;
//	Node<Type>* next;
//	Node();
//	Node(Type item, Node<Type>* link = NULL);
//};
//
//template<class Type>
//class LinkList
//{
//protected:
//	Node<Type>* head;
//	Node<Type>* GetElemPtr(int position)const;
//public:
//	LinkList();
//	virtual ~LinkList();
//	int Length()const;
//	bool Empty()const;
//	void Clear();
//	bool Delete(int position, Type& e);
//	bool Insert(int position, const Type& e);
//};
//
//template<class Type>
//void Distribute(vector<Type> elem, int r, int d, int i, LinkList<Type> list[])
//{
//	for (int power = (int)pow((double)r, i - 1), j = 0; j < elem.size(); j++)
//	{
//		int index = (elem[j] / power) % r;
//		list[index].Insert(list[index].Length() + 1, elem[j]);
//	}
//}
//
//template<class Type>
//void Colect(vector<Type> elem, int r, int d, int i, LinkList<Type>list[])
//{
//	for (int k = 0, j = 0; j < r; j++)
//	{
//		Type tmpElem;
//		while (!list[j].Empty())
//		{
//			list[j].Delete(1, tmpElem);
//			elem[k++] = tmpElem;
//		}
//	}
//}
//
//template<class Type>
//void RadixSort(vector<Type> elem, int r, int d)
//{
//	LinkList<Type>* list;
//	list = new LinkList<Type>[r];
//	for (int i = 0; i <= d; i++)
//	{
//		for (int i = 1; i <= d; i++)
//		{
//			Distribute(elem, r, d, i, list);
//			Colect(elem, r, d, i, list);
//		}
//		delete[]list;
//	}
//}
//
//template<class Type>
//void SimpleMerge(vector<Type>& elem, int low, int mid, int high)
//{
//	Type* tmpElem = new Type[high + 1];
//
//	int i, j, k;
//	for (i = low, j = mid + 1, k = low; i < mid && j <= high; k++)
//	{
//		if (elem[i] <= elem[j])
//		{
//			tmpElem[k] = elem[i];
//			i++;
//		}
//		else
//		{
//			tmpElem[k] = elem[j];
//			j++;
//		}
//	}
//	for (; i <= mid; i++, k++)
//	{
//		tmpElem[k] = elem[i];
//	}
//	for (; j <= high; j++, k++)
//	{
//		tmpElem[k] = elem[j];
//	}
//	for (i = low; i <= high; i++)
//	{
//		elem[i] = tmpElem[i];
//	}
//	delete[]tmpElem;
//}
//
//template<class Type>
//void SimpleMergeSortAssist(vector<Type>& elem, int low, int high)
//{
//	if (low < high)
//	{
//		int mid = (low + high) / 2;
//		SimpleMergeSortAssist(elem, low, mid);
//		SimpleMergeSortAssist(elem, mid + 1, high);
//		SimpleMerge(elem, low, mid, high);
//	}
//}
//
//template<class Type>
//void SimpleMergeSort(vector<Type>& elem)
//{
//	SimpleMergeSortAssist(elem, 0, elem.size() - 1);
//}
//
//template<class Type>
//void SiftAdjust(vector<Type>& elem, int low, int high)
//{//操作结果 ： elemtiow..high) 中记录除 elem 〔 1 “ ] 以外都满足堆定义 ， 调整 elem[low]使其elem[low..high]成为一个大堆
//	for (int f = low, i = 2 * low + 1; i <= high; i = 2 * i + 1)
//	{
//		if (i < high && elem[i] < elem[i + 1])
//		{
//			i++;
//		}
//		if (elem[f] > elem[i])
//		{
//			break;
//		}
//		swap(elem[f], elem[i]);
//		f = i;
//	}
//}
//
//template<class Type>
//void HeapSort(vector<Type> &elem)
//{
//	int i;
//	for (i = (elem.size() - 2) / 2; i >= 0; --i)
//	{
//		SiftAdjust(elem, i, elem.size() - 1);
//	}
//	for (i = elem.size() - 1; i > 0; --i)
//	{
//		swap(elem[0], elem[i]);
//		SiftAdjust(elem, 0, i - 1);
//	}
//}
//
//template<class Type>
//void InsertElem(vector<Type>& vec)
//{
//	Type elem;
//	while (1)
//	{
//		cout << "请输入想要添加的元素(按下‘0’以终止输入)" << endl;
//		cin >> elem;
//		vec.push_back(elem);
//	}
//}
//
//template<class Type>
//void DefaultVector(vector<Type>& vec)
//{
//	vec.push_back(35);
//	vec.push_back(22);
//	vec.push_back(23);
//	vec.push_back(11);
//	vec.push_back(98);
//	vec.push_back(68);
//	vec.push_back(82);
//	vec.push_back(49);
//	vec.push_back(31);
//	vec.push_back(46);
//	vec.push_back(90);
//	vec.push_back(1093);
//	vec.push_back(52);
//	vec.push_back(761);
//	vec.push_back(210);
//	vec.push_back(982);
//	vec.push_back(67);
//	vec.push_back(24);
//	vec.push_back(4);
//	vec.push_back(7);
//	vec.push_back(15);
//	vec.push_back(77);
//}
//
//template<class Type>
//Node<Type>::Node()
//{
//	next = NULL;
//}
//
//template<class Type>
//Node<Type>::Node(Type item, Node<Type>* link)
//{
//	data = item;
//	next = link;
//}
//
//template<class Type>
//Node<Type>* LinkList<Type>::GetElemPtr(int position)const
//{
//	Node<Type>* tmpPtr = head;
//	int pos = 0;
//	while (tmpPtr != NULL && pos < position)
//	{
//		tmpPtr = tmpPtr->next;
//		pos++;
//	}
//	if (tmpPtr != NULL && pos == position)
//	{
//		return tmpPtr;
//	}
//	else
//	{
//		return NULL;
//	}
//}
//
//template<class Type>
//LinkList<Type>::LinkList()
//{
//	head = new Node<Type>;
//}
//
//template<class Type>
//LinkList<Type>::~LinkList()
//{
//	Clear();
//	delete head;
//}
//
//template<class Type>
//int LinkList<Type>::Length()const
//{
//	int count = 0;
//	for (Node<Type>* tmpPtr = head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
//	{
//		count++;
//	}
//	return count;
//}
//
//template<class Type>
//bool LinkList<Type>::Empty()const
//{
//	return head->next == NULL;
//}
//
//template<class Type>
//void LinkList<Type>::Clear()
//{
//	Type tmpElem;
//	while (!Empty())
//	{
//		Delete(1, tmpElem);
//	}
//}
//
//template<class Type>
//bool LinkList<Type>::Insert(int position, const Type& e)
//{
//	if (position<1 || position>Length() + 1)
//	{
//		return false;
//	}
//	else
//	{
//		Node<Type>* tmpPtr;
//		tmpPtr = GetElemPtr(position - 1);
//		Node<Type>* newPtr;
//		newPtr = new Node<Type>(e, tmpPtr->next);
//		tmpPtr->next = newPtr;
//		return true;
//	}
//}
//
//template<class Type>
//bool LinkList<Type>::Delete(int position, Type& e)
//{
//	if (position<1 || position>Length())
//	{
//		return false;
//	}
//	else
//	{
//		Node<Type>* tmpPtr;
//		tmpPtr = GetElemPtr(position - 1);
//		Node<Type>* nextPtr = tmpPtr->next;
//		tmpPtr->next = nextPtr->next;
//		e = nextPtr->data;
//		delete nextPtr;
//		return true;
//	}
//}