#include "Node.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Node::Node(string nameIn) {
  name = nameIn;
};

Node::~Node(){
  cout << "Delete Node all children." << this->getName() << endl;
  /*
  for (vector<Node>::iterator i = children.begin(); i != children.end(); ++i)
  {
    cout << i->getName() << endl;
  }
  */
 if(this->numOfChilds()){
  delete &children[0];
 }
};

string Node::getName()
{
  return name;
};

void Node::setName(string nameIn){
  name = nameIn;
};

int Node::numOfChilds(){
  return children.size();
}

Node& Node::getChild(int i){
  if(i < this->numOfChilds()){
    return children[i];
  }else{
    return NULL;
  }
};

void Node::addChild(Node child){
  children.push_back(child);
}