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
}
void HeapLeftist::nodeSwap(Node *&node1, Node *&node2)
{
    //cout << "    " << node1 << " vs " << node2 << " then ";
    //cout << "    " << node1->value << " vs " << node2->value << " then ";
    Node *temp = node1;
    node1 = node2;
    node2 = temp;
    //cout << node1 << " vs " << node2 << endl;
    //cout << node1->value << " vs " << node2->value << endl;

    return;
}
void HeapLeftist::merge(int value)
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

    //cout << root1->value << " vs " << root2->value << endl;

    if (root1->value > root2->value)
    {
        //cout << "    need to swap" << endl;
        //cout << "    " << root1->value << " vs " << root2->value << " then ";
        nodeSwap(root1, root2);
        //cout << "    now: " << root1 << " vs " << root2 << endl;
        //cout << "    now: " << root1->value << " vs " << root2->value << endl;
    }


    root1->childRight = merge(root1->childRight, root2);
    //root1->rank = min(root1->childRight->rank, root1->childLeft->rank) + 1;
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


void HeapLeftist::levelOrder()
{
    if (heapHead == NULL)
        return;

    cout << "Level order: " ;

    Queue *queueHead = new Queue(NULL, heapHead);
    Queue *queueTail = queueHead;

    while (queueHead != NULL)
    {
        if (queueHead->node->childLeft != NULL)
        {
            queueTail->ll = new Queue(NULL, queueHead->node->childLeft);
        }
        if (queueHead->node->childRight != NULL)
        {
            queueTail->ll = new Queue(NULL, queueHead->node->childRight);
        }

        cout << queueHead->node->value << " ";

        Queue *temp = queueHead;
        queueHead = queueHead->ll;
        delete temp;
    }

    cout << endl;
    return;
}
