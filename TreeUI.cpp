#include "Node.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    /* 
    // Auskommentiert, damit die Nummerierung der Nodes in
    // den letzten Aufgaben von 1 beginnt
    std::string name = "root Node";
    Node* root1 = new Node(&name);    
    name = "left child Node";
    Node* left_child = new Node(&name);
    root1->addChild(left_child);
    name = "right child Node";
    Node* right_child = new Node(&name);
    root1->addChild(right_child);
    delete root1;
    */

    Node* root = new Node();
    try{
        root->createCompleteTree(2,4);
        root->createCompleteTree(2,-1);
    }catch (const char* msg){
        cout << "An error occured: " << msg << endl;
    }
    //root->print(cout, 0);
    cout << *root;
    delete root;
    return 0;
}