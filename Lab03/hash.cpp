#include "hash.h"
#include <iostream>

using namespace std;


HashTable::HashTable(int p)
{
	noEntries = 0;
    prime = p;
    table = new Node*[p];
	
    // initialize hash table
    for (int i = 0; i < prime; i++)
	{
		table[i] = new Node(-1,false);
	}
}

HashTable::~HashTable() {
	for (int i = 0; i <= prime; i++)
	{
		delete table[i];
	}
	delete table;
}

int HashTable::hash(int value, int probe)
{
    return (value + probe) % prime;
}

void HashTable::insert(int value)
{
	if (value == -1)
	{
		cout << "\nThat is an invalid selection. '-1' not inserted.\n";
		return;
	}
    int probe = 0;
	int key = hash(value, probe);
    while ((table[key]->value != -1) && (table[key]->value != value))
    {
        probe++;
		key = hash(value, probe);
    }
    table[key]->value = value;
	noEntries++;
}

bool HashTable::remove(int value)
{
	if (value == -1)
	{
		cout << "\n'-1' is an invalid selection.\n";
		return false;
	}
	int count = 1;
	int probe = 0;
	int key = hash(value, probe);
	while ((table[key]->value != value) && (count <= prime))
	{
		count++;
		probe++;
		key = hash(value, probe);
	}
	if (count == prime)
	{
		return false;
	}
	else if (table[key]->value == value)
	{
		table[key]->value = -1;
		table[key]->flag = true;
		noEntries--;
		
		return true;
	}
}
void HashTable::print()
{
	for (int i = 0; i < prime; i++)
	{
		cout << i << ": " << table[i]->value << "\tflag = ";
		if (table[i]->flag)
			cout << "true";
		else
			cout << "false";
		cout << endl;
	}
	
}
double HashTable::getLoadFactor()
{
	return noEntries / prime;
}
int HashTable::getLoad()
{
	return noEntries;
}
int HashTable::getPrime()
{
	return prime;
}