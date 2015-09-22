#include "hash.h"
#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

int menu(int type);
int nextPrime(int prime);
bool primeCheck(int value);

int main()
{

	ifstream dataFile("data.txt");
	
	
	// read in the prime number
    int prime;
    if (dataFile.good())
    {
        dataFile >> prime;
    }
	
	
	// create a hash table
	HashTable* hashTable = new HashTable(prime);
	
	
	// populate the hash table
    int valTmp;
	while (dataFile >> valTmp)
    {
		hashTable->insert(valTmp);
	}		
		
	int choice = -1;
	do 
    {
        // display main menu and get user choice
        choice = menu(0);
        
		if (choice == 1) // display insert menu and then insert provided value
        {
            choice = menu(1);
            
            // gather information about the current table
            int load = hashTable->getLoad();
            int prime = hashTable->getPrime();
            
            // check if the load factor is too high
            if (((double)load + 1) / prime > 0.5)
            { // Load factor is too high, re-hashing...
                
                // Gather old table values
                int temp [prime];
                for (int i=0; i < prime; i++)
                {
                    temp[i] = hashTable->getValueAtKey(i);
                }
                
                // create a new table
                hashTable = new HashTable(nextPrime(2*prime));
                
                // populate the new table with the values from the old table
                for (int i=0; i < prime; i++)
                {
                    if (temp[i] != -1 )
                    {
                        hashTable->insert(temp[i]);
                    }
                }
                
            }
            
            // insert the origionally intended value
			hashTable->insert(choice);
		} 
        else if (choice == 2) // display erase menu and then insert provided value
        {
            choice = menu(2);
            
			if (!hashTable->remove(choice)) 
            {
				cout << "\nThe number entered is not in the list.\n";
			}
		} 
        else if (choice == 3) // print list contents
        {
			cout << endl;
			hashTable->print();
		}
        
    } while (choice != 4);// exit when user selects option 4
}


int nextPrime(int prime)
{
    int primeCandidate = prime+1;
    while (! primeCheck(primeCandidate))
    {
        primeCandidate++;
    }
    return primeCandidate;
}

bool primeCheck(int value)
{
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


int menu(int type){
    
    int choice = -1;
    
    switch (type)
    {
        case 0: // main menu
            while (choice != 1 and choice != 2 and choice != 3 and choice != 4) 
            {
                cout << endl << ".........................................................." << endl;
                if (choice != -1)
                {
                    cout << endl << endl << "Invalid selection, please try again";
                }
                cout << endl << "Please choose one of the following commands:" << endl;
                cout << "1 - insert" << endl;
                cout << "2 - delete" << endl;
                cout << "3 - print"  << endl;
                cout << "4 - exit"   << endl;
                cout << "> "         << "";
                cin >> choice;
            }
            return choice;
            break;
        case 1: // insert menu
            cout << "What number do you want to insert into the hash table?" << endl;
            cout << "> ";
            cin >> choice;
            return choice;
            break;
        case 2: // erase menu
            cout << "What number do you want to remove from the hash table?" << endl;
            cout << "> ";
            cin >> choice;
            return choice;
            break;
        default: 
            return -1;
            break;
    }
}