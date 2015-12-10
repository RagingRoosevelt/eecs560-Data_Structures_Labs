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

void Graph::initializeTable(Table &t)
{
	t.edges = new int* [t.vertexCount];
	for (int i=0; i<t.vertexCount; i++)
	{
		t.edges[i] = new int [t.vertexCount];
        for (int j=0; j<t.vertexCount; j++)
        {
            t.edges[i][j] = 0;
        }
	}
}
void Graph::print()
{
    cout << "Adjacency matrix:" << endl;
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
int Graph::mstCost(Table t)
{
    int sum=0;
    for (int row=0; row<t.vertexCount; row++)
	{
		for (int col=0; col<row; col++)
		{
            if (t.edges[row][col] != 0)
            {
                sum+=t.edges[row][col];
            }
		}
	}
    
    return sum;
}
void Graph::printMST(Table t)
{
    for (int row=0; row<t.vertexCount; row++)
	{
		for (int col=0; col<row; col++)
		{
            if (t.edges[row][col] != 0)
            {
                cout << "(" << col << ", " << row << ")";
            }
		}
	}
    
    cout << "  Cost = " << mstCost(t) << endl;
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

bool Graph::kruskal()
{
    llHeap candidateEdges;
    
    Table mst(graph.vertexCount);
    initializeTable(mst);
    int mstEdgeCount = 0;
    
	initializeVisited();
    

    // build list of candidate edges
	for (int row=0; row<graph.vertexCount; row++)
	{
		for (int col=0; col<row; col++)
		{
            if (graph.edges[row][col] != 0)
            {
                candidateEdges.insert(row, col, graph.edges[row][col]);
            }
		}
	}
    cout << endl << "Candidate edges - (from, to): cost" << endl;
    candidateEdges.print();
    cout << endl;

    int t, f, c;
    while (!candidateEdges.isEmpty() && mstEdgeCount < graph.vertexCount - 1)
    {
        candidateEdges.remove(t, f, c);
        
        if (!cycleDetection(f, t))
        {
            visited[f] = 1;
            visited[t] = 1;
            mst.edges[f][t] = graph.edges[f][t];
            mst.edges[t][f] = graph.edges[t][f];
            mstEdgeCount++;
        }
    }
    
    if (mstEdgeCount == graph.vertexCount - 1)
    {
        
        cout << "Kruskal: ";
        printMST(mst);
        return true;
    }
    else
    {
        cout << "warning: No solution" << endl;
        return false;
    }
}
bool Graph::cycleDetection(int from, int to)
{
	if (visited[from] && visited[to])
		return true;
	else
		return false;
}

bool Graph::prim()
{
    llHeap candidateEdges;
    
    Table mst(graph.vertexCount);
    initializeTable(mst);
    int mstEdgeCount = 0;
    
	initializeVisited();
    
    
}

llHeap::llHeap()
{
    head = NULL;
    size = 0;
}
llHeap::~llHeap()
{
    Node* temp; 
    while (head!=NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}
void llHeap::insert(int t, int f, int c)
{
    Node* cursor = head;
    size ++;
    
    if (head == NULL)
    {
        head = new Node(t, f, c);
    }
    else if (head->cost >= c)
    {
        cursor = head;
        
        head = new Node(t, f, c);
        head->next = cursor;
        
        return;
    }
    
    while (cursor != NULL)
    {
        if (cursor->cost <= c)
        {
            if (cursor->next == NULL)
            {
                cursor->next = new Node(t, f, c);
                return;
            }
            else
            {
                if (cursor->next->cost > c)
                {
                    Node* temp = cursor->next;
                    cursor->next = new Node(t, f, c);
                    cursor->next->next = temp;
                    return;
                }
            }
        }
        cursor = cursor->next;
    }
}
void llHeap::remove(int &t, int &f, int &c)
{
    if (head == NULL)
    {
        t = -1;
        f = -1;
        c = -1;
        
        return;
    }
    
    t = head->to;
    f = head->from;
    c = head->cost;
    
    Node* temp = head;
    head = head->next;
    delete temp;
    
    size --;
}
void llHeap::print()
{
    if (head == NULL)
    {
        cout << "note: Heap is empty" << endl;
        return;
    }
    
    Node* cursor = head;
    while (cursor != NULL)
    {
        cout << "(" << cursor->from << ", " << cursor->to <<  "): " << cursor->cost << endl;
        cursor = cursor->next;
    }
}
bool llHeap::isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
int llHeap::length()
{
    return size;
}