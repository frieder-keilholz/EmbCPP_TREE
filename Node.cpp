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

Node::Node(string* nameIn) {
  name = *nameIn;
};

Node::~Node(){
  cout << "Delete Node " << this->getName() << " Number of childs: " << this->numOfChilds() << endl;
  for(int i = 0; i < this->numOfChilds();  i++){
    delete children[i];
  }
 /*
 if(this->numOfChilds()){
  delete &children[0];
 }
 */
};

string Node::getName()
{
  return name;
};

void Node::setName(string* nameIn){
  name = *nameIn;
};

int Node::numOfChilds(){
  return children.size();
}

Node* Node::getChild(int i){
  //if(i < this->numOfChilds()){
    return children[i];
  //}else{
  //  return ;
  //}
};

void Node::addChild(Node* child){
  children.push_back(child);
}