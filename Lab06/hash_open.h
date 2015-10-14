#ifndef HASH_OPEN_H
#define HASH_OPEN_H

#include <iostream>

using namespace std;

class HashTableOpen
{
private:
    // entry structure
    struct Node
    {
        int value;
        bool flag;

        Node(int v, bool f):
            value(v), flag(f) {}
    };

    // for calculating load factor
    int prime;
    int noEntries;

    // table
    Node** table;

public:
    // constructor and destructor
    HashTableOpen(int p);
    virtual ~HashTableOpen();
    
    // required functions
    void insert(int value);
    bool remove(int value);
    void print();
    
    // helper functions
    int hash(int value, int probe);
    double getLoadFactor();
    int getLoad();
    int getPrime();
    int getValueAtKey(int key);
    
};
#endif
