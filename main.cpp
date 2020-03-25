#include "Node.cpp"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  cout << "Hello World!" << endl << "Classe bauen:";
  Node *node = new Node("Ich bin eine Klasse!");

  cout << node->getName() << endl;
  
  node->setName("Und ich heiße jetzt anders :]");
  
  cout << node->getName() << endl;

  Node *child1 = new Node("Im child 1");
  Node *child2 = new Node("Im child 2");
  child1->addChild(*child2);
  node->addChild(*child1);

  delete node;

  return 0;
}
