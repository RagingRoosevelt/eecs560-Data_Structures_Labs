// list.cpp
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 01

#include "list.h"
using namespace std;

List::List() {

	firstNode = NULL;
}



List::~List() 
{
	Node* currentNode = firstNode; // run through the list and delete entries
	while (currentNode != NULL) {
		Node* previousNode = currentNode;
		currentNode = currentNode->nextNode;
		delete previousNode;
	}
	firstNode = NULL;
}



int List::largest(){
    return largestRecursor(nodeRoot, nodeRoot->nodeLeft, nodeRoot->nodeRight);
}
int List::largestRecursor(List::Node* nodeSelf, List::Node* nodeLeft, List::Node* nodeRight){
    int self  = nodeSelf->data;
    int left  = 0;// assume the left node doesn't exist
    int right = 0;// assume the right node doesn't exist
    
    if (nodeLeft != NULL)
    { // if the left node exists, 
        left = largestRecursor(nodeLeft, nodeLeft->nodeLeft, nodeLeft->nodeRight);
    }
    
    if (nodeRight != NULL) {
        right = largestRecursor(nodeRight, nodeRight->nodeLeft, nodeRight->nodeRight);
    }
    
    return max(left, max(self, right));
}

void List::build()
{
// as we create a row of nodes, we keep track of all non-NULL nodes in order to 
// know which nodes need children when we create the next row
}
