#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

class Graph
{
private:
	struct Table{
		int** edges;
		int vertexCount;
		int currentRow;
		int currentColumn;
	};

	Table graph;
	bool* visited;
	bool cycleDetection(int from, int to);
	void initializeVisited();
	void initializeTable(Table t);
	void print(Table t);

public:
    // constructor and destructor
    Graph(int vc);
    virtual ~Graph();

    // interface functions
    void insert(int value);
	void print();
	void prim();
	void kruskal();
};
#endif
