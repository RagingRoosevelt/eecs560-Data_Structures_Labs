#ifndef HASH_H
#define HASH_H

#include <iostream>

using namespace std;

class HashTable
{
private:
    struct Node
    {
        int value;
        bool flag;

        Node(int v, bool f):
            value(v), flag(f) {}
    };

    int prime;
	double noEntries;

    Node** table;


public:
    HashTable(int p);
	virtual ~HashTable();
    int hash(int value, int probe);
    void insert(int value);
	bool remove(int value);
	void print();
	double getLoadFactor();
	int getLoad();
	int getPrime();


};
#endif
