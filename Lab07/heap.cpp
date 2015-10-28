#include "heap.h"
#include <iostream>
#include <cmath>

using namespace std;

Heap::Heap()
{
    noChildren = 5;
    
    for (int index=0; index < 500; index++)
    {
        heap[index] = -1;
    }

    lastIndex = -1;
}


Heap::~Heap()
{
}


int Heap::parent(int index)
// returns index's parent index
{ 
    return floor((index - 1) / double(noChildren));
}


int Heap::jthChild(int index, int j)
// takes node's index and j=1..5
{ 
    int newIndex = noChildren * index + (j);
    if (newIndex > lastIndex)
    {
        return -1;
    }
    else
    {
        return newIndex;
    }
}


int Heap::myJ(int index)
// returns j=1..5
{ 
    return index % noChildren;
}


void Heap::swapValues(int& val1, int& val2)
// swaps the values contained in val1, val2
{ 
    int temp = val1;
    val1 = val2;
    val2 = temp;
}


void Heap::levelOrder()
// print the heap to console in level order
{
    int depth = 0;
    
    cout << "Level order:" << endl;
    for (int index=0; index <= lastIndex; index++)
    {
        cout << heap[index] << " ";
        
        if (index % 5 == 0)
        {
            if (isEOL(index) || index==0)
            {
                cout << endl;
            }
            else if (index < lastIndex)
            {
                cout << " - ";
            }
        }
    }
    cout << endl;
}

bool Heap::isEOL(int value)
{
    bool eol = false;
    
    int sum = 0;
    int power = 1;
    
    while (sum < value)
    {
        sum += pow(noChildren, power);
        power++;
        if (value == sum)
        {
            return true;
        }
    }
    return false;
}


void Heap::populate(int value)
// insert an entry at the first unused location in the array.  don't bother with sorting
{ 
    lastIndex++;
    cout << "Inserting '" << value << "' at position " << lastIndex << endl;
    heap[lastIndex] = value;
}


void Heap::insert(int value)
// insert a new value into the heap, then sort to ensure heap property holds
{
    populate(value);
    bubbleUp(lastIndex);
}


int Heap::findSmallestChild(int root)
{
    int smallestChild = jthChild(root, 1);
    if (smallestChild == -1)
    {
        return -1;
    }
    //cout << "\tCurrent smallest child is at " << smallestChild << endl;
    for (int j = 2; j <= noChildren; j++)
    {
        int jth = jthChild(root, j);
        if (jth == -1)
        {
            break;
        }
        else if (heap[jth] < heap[smallestChild])
        {
            smallestChild = jth;
            //cout << "\tCurrent smallest child is at " << smallestChild << endl;
        }
    }
    //cout << "\tSmallest child is (" << smallestChild << ", " << heap[smallestChild] << ")" << endl;
    return smallestChild;
}

void Heap::sortSubtree(int root, bool sortDown)
// heapify root and its children.  
// if sortDown is true, also heapify the subtrees where root's children are roots
{ 
    //cout << "Looking at value (" << root << ", " << heap[root] << ")" << endl;
    int smallestChild = findSmallestChild(root);
    // int smallestChild = jthChild(root, 1);
    if (smallestChild == -1)
    {
        return;
    }
    // cout << "\tCurrent smallest child is at " << smallestChild << endl;
    // for (int j = 2; j <= noChildren; j++)
    // {
        // int jth = jthChild(root, j);
        // if (jth == -1)
        // {
            // break;
        // }
        // else if (heap[jth] < heap[smallestChild])
        // {
            // smallestChild = jth;
            // cout << "\tCurrent smallest child is at " << smallestChild << endl;
        // }
    // }
    // cout << "\tSmallest child is (" << smallestChild << ", " << heap[smallestChild] << ")" << endl;
    if (heap[smallestChild] < heap[root])
    {
        swapValues(heap[smallestChild], heap[root]);
        //cout << "\tSwapping with smallest child" << endl;
    }
    
    //cout << "\t\t" << jthChild(smallestChild,1) << " vs " << lastIndex << endl;
    if (jthChild(smallestChild,1) <= lastIndex && jthChild(smallestChild,1) >= 0 && sortDown)
    {
        sortSubtree(smallestChild, true);
    }
    else
    {
        return;
    }
}


void Heap::bubbleUp(int index)
// heapify starting at the bottom and working up
{
    while (index >= 0)
    {
        sortSubtree(index, false);
        
        index = parent(index);
    }
}


void Heap::bubbleUpAll()
// heapify the whole heap
{
    int index = parent(lastIndex);
    while (index >= 0)
    {
        sortSubtree(index, true);
        
        int j = myJ(index);
        if (index == 0)
        {
            return;
        }
        else if (j==1)
        {
            index = parent(index);
        }
        else
        {
            int par = parent(index);
            index = jthChild(par, j-1);
        }
    }
}


void Heap::bubbleDown(int index)
{
    while (index <= lastIndex)
    {
        int smallest = findSmallestChild(index);
        if (heap[smallest] < heap[index] && smallest <= lastIndex && smallest != -1)
        {
            swapValues(heap[smallest], heap[index]);
            index = smallest;
        }
        else
        {
            return;
        }
    }
}

bool Heap::remove(int value)
// defaults to removing all instances of value
{
    return remove(value, true);
}
bool Heap::remove(int value, bool removeMultiple)
{
    bool sucessful = false;
    int index = 0;
    // find the first occurrence of the value
    while (heap[index] != value && index <= lastIndex)
    {
        index++;
    }
    if (index > lastIndex)
    { // value not in heap
        return false;
    }
    else if (index == lastIndex)
    { // entry is the last entry
        cout << "Removing '" << heap[index] << "' at position " << index << endl;
        heap[lastIndex] = -1;
        lastIndex--;
        sucessful = true;
    }
    else
    { // is not last entry and entry has children
        cout << "Removing '" << heap[index] << "' at position " << index << endl;
        
        heap[index] = heap[lastIndex];
        heap[lastIndex] = -1;
        lastIndex--;
        
        bubbleDown(index);
        
        if (removeMultiple)
        {
            remove(value);
        }
        
        sucessful = true;
    }
    
    if (removeMultiple)
    {
        return (sucessful || remove(value, true));
    }
    else
    {
        return (sucessful);
    }
    
}


void Heap::deleteMin()
{
    remove(heap[0], false);
}


void Heap::deleteMax()
{
    int maxIndex = 0;
    for (int index=0; index <= lastIndex; index++)
    {
        if (heap[maxIndex] < heap[index])
        {
            maxIndex = index;
        }
    }
    
    remove(heap[maxIndex], false);
}