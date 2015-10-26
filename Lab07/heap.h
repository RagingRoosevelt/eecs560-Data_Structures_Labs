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

public:
    // constructor and destructor
    Heap();
    virtual ~Heap();

    // required functions
    bool remove(int value);
    bool remove(int value, bool removeMultiple);
    void levelOrder();
    void insert(int value);
    void deleteMin();
    void deleteMax();

    // helper functions
    void populate(int value);
    void bubbleUpAll();
    void bubbleUp(int index);
    void bubbleDown(int index);
    void sortSubtree(int index, bool sortDown);
    int parent(int index);
    int jthChild(int index, int j);
    int myJ(int index);
    void swapValues(int& val1, int& val2);
    int findSmallestChild(int root);

};
#endif
