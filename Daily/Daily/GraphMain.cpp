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
//	cout << "ʵ������ͼ�����ɹ�" << endl;
//	Sleep(1000);
//	while (1)
//	{
//		system("cls");
//		cout << "��ѡ��Ҫ���в�������Ӧ�����:" << endl
//			<< "1.��ʾͼ���ڽӾ���" << endl
//			<< "2.��ʾͼ��������ȱ�����Ӧ�Ľ��" << endl
//			<< "3.��ʾͼ�Ĺ�����ȱ�����Ӧ�Ľ��" << endl
//			<< "4.��������" << endl;
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
//			cout << "��ͼ��������ȱ����Ľ��Ϊ��";
//			for (int i = 0; i < N; i++)
//				cout << dfs[i] << " ";
//			cout << endl;
//			Sleep(3000);
//		}
//			break;
//		case '3':
//		{
//			vector<int> bfs = graph.BFSTraverse(0);
//			cout << "��ͼ�Ĺ�����ȱ����Ľ��Ϊ��";
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