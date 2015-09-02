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



bool List::erase(int data) 
{ // use the recursor to find the first occurrence of the value, then delete it
	return eraseRecursor(data, firstNode);
}
bool List::eraseRecursor(int data, List::Node*& node) 
{ // check for an empty list
	if (node == NULL) 
    {
		return false;
	} 
    else if (node->data == data) 
    { // check if current node has the data we're looking for, if so delete it and patch list linking
		Node* removedNode = node;
		node = removedNode->nextNode;
		delete removedNode;
		return true;
	} 
    else if (node->nextNode != NULL && node->nextNode->data == data) 
    { // check if the next node has the data we're looking for
		Node* removedNode = node->nextNode;
		node->nextNode = removedNode->nextNode;

		delete removedNode;
		return true;
	}
    // move on to the next node
	return eraseRecursor(data, node->nextNode);
}



void List::insert(int data) // detect if it's an empty list
{
	if (firstNode == NULL)
    { // empty list, create first entry
		firstNode = new Node(data, NULL);
    }
	else
    { // not empty list, use recursor to find the end, insert data
		insertRecursor(data, firstNode);
    }

}
void List::insertRecursor(int data, List::Node* node) // find the end of the list and then insert the data
{
	if (node == NULL) 
    { // if the list is empty or we've reached the end
		node = new Node(data, NULL);
	}
    else if (node->nextNode == NULL) 
    { // if the next node doesn't exist, create it and link the current node to it
		node->nextNode = new Node(data, NULL);
	} 
    else 
    {
        // move on to the next node
		insertRecursor(data, node->nextNode);
	}
}



bool List::isEmpty() 
{ 
	if (firstNode == NULL) // check if the fist node exists
    {
        return true;
    }
    else
    {
        return false;
    }
}



void List::print() 
{
    // starting at the first node
	Node* currentNode = firstNode;
	while (currentNode != NULL) 
    { // cycle through nodes and display their data until the "nextNode" property returns empty
		cout << " " << currentNode->data;
		currentNode = currentNode->nextNode;
	}
	delete currentNode;
    cout << endl;
}



List::Node* List::find(int data) 
{ // call the recursive function
	return findRecursor(data, firstNode);
}
List::Node* List::findRecursor(int data, List::Node* node) 
{
	if (node == NULL)
    { // if the list is empty or we reach the end, return a "node not found"
		return NULL;
	} 
    else if (node->data == data) 
    { // if the data is found, return the node location
		return node;
	}

    // move on to the next node
	return findRecursor(data, node->nextNode);
}