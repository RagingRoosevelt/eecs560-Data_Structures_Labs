#include "hash.h"
#include <iostream>

using namespace std;


HashTable::HashTable(int p)
{// constructor
    // initialize class variables
    noEntries = 0;
    prime = p;
    table = new Node*[p];
    
    // initialize hash table
    for (int i = 0; i < prime; i++)
    {
        table[i] = new Node(-1,false);
    }
}


HashTable::~HashTable() 
{// destructor
    for (int i = 0; i < prime; i++)
    {
        delete table[i];
    }
    delete table;
}


int HashTable::hash(int value, int probe)
{// return hash key given value and probe amount
    return (value + probe) % prime;
}


void HashTable::insert(int value)
{// insert a value into the table

    // check if the value is -1 since we're using -1 to store "empty"
    if (value == -1)
    {
        cout << "\nThat is an invalid selection. '-1' not inserted.\n";
        return;
    }
    
    // start off without probing
    int probe = 0;
    // calculate key with no probing
    int key = hash(value, probe);
    
    // if there is a collision, hunt for a key that won't cause a collision
    while (((table[key]->value != -1) || (table[key]->flag == true)) && (table[key]->value != value)) 
    // old, buggy version: while ((table[key]->value != -1) && (table[key]->value != value))    
    {
        probe++;
        key = hash(value, probe);
    }
    
    // if the value isn't already in the table, insert it
    if (table[key]->value != value)
    {
        table[key]->value = value;
        noEntries++;
    }
    else
    {
        cout << endl << "The value " << value << " is already in the table.";
    }
}


bool HashTable::remove(int value)
{// remove a value from the table

    // since we're using -1 to store blanks, we don't want to remove -1
    if (value == -1)
    {
        cout << "\n'-1' is an invalid selection.\n";
        return false;
    }
    
    // hunt for the entry to remove based on key and starting with no probing
    int count = 1;
    int probe = 0;
    int key = hash(value, probe);
    while ((table[key]->value != value) && (count <= prime))
    {
        count++;
        probe++;
        key = hash(value, probe);
    }
    
    // if we've looped all the way around, we won't be able to find it
    if (count == prime)
    {
        return false;
    }
    
    // if our current key location has the value, remove it.
    else if (table[key]->value == value)
    {
        table[key]->value = -1;
        table[key]->flag = true;
        noEntries--;
        
        return true;
    }
}


void HashTable::print()
{// print the table just iterating over the values
    for (int i = 0; i < prime; i++)
    {
        if (i < 10)
            cout << " " << i;
        else
            cout << i;
        cout << ": " << table[i]->value << "\tflag = ";
        if (table[i]->flag)
            cout << "true";
        else
            cout << "false";
        cout << endl;
    }
    
}


int HashTable::getValueAtKey(int key)
{// return the value stored at a particular key location
    return table[key]->value;
}


double HashTable::getLoadFactor()
{ // calcualte and return the load factor
    return (double)noEntries / prime;
}


int HashTable::getLoad()
{// return the number of entries in the table
    return noEntries;
}


int HashTable::getPrime()
{// return the size of the table (the prime that was used to create it)
    return prime;
}