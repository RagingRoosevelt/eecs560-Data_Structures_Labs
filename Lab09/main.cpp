// main.cpp
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 02

#include "heap_leftist.h"
#include <fstream>
#include <iostream>

#include <cstdlib>
#include <ctime>

int menu(int type);
int randi(int max);

using namespace std;
int main() {
    HeapLeftist heapL;

    // srand(time(NULL));

    // for (int i=1; i <= 15; i++)
    // {
        // heap.populate(randi(30));
    // }
    srand(0);
    for (int i=0; i<4; i++)
    {
        int val = randi(50);
        cout << "Inserting " << val << endl;
        heapL.merge(val);
        heapL.levelOrder();
    }

    cout << "===================" << endl;
    heapL.levelOrder();
}




int randi(int max)
{

    return rand() % max;
}
