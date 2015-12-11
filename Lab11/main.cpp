// main.cpp
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 10

#include "graph.h"
#include <fstream>
#include <iostream>

#include <cstdlib>
#include <ctime>
#include <vector>

int menu(int type);
int randi(int max);

using namespace std;
int main() {
    
    ifstream infile;
    
	int testCases;
	int vertices;
	int val;
    
    infile.open("data1.txt");
    for (int fileNo = 1; fileNo <= 2; fileNo++)
    {
        cout << endl << endl;
        cout << "..................................." << endl
             << "Output for 'data" << fileNo << ".txt':" << endl;
        if (infile.fail())
        {
            cout << "warning: Failed to open 'data" << fileNo << ".txt'." << endl;
            return 0;
        }
        
        infile >> testCases;
        
        for (int grph=1; grph <= testCases; grph++)
        {
            infile >> vertices;
            Graph graph(vertices);
            
            for (int i=0; i<vertices*vertices; i++)
            {
                infile >> val;
                graph.insert(val);
            }
            
            cout << "Graph " << grph << ": " << endl;
            graph.print();
            graph.kruskal();
            graph.prim();
            cout << endl << endl;
        }
        
        infile.close();
        infile.open("data2.txt");
    }


    return 0;
}