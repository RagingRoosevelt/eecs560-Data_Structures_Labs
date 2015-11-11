#ifndef HEAP_LEFTIST_H
#define HEAP_LEFTIST_H

#include <iostream>

using namespace std;

class HeapLeftist
{
private:
    // node
    struct Node {
        long int value;
        long int rank;

        Node *childLeft;
        Node *childRight;

        Node(long int v, long int r, Node *left, Node *right) :
            value(v), rank(r), childLeft(left), childRight(right) {
        }
    };

    struct Queue{
        Queue *llNext;
        Node *node;

        Queue(Queue *l, Node *n) :
            llNext(l), node(n) {
        }
    };

    // heap (array-based)
    Node *heapHead;

public:
    // constructor and destructor
    HeapLeftist();
    virtual ~HeapLeftist();

    // required functions
    void levelOrder();

    void merge(int value);
    Node * merge(Node *root1, Node *root2);
    void nodeSwap(Node *&node1, Node *&node2);

};
#endif
