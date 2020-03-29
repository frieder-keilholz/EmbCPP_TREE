/**
 * @file    Node.cpp
 * @author  Frieder Keilholz
 * @date    29.03.2020
 * @brief   
*/

#include "Node.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Node::Node(const string* nameIn ) {
  name = *nameIn;
};

Node::~Node(){
  cout << "Delete Node " << this->getName() << " Number of childs: " << this->getNrOfChildren() << endl;
  for(int i = 0; i < this->getNrOfChildren();  i++){
    delete children[i];
  }
};

string Node::getName() const
{
  return name;
};

void Node::setName(string* nameIn){
  name = *nameIn;
};

int Node::getNrOfChildren() const{
  return children.size();
}

Node* Node::getChild(int i) const{
  if(i < this->getNrOfChildren()){
    return children[i];
  }else{
    return NULL;
  }
};

void Node::addChild(Node* child){
  children.push_back(child);
}