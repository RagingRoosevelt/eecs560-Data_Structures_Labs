// main.cpp
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 02

#include "heap.h"
#include <fstream>
#include <iostream>

#include <cstdlib>
#include <ctime>

int menu(int type);
int randi(int max);

using namespace std;
int main() {
    Heap heap;
    
    // srand(time(NULL));
    
    // for (int i=1; i <= 15; i++)
    // {
        // heap.populate(randi(30));
    // }
    ifstream dataFile ("data.txt");
    int val;
    while (dataFile >> val)
    {
        heap.populate(val);
    }
    dataFile.close();
    heap.trickleDown();
    
    cout << "===================" << endl;
    heap.levelOrder();


    int choice = -1;
    do
    {
        // display main menu and get user choice
        choice = menu(0);

        switch (choice)
        {
            case 1: // insert
                heap.insert(menu(1));
                break;
            case 2: // delete min
                if (!heap.deleteMin())
                    cout << "warning: The heap was empty" << endl;
                break;
            case 3: // delete max
                if (!heap.deleteMax())
                    cout << "warning: The heap was empty" << endl;
                break;
            case 4: // remove
                if (!heap.remove(menu(2)))
                {
                    cout << "warning: The specified value wasn't found in the heap" << endl;
                }
                break;
            case 5: // level order
                heap.levelOrder();
                break;
            default:
                break;
        }

    } while (choice != 6);// exit when user selects option 4
    return 0;
}



int menu(int type){

    int choice = -1;

    switch (type)
    {
        case 0: // main menu
            //while (choice != 1 and choice != 2 and choice != 3 and choice != 4)
            //{
                cout << endl << ".........................................................." << endl;
                if (choice != -1)
                {
                    cout << endl << endl << "Invalid selection, please try again";
                }
                cout << endl << "Please choose one of the following commands:" << endl;
                cout << "1 - Insert element" << endl;
                cout << "2 - Delete min element" << endl;
                cout << "3 - Delete max element" << endl;
                cout << "4 - Remove an element" << endl;
                cout << "5 - Print level-order traversal" << endl;
                cout << "6 - Exit" << endl;
                cout << "> ";
                cin >> choice;
            //}
            return choice;
            break;
        case 1:
            cout << "Please enter the number that you want to be inserted into the heap\n> ";
            cin >> choice;
            return choice;
            break;

        case 2:
            cout << "Which number would you like to remove from the heap?\n> ";
            cin >> choice;
            return choice;
            break;
    }
}

int randi(int max)
{
    
    return rand() % max;
}
