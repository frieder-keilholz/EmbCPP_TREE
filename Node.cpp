/**
  @file    Node.cpp
  @author  Frieder Keilholz
  @date    29.03.2020
  @brief   Implementierung der Node-Klasse
*/

#include "Node.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int Node::id = 1;

// Konstruktor ohne Parameter, Name wird automatisch generiert
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

/*  Konstruktor
    @param nameIn Name des Nodes
    Wird kein Name angegeben, wird er aus ID generiert
*/
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

/*  Destruktor, löscht alle Kindknoten
*/
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

/*  Getter für Namen
    @return Name des Nodes
*/
string Node::getName() const
{
  return name;
};

/*  Setter für den Namen
    @param nameIn Name, der gesetzt werden soll
*/
void Node::setName(string* nameIn)
{
  name = *nameIn;
};

/*  Gibt Anzahl der Kindknoten aus
    @return Anzahl Kindknoten
*/
int Node::getNrOfChildren() const
{
  return children.size();
};

/*  Gibt den i-ten Kindknoten aus
    @param i Index des Kindnotens
    @return Referenz auf den Kindknoten
*/
Node* Node::getChild(const int i) const
{
  // Prüfung, ob der Angegebene Index valide ist
  if(i < this->getNrOfChildren() && i >= 0){
    return children[i];
  }else{
    return NULL;
  }
};

/*  

*/
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
};

void Node::print(std::ostream &str, int depth) const
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

ostream& operator<<(ostream& os, Node& node)
{
  node.print(os, 0);
  return os;
};