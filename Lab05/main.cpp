// main.cpp
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 02

#include "bst.h"
#include <fstream>
#include <iostream>

int menu(int type);

using namespace std;
int main(int argc, const char* argv[]) {
    Tree tree;

    int valTemp;
    ifstream dataFile("data.txt");
    while (dataFile >> valTemp)
    {
        tree.insert(valTemp);
    }
    dataFile.close();
    
    // Lab assignment tests:
    if (false)
    {
        tree.deleteMin();
        tree.deleteMax();
        tree.remove(7);
        tree.preOrder();   // 8 3 6 13 9 10
        tree.insert(2);
        tree.insert(13);
        tree.insert(11);
        tree.insert(12);
        tree.insert(13);
        tree.preOrder();   // 8 3 2 6 13 9 10 11 12 13 13
        tree.remove(6);
        tree.remove(10);
        tree.remove(13);
        tree.remove(20); // not in tree
        tree.preOrder();   // 8 3 2 9 11 12
        tree.inOrder();    // 2 3 8 9 11 12
        tree.levelOrder(); // 8 3 9 2 11 12
    }


    // main loop, waiting for user to select option 4
    int choice = -1;
    do
    {
        // display main menu and get user choice
        choice = menu(0);

        switch (choice)
        {
            case 1:
                tree.insert(menu(1));
                break;
            case 2:
				if (!tree.remove(menu(2)))
				{
					cout << "warning: The specified value wasn't found in the tree." << endl;
				}
                break;
            case 3:
				if (!tree.deleteMin())
				{
					cout << "warning: No minimum value found.  The tree must be empty." << endl;
				}
                break;
            case 4:
				if (!tree.deleteMax())
				{
					cout << "warning: No maximum value found.  The tree must be empty." << endl;
				}
                break;
            case 5:
                tree.preOrder();
                break;
            case 6:
                tree.inOrder();
                break;
            case 7:
                tree.levelOrder();
                break;
            case 8:
                break;
            default:
                break;
        }

    } while (choice != 8);// exit when user selects option 4
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
                cout << "2 - Remove element" << endl;
                cout << "3 - Delete min element" << endl;
                cout << "4 - Delete max element" << endl;
                cout << "5 - Print pre-order traversal" << endl;
                cout << "6 - Print in-order traversal" << endl;
                cout << "7 - Print level-order traversal" << endl;
                cout << "8 - Exit"   << endl;
                cout << "> ";
                cin >> choice;
            //}
            return choice;
            break;
        case 1:
            cout << "Please enter the number that you want to be inserted into the tree\n> ";
            cin >> choice;
            return choice;
			break;
			
		case 2:
			cout << "Which number do you like to remove from the tree?\n> ";
			cin >> choice;
			return choice;
			break;
    }
}
