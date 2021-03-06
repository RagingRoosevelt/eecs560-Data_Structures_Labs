#ifndef HEAP_SKEW_H
#define HEAP_SKEW_H

#include <iostream>

using namespace std;

class HeapSkew
{
private:
    // node
    struct Node {
        long int value;

        Node *childLeft;
        Node *childRight;

        Node(long int v, Node *left, Node *right) :
            value(v), childLeft(left), childRight(right) {
        }
    };

    struct Queue{
        Queue *llNext;
        Node *node;
        long int level;
        long int prev_level;

        Queue(Queue *q, Node *n, long int l, long int pl) :
            llNext(q), node(n), level(l), prev_level(pl) {
        }
    };

    // heap (array-based)
    Node *heapHead;
    
    // assistance functions;
    void deconstructorAssist(Node* root);
    void nodeSwap(Node *&node1, Node *&node2);
    Node * merge(Node *root1, Node *root2);
    void dfsPrint(Node* root, char method);

public:
    // constructor and destructor
    HeapSkew();
    virtual ~HeapSkew();

    // required functions
    void levelOrder();

    void insert(long int value);
    void deleteMin();
    void inorder();
    void preorder();

};
#endif
