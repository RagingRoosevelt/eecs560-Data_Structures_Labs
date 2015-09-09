// tree.h
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 02

#ifndef TREE_H_
#define TREE_H_
#include <iostream>
#include <fstream>
#include <sstream>

class Tree {

private:
	struct Node {
		int data;
		bool isLeaf;
		Node *nodeLeft;
		Node *nodeRight;
		Node(int d, Node *l, Node *r) :
				data(d), nodeLeft(l), nodeRight(r) {
		}
	};
	Node *nodeRoot;
    int leafCount;

    // helping functions using recursion
    void deleteNodeRecursor(Node* node);
    int largestRecursor(Node* nodeSelf, Node* nodeLeft, Node* nodeRight);
    void printRecursor(Node* node);
    void countLeavesRecursor(Node* node);
    void insertRecursor(Node* node, int levelCurrent, int levelTarget, std::ifstream& dataFile);

public:
	Tree();
	virtual ~Tree();
    void build();
    void largest();
    void leaves();
    void print();

};

#endif
