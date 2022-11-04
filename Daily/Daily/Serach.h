#pragma once
#include "basis.h";

typedef int Type;

template<class ElemType,class KeyType>    
int SqSerach(vector<ElemType> elem, KeyType key)//À≥–Ú≤È’“
{
	for (int i = 0; i<elem.size() && elem[i] != key; i++)
	{
		if (i < elem.size())
		{
			return i;
		}
		else
		{
			return -1;
		}
	}
}

template<class ElemType,class KeyType>
int BinSerach(vector<ElemType> elem, KeyType key)//’€∞Î≤È’“∑®
{
	vector<Type>median;
	for (int i = 0; i < elem.size(); i++)
	{
		median.push_back(i);
	}
	for (int i = 0; i < elem.size(); i++)
	{
		int j;
		int min = elem[i];
		for (j = i + 1; j < elem.size(); j++)
		{
			if (elem[j] < min)
			{
				min = elem[j];
			}
		}
		int t = elem[i];
		elem[i] = elem[j];
		elem[j] = t;
		t = median[i];
		median[j] = median[i];
		median[i] = t;
	}
	int low = 0, high = elem.size() - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
			if (key == elem[mid])
			{
				return median[mid];
			}
			else if (key < elem[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		return -1;
	}
}