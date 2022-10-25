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
	mutable bool* tag;//ָ���־�����ָ��
	void DestroyAssist();
	void DFS(int v, vector<Type>& vec)const;//�����������
	void BFS(int v, vector<Type>& vec)const;//�����������
public:
	AdjMatrixUndirGraph(Type data[],int vexNum=DEFAULT_SIZE);//������data����Ϊ���ݣ��������ΪvexNum��ͼ.
	AdjMatrixUndirGraph(int vexNum = DEFAULT_SIZE);//���춥�����ΪvexNum,����Ϊ0��ͼ
	bool GetElement(int v, Type& e)const;//�󶥵�Ԫ��
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