#include "Node.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    /*
    std::string name = "root Node";
    Node* root = new Node(&name);
    name = "";
    
    name = "left child Node";
    Node* left_child = new Node(&name);
    root->addChild(left_child);
    //name = "right child Node";
    Node* right_child = new Node(&name);
    root->addChild(right_child);
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
    //std::cout << "Ich hab dich lieb <3"<< std::endl;
    delete root;
    return 0;
}