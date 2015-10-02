// Tree.cpp
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 02

#include "bst.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// construct the tree
Tree::Tree() {
    treeRoot = NULL;
    
    listHead = NULL;
    listTail = NULL;
}


// destroy the tree
Tree::~Tree() {
    
}


void Tree::levelOrder()
{
    if (treeRoot != NULL)
    {
        listHead = new llNode(NULL, treeRoot);
        listTail = listHead;
        
        while (listHead != NULL)
        {
            cout << listHead->treeNode->value << " ";
            
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
                return;
            }
        }
    }
}


void Tree::preOrder()
{
    preOrderRecursor(treeRoot);
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
    inOrderRecursor(treeRoot);
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


bool Tree::insert(int value){ // function to build the tree
    if (treeRoot == NULL)
    {
        treeRoot = new bstNode(value, NULL, NULL);
        return true;
    }// end if
    else
    {
        bstNode *node = treeRoot;
        
        while (node != NULL)
        {
        
            if (value < node->value)
            {
                if (node->nodeLeft == NULL)
                {
                    node->nodeLeft = new bstNode(value, NULL, NULL);
                    break;
                }
                else
                {
                    node = node->nodeLeft;
                }
            }// end if
            else
            {
                if (node->nodeRight == NULL)
                {
                    node->nodeRight = new bstNode(value, NULL, NULL);
                    break;
                }// end if
                else
                {
                    node = node->nodeRight;
                }// end else
            }// end else
        }// end while
    }// end else
}// end Tree::insert


bool Tree::remove(int value)
{
    bstNode *node = treeRoot;
    
    while (node != NULL)
    {
        if (value == node->value)
        {
            // remove value
        }
        else
        {
            
        }
    }
    
    return false;
    
}

