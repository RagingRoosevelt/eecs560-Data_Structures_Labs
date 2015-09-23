#include "hash.h"
#include <fstream>
#include <iostream>

using namespace std;

int menu(int type);

int main()
{// read in data file, then display menu.  from menu selection, perform corresponding action.

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
        // insert the value
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


            // insert the originally intended value
			hashTable->insert(choice);
		}
        else if (choice == 2) // display erase menu and then insert provided value
        {
            choice = menu(2);

            // remove the value if possible
			if (!hashTable->remove(choice))
            {
				cout << "\nThe number entered is not in the list.\n";
			}
		}
        else if (choice == 3) // print list contents
        {
			cout << endl;
            // print the table
			hashTable->print();
		}

    } while (choice != 4);// exit when user selects option 4
}


int menu(int type)
{// display the main menu and sub menus.  return values entered by the user
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
        case 2: // remove menu
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
