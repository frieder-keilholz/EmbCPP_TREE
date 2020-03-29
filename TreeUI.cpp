#include "Node.h"
#include <string>
#include <iostream>


int main()
{
    std::string name = "root Node";
    Node* root = new Node(&name);
    name = "left child Node";
    Node* left_child = new Node(&name);
    root->addChild(left_child);
    name = "right child Node";
    Node* right_child = new Node(&name);
    root->addChild(right_child);
    std::cout << "Ich hab dich lieb <3"<< std::endl;
    delete root;
    return 0;
}