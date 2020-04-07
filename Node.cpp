/**
 * @file    Node.cpp
 * @author  Frieder Keilholz
 * @date    29.03.2020
 * @brief   
**/
#include "Node.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int Node::id = 1;

Node::Node()
{
    std::stringstream strSm;
    strSm << "node_" << Node::id;
    name = strSm.str();
    Node::id++;
    #ifdef DEBUG
    cout << "New node created: " << this->name << endl;
    #endif
};

Node::Node(const string* nameIn)
{  
  if(*nameIn == "")
  {
    std::stringstream strSm;
    strSm << "node_" << Node::id;
    name = strSm.str();
  }else
  {
    name = *nameIn;  
  }
  Node::id++;
  #ifdef DEBUG
  cout << "New node created: " << this->name << endl;
  #endif
};

Node::~Node()
{
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

void Node::setName(string* nameIn)
{
  name = *nameIn;
};

int Node::getNrOfChildren() const
{
  return children.size();
};

Node* Node::getChild(const int i) const
{
  if(i < this->getNrOfChildren()){
    return children[i];
  }else{
    return NULL;
  }
};

void Node::addChild(Node* child)
{
  children.push_back(child);
};

Node* Node::createCompleteTree(int nrChildNodes, int treeDepth)
{
  if(nrChildNodes < 1 || treeDepth < 1){
    throw "Invalid Parameter Values provided!";
  }
  if(treeDepth > 1){
    // create n child nodes
    for(int i = 0; i < nrChildNodes; i++)
    {
      Node* nNode = new Node();

      nNode->createCompleteTree(nrChildNodes,treeDepth-1);
      this->addChild(nNode);
    }
  }
  // return this Node
  return this;
};

void Node::print(std::ostream &str, int depth)
{
  string spacing = "";
  for(int i = 0; i < depth; i++){
    str << "  ";
  }
  str << this->getName() << endl;
  for(int i = 0; i < this->getNrOfChildren();i++)
  {
    this->getChild(i)->print(str, depth+1);
  }
};