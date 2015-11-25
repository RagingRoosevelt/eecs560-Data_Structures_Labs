// main.cpp
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 02

#include "binom_queue.h"
#include <fstream>
#include <iostream>

#include <cstdlib>
#include <ctime>

int menu(int type);
int randi(int max);

using namespace std;
int main() {
    BinomQueue queue;
    
    


    int choice = -1;
    do
    {
        // display main menu and get user choice
        choice = menu(0);

        switch (choice)
        {
            case 1: // insert
                queue.insert(menu(1));
                break;
            case 2: // delete min
                break;
            case 3: // level order
                queue.levelOrder();
                break;
            case 4: // exit
                break;
            default:
                break;
        }

    } while (choice != 4);// exit when user selects option 4
    return 0;
}



int menu(int type){

    int choice = -1;

    switch (type)
    {
        case 0: // main menu
            
            cout << endl << ".........................................................." << endl;
            if (choice != -1)
            {
                cout << endl << endl << "Invalid selection, please try again";
            }
            cout << endl << "Please choose one of the following commands:" << endl;
            cout << "1 - Insert element" << endl;
            cout << "2 - Delete min element" << endl;
            cout << "3 - Print level-order traversal" << endl;
            cout << "4 - Exit" << endl;
            cout << "> ";
            cin >> choice;
            while (choice != 1 and choice != 2 and choice != 3 and choice != 4)
            {
                cout << "warning: Invalid selection.  Please try again\n> ";
                cin >> choice;
            }
            return choice;
            break;
        case 1:
            cout << "Please enter the number that you want to be inserted into the heap\n> ";
            cin >> choice;
            return choice;
            break;
    }
}

int randi(int max)
{
    
    return rand() % max;
}
