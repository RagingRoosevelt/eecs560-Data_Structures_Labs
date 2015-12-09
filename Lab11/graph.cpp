#include "graph.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


Graph::Graph(int vc)
{
	graph.vertexCount = vc;
	initializeTable(graph);

	visited = new bool [graph.vertexCount];
	initializeVisited();



	graph.currentRow = 0;
	graph.currentColumn = 0;
}
void Graph::initializeVisited()
{
	for (int i=0; i<graph.vertexCount; i++)
	{
		visited[i] = false;
	}
}
Graph::~Graph()
{
    for (int i=0; i<graph.vertexCount; i++)
	{
		delete [] graph.edges[i];
	}

	delete [] graph.edges;
}

void Graph::initializeTable(Table t)
{
	graph.edges = new int* [graph.vertexCount];
	for (int i=0; i<graph.vertexCount; i++)
	{
		graph.edges[i] = new int [graph.vertexCount];
	}
}
void Graph::print()
{
	print(graph);
}
void Graph::print(Table t)
{
	for (int row=0; row<t.vertexCount; row++)
	{
		for (int col=0; col<t.vertexCount; col++)
		{
			cout << setw(4) << t.edges[row][col];
			if (col+1 == t.vertexCount)
			{
				cout << endl;
			}
			else
			{
				cout << " ";
			}
		}
	}
}

void Graph::insert(int value)
{
	if (graph.currentColumn + graph.currentRow == -2)
	{
		cout << "warning: Adjacency matrix is already full" << endl;
		return;
	}

	graph.edges[graph.currentRow][graph.currentColumn] = value;

	graph.currentColumn += 1;
	if (graph.currentColumn >= graph.vertexCount)
	{
		graph.currentColumn = 0;
		graph.currentRow += 1;
	}
	if (graph.currentRow >= graph.vertexCount)
	{
		graph.currentColumn = -1;
		graph.currentRow = -1;
	}
}

void Graph::kruskal()
{
	initializeVisited();

	for (int col=0; col<graph.vertexCount; col++)
	{
		for (int row=0; row<graph.vertexCount; row++)
		{

		}
	}


}

bool Graph::cycleDetection(int from, int to)
{
	if (visited[from] && visited[to])
		return true;
	else
		return false;
}
