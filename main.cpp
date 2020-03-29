#include "Node.cpp"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  cout << "Hello World!" << endl << "Classe bauen:";
  Node *node = new Node("Node 1");

  cout << node->getName() << endl;
  
  node->setName("Node 1 :)");
  
  cout << node->getName() << endl;

  Node *child1 = new Node("Node 2");
  Node *child2 = new Node("Node 3");
  child1->addChild(child2);
  node->addChild(child1);

  delete node;

  return 0;
}
