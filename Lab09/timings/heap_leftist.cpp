#include "heap_leftist.h"
#include <iostream>
#include <cmath>

using namespace std;

HeapLeftist::HeapLeftist()
{
    heapHead = NULL;
}
HeapLeftist::~HeapLeftist()
{
    deconstructorAssist(heapHead);
}
void HeapLeftist::deconstructorAssist(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    deconstructorAssist(root->childLeft);
    deconstructorAssist(root->childRight);
    delete root;
}


void HeapLeftist::nodeSwap(Node *&node1, Node *&node2)
{
    Node *temp = node1;
    node1 = node2;
    node2 = temp;

    return;
}
void HeapLeftist::insert(long int value)
{
    {
        Node *root2 = new Node(value, 1, NULL, NULL);
        heapHead = merge(heapHead, root2);
        //cout << heapHead->value << endl;
    }
}
HeapLeftist::Node * HeapLeftist::merge(Node *root1, Node *root2)
{
    if (root1 == NULL)
    {
        return root2;
    }
    if (root2 == NULL)
    {
        return root1;
    }

    if (root1->value > root2->value)
    {
        nodeSwap(root1, root2);
    }


    root1->childRight = merge(root1->childRight, root2);
    if (root1->childRight == NULL || root1->childLeft == NULL)
    {
        root1->rank = 1;
    }
    else
    {
        root1->rank = min(root1->childRight->rank, root1->childLeft->rank);
    }
    if (root1->childLeft == NULL)
    {
        nodeSwap(root1->childLeft, root1->childRight);
        root1->rank = 1;
    }
    else
    {
        if (root1->childLeft->rank < root1->childRight->rank)
        {
            nodeSwap(root1->childLeft, root1->childRight);
        }
        root1->rank = min(root1->childLeft->rank, root1->childRight->rank) + 1;
    }
    return root1;


}
void HeapLeftist::inorder()
{
    dfsPrint(heapHead,'i');
}
void HeapLeftist::preorder()
{
    dfsPrint(heapHead,'p');
}
void HeapLeftist::dfsPrint(Node* root, char method)
{
    if (root == NULL)
    {
        return;
    }
    else if (method == 'i')
    {
        dfsPrint(root->childLeft,method);
        cout << root->value << " ";
        dfsPrint(root->childRight,method);
    }
    else if (method == 'p')
    {
        cout << root->value << " ";
        dfsPrint(root->childLeft,method);
        dfsPrint(root->childRight, method);
    }
    return;
}
void HeapLeftist::deleteMin()
{
    if (heapHead == NULL)
    {
        cout << endl << "warning: Tree is empty" << endl;
        return;
    }
    
    Node* temp = heapHead;
    
    heapHead = merge(heapHead->childLeft, heapHead->childRight);
    
    delete temp;
    
}


void HeapLeftist::levelOrder()
{
    if (heapHead == NULL)
    {
        cout << endl << "warning: Tree is empty" << endl;
        return;
    }

    cout << "Level order: " << endl ;

    Queue *queueHead = new Queue(NULL, heapHead, 0, -1);
    Queue *queueTail = queueHead;

    while (queueHead != NULL)
    {
        if (queueHead->prev_level != -1 && queueHead->prev_level != queueHead->level)
        {
            cout << endl;
        }
        cout << queueHead->node->value << " ";//" (rank: " << queueHead->node->rank << ")   ";



        if (queueHead->node->childLeft != NULL)
        {
            queueTail->llNext = new Queue(NULL, queueHead->node->childLeft, queueHead->level + 1, queueTail->level);
            queueTail = queueTail->llNext;
        }

        if (queueHead->node->childRight != NULL)
        {
            queueTail->llNext = new Queue(NULL, queueHead->node->childRight, queueHead->level + 1, queueTail->level);
            queueTail = queueTail->llNext;
        }

        Queue* temp = queueHead;
        queueHead = queueHead->llNext;
        delete temp;
    }

    cout << endl;
    return;
}
