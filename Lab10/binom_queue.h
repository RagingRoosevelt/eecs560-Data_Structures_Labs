#ifndef BINOM_QUEUE_H
#define BINOM_QUEUE_H

#include <iostream>

using namespace std;

class BinomQueue
{
private:
    struct Node{
        int order;
        int key;
        Node* fChild;
        Node* rSib;
        
        Node(int k, int o, Node* s, Node* f) :
        key(k), order(o), rSib(s), fChild(f) {}
    };
    
    int treecount;
    Node** queue;
    
    // utility functions
    Node** mergeQueues(Node** queueOrig, Node** queueTemp);
    Node* mergeTrees(Node* root1, Node* root2);
    void nodeSwap(Node* &node1, Node* &node2);
    void levelOrderTree(Node* root);
    

public:
    // constructor and destructor
    BinomQueue();
    virtual ~BinomQueue();
    
    // interface functions
    void insert(int value);
    void levelOrder();
};
#endif
