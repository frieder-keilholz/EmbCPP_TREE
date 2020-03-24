#include "Node.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Node::Node(string nameIn) {
  name = nameIn;
};

void Node::deleteChilds(){
  
}

string Node::getName()
{
  return name;
};

void Node::setName(string nameIn){
  name = nameIn;
};

