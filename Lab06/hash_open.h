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
        long int value;
        bool flag;

        Node(long int v, bool f):
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
    void insert(long int value);
    bool remove(long int value);
    void print();
    
    // helper functions
    int hash(long int value, int probe);
    double getLoadFactor();
    int getLoad();
    int getPrime();
    int getValueAtKey(int key);
    
};
#endif
