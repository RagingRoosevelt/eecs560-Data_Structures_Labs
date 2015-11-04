#ifndef HEAP_H
#define HEAP_H

#include <iostream>

using namespace std;

class Heap
{
private:
    // heap (array-based)
    int heap[500];
    int lastIndex;
    int noChildren;
    
    // heapify functions
    void trickleDown(int index);
    void trickleDownMin(int index);
    void trickleDownMax(int index);
    void bubbleUp(int index);
    void bubbleUpMin(int index);
    void bubbleUpMax(int index);
    
    // Helper functions for getting
    // info based on given index or value
    int findSmallestGrandchild(int index);
    int findSmallestChild(int index);
    int findLargestGrandchild(int index);
    int findLargestChild(int index);
    void swapValues(int& val1, int& val2);
    bool minLevelCheck(int index);
    int parent(int index);
    int jthChild(int index, int j);
    int myJ(int index);
    bool isEOL(int value);
    int findValue(int value);

public:
    // constructor and destructor
    Heap();
    virtual ~Heap();

    // required functions
    void levelOrder();
    void insert(int value);
    bool deleteMin();
    bool deleteMax();
    bool remove(int value);
    void populate(int value);
    void trickleDown();

};
#endif
