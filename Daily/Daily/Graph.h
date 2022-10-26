#pragma once
#include "basis.h"

const int N = 5;

template<class Type>
class AdjMatrixUndirGraph
{
protected:
	int vexNum;//�������
	int edgeNum;//�߸���
	int Martrix[N][N];//�ڽӾ���
	Type elems[N];//��������
	bool tag[N];//ָ���־�����ָ��
	void DestroyAssist();
	void DFS(int v, vector<Type>& vec);//�����������
	void BFS(int v, vector<Type>& vec);//�����������
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
	void SetTag(int v, bool val);//���ö���v�ı�־Ϊval
	vector<Type> DFSTraverse(int v);//������ȱ���
	vector<Type> BFSTraverse(int v);//������ȱ���
	int FirstAdjVex(int v);//ȡ������ĵ�һ���ڽӶ���
	int NextAdjVex(int v1, int v2);//���ض���v1�������v2����һ���ڽӵ�
	void OutputMartrix();//��ʾͼ���ڽӾ���
	~AdjMatrixUndirGraph();
};

template<class Type>
void AdjMatrixUndirGraph<Type>::OutputMartrix()
{
	for (int i = 0; i < this->vexNum; i++)
	{
		for (int j = 0; j < this->vexNum; j++)
		{
			cout << this->Martrix[i][j] << " ";
		}
		cout << endl;
	}
}

template<class Type>
int AdjMatrixUndirGraph<Type>::NextAdjVex(int v1, int v2)
{
	int i;
	for (i = v2 + 1; i < this->vexNum && this->Martrix[v1][i] == 0; i++)
	{

	}
	if (i == this->vexNum)
	{
		return -1;
	}
	return i;
}

template<class Type>
int AdjMatrixUndirGraph<Type>::FirstAdjVex(int v)
{
	int v2;
	for (v2 = 0; v2 < this->vexNum && this->Martrix[v][v2] == 0; v2++)
	{

	}
	return v2;
}

template<class Type>
void AdjMatrixUndirGraph<Type>::DFS(int v, vector<Type>& vec)
{
	int median;
	SetTag(v,true);
	vec.push_back(v);
	if (vec.size() == vexNum)
		return;
	for(median=0;(this->Martrix[v][median]==0 || this->tag[median]==true) && median<this->vexNum;median++)
	{ 
		if (median == vexNum - 1)
		{
			for (int i = 0; i < vexNum; i++)
			{
				if (tag[i] == false)
					median = i;
			}
			break;
		}
	}
	DFS(median, vec);
}

template<class Type>
void AdjMatrixUndirGraph<Type>::BFS(int v, vector<Type>& vec)
{
	SetTag(v, true);
	vec.push_back(v);
	queue<int> q;
	q.push(v);
	while (!q.empty())
	{
		int u, w;
		u = q.front();
		q.pop();
		for (w = FirstAdjVex(u); w >= 0 && w<this->vexNum; w = NextAdjVex(u, w))
		{
			if (!GetTag(w))
			{
				SetTag(w, true);
				vec.push_back(w);
			}
		}
	}
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
		return true;
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
		return true;
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
	if (v < 0 || v >= this->vexNum)
	{
		return true;
	}
	return this->tag[v];
}

template<class Type>
void AdjMatrixUndirGraph<Type>::SetTag(int v, bool val)
{
	this->tag[v] = val;
}

template<class Type>
vector<Type> AdjMatrixUndirGraph<Type>::DFSTraverse(int v)
{
	vector<Type> vec;
	DFS(v, vec);
	return vec;
}

template<class Type>
vector<Type> AdjMatrixUndirGraph<Type>::BFSTraverse(int v)
{
	int i;
	vector<Type> vec;
	for (i = 0; i < this->vexNum; i++)
	{
		SetTag(i, false);
	}
	for (i = 0; i < this->vexNum; i++)
	{
		if (!GetTag(i))
		{
			BFS(i, vec);
		}
	}
	for (i = 0; i < this->vexNum; i++)
	{
		SetTag(i, false);
	}
	return vec;
}

template<class Type>
AdjMatrixUndirGraph<Type>::~AdjMatrixUndirGraph()
{
	this->DestroyAssist();
}