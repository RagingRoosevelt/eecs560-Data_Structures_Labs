#include "binom_queue.h"
#include <iostream>
#include <cmath>

using namespace std;

BinomQueue::BinomQueue()
{
    treecount = 10;
    queue = new Node* [treecount];
    
    for (int index=0; index < treecount; index++)
    {
        queue[index] = NULL;
    }
}
BinomQueue::~BinomQueue()
{
    delete [] queue;
}


void BinomQueue::nodeSwap(Node* &node1, Node* &node2)
{
    Node *temp = node1;
    node1 = node2;
    node2 = temp;

    return;
}

void BinomQueue::insert(int value)
{
    Node** tempQueue = new Node* [treecount];
    tempQueue[0] = new Node(value, 0, NULL, NULL);
    for (int index=1; index < treecount; index++)
    {
        tempQueue[index] = NULL;
    }
    queue = mergeQueues(queue, tempQueue);
}

BinomQueue::Node** BinomQueue::mergeQueues(Node** queueOrig, Node** queueTemp)
{
    
    // create two temporary queues.  one stores the final result, one stores the carry
    Node** resultQueue = new Node* [treecount];
    Node** carryQueue = new Node* [treecount];
    // set each queue to null initially
    for (int index=1; index < treecount; index++)
    {
        resultQueue[index] = NULL;
        carryQueue[index] = NULL;
    }
    
    // go through each order and merge the trees
    for (int index=0; index < treecount; index++)
    {
    
        Node* newRoot = mergeTrees(queueOrig[index], queueTemp[index]);
        
        if (newRoot == NULL)
        {
            continue;
        }
        else if (newRoot->order == index)
        {
            if (resultQueue[index] == NULL)
                resultQueue[index] = newRoot;
            else
                carryQueue[index] = newRoot;
        }
        else if (index+1 < treecount)
        {
            if (resultQueue[index+1] == NULL)
                resultQueue[index+1] = newRoot;
            else
                carryQueue[index+1] = newRoot;
        }
    }
    
    // determine if merge occurred without a carry
    bool carryEmpty = true;
    for (int index=0; index<treecount; index++)
    {
        if (carryQueue[index] != NULL)
        {
            carryEmpty = false;
            break;
        }
    }
    
    // if the carry queue was non-empty, merge it with the results queue
    if (!carryEmpty)
        resultQueue = mergeQueues(resultQueue, carryQueue);
    
    // return the results queue
    return resultQueue;
    
    
    
}

BinomQueue::Node* BinomQueue::mergeTrees(Node* root1, Node* root2)
{
    if (root2 == NULL)
    {
        return root1;
    }
    if (root1 == NULL)
    {
        return root2;
    }
    
    
    if (root1->key > root2->key)
    {
        nodeSwap(root1, root2);
    }
    
    root1->order += 1;
        
    // check if root1 has no child
    if (root1->fChild == NULL)
    {
        // if root1 has no child, then root2 is the first child
        root1->fChild = root2;
        return root1;
    }
    
    
    // if root1 does have a child, then find it's last child
    Node* lastChild = root1->fChild;
    while (lastChild->rSib != NULL)
    {
        lastChild = lastChild->rSib;
    }
    
    // set root1's last child's sibling to root2
    lastChild->rSib = root2;
    
    return root1;
}


void BinomQueue::levelOrder()
{
    cout << "Level order:";
    for (int order=0; order<treecount; order++)
    {
        cout << endl << endl << "---B" << order << "---" << endl;
        Node* node = queue[order];
        
        if (node==NULL)
            cout << "tree is empty";
        
        
        levelOrderTree(node);
    }
    cout << "--------" << endl;
}

void BinomQueue::levelOrderTree(Node* root)
{
    Node* rSib;
    
    while (root != NULL)
    {
        cout << root->key << " ";
        rSib = root->rSib;
        while (rSib != NULL)
        {
            cout << rSib->key << " ";
            
            rSib = rSib->rSib;
        }
            
        cout << endl;
        root = root->fChild;
    }
    return;
}