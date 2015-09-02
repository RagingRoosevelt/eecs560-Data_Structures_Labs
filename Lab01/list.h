// list.h
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 01

#ifndef LIST_H_
#define LIST_H_
#include <iostream>

class List {

private:
    // node structure.  stores node data and info about next node in list
	struct Node {
		int data;
		Node *nextNode;
		Node(int d, Node *n) :
				data(d), nextNode(n) {
		}
	};
	Node *firstNode;

    // supporting methods that will cycle through nodes
	void insertRecursor(int data, Node* node);
	bool eraseRecursor(int data, Node*& node);
	Node* findRecursor(int data, Node* node);

public:
    // constructor, destructor
	List();
	virtual ~List();
    // menu back-end methods for list management
	void insert(int data);
	bool erase(int data);
	void print();
    
	bool isEmpty();
	Node* find(int data);
};

#endif