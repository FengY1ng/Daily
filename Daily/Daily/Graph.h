#pragma once
#include "basis.h"

template<class Type>
class AdjMatrixUndirGraph
{
protected:
	int vexNum;//�������
	int edgeNum;//�߸���
	int** Martrix;//�ڽӾ���
	Type* elems;//��������
	bool* tag;//ָ���־�����ָ��
	void DestroyAssist();
	void DFS(int v, vector<Type>& vec)const;//�����������
	void BFS(int v, vector<Type>& vec)const;//�����������
public:
	AdjMatrixUndirGraph(Type data[],int vexNum=DEFAULT_SIZE);//������data����Ϊ���ݣ��������ΪvexNum��ͼ.
	AdjMatrixUndirGraph(int vexNum = DEFAULT_SIZE);//���춥�����ΪvexNum,����Ϊ0��ͼ
	bool GetElement(int v, Type& e)const;//��ȡ����Ԫ��
	bool SetElement(int v, const Type& e);//���ö����Ԫ��ֵ
	Type GetVexData(int v)const;//��ȡ����Ԫ��ֵ
	int GetVexCount()const;//��ȡ�������
	int GetEdgeCount()const;//��ȡ�ߵĸ���
	void InsertEdge(int v1, int v2);//������v1��v2Ϊ����ı�
	void DeleteEdge(int v1, int v2);//ɾ����v1��v2Ϊ����ı�
	bool GetTag(int v)const;//���ض���v�ı�־
	void SetTag(int v, bool val)const;//���ö���v�ı�־Ϊval
	void DFSTraverse(void(*visit)(const Type& e))const;//������ȱ���
	void BFSTraverse(void(*visit)(const Type& e))const;//������ȱ���
	~AdjMatrixUndirGraph();
};

template<class Type>
void AdjMatrixUndirGraph<Type>::DFS(int v, vector<Type>& vec)const
{
	this->Settag(v);
	vec.push_back(tag[v]);
	for (int i = 0; i < this->vexNum && i != v && this->Martrix[v][i] != 0 && this->tag[i] != true; i++)
	{
		DFS(i, vec);
	}
}

template<class Type>
void AdjMatrixUndirGraph<Type>::BFS(int v, vector<Type>& vec)const
{
	SetTag(v);
	vec.push_back(tag[v]);

}

template<class Type>
AdjMatrixUndirGraph<Type>::AdjMatrixUndirGraph(Type data[], int vexNum)
{
	this->vexNum = vexNum;
	this->Martrix = new Type[vexNum][vexNum];
}

template<class Type>
AdjMatrixUndirGraph<Type>::AdjMatrixUndirGraph(int vexNum)
{
	this->vexNum = vexNum;
	for (int i = 0; i < vexNum; i++)
	{
		this->tag[i] = false;
		for (int j = 0; j < vexNum; j++)
		{
			this->Martrix[i][j] = 0;
		}
	}
	this->edgeNum = 0;
}

template<class Type>
void AdjMatrixUndirGraph<Type>::DestroyAssist()
{
	delete[]this->elems;
	delete[]this->tag;

	for (int i = 0; i < vexNum; i++)
	{
		delete[]this->Martrix[i];
	}
	delete[]this->Martrix;
}

template<class Type>
void AdjMatrixUndirGraph<Type>::InsertEdge(int v1, int v2)
{
	if (v1 < 0 || v1 >= vexNum) throw"v1���Ϸ�";
	if (v2 < 0 || v2 >= vexNum)throw"v2���Ϸ�";
	if (v1 == v2)throw"v1���õ���v2";
	if (this->Martrix[v1][v2] == 0 && this->Martrix[v2][v1] == 0)
	{
		this->edgeNum++;
	}
	this->Martrix[v1][v2] = this->Martrix[v2][v1] = 1;
}

template<class Type>
int AdjMatrixUndirGraph<Type>::GetVexCount()const
{
	return this->vexNum;
}

template<class Type>
int AdjMatrixUndirGraph<Type>::GetEdgeCount()const
{
	return this->edgeNum;
}

template<class Type>
bool AdjMatrixUndirGraph<Type>::GetElement(int v, Type& e)const
{
	if (v < 0 && v >= vexNum)
	{
		return false;
	}
	else
	{
		e = this->elems[v];
	}
}

template<class Type>
bool AdjMatrixUndirGraph<Type>::SetElement(int v, const Type& e)
{
	if (v < 0 && v >= this->vexNum)
	{
		return false;
	}
	else
	{
		this->elems[v] = e;
	}
}

template<class Type>
Type AdjMatrixUndirGraph<Type>::GetVexData(int v)const
{
	if (v < 0 && v >= this->vexNum)
	{
		return;
	}
	else
	{
		return this->elems[v];
	}
}

template<class Type>
void AdjMatrixUndirGraph<Type>::DeleteEdge(int v1, int v2)
{
	this->Martrix[v1, v2] = this->Martrix[v2][v1] = 0;
	this->edgeNum--;
}

template<class Type>
bool AdjMatrixUndirGraph<Type>::GetTag(int v)const
{
	return this->tag[v];
}

template<class Type>
void AdjMatrixUndirGraph<Type>::SetTag(int v, bool val)const
{
	this->tag[v] = val;
}

template<class Type>
void AdjMatrixUndirGraph<Type>::DFSTraverse(void(*visit)(const Type& e))const
{

}

template<class Type>
void AdjMatrixUndirGraph<Type>::BFSTraverse(void(*visit)(const Type& e))const
{

}

template<class Type>
AdjMatrixUndirGraph<Type>::~AdjMatrixUndirGraph()
{
	this->DestroyAssist();
}