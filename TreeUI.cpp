#include "Node.h"
#include <string>
#include <iostream>

int main()
{
    std::string name = "root Node";
    Node* root = new Node(&name);
    name = "left child Node";
    Node* left_child = new Node(&name);
    name = "right child Node";
    Node* right_child = new Node(&name);
    delete root;
    return 0;
}