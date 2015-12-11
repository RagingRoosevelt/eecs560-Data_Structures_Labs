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
{ // sets the visited flags to false
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
{ // sets the pointer rows and sets all the default costs to zero
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
{ // calls the print function on the graph
    cout << "Adjacency matrix:" << endl;
	print(graph);
}
void Graph::print(Table t)
{ // prints the adjacency matrix t
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
{ // calculates the sum of the costs of the edges in the minimum spanning tree t
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
{ // prints the edges and cost of the minimum spanning tree t
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
{ // inserts a cost into the adjacency matrix graph
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
{ // computes the MST solution using Kruskal's algorithm
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
    // cout << endl << "Candidate edges - (from, to): cost" << endl;
    // candidateEdges.print();
    cout << endl;

    int t, f, c;
    while (!candidateEdges.isEmpty() && mstEdgeCount < graph.vertexCount - 1)
    {
        //cout << "====================" << endl;
        //candidateEdges.print();
        
        candidateEdges.remove(t, f, c);
        
        if (!cycleDetection(f, t))
        {
            //cout << "    picked (" << f << ", " << t << "): " << c << endl;
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
{ // return true if a cycle will be created, false otherwise
	if (visited[from] && visited[to])
		return true;
	else
		return false;
}

bool Graph::prim()
{ // computes the MST solution using Prim's algorithm
    llHeap candidateEdges;
    
    Table mst(graph.vertexCount);
    initializeTable(mst);
    int mstEdgeCount = 0;
    
	initializeVisited();

    
    visited[0] = true;
    do
    {
        // update pool of candidate edges
        candidateEdges.clear();
        for (int from=0; from<graph.vertexCount; from++)
        {
            if (visited[from])
            {
                for (int to=0; to<graph.vertexCount; to++)
                {
                    // if the edge doesn't have cost zero and doesn't form a cycle, 
                    //      add it to the candidate pool
                    if (graph.edges[from][to] != 0 && !cycleDetection(from, to))
                    {
                        candidateEdges.insert(to, from, graph.edges[from][to]);
                    }
                }
            }
        }
        
        
        //cout << "====================" << endl;
        //candidateEdges.print();
        int t, f, c;
        candidateEdges.remove(t,f,c);
        //cout << "    picked (" << f << ", " << t << "): " << c << endl;
        if (t != -1 && f != -1)
        {
            mst.edges[f][t] = c;
            mst.edges[t][f] = c;
            visited[t] = 1;
            visited[f] = 1;
        }
        else
        {
            break;
        }
        
    } while (!candidateEdges.isEmpty() && edgeCount(mst) < graph.vertexCount-1);
    
    if (edgeCount(mst) == graph.vertexCount - 1)
    {
        cout << "Prim: ";
        printMST(mst);
        return true;
    }
    else
    {
        cout << "warning: No solution" << endl;
        return false;
    }
}
int Graph::edgeCount(Table t)
{ // counts the number edges in adjacency matrix t
    int sum = 0;
    for (int row=0; row<t.vertexCount; row++)
	{
		for (int col=0; col<row; col++)
		{
            if (t.edges[row][col] != 0)
            {
                sum++;
            }
		}
	}
    return sum;
}


///////////////////////////
// Heap Member Functions //
///////////////////////////
llHeap::llHeap()
{
    head = NULL;
    size = 0;
}
llHeap::~llHeap()
{
    clear();
}
void llHeap::clear()
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
    // check if edge was already inserted
    if (contains(t,f))
        return;
    
    
    Node* cursor = head;
    size ++;
    
    if (head == NULL)
    {
        head = new Node(t, f, c);
    }
    else if (head->cost > c)
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
bool llHeap::contains(int t, int f)
{
    Node* cursor = head;
    while (cursor != NULL)
    {
        if (cursor->to == t && cursor->from == f)
        {
            return true;
        }
        else if (cursor->to == f && cursor->from == t)
        {
            return true;
        }
        
        cursor = cursor->next;
    }
    
    return false;
}
