#ifndef HASH_CHAIN_H 
#define HASH_CHAIN_H

#include <iostream>

using namespace std;

class HashTableChain
{
private:
    // entry structure
    struct Node {
        long int value;
        Node *nextNode;
        Node(long int v, Node *n) :
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
    void insert(long int value);
    bool remove(long int value);
    void print();
    bool find(long int value);
    int hash(long int value);

    // helper functions
    void rehash();
    double getLoadFactor();
    int getLoad();
    int getPrime();
    bool primeCheck(int value);
    int nextPrime(int value);
    void insertDoer(long int value);

};
#endif
