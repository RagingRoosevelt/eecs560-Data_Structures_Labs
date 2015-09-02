// main.cpp
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 01

#include "list.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int menu(int type);

using namespace std;
int main(int argc, const char* argv[]) {
	List list;
    
    // prepare file for reading
	ifstream dataFile;
	dataFile.open("data.txt");
    
    // temp variables for reading the file into the linked list
    int value;
    char character;
    string temp;
	
    // read through the data file
	while (dataFile.good())
    {
        character = char(dataFile.get());
        // add characters to the temp string until a space is encountered, then insert into linked list
        if (character == ' ')
        {
            stringstream temps(temp);
            temps >> value;
            list.insert(value);
            //cout << value << endl;
            temp = "";
        } 
        else 
        {
            temp += character;
        }
    }
	dataFile.close();
    
	cout << endl << "data.txt elements:";
    list.print();

    
    // main loop, waiting for user to select option 4
    int choice = -1;
	do 
    {
        // display main menu and get user choice
        choice = menu(0);
        
		if (choice == 1) // display insert menu and then insert provided value
        {
            choice = menu(1);
			list.insert(choice);
		} 
        else if (choice == 2) // display erase menu and then insert provided value
        {
            choice = menu(2);
            
			if (!list.erase(choice)) 
            {
				cout << "\nThe number entered is not in the list.";
			}
		} 
        else if (choice == 3) // print list contents
        {
            
            cout << endl << "List:";
			list.print();
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
            cout << "Choose a number to be inserted to the list:" << endl;
            cout << "> ";
            cin >> choice;
            return choice;
            break;
        case 2: // erase menu
            cout << "Choose a number to be deleted from the list:" << endl;
            cout << "> ";
            cin >> choice;
            return choice;
            break;
        default: 
            return -1;
            break;
    }
}