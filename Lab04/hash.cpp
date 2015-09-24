#include "hash.h"
#include <iostream>
#include <math.h>

using namespace std;


HashTable::HashTable(int p)
{// constructor
    // initialize class variables
    noEntries = 0;
    prime = p;
    table = new Node*[prime];

    // initialize hash table
    for (int i = 0; i < prime; i++)
    {
        table[i] = new Node(-1,NULL);
    }
}


HashTable::~HashTable()
{// destructor
    for (int i = 0; i <= prime; i++)
    {
        delete table[i];
    }
    delete table;
}


int HashTable::hash(int value)
{// return hash key given value and probe amount
    return value % prime;
}


void HashTable::insert(int value)
{// insert a value into the table


    // determine key
    int key = hash(value);

    Node* node = table[key];

    while ((node->value != -1) && (node->value != value))
    {
        node = node->nextNode;
    }

    if (node->value != value)
    {
        rehash();
        node->value = value;
        node->nextNode = new Node(-1,NULL);
        noEntries++;

        cout << value << " inserted. Load factor is now " << getLoadFactor() << endl;
    }
    else
    {
        cout << "\n============Warning============"
              << endl << value << " is already in the hash table"
              << "\nValue not inserted again" << endl
             << "===============================" << endl;
    }
}


bool HashTable::remove(int value)
{// remove a value from the table
    /*
    // since we're using -1 to store blanks, we don't want to remove -1
    if (value == -1)
    {
        cout << "\n'-1' is an invalid selection.\n";
        return false;
    }

    // hunt for the entry to remove based on key and starting with no probing
    int count = 1;
    int probe = 0;
    int key = hash(value);
    while ((table[key]->value != value) && (count <= prime))
    {
        count++;
        probe++;
        key = hash(value);
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
    */
}


void HashTable::rehash()
{// rehash the table
    double load = getLoad() + 1;

    if (load / prime > 1)
    {// the we need to rehash
        cout << "We need to rehash" << endl;

        Node** oldTable = table;
        int oldPrime = prime;

        // find new prime then create new table
        prime = nextPrime(2*prime);
        table = new Node*[prime];

        // initialize the new hash table
        for (int i = 0; i < prime; i++)
        {
            table[i] = new Node(-1,NULL);
        }

        noEntries = 0;
        for (int i = 0; i < prime; i++)
        {
            Node* node = oldTable[i];

            // BUG HERE, PROBABLY

            while (node->value != -1)
            {
                insert(node->value);
                node = node->nextNode;
            }
        }

    }
}


void HashTable::print()
{// print the table just iterating over the values
    for (int i = 0; i < prime; i++)
    {
        Node* node = table[i];

        cout << endl;
        if ((i < 10) && (prime >= 10))
        {
            cout << " " << i;
        }
        else
        {
            cout << i;
        }
        cout << ": ";

        while (node->value != -1)
        {
            cout << node->value << " ";
            node = node->nextNode;
        }
    }
}


bool find(int value)
{// return true if the value x is in the hash table, false otherwise

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


int HashTable::nextPrime(int value)
{// find the first prime number larger than the passed value
    int primeCandidate = value+1;
    while (! primeCheck(primeCandidate))
    {
        primeCandidate++;
    }
    return primeCandidate;
}


bool HashTable::primeCheck(int value)
{// check if a number is prime
    if (value % 2 == 0)
    {
        return false;
    }

    for (int div = 3; div <= sqrt(value); div ++)
    {
        if (value % div == 0)
        {
            return false;
        }
    }

    return true;
}
