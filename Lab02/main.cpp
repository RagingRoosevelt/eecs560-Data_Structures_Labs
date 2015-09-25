// main.cpp
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 02

#include "tree.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int menu(int type);

using namespace std;
int main(int argc, const char* argv[]) {
    Tree tree;

    // build the tree from the file
    tree.build();


    // main loop, waiting for user to select option 4
    int choice = -1;
    do
    {
        // display main menu and get user choice
        choice = menu(0);

        if (choice == 1) // ask the tree to print out what its largest value is
        {
            tree.largest();
        }
        else if (choice == 2) // ask the tree to print out how many leaves it has
        {
            tree.leaves();
        }
        else if (choice == 3) // print tree contents
        {
            tree.print();
        }

    } while (choice != 4);// exit when user selects option 4
    return 0;
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
                cout << "1 - Largest element" << endl;
                cout << "2 - Number of Leaves" << endl;
                cout << "3 - Print Tree"  << endl;
                cout << "4 - Exit"   << endl;
                cout << "> ";
                cin >> choice;
            }
            return choice;
            break;
    }
}
