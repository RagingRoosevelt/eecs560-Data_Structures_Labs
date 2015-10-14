#ifndef HASH_CHAIN_H
#define HASH_CHAIN_H

#include <iostream>

using namespace std;

class HashTableChain
{
private:
    // entry structure
    struct Node {
        int value;
        Node *nextNode;
        Node(int v, Node *n) :
            value(v), nextNode(n) {
        }
    };

    // for calculating load factor
    int prime;
    int noEntries;

    // table
    Node** table;

public:
    // constructor and destructor
    HashTableChain(int p);
    virtual ~HashTableChain();

    // required functions
    void insert(int value);
    bool remove(int value);
    void print();
    bool find(int value);
    int hash(int value);

    // helper functions
    void rehash();
    double getLoadFactor();
    int getLoad();
    int getPrime();
    bool primeCheck(int value);
    int nextPrime(int value);
    void insertDoer(int value);

};
#endif
