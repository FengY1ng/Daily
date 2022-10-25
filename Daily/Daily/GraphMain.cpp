#include "Graph.h"
#include "Myusers.h";

typedef int TEST;
const int N = 5;

int main()
{
	TEST median;
	AdjMatrixUndirGraph<TEST> graph(N);
	vector<TEST> traverse;
	for (int i = 0; i < N; i++)
		graph.SetElement(i, i);
	GraphEdge(graph);
	graph.GetElement(1, median);
	cout << median;
}