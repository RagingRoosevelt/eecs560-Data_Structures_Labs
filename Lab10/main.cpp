// main.cpp
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 10

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
    
    int dataSource = menu(2);
    
    if (dataSource == 0)
        dataSource = 2;
    
    switch (dataSource)
    {
    case 1:        
        queue.insert(2);
        queue.insert(5);
        queue.insert(23);
        queue.insert(10);
        queue.insert(38);
        queue.insert(103);
        queue.insert(30);
        queue.insert(10);
        queue.insert(9293);
        queue.insert(99);
        queue.insert(90);
        queue.insert(20);
        queue.insert(234);
        queue.insert(234);
        queue.insert(329);
        queue.insert(2938);
        break;
    case 2:
        queue.insert(3);
        queue.insert(8);
        queue.insert(6);
        queue.insert(4);
        queue.insert(2);
        queue.insert(7);
        queue.insert(9);
        queue.insert(16);
        queue.insert(1);
        queue.insert(5);
        queue.insert(10);
        break;
    case 3:
        break;
    default:
        ifstream infile ;
        infile.open("data.txt");
        int val;
        while (infile >> val)
        {
            queue.insert(val);
        }
        infile.close();
        break;
    }


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
                if (!queue.deleteMin())
                {
                    cout << endl << "warning: Tree is empty!" << endl;
                }
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
        case 2:
        {
            string usrchoice = " ";
            cout << "How would you like the heap to be initialized?" << endl;
            cout << "1 - test case A" << endl;
            cout << "2 - test case B" << endl;
            cout << "3 - as an empty queue" << endl;
            cout << "  - from 'data.txt' (default)" << endl;
            cout << "> ";
            while (usrchoice != "" && usrchoice[0] != '1' && usrchoice[0] != '2' && usrchoice[0] != '3')
                getline(cin, usrchoice);
            
            if (usrchoice[0] == '1')
                return 1;
            else if (usrchoice[0] == '2')
                return 2;
            else if (usrchoice[0] == '3')
                return 3;
            else
                return 0;
            break;
        }
    }
}

int randi(int max)
{
    
    return rand() % max;
}
