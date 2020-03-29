#include <iostream>
#include <vector>

using namespace std;

int main()
{
  cout << "Hello World!" << endl << "Klasse bauen: ";
  string name = "Node 1";
  Node *node = new Node(&name);

  cout << node->getName() << endl;
  
  name = "Node 1 :-)";
  node->setName(&name);
  
  cout << node->getName() << endl;

  name = "Node 2";
  Node *child1 = new Node(&name);
  name = "Node 3";
  Node *child2 = new Node(&name);
  child1->addChild(child2);
  node->addChild(child1);

  delete node;

  return 0;
}
