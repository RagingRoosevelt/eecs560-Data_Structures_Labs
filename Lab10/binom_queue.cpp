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
    cout << endl << "Level order:" << endl;
    for (int order=0; order<treecount; order++)
    {
        Node* node = queue[order];
        if (node != NULL)
        {
            cout << "---B" << order << "---" << endl;
            
            
            levelOrderTree(node);
        }
    }
    cout << "--------" << endl << endl;
}

void BinomQueue::levelOrderTree(Node* root)
{
    Queue* currentLevel_h = new Queue(NULL, root);
    Queue* currentLevel_t = currentLevel_h;
    Queue* nextLevel_h = NULL;
    Queue* nextLevel_t = NULL;
    
    while (currentLevel_h != NULL)
    {
        Node* node = currentLevel_h->node;
        
        while (node != NULL)
        {
            cout << node->key << " ";
            
            if (node->fChild != NULL)
            {
                if (nextLevel_h == NULL)
                {
                    nextLevel_h = new Queue(NULL, node->fChild);
                    nextLevel_t = nextLevel_h;
                }
                else
                {
                    nextLevel_t->next = new Queue(NULL, node->fChild);
                    nextLevel_t = nextLevel_t->next;
                }
            }
            
            node = node->rSib;
        }
        
        if (currentLevel_h->next != NULL)
        {
            Queue* temp = currentLevel_h;
            currentLevel_h = currentLevel_h->next;
            delete temp;
        }
        else
        {
            currentLevel_h = nextLevel_h;
            currentLevel_t = nextLevel_t;
            nextLevel_h = NULL;
            nextLevel_t = NULL;
            cout << endl;
        }
    }
    
    
    return;
}


bool BinomQueue::deleteMin()
{
    int smallestIndex = -1;
    for (int index = 0; index < treecount; index++)
    {
        if (queue[index] != NULL)
        {
            if (smallestIndex == -1 || queue[index]->key < queue[smallestIndex]->key)
            {
                smallestIndex = index;
            }
        }
    }
    
    if (smallestIndex == -1)
    {
        return false;
    }
    
    
    if (smallestIndex == 0)
    {
        Node* temp = queue[smallestIndex];
        queue[smallestIndex] = NULL;
        delete temp;
        return true;
    }
    
    
    Node* tempRoot = queue[smallestIndex];
    Node* child = tempRoot->fChild;
    queue[smallestIndex] = NULL;
    
    
    Node** tempQueue = new Node* [treecount];
    for (int index=0; index < treecount; index++)
    {
        if (index >= smallestIndex)
        {
            tempQueue[index] = NULL;
        }
        else
        {
            tempQueue[index] = child;
            child = child->rSib;
            tempQueue[index]->rSib = NULL;
        }
    }
    
    delete tempRoot;
    queue = mergeQueues(queue, tempQueue);
    
    return true;
}