// tree.h
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 01

#ifndef TREE_H_
#define TREE_H_
#include <iostream>

class Tree {

private:
	struct Node {
		int data;
		Node *nodeLeft;
		Node *nodeRight;
		Node(int d, Node *l, Node *r) :
				data(d), nodeLeft(l), nodeRight(r) {
		}
	};
	Node *nodeRoot;
    
    int leafCount = 0;    
    
    void deleteNodeRecursor(Node* node);
    int largestRecursor(Node* nodeSelf, Node* nodeLeft, Node* nodeRight);
    void printRecursor(Node* node);
    void countLeavesRecursor(Node* node);
    void insert(data, ) // working on this

public:
	Tree();
	virtual ~Tree();
    void build(int ); // working on this
    void largest();
    void leaves();
    void print();
    
};

#endif
