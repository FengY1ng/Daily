//#pragma once
//#include "basis.h"
//
//template<class ElemType,class KeyType>
//class HashTable
//{
//protected:
//	ElemType* ht;	//散列表
//	bool* empty;	//空元素
//	int m;			//散列表容量
//	int p;			//除留余数法的除数
//
//	int H(const KeyType& key)const;	//散列函数模板
//	int Collision(const KeyType& key, int i)const;//处理冲突的函数模板
//	bool SearchAssist(const KeyType& key, int& pos)const;//
//
//public:
//	HashTable(int size, int divisor);
//	~HashTable();
//	void Traverse(void (*visit)(const ElemType&))const;
//	bool Search(const KeyType& key, ElemType &e)const;
//	bool Insert(const ElemType& e);
//	bool Delete(const KeyType& key);
//	HashTable(const HashTable<ElemType, KeyType>& copy);
//	HashTable<ElemType, KeyType>& operator=(const HashTable<ElemType, KeyType>& copy);
//};
//
//
//
//template<class ElemType,class KeyType>
//int HashTable<ElemType, KeyType>::H(const KeyType& key)const
//{
//	return key % p;
//}
//
//template<class ElemType,class KeyType>
//int HashTable<ElemType, KeyType>::Collision(const KeyType& key, int i)const
//{
//	return (H(key) + i) % m;
//}
//
//template<class ElemType,class KeyType>
//HashTable<ElemType, KeyType>::HashTable(int size, int divisor)
//{
//	m = size;					//赋值散列表容量
//	p = divisor;				//赋值除数
//	ht = new ElemType[m];		//分配存储空间
//	empty = new bool[m];		//分配存储空间
//
//	for (int pos = 0; pos < m; pos++)
//	{
//		empty[pos] = true;
//	}
//}
//
//template<class ElemType,class KeyType>
//HashTable<ElemType, KeyType>::~HashTable()
//{
//	delete[]ht;
//	delete[]empty;
//}
//
//template<class ElemType,class KeyType>
//void HashTable<ElemType, KeyType>::Traverse(void (*visit)(const ElemType&))const
//{
//	for (int pos = 0; pos < m; pos++)
//	{
//		if (!empty[pos])
//		{
//			(*visit)(ht[pos]);
//		}
//	}
//}
//
//template<class ElemType,class KeyType>
//bool HashTable<ElemType, KeyType>::SearchAssist(const KeyType& key, int& pos)const
//{
//	int c = 0;				//冲突次数
//	pos = H(key);
//
//	while (c < m && !empty[pos] && ht[pos] != key)	//冲突次数应小于m，元素ht[pos]非空，关键字值不等
//	{
//		pos = Collision(key, ++c);				//求得下一个探查地址
//	}
//
//	if (c >= m || empty[pos])
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}
//
//template<class ElemType,class KeyType>
//bool HashTable<ElemType, KeyType>::Search(const KeyType& key, ElemType& e)const
//{
//	int pos;			//元素的位置
//	if (SearchAssist(key, pos))
//	{
//		e = ht[pos];	//用e返回元素值
//		return true;	//返回true
//	}
//	else
//	{
//		return false;
//	}
//}
//
//template<class ElemType,class KeyType>
//bool HashTable<ElemType, KeyType>::Insert(const ElemType& e)
//{
//	int pos;
//	if (!SearchAssist(e, pos) && empty[pos])
//	{
//		ht[pos] = e;
//		empty[pos] = false;
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//template<class ElemType,class KeyType>
//bool HashTable<ElemType, KeyType>::Delete(const KeyType& key)
//{
//	int pos;
//	if (SearchAssist(key, pos))
//	{
//		empty[pos] = true;
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//template<class ElemType,class KeyType>
//HashTable<ElemType, KeyType>::HashTable(const HashTable<ElemType, KeyType>& copy)
//{
//	m = copy.m;
//	p = copy.p;
//	ht = new ElemType[m];
//	empty = new bool[m];
//
//	for (int pos = 0; pos < m; pos++)
//	{
//		ht[pos] = copy.ht[pos];
//		empty[pos] = copy.empty[pos];
//	}
//}
//
//template<class ElemType>
//void visit(const ElemType&)
//{
//	cout << "1";
//}
//
//template<class ElemType,class KeyType>
//HashTable<ElemType, KeyType>& HashTable<ElemType, KeyType>::operator=(const HashTable<ElemType, KeyType>& copy)
//{
//	if (&copy != this)
//	{
//		delete[]ht;
//		m = copy.m;
//		p = copy.p;
//		ht = new ElemType[m];
//		empty = new bool[m];
//
//		for (int pos = 0; pos < m; pos++)
//		{
//			ht[pos] = copy.ht[pos];
//			empty[pos] = copy.empty[pos];
//		}
//	}
//	return *this;
//}