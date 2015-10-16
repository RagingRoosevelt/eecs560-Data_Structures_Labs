#include "hash_chain.h" 
#include <iostream>
#include <math.h>

using namespace std;


HashTableChain::HashTableChain(int p)
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


HashTableChain::~HashTableChain()
{// destructor
    for (int i = 0; i < prime; i++)
    {
        delete table[i];
    }
    delete table;
}


int HashTableChain::hash(long int value)
{// return hash key given value and probe amount
    return value % prime;
}


void HashTableChain::insert(long int value)
{// insert a value into the table
    if (value == -1)
    {
        //cout << endl << "-1 is not a valid choice." 
        //     << endl << "Nothing was inserted." << endl;
        return;
    }

    if (!find(value))
    {// check if value is already in table

        // rehash if needed
        rehash();
        
        // actually insert the value
        insertDoer(value);
    }
    else
    {
        //cout << endl << value << " is already in the table.  Value not inserted again.\n";
    }
}


void HashTableChain::insertDoer(long int value)
{// no need to rehash since either called by rehash or by insert (which rehashes if needed)

    // determine key
    int key = hash(value);
    Node* node = table[key];

    while (node->value != -1)
    { // cycle through the linked list until we find the end
        node = node->nextNode;
    }
    
    // insert the value
    node->value = value;
    node->nextNode = new Node(-1,NULL);
    noEntries++;

    //cout << value << " inserted. Load factor is now " << getLoadFactor() << "." << endl;
}


bool HashTableChain::remove(long int value)
{// remove a value from the table
    if (value == -1)
    {
        //cout << endl << "-1 is not a valid choice." ;
        return false;
    }

    int key = hash(value);
    
    Node* node = table[key];
    Node* previous = NULL;
    while (node->value != -1)
    {// loop until the end of the linked list is found
        if (node->value == value)
        {// if we find the value in the table
            if (previous == NULL)
            {// set the table's head pointer to this node
                table[key] = node->nextNode;
            }
            else
            {// set the previous node's pointer to this node
                previous->nextNode = node->nextNode;
            }
            noEntries--;
            return true;
        }
        
        // advance though the linked list
        previous = node;
        node = node->nextNode;
    }
    return false;
}


void HashTableChain::rehash()
{// rehash the table
    double loadFactor = double(getLoad() + 1) / prime;

    if (loadFactor > 1)
    {// check if we need to rehash

        // set aside old table to pull values from
        Node** oldTable = table;
        int oldPrime = prime;

        // find new prime then create new table
        prime = nextPrime(2*prime);
        table = new Node*[prime];
        
        cout << "New load factor would have been " << loadFactor 
             << ".\nRehashing needed.  New prime is " << prime << ".\n\n";

        // initialize the new hash table
        for (int i = 0; i < prime; i++)
        {
            table[i] = new Node(-1,NULL);
        }

        // start inserting values into the new table from the old one
        noEntries = 0;
        for (int i = 0; i < oldPrime; i++)
        {
            Node* node = oldTable[i];
            
            while (node->nextNode != NULL)
            {
                insertDoer(node->value);
                node = node->nextNode;
            }
        }

    }
}


void HashTableChain::print()
{// print the table just iterating over the values
    for (int i = 0; i < prime; i++)
    {
        // start at the head of the linked list
        Node* node = table[i];

        // padding if table index is less than 10
        if ((i < 10) && (prime >= 10))
        {
            cout << " " << i;
        }
        else
        {
            cout << i;
        }
        cout << ": ";
        
        // run through linked list at current table index
        while (node->value != -1)
        {
            cout << node->value << " ";
            node = node->nextNode;
        }
        
        cout << endl;
    }
}


bool HashTableChain::find(long int value)
{// return true if the value x is in the hash table, false otherwise
    int key = hash(value);
    
    Node* node = table[key];
    
    while (node->value != -1)
    {// while we haven't found the end of the list yet
        if (node->value == value)
        {
            return true;
        }
        node = node->nextNode; // step through linked list
    }
    return false;
}


double HashTableChain::getLoadFactor()
{ // calcualte and return the load factor
    return (double)noEntries / prime;
}


int HashTableChain::getLoad()
{// return the number of entries in the table
    return noEntries;
}


int HashTableChain::getPrime()
{// return the size of the table (the prime that was used to create it)
    return prime;
}


int HashTableChain::nextPrime(int value)
{// find the first prime number larger than the passed value
    int primeCandidate = value+1;
    while (! primeCheck(primeCandidate))
    {
        primeCandidate++;
    }
    return primeCandidate;
}


bool HashTableChain::primeCheck(int value)
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
