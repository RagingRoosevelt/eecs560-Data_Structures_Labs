#include "heap_skew.h"
#include <iostream>
#include <cmath>

using namespace std;

HeapSkew::HeapSkew()
{
    heapHead = NULL;
}
HeapSkew::~HeapSkew()
{
    deconstructorAssist(heapHead);
}
void HeapSkew::deconstructorAssist(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    deconstructorAssist(root->childLeft);
    deconstructorAssist(root->childRight);
    delete root;
}


void HeapSkew::nodeSwap(Node *&node1, Node *&node2)
{
    Node *temp = node1;
    node1 = node2;
    node2 = temp;

    return;
}
void HeapSkew::insert(long int value)
{
    {
        Node *root2 = new Node(value, NULL, NULL);
        heapHead = merge(heapHead, root2);
        //cout << heapHead->value << endl;
    }
}
HeapSkew::Node * HeapSkew::merge(Node *root1, Node *root2)
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

    Node* temp = root1->childRight;
    root1->childRight = root1->childLeft;
    root1->childLeft = merge(temp, root2);
    
    return root1;


}
void HeapSkew::inorder()
{
    dfsPrint(heapHead,'i');
}
void HeapSkew::preorder()
{
    dfsPrint(heapHead,'p');
}
void HeapSkew::dfsPrint(Node* root, char method)
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
void HeapSkew::deleteMin()
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


void HeapSkew::levelOrder()
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
        cout << queueHead->node->value << " ";



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
