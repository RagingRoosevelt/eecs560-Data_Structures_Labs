// Tree.cpp
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 01

#include "tree.h"
using namespace std;

Tree::Tree() {
	nodeRoot = NULL;
}


Tree::~Tree() {
	deleteNodeRecursor(nodeRoot);
}
void Tree::deleteNodeRecursor(Tree::Node* node){
    if (node!=NULL)
    {
        deleteNodeRecursor(node->nodeLeft);
        deleteNodeRecursor(node->nodeRight);
        delete node;
    }
}


void Tree::largest(){
    cout << "Largest element: " 
         << largestRecursor(nodeRoot, nodeRoot->nodeLeft, nodeRoot->nodeRight);
}
int Tree::largestRecursor(Tree::Node* nodeSelf, Tree::Node* nodeLeft, Tree::Node* nodeRight){
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


void Tree::print(){
    cout << "Inorder: "
    printRecursor(nodeRoot)
}
void Tree::printRecursor(Tree::Node* node){
    if (node->nodeLeft != NULL)
    {
        printRecursor(node->nodeLeft);
    }
    cout << node->data << " ";
    if (node->nodeRight != NULL)
    {
        printRecursor(node->nodeRight);
    }
}


void leaves(){
    countLeavesRecursor(nodeRoot);
    cout << "Number of leaves: " 
         << leafCount;
}
void countLeavesRecursor(Tree::Node* node){
    if (node->nodeLeft == NULL) && (node->nodeRight == NULL)
    {
        leafCount++;
    }
    else
    {
        if (node->nodeLeft != NULL)
        {
            countLeavesRecursor(node->nodeLeft);
        }
        if (node->nodeRight != NULL)
        {
            countLeavesRecursor(node->nodeRight);
        }
    }
}


void Tree::build(int values[]){
// as we create a row of nodes, we keep track of all non-NULL nodes in order to 
// know which nodes need children when we create the next row
    if (nodeRoot == Null)
    {
        nodeRoot = new Node(values[0], NULL);
    }
    else
    {
        
    }
}
void Tree::insert(data, Tree::Node* node){
    //something
}
