#include "Graph.h"

template<class Type>
void AdjMatrixUndirGraph<Type>::DFS(int v, vector<Type> &vec)const
{
	this-> Settag(v);
	vec.push_back(tag[v]);
	for (int i = 0; i < this->vexNum && i != v && this->Martrix[v][i]!=0 && this->tag!=true; i++)
	{
		DFS(i, vec);
	}
}

template<class Type>
void AdjMatrixUndirGraph<Type>::BFS(int v, vector<Type> &vec)const
{
	
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
	this->Martrix = new Type[vexNum][vexNum]{0};
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
	if (this->Martrix[v1][v2] == 0 && this->Matrix[v2][v1] == 0)
	{
		this->edgeNum++;
	}
	Matrix[v1][v2] = Matrix[v2][v1] = 1;
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

 }

 template<class Type>
 bool AdjMatrixUndirGraph<Type>::SetElement(int v, const Type& e)
 {

 }

 template<class Type>
 Type AdjMatrixUndirGraph<Type>::GetVexData(int v)const
 {

 }

 template<class Type>
 void AdjMatrixUndirGraph<Type>::DeleteEdge(int v1, int v2)
 {

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