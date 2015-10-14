// bst.h
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 02

#ifndef BST_H_
#define BST_H_
#include <iostream>
#include <fstream>
#include <sstream>

class Tree {

private:
    struct bstNode {
        int value;
        bstNode *nodeParent;
        bstNode *nodeLeft;
        bstNode *nodeRight;
        bstNode(int v, bstNode *l, bstNode *r, bstNode *p) :
                value(v), nodeLeft(l), nodeRight(r), nodeParent(p) {}
    };

    struct llNode{
        bstNode *treeNode;
        llNode *nodeNext;
        llNode(llNode *nn, bstNode *bst) :
                nodeNext(nn), treeNode(bst){}
    };

    bstNode *treeRoot;
    llNode *listHead;
    llNode *listTail;
    
    // recursive helper functions
    void inOrderRecursor(bstNode *node);
    void preOrderRecursor(bstNode *node);
    int deleteMinFromSubtree(bstNode *root);
    bstNode * search(int value, bstNode *node);
    bstNode * findMax(bstNode *node);
    bstNode * findMin(bstNode *node);
    bool removeNode(bstNode *node);

public:
    Tree();
    virtual ~Tree();
    
    // required functions
    bool insert(int value);
    bool remove(int value); // needs work
    bool deleteMin();
    bool deleteMax();
    void preOrder();
    void inOrder();
    void levelOrder();
    

};

#endif
