////main.cpp
//#include "Graph.h"
//#include "Myusers.h";
//
//typedef int TEST;
//int main()
//{
//	int choose;
//	AdjMatrixUndirGraph<TEST> graph(N);
//	vector<TEST> traverse;
//	for (int i = 0; i < N; i++)
//		graph.SetElement(i, i);
//	GraphEdge(graph);
//	cout << "实例无向图构建成功" << endl;
//	Sleep(1000);
//	while (1)
//	{
//		system("cls");
//		cout << "请选择要进行操作所对应的序号:" << endl
//			<< "1.显示图的邻接矩阵" << endl
//			<< "2.显示图的深度优先遍历对应的结果" << endl
//			<< "3.显示图的广度优先遍历对应的结果" << endl
//			<< "4.结束程序" << endl;
//		choose = _getch();
//		switch (choose)
//		{
//		case '1':
//			graph.OutputMartrix();
//			Sleep(3000);
//			break;
//		case '2':
//		{
//			vector<int> dfs = graph.DFSTraverse(0);
//			cout << "该图的深度优先遍历的结果为：";
//			for (int i = 0; i < N; i++)
//				cout << dfs[i] << " ";
//			cout << endl;
//			Sleep(3000);
//		}
//			break;
//		case '3':
//		{
//			vector<int> bfs = graph.BFSTraverse(0);
//			cout << "该图的广度优先遍历的结果为：";
//			for (int i = 0; i < N; i++)
//				cout << bfs[i] << " ";
//			cout << endl;
//			Sleep(5000);
//		}
//			break;
//		case '4':
//			return 0;
//		}
//	}
//}