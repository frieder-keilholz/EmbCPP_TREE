#include "Node.h"

#include <iostream>
#include <string>
#include <vector>

Node::Node(std::string nameIn) {
  name = nameIn;
};

std::string Node::getName()
{
  return name;
};

void Node::setName(std::string nameIn){
  name = nameIn;
};