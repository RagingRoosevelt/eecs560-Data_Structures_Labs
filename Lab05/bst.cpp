// bst.cpp
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 02

#include "bst.h"
#include <iostream>

using namespace std;

// construct the tree
Tree::Tree() {
    treeRoot = NULL;
    
    listHead = NULL;
    listTail = NULL;
}


// destroy the tree
Tree::~Tree() {
    if (treeRoot != NULL)
    {
        listHead = new llNode(NULL, treeRoot);
        listTail = listHead;
        
        while (listHead != NULL)
        {
            if (listHead->treeNode->nodeLeft != NULL)
            {
                listTail->nodeNext = new llNode(NULL, listHead->treeNode->nodeLeft);
                listTail = listTail->nodeNext;
            }
            if (listHead->treeNode->nodeRight != NULL)
            {
                listTail->nodeNext = new llNode(NULL, listHead->treeNode->nodeRight);
                listTail = listTail->nodeNext;
            }
            
            delete listHead->treeNode;
            
            llNode *temp = listHead;
            if (listHead->nodeNext != NULL)
            {
                listHead = listHead->nodeNext;
                if (temp != NULL)
                {
                    delete temp;
                }
            }
            else
            {
                // delete the linked list as we leave this function
                while (listHead->nodeNext != NULL)
                {
                    listHead = listHead->nodeNext;
                    delete temp;
                    llNode *temp = listHead;
                }
                return;
            }
        }
    }
}


void Tree::levelOrder()
{
    cout << "levelorder: ";
    if (treeRoot != NULL)
    {
        listHead = new llNode(NULL, treeRoot);
        listTail = listHead;
        
        while (listHead != NULL)
        {
            cout << listHead->treeNode->value << " ";
            /*cout << endl << listHead->treeNode->value << "(" << listHead->treeNode 
                 << ", par: " << listHead->treeNode->nodeParent << ")" << endl
                 << "    left : " << listHead->treeNode->nodeLeft << endl
                 << "    right: " << listHead->treeNode->nodeRight << endl;*/
            
            if (listHead->treeNode->nodeLeft != NULL)
            {
                listTail->nodeNext = new llNode(NULL, listHead->treeNode->nodeLeft);
                listTail = listTail->nodeNext;
            }
            if (listHead->treeNode->nodeRight != NULL)
            {
                listTail->nodeNext = new llNode(NULL, listHead->treeNode->nodeRight);
                listTail = listTail->nodeNext;
            }
            
            
            llNode *temp = listHead;
            if (listHead->nodeNext != NULL)
            {
                listHead = listHead->nodeNext;
                if (temp != NULL)
                {
                    delete temp;
                }
            }
            else
            {
                // delete the linked list as we leave this function
                while (listHead->nodeNext != NULL)
                {
                    listHead = listHead->nodeNext;
                    delete temp;
                    llNode *temp = listHead;
                }
                cout << endl;
                return;
            }
        }
    }
}


void Tree::preOrder()
{
    cout << "preorder: ";
    preOrderRecursor(treeRoot);
    cout << endl;
    return;
}
void Tree::preOrderRecursor(bstNode *node)
{
    if (node != NULL)
    {
        cout << node->value << " ";
        preOrderRecursor(node->nodeLeft);
        preOrderRecursor(node->nodeRight);
    }
    return;
}


void Tree::inOrder()
{
    cout << "inorder: ";
    inOrderRecursor(treeRoot);
    cout << endl;
    return;
}
void Tree::inOrderRecursor(bstNode *node)
{
    if (node != NULL)
    {
        inOrderRecursor(node->nodeLeft);
        cout << node->value << " ";
        inOrderRecursor(node->nodeRight);
    }
    return;
}


bool Tree::insert(int value)
{ // function to build the tree
    if (treeRoot == NULL)
    {
        treeRoot = new bstNode(value, NULL, NULL, NULL);
        return true;
    }
    else
    {
        bstNode *node = treeRoot;
        
        while (node != NULL)
        {
        
            if (value < node->value)
            {
                if (node->nodeLeft == NULL)
                {
                    node->nodeLeft = new bstNode(value, NULL, NULL, node);
                    break;
                }
                else
                {
                    node = node->nodeLeft;
                }
            }
            else if (value >= node->value)
            {
                if (node->nodeRight == NULL)
                {
                    node->nodeRight = new bstNode(value, NULL, NULL, node);
                    break;
                }
                else
                {
                    node = node->nodeRight;
                }
            }
        }
        return true;
    }
}


Tree::bstNode * Tree::findMax(bstNode *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    
    while (node->nodeRight != NULL)
    {
        node = node->nodeRight;
    }
    
    return node;
}


Tree::bstNode * Tree::findMin(bstNode *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    
    while (node->nodeLeft != NULL)
    {
        node = node->nodeLeft;
    }
    
    return node;
}


bool Tree::deleteMin()
{
    bstNode *node = findMin(treeRoot);
    if (node != NULL)
    {
        int value = node->value;
        return remove(value);
    }
    else
    {
        return false;
    }
}


bool Tree::deleteMax()
{
    bstNode *node = findMax(treeRoot);
    if (node != NULL)
    {
        int value = node->value;
        return remove(value);
    }
    else
    {
        return false;
    }
}


Tree::bstNode * Tree::search(int value, bstNode *node)
{
    if (node == NULL)
    {// if the node doesn't exist (we've traversed to the bottom of the tree)
        return NULL;
    }
    else if (node->value == value)
    {// if the current node contains the value we're looking for
        return node;
    }
    else if (value < node->value)
    {// if the value we're looking for is to the left
        return search(value, node->nodeLeft);
    }
    else
    {// if the value we're looking for is to the right
        return search(value, node->nodeRight);
    }
}


bool Tree::remove(int value)
{
    bool nodeRemoved = false;
    bstNode *node = search(value, treeRoot);
    
    while (node != NULL)
    {
        if (removeNode(node))
        {
            nodeRemoved = true;
        }
        node = search(value, treeRoot);
    }
    
    return nodeRemoved;
}
bool Tree::removeNode(bstNode *node)
{
    if (node == NULL)
    {// entry doesn't exist
        return false;
    }
    else if (node->nodeLeft == NULL && node->nodeRight == NULL)
    {// No children: delete node.
        if (node == treeRoot)
        {
            treeRoot = NULL;
        }
        else if (node == node->nodeParent->nodeLeft)
        {
            node->nodeParent->nodeLeft = NULL;
        }
        else if (node == node->nodeParent->nodeRight)
        {
            node->nodeParent->nodeRight = NULL;
        }
        delete node;
    }
    else if (node->nodeLeft == NULL && node->nodeRight != NULL)
    {// Only one child (R): replace node with it's only child

        /*cout << endl << node->value << "(" << node 
                 << ", par: " << node->nodeParent << ")" << endl
                 << "    left : " << node->nodeLeft << endl
                 << "    right: " << node->nodeRight << endl;*/
        
        
        if (node == treeRoot)
        {
            treeRoot = node->nodeRight;
            treeRoot->nodeParent = NULL;
        }
        else
        {
            if (node->nodeParent->nodeLeft == node)
            {
                node->nodeParent->nodeLeft = node->nodeRight;
            }
            else
            {
                node->nodeParent->nodeRight = node->nodeRight;
            }
            node->nodeRight->nodeParent = node->nodeParent;
            
        }
        delete node;
        
    }
    else if (node->nodeLeft != NULL && node->nodeRight == NULL)
    {// Only one child (L): replace node with it's only child
        
        if (node == treeRoot)
        {
            treeRoot = node->nodeLeft;
            treeRoot->nodeParent = NULL;
        }
        else
        {
            if (node->nodeParent->nodeLeft == node)
            {
                node->nodeParent->nodeLeft = node->nodeLeft;
            }
            else
            {
                node->nodeParent->nodeRight = node->nodeLeft;
            }
            node->nodeLeft->nodeParent = node->nodeParent;
        }
        delete node;
    }
    else if (node->nodeLeft != NULL && node->nodeRight != NULL)
    {// Both children: replace node with min priority element of right subtree
        
        // find the min priority element of the right subtree
        bstNode *min = findMin(node->nodeRight);
        
        /*cout << "min found\n";
        cout << endl << min->value << "(" << min 
                 << ", par: " << min->nodeParent << ")" << endl
                 << "    left : " << min->nodeLeft << endl
                 << "    right: " << min->nodeRight << endl;*/
        
        // set node's value to the min value
        node->value = min->value;
        
        if (min->nodeRight != NULL)
        {
            if (min->nodeParent->nodeLeft == min)
            {
                min->nodeParent->nodeLeft = min->nodeRight;
                min->nodeRight->nodeParent = min->nodeParent;
            }
            else
            {
                min->nodeParent->nodeRight = min->nodeRight;
                min->nodeRight->nodeParent = min->nodeParent;
            }
        }
        removeNode(min);
    }
    
    return true;
}
