#include "heap.h"
#include <iostream>
#include <cmath>

using namespace std;

Heap::Heap()
{
    noChildren = 2;

    for (int index=0; index < 500; index++)
    {
        heap[index] = -1;
    }

    lastIndex = -1;
}
Heap::~Heap()
{
}

//////////////////////////////////////////////
// Utility and simple calculation functions //
//////////////////////////////////////////////
bool Heap::minLevelCheck(int index)
{// checks if the given index is a min-level (or max)
    int level;
    if (noChildren == 2)
        level = ceil(log2(index+2)-1);
    else
        level = ceil(log(index+2)/log(noChildren)-1);
    
    if (level % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int Heap::parent(int index)
{// returns index's parent index
    if (index <= 0)
        return -1;
    else
        return floor((index - 1) / double(noChildren));
}
int Heap::jthChild(int index, int j)
{// takes node's index and j=1..5
    int newIndex = noChildren * index + (j);
    //cout << noChildren << " * " << index << " + " << j << " = " << newIndex << endl;
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
{// returns j=1..5
    return index % noChildren;
}
void Heap::swapValues(int& val1, int& val2)
{// swaps the values contained in val1, val2
    int temp = val1;
    val1 = val2;
    val2 = temp;
}
bool Heap::isEOL(int value)
{// determines if the given index is at the end of a level
    
    double level;
    double level_ur;
    if (noChildren == 2)
    {
        level = ceil(log2(value+2)-1);
        level_ur = log2(value+2)-1;
    }
    else
    {
        level = ceil(log(value+2)/log(noChildren)-1);
        level_ur = log(value+2)/log(noChildren)-1;
    }
    
    //cout << "(" << level << " vs " << level_ur << ")" << endl;
    
    if (level_ur == level)
        return true;
    else
        return false;
}
int Heap::findLargestChild(int index)
{ // finds the largest child of the specified node
    if (jthChild(index, 1) == -1)
    {
        return -1;
    }
    int largest = jthChild(index,1);
    for (int i=2; i <= noChildren; i++)
    {
        if (jthChild(index, i) == -1)
            break;
        if (heap[largest] < heap[jthChild(index,i)])
            largest = jthChild(index,i);
    }
    return largest;
}
int Heap::findLargestGrandchild(int index)
{ // finds the largest grandchild of the specified node
    if (jthChild(index,1) == -1)
    {
        return -1;
    }
    if (jthChild(jthChild(index,1), 1) == -1)
    {
        return -1;
    }
    
    int largest = jthChild(jthChild(index,1), 1);
    for (int i = 1; i <= noChildren; i++)
    {
        for (int j = 1; j <= noChildren; j++)
        {
            if (jthChild(jthChild(index,i), j) == -1)
                break;
            if (heap[jthChild(jthChild(index,i), j)] > heap[largest])
                largest = jthChild(jthChild(index,i), j);
        }
    }
    return largest;
}
int Heap::findSmallestChild(int index)
{ // finds the smallest child of the specified node
    if (jthChild(index, 1) == -1)
    {
        return -1;
    }
    int smallest = jthChild(index,1);
    for (int i=2; i <= noChildren; i++)
    {
        if (jthChild(index, i) == -1)
            break;
        if (heap[smallest] > heap[jthChild(index,i)])
            smallest = jthChild(index,i);
    }
    return smallest;
}
int Heap::findSmallestGrandchild(int index)
{ // finds the smallest grandchild of the specified node
    if (jthChild(index,1) == -1)
    {
        return -1;
    }
    if (jthChild(jthChild(index,1), 1) == -1)
    {
        return -1;
    }
    
    int smallest = jthChild(jthChild(index,1), 1);
    for (int i = 1; i <= noChildren; i++)
    {
        for (int j = 1; j <= noChildren; j++)
        {
            if (jthChild(jthChild(index,i), j) == -1)
                break;
            if (heap[jthChild(jthChild(index,i), j)] < heap[smallest])
                smallest = jthChild(jthChild(index,i), j);
        }
    }
    return smallest;
}
int Heap::findValue(int value)
{
    if (lastIndex < 0)
        return -1;
    
    for (int i=0; i <= lastIndex; i++)
    {
        if (heap[i] == value)
            return i;
    }
    
    return -1;
}


/////////////////////////////////////////////////////////////////
// for heapification when: building heap, deleteMin, deleteMax //
/////////////////////////////////////////////////////////////////
void Heap::trickleDown()
{
	int start = parent(lastIndex);
    for (int i=start; i >= 0; i--)
    {
        trickleDown(i);
    }
}
void Heap::trickleDown(int index)
{// adapted from pseudocode in "Min-Max Heaps and Generalized Priority Queues" (Atkinson, et al)
    //cout << "Is this a min level? " << minLevelCheck(index) << endl;
    if (minLevelCheck(index))
    {
        trickleDownMin(index);
    }
    else
    {
        trickleDownMax(index);
    }
}
void Heap::trickleDownMin(int index)
{// adapted from pseudocode in "Min-Max Heaps and Generalized Priority Queues" (Atkinson, et al)
    if (jthChild(index,1) > -1) // if index has child
    {
        int smallestChild = findSmallestChild(index);
        int smallestGrandchild = findSmallestGrandchild(index);
        int smallest;
        //cout << "@" << index << ": " << smallestChild << " and " << smallestGrandchild << endl;
        if ((smallestGrandchild > -1) && (heap[smallestChild] > heap[smallestGrandchild]))
        { // smallest is a grandchild
            smallest = smallestGrandchild;
            if (heap[smallest] < heap[index])
            {
                swapValues(heap[smallest],heap[index]);
                if (heap[smallest] > heap[parent(smallest)])
                {
                    swap(heap[smallest], heap[parent(smallest)]);
                }
                trickleDownMin(smallest);
            }
        }
        else
        { // smallest is a child
            smallest = smallestChild;
            if (heap[smallest] < heap[index])
            {
                swap(heap[index], heap[smallest]);
            }
        }
    }
}
void Heap::trickleDownMax(int index)
{// adapted from pseudocode in "Min-Max Heaps and Generalized Priority Queues" (Atkinson, et al)
    if (jthChild(index,1) < lastIndex) // if index has child
    {
        int largestChild = findLargestChild(index);
        int largestGrandchild = findLargestGrandchild(index);
        int largest;
        if ((largestGrandchild > 0) && (heap[largestChild] < heap[largestGrandchild]))
        { // smallest is a grandchild
            largest = largestGrandchild;
            if (heap[largest] > heap[index])
            {
                swapValues(heap[largest],heap[index]);
                if (heap[largest] < heap[parent(largest)])
                {
                    swap(heap[largest], heap[parent(largest)]);
                }
                trickleDownMax(largest);
            }
        }
        else
        { // smallest is a child
            largest = largestChild;
            if (heap[largest] > heap[index])
            {
                swap(heap[index], heap[largest]);
            }
        }
    }
}

///////////////////////////////////////
// for heapification when: inserting //
///////////////////////////////////////
void Heap::bubbleUp(int index)
{// adapted from pseudocode in "Min-Max Heaps and Generalized Priority Queues" (Atkinson, et al)
    
    int par = parent(index);
    if (par == -1)
        return;
    
    else if (minLevelCheck(index))
    {
        if (heap[index] > heap[par])
        {
            swapValues(heap[index], heap[par]);
            bubbleUpMax(par);
        }
        else
        {
            bubbleUpMin(index);
        }
    }
    else
    {
        if (heap[index] < heap[par])
        {
            swapValues(heap[index],heap[par]);
            bubbleUpMin(par);
        }
        else
        {
            bubbleUpMax(index);
        }
    }
}
void Heap::bubbleUpMin(int index)
{// adapted from pseudocode in "Min-Max Heaps and Generalized Priority Queues" (Atkinson, et al)
    int gpar = parent(parent(index));
    if (gpar == -1)
        return;
    else
    {
        if (heap[index] < heap[gpar])
        {
            swapValues(heap[index],heap[gpar]);
            bubbleUpMin(gpar);
        }
    }
}
void Heap::bubbleUpMax(int index)
{// adapted from pseudocode in "Min-Max Heaps and Generalized Priority Queues" (Atkinson, et al)
    int gpar = parent(parent(index));
    if (gpar == -1)
        return;
    else
    {
        if (heap[index] > heap[gpar])
        {
            swapValues(heap[index],heap[gpar]);
            bubbleUpMax(gpar);
        }
    }
}


void Heap::levelOrder()
{// print the heap to console in level order
    if (lastIndex < 0)
    {
        cout << "warning: The heap is empty" << endl;
        return;
    }
    
    int depth = 0;

    cout << "Level order:" << endl;
    for (int index=0; index <= lastIndex; index++)
    {
        cout << heap[index] << " ";

        if (index % noChildren == 0)
        {
            if (isEOL(index) || index==0)
            {
                cout << endl;
            }
            else if (index < lastIndex)
            {
                cout << "- ";
            }
        }
    }
    cout << endl;
}


void Heap::populate(int value)
{// insert an entry at the first unused location in the array.  don't bother with sorting
    if (lastIndex >= 500-1)
        return; // heap is full
        
    lastIndex++;
    cout << "Inserting '" << value << "' at position " << lastIndex << endl;
    heap[lastIndex] = value;
}


void Heap::insert(int value)
{// insert 'value' into the heap then heapify
    if (lastIndex >= 500-1)
        return; // heap is full
        
    lastIndex++;
    heap[lastIndex] = value;
    
    bubbleUp(lastIndex);
}


bool Heap::deleteMin()
{// delete the minimum value (located at the root)
    if (lastIndex < 0)
        return false;
    
    heap[0] = heap[lastIndex];
    heap[lastIndex] = -1;
    lastIndex--;
    trickleDown(0);
    return true;
}


bool Heap::deleteMax()
{// delete the maximum value (located at the root or one of its children)
    if (lastIndex < 0)
        return false;
    
    
    if (lastIndex == 0)
    {
        heap[0] = -1;
        lastIndex--;
    }
    else
    {
        int largest = 1;
        for (int i=2; i <= noChildren; i++)
        {
            if (i > lastIndex)
                break;
            
            if (heap[largest] < heap[i])
                largest = i;
        }
        
        heap[largest] = heap[lastIndex];
        heap[lastIndex] = -1;
        lastIndex--;
        trickleDown(largest);
    }
    
    return true;
    
}


bool Heap::remove(int value)
{// remove all occurrences of 'value'
    int index = findValue(value);
    if (index == -1)
        return false;
    
    heap[index] = heap[lastIndex];
    heap[lastIndex] = -1;
    lastIndex--;
    trickleDown(index);
    
    remove(value);
    
    return true;
}