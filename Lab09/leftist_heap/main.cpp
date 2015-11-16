// main.cpp
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 02

#include "heap_leftist.h"
#include <fstream>
#include <iostream>

#include <cstdlib>
#include <ctime>

int menu(int type);
int randi(int max);

using namespace std;
int main() {
    HeapLeftist heapL;

    int source = menu(2);
    if (source == 0)
    {
        // read from file
        ifstream file;
        file.open("data.txt");
        long int val;
        while (file >> val)
        {
            cout << "Inserting " << val << endl;
            heapL.insert(val);
        }
    }
    else if (source == 1)
    {
        // use sample data
        int values[] = {33, 36, 38, 15, 20, 25};
        srand(0);
        for (int i=0; i<6; i++)
        {
            cout << "Inserting " << values[i] << endl;
            heapL.insert(values[i]);
        }

        cout << "===================" << endl;
        heapL.levelOrder();
    }
    
    int choice = -1;
    do
    {
        // display main menu and get user choice
        choice = menu(0);

        switch (choice)
        {
            case 1: // insert
                heapL.insert(menu(1));
                break;
            case 2: // delete min
                heapL.deleteMin();
                break;
            case 3: // pre-order traversal
                heapL.preorder();
                break;
            case 4: // in-order traversal
                heapL.inorder();
                break;
            case 5: // level-order traversal
                heapL.levelOrder();
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
            while (choice < 1 || choice > 6)
            {
                if (choice != -1)
                {
                    cout << endl << "Invalid selection, please try again\n> ";
                }
                else
                {
                    cout << endl << ".........................................................." << endl;
                    cout << ".......................Leftist Heap......................." << endl;
                    cout << ".........................................................." << endl;
                    cout << "Please choose one of the following commands:" << endl;
                    cout << "1 - Insert element" << endl;
                    cout << "2 - Delete min element" << endl;
                    cout << "3 - Print pre-order traversal" << endl;
                    cout << "4 - Print in-order traversal" << endl;
                    cout << "5 - Print level-order traversal" << endl;
                    cout << "6 - Exit" << endl;
                    cout << "> ";
                }
                cin >> choice;
            }
            return choice;
            break;
        case 1:
            cout << "Please enter the number that you want to be inserted into the heap\n> ";
            cin >> choice;
            return choice;
            break;
        case 2:
        {
            string usrchoice = " ";
            cout << "\n\nHow would you like the heap to be initialized?" << endl;
            cout << "* with data from 'data.txt' (default, press enter)" << endl;
            cout << "* with data from a predefined test set (enter 'test')" << endl;
            cout << "* as an empty heap (enter 'empty')" << endl;
            cout << "> ";
            while (usrchoice != "" && usrchoice[0] != 't' && usrchoice[0] != 'e')
                getline(cin, usrchoice);
            
            if (usrchoice == "" || usrchoice[0] == 'd')
                return 0;
            else if (usrchoice[0] == 't')
                return 1;
            else
                return 2;
            break;
        }
    }
}



int randi(int max)
{
    return rand() % max;
}
