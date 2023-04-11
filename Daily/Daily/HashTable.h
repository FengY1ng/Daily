//#pragma once
//#include "basis.h"
//
//template<class ElemType,class KeyType>
//class HashTable
//{
//protected:
//	ElemType* ht;	//ɢ�б�
//	bool* empty;	//��Ԫ��
//	int m;			//ɢ�б�����
//	int p;			//�����������ĳ���
//
//	int H(const KeyType& key)const;	//ɢ�к���ģ��
//	int Collision(const KeyType& key, int i)const;//�����ͻ�ĺ���ģ��
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
//	m = size;					//��ֵɢ�б�����
//	p = divisor;				//��ֵ����
//	ht = new ElemType[m];		//����洢�ռ�
//	empty = new bool[m];		//����洢�ռ�
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
//	int c = 0;				//��ͻ����
//	pos = H(key);
//
//	while (c < m && !empty[pos] && ht[pos] != key)	//��ͻ����ӦС��m��Ԫ��ht[pos]�ǿգ��ؼ���ֵ����
//	{
//		pos = Collision(key, ++c);				//�����һ��̽���ַ
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
//	int pos;			//Ԫ�ص�λ��
//	if (SearchAssist(key, pos))
//	{
//		e = ht[pos];	//��e����Ԫ��ֵ
//		return true;	//����true
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