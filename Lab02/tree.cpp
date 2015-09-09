// Tree.cpp
// Theodore Lindsey
// EECS 560 (F'2015)
// Lab 02

#include "tree.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// construct the tree
Tree::Tree() {
    nodeRoot = NULL;
    leafCount = 0;
}


// destroy the tree
Tree::~Tree() {
    deleteNodeRecursor(nodeRoot);
}
void Tree::deleteNodeRecursor(Tree::Node* node){
    if (node!=NULL)
    {
        deleteNodeRecursor(node->nodeLeft);
        deleteNodeRecursor(node->nodeRight);
        delete node;
    }
}


void Tree::largest(){
    cout << "Largest element: "
         << largestRecursor(nodeRoot, nodeRoot->nodeLeft, nodeRoot->nodeRight);
}
int Tree::largestRecursor(Tree::Node* nodeSelf, Tree::Node* nodeLeft, Tree::Node* nodeRight){
    // recursivly determine the largest node
    int self  = nodeSelf->data;
    int left  = 0;// assume the left node doesn't exist
    int right = 0;// assume the right node doesn't exist

    if (nodeLeft != NULL)
    { // if the left node exists, ask it how large it and its decendent are
        left = largestRecursor(nodeLeft, nodeLeft->nodeLeft, nodeLeft->nodeRight);
    }

    if (nodeRight != NULL) 
    {// if the right node exists, ask it how large it and its decendent are
        right = largestRecursor(nodeRight, nodeRight->nodeLeft, nodeRight->nodeRight);
    }

    // between the current node and its decendents, return the maximum value
    return max(left, max(self, right));
}


void Tree::print(){
    cout << "Inorder: ";
    printRecursor(nodeRoot);
}
void Tree::printRecursor(Tree::Node* node){
    // recursivly print the value of each node
    // have the left node and its children print their values first
    // then print the value of this node
    // then have the right node and its children print their values
    if (node->nodeLeft != NULL)
    {
        printRecursor(node->nodeLeft);
    }
    cout << node->data << " ";
    if (node->nodeRight != NULL)
    {
        printRecursor(node->nodeRight);
    }
}


void Tree::leaves(){
    countLeavesRecursor(nodeRoot);
    cout << "Number of leaves: " << leafCount;
    leafCount = 0;
}
void Tree::countLeavesRecursor(Tree::Node* node){
    if ((node->nodeLeft == NULL) && (node->nodeRight == NULL))
    { // if neither the left or right child exists, this is a leaf.  increment the var
        leafCount++;
    }
    else
    { // this node isn't a leaf so let the children nodes check if they are leaves
        if (node->nodeLeft != NULL)
        {
            countLeavesRecursor(node->nodeLeft);
        }
        if (node->nodeRight != NULL)
        {
            countLeavesRecursor(node->nodeRight);
        }
    }
}


void Tree::build(){ // function to build the tree
        
        // count the number of lines in the file
        int numberOfLines = 0;
        ifstream dataFile("data.txt");
        while ( dataFile.good() )
        {
            string line;
            getline(dataFile, line);
            numberOfLines++;
        }
        dataFile.close();
        /*cout << "there are " << numberOfLines << " lines in the file\n";*/


        // reopen the data file to start back at the beginning
        dataFile.open("data.txt");
        
        
        
        int levelTarget = 0;
        while(!dataFile.eof() && levelTarget < numberOfLines-2)
        {
                if (nodeRoot == NULL)
                { // if the root doesn't exist, create it
                        int value;
                        dataFile >> value;
                        nodeRoot = new Node(value, NULL, NULL);
                }
                else
                { // starting with the root, decent down to the current level of leaves in order to give them children
                        /*cout << "\n\ntarget level is " << levelTarget << endl;*/
                        insertRecursor(nodeRoot, 0, levelTarget, dataFile);
                        levelTarget++;
                }
        }
        dataFile.close();
}
void Tree::insertRecursor(Tree::Node* node, int levelCurrent, int levelTarget, ifstream& dataFile){
    /*cout << "current level is " << levelCurrent << endl;*/
    if (node == NULL || !dataFile.good())
    { // this node isn't supposed to exist or we've reached eof, go back
            return;
    }
    else if (levelTarget == levelCurrent)
    {// create some nodes, if necessary
            /*cout << "  looking at node \"" << node->data << "\"" << endl;*/
            int valueL;
            int valueR;
            // get a pair of values from the text file
            dataFile >> valueL;
            dataFile >> valueR;
            if (valueL != 0)
            { // if we have a value for the left node, create it and establish the link
                    /*cout << "    inserting " << valueL << endl;*/
                    node->nodeLeft = new Node(valueL, NULL, NULL);
            }
            if (valueR != 0)
            {// if we have a value for the right node, create it and establish the link

                    /*cout << "    inserting " << valueR << endl;*/
                    node->nodeRight = new Node(valueR, NULL, NULL);
            }

    }
    else
    {//filter down the tree, if possible
            insertRecursor(node->nodeLeft, levelCurrent+1, levelTarget, dataFile);
            insertRecursor(node->nodeRight, levelCurrent+1, levelTarget, dataFile);
    }

}
