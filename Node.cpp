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

int Node::id = 0;

Node::Node(const string* nameIn) {
  Node::id++;
  #ifdef DEBUG
  cout << "New node created: " << this->name << endl;
  #endif
};

Node::~Node(){
  //cout << "Delete Node " << this->getName() << " Number of childs: " << this->getNrOfChildren() << endl;
  #ifdef DEBUG
  cout << "enter ~node() of " << this->name << endl;
  #endif
  for(int i = 0; i < this->getNrOfChildren();  i++){
    delete children[i];
  }
  #ifdef DEBUG
  cout << "leave ~node() of " << this->name << endl;
  #endif
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
};

Node* Node::getChild(const int i) const{
  if(i < this->getNrOfChildren()){
    return children[i];
  }else{
    return NULL;
  }
};

void Node::addChild(Node* child){
  children.push_back(child);
};