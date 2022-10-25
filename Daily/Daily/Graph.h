#pragma once
#include "basis.h"

template<class Type>
class AdjMatrixUndirGraph
{
protected:
	int vexNum;//顶点个数
	int edgeNum;//边个数
	int** Martrix;//邻接矩阵
	Type* elems;//顶点数据
	bool* tag;//指向标志数组的指针
	void DestroyAssist();
	void DFS(int v, vector<Type>& vec)const;//深度优先搜索
	void BFS(int v, vector<Type>& vec)const;//广度优先搜索
public:
	AdjMatrixUndirGraph(Type data[],int vexNum=DEFAULT_SIZE);//创建以data数组为数据，顶点个数为vexNum的图.
	AdjMatrixUndirGraph(int vexNum = DEFAULT_SIZE);//构造顶点个数为vexNum,边数为0的图
	bool GetElement(int v, Type& e)const;//获取顶点元素
	bool SetElement(int v, const Type& e);//设置顶点的元素值
	Type GetVexData(int v)const;//获取顶点元素值
	int GetVexCount()const;//获取顶点个数
	int GetEdgeCount()const;//获取边的个数
	void InsertEdge(int v1, int v2);//插入以v1，v2为顶点的边
	void DeleteEdge(int v1, int v2);//删除以v1，v2为顶点的边
	bool GetTag(int v)const;//返回顶点v的标志
	void SetTag(int v, bool val)const;//设置顶点v的标志为val
	void DFSTraverse(void(*visit)(const Type& e))const;//深度优先遍历
	void BFSTraverse(void(*visit)(const Type& e))const;//广度优先遍历
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
	if (v1 < 0 || v1 >= vexNum) throw"v1不合法";
	if (v2 < 0 || v2 >= vexNum)throw"v2不合法";
	if (v1 == v2)throw"v1不得等于v2";
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