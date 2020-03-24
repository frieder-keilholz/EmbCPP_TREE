#include "Node.cpp"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  cout << "Hello World!" << endl << "Classe bauen:";
  Node *node = new Node("Ich bin eine neue Klasse :]");
  cout << " ok" << endl;
  cout << node->getName() << endl;
  return 0;
}
