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
        
        Table(int v) : vertexCount(v) {}
        Table() {}
	};

	Table graph;
	bool* visited;
    
	bool cycleDetection(int from, int to);
	void initializeVisited();
	void initializeTable(Table &t);
	void print(Table t);
    void sortArray(int a[][3], int size);
    void printMST(Table t);
    int mstCost(Table t);
    int edgeCount(Table t);

public:
    // constructor and destructor
    Graph(int vc);
    virtual ~Graph();

    // interface functions
    void insert(int value);
	void print();
	bool prim();
	bool kruskal();
};

class llHeap
{
private:
    struct Node{
        Node* next;
        
        int to;
        int from;
        int cost;
        
        Node(int t, int f, int c) :
            to(t), from(f), cost(c), next(NULL) {}
    };
    
    Node* head;
    int size;
    
public:
    llHeap();
    virtual ~llHeap();
    void clear();
    void insert(int t, int f, int c);
    void remove(int &t, int &f, int &c);
    void print();
    bool isEmpty();
    int length();
    bool contains(int t, int f);
};
#endif
