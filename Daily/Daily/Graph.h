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
	mutable bool* tag;//指向标志数组的指针
	void DestroyAssist();
	void DFS(int v, vector<Type>& vec)const;//深度优先搜索
	void BFS(int v, vector<Type>& vec)const;//广度优先搜索
public:
	AdjMatrixUndirGraph(Type data[],int vexNum=DEFAULT_SIZE);//创建以data数组为数据，顶点个数为vexNum的图.
	AdjMatrixUndirGraph(int vexNum = DEFAULT_SIZE);//构造顶点个数为vexNum,边数为0的图
	bool GetElement(int v, Type& e)const;//求顶点元素
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