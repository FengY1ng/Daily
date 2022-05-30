#include <iostream>
#include <string>
#include <conio.h>
#include <cstring>

using namespace std;

int main()
{
	int a[10] = { 17,12,5,36,55,19,3,9,25,41 },*p1=a;
	for (int i = 0; i < 10; i++)
	{
		int *max = p1+i;
		for (int j = i; j < 10; j++)
			if (*(p1+j) > *max)
				max = p1+j;
		int t = *max;
		*max = *(p1+i);
		*(p1+i) = t;
	}
	for (int i = 0; i < 10; i++)
		cout << a[i]<<"\t";
}

//// Project05.cpp : Defines the entry point for the console application.
////
//
//#include "stdafx.h"
//#include <iostream>
//#include <string>
//#include <vector>
//#include <fstream>
//using namespace std;
//
///*
//DirectedGraph类：
//用来表示一个有向图。
//成员变量：
//m_AdjMat：邻接矩阵
//m_ReachabilityMat：可达矩阵
//成员函数：
//DirectedGraph()：默认构造函数，构造一个空图。
//~DirectedGraph()：析构函数
//DirectedGraph(string filepath)：解析文件filepath，构造一个DirectedGraph对象。
//filepath文件格式与项目四相同，但本项目的图为有向图。
//DirectedGraph(const Graph & graph)：复制构造函数
//operator=(const Graph & graph)：赋值运算符
//ClearGraph()：清空图的邻接矩阵和可达矩阵。
//OutputGraph()：输出图的邻接矩阵
//operator*(const DirectedGraph & graph): 乘法运算符，用于实现可达矩阵运算中的矩阵逻辑乘
//DirectedGraph Pow(int power)：邻接矩阵的整数次幂。
//用法如下：
//DirectedGraph a;
//a = a.Pow(5);
//即a的5次幂，相当于a = a * a * a * a * a;
//注意要考虑0次幂的情况。
//该函数适合以递归实现。
//DirectedGraph MatOr(DirectedGraph graph)：矩阵逐元素的逻辑或运算。
//例如：
//1 0
//0 1
//与
//0 1
//1 0
//运算后的结果为
//1 1
//1 1
//void CalcReachabilityMat()：计算可达矩阵，要求该函数基于*运算符和Pow函数实现
//void OutputReachabilityMat()：输出可达矩阵
//IsConnected(int src, int dst)：基于可达矩阵判断从节点src与dst之间是否存在通路，如存在返回真，否则返回假
//
//注意：请不要修改本文件中现有的任何内容，只允许添加各成员函数的定义。如需要，可自行添加任意辅助函数
//*/
//class DirectedGraph
//{
//private:
//	vector<vector<int>> m_AdjMat;
//	vector<vector<int>> m_ReachabilityMat;
//public:
//	DirectedGraph();
//	~DirectedGraph();
//	void ClearGraph();
//	DirectedGraph(string filepath);
//	DirectedGraph(const DirectedGraph& graph);
//	DirectedGraph& operator=(const DirectedGraph& graph);
//	void OutputGraph();
//	DirectedGraph operator*(const DirectedGraph& graph);
//	DirectedGraph Pow(int power);
//	DirectedGraph MatOr(DirectedGraph graph);
//	void CalcReachabilityMat();
//	void OutputReachabilityMat();
//	bool IsConnected(int src, int dst);
//};
//
//
//int main()
//{
//	DirectedGraph dg("../graph.gg");
//	dg.OutputGraph();
//	system("pause");
//
//	DirectedGraph dg2 = dg * dg;
//	cout << "dg * dg:\n";
//	dg2.OutputGraph();
//	system("pause");
//
//	DirectedGraph dg3 = dg.Pow(0);
//	cout << "dg^0\n";
//	dg3.OutputGraph();
//	system("pause");
//	cout << "dg^1\n";
//	dg3 = dg.Pow(1);
//	dg3.OutputGraph();
//	system("pause");
//	cout << "dg^2\n";
//	dg3 = dg.Pow(2);
//	dg3.OutputGraph();
//	system("pause");
//	cout << "dg^3\n";
//	dg3 = dg.Pow(3);
//	dg3.OutputGraph();
//	system("pause");
//
//	dg.CalcReachabilityMat();
//	dg.OutputReachabilityMat();
//	system("pause");
//
//	cout << dg.IsConnected(0, 2) << endl;
//	cout << dg.IsConnected(2, 0) << endl;
//	system("pause");
//	return 0;
//}
//
//DirectedGraph::DirectedGraph()
//{ 
//	vector<vector<int>>(0).swap(this->m_AdjMat);
//	vector<vector<int>>(0).swap(this->m_ReachabilityMat);
//}
//
//DirectedGraph::~DirectedGraph()
//{
//	vector<vector<int>>(0).swap(this->m_AdjMat);
//	vector<vector<int>>(0).swap(this->m_ReachabilityMat);
//}
//
//void DirectedGraph::ClearGraph()
//{
//	vector<vector<int>>(0).swap(this->m_AdjMat);
//	vector<vector<int>>(0).swap(this->m_ReachabilityMat);
//}
//
//DirectedGraph::DirectedGraph(string filepath)
//{
//	ifstream fin;
//	fin.open(filepath);
//	string s;
//	if (!fin.is_open())
//	{
//		cout << "无法打开文件！" << endl << "错误原因：文件名或文件路径错误!";
//		exit(1);
//	}
//	getline(fin, s);
//	int row = s.at(0) - '0';
//	vector<vector<int>>(row, vector<int>(row, 0)).swap(this->m_AdjMat);
//	getline(fin, s);
//	int line = s.at(0) - '0';
//	for (int i = 0; i < line; i++)
//	{
//		getline(fin, s);
//		this->m_AdjMat[s.at(0)-'0'][s.at(2)-'0'] = 1;
//	}
//}
//
//DirectedGraph::DirectedGraph(const DirectedGraph& graph)
//{
//	this->m_AdjMat = graph.m_AdjMat;
//	this->m_ReachabilityMat = graph.m_ReachabilityMat;
//}
//
//DirectedGraph& DirectedGraph::operator=(const DirectedGraph& graph)
//{
//	this->m_AdjMat = graph.m_AdjMat;
//	this->m_ReachabilityMat = graph.m_ReachabilityMat;
//	return *this;
//}
//
//void DirectedGraph::OutputGraph()
//{
//	cout << "当前图的邻接矩阵为:" << endl;
//	for (int i = 0; i < this->m_AdjMat.size(); i++)
//	{
//		for (int j = 0; j < this->m_AdjMat.size(); j++)
//			cout << this->m_AdjMat[i][j] << "\t";
//		cout << endl;
//	}
//}
//
//DirectedGraph DirectedGraph::operator*(const DirectedGraph& graph)
//{
//	if (this->m_AdjMat.size() != graph.m_AdjMat.size())
//	{
//		cout << "无法进行乘运算!" << endl << "错误原因:两矩阵维数不同";
//		return DirectedGraph();
//	}
//	DirectedGraph multiplication;
//	vector<vector<int>>(this->m_AdjMat.size(), vector<int>(this->m_AdjMat.size(), 0)).swap(multiplication.m_AdjMat);
//	for (int i = 0; i < this->m_AdjMat.size(); i++)
//		for (int j = 0; j < this->m_AdjMat.size(); j++)
//			for (int k = 0; k < this->m_AdjMat.size(); k++)
//			{
//				multiplication.m_AdjMat[i][j] += this->m_AdjMat[i][k] * graph.m_AdjMat[k][j];
//				multiplication.m_AdjMat[i][j] = multiplication.m_AdjMat[i][j] > 0 ? 1 : 0;
//			}
//	return multiplication;
//}
//
//DirectedGraph DirectedGraph::Pow(int power)
//{
//	DirectedGraph pow;
//	vector<vector<int>>(this->m_AdjMat.size(), vector<int>(this->m_AdjMat.size(), 0)).swap(pow.m_AdjMat);
//	if (power == 0)
//	{
//		for (int i = 0; i < this->m_AdjMat.size(); i++)
//			pow.m_AdjMat[i][i] = 1;
//		return pow;
//	}
//	return Pow(power - 1) * (*this);
//}
//
//DirectedGraph DirectedGraph::MatOr(DirectedGraph graph)
//{
//	if (this->m_AdjMat.size() != graph.m_AdjMat.size())
//	{
//		cout << "无法进行或运算!" << endl << "错误原因:两矩阵维数不同";
//		exit(1);
//	}
//	DirectedGraph median;
//	vector<vector<int>>(this->m_AdjMat.size(), vector<int>(this->m_AdjMat.size(), 0)).swap(median.m_AdjMat);
//	for (int i = 0; i < this->m_AdjMat.size(); i++)
//		for (int j = 0; j < this->m_AdjMat.size(); j++)
//			median.m_AdjMat[i][j] = (this->m_AdjMat[i][j] || graph.m_AdjMat[i][j]) ? 1 : 0;
//	return median;
//}
//
//void DirectedGraph::CalcReachabilityMat()
//{
//	DirectedGraph cal=Pow(0);
//	for (int i = 0; i < this->m_AdjMat.size(); i++)
//		cal = cal.MatOr(Pow(i));
//	this->m_ReachabilityMat = cal.m_AdjMat;
//}
//
//void DirectedGraph::OutputReachabilityMat()
//{
//	cout << "当前图的可达矩阵:" << endl;
//	for (int i = 0; i < this->m_ReachabilityMat.size(); i++)
//	{
//		for (int j = 0; j < this->m_ReachabilityMat.size(); j++)
//			cout << this->m_ReachabilityMat[i][j] << "\t";
//		cout << endl;
//	}
//}
//
//bool DirectedGraph::IsConnected(int src, int dst)
//{
//	return this->m_ReachabilityMat[src][dst]?true:false;
//}
