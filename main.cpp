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
  return 0;
}
