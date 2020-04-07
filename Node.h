#ifndef Node_H
#define Node_H

#define DEBUG

#include <iostream>
#include <string>
#include <vector>

class Node
{
  private:
  static int id;
    std::string name;
    std::vector<Node*> children;
  public:
    Node();
    Node(const std::string* name);
    ~Node();

    std::string getName() const;
    void setName(std::string* name);
    int getNrOfChildren() const;
    Node* getChild(const int i) const;
    void addChild(Node* child);
    Node* createCompleteTree(int nrChildNodes, int treeDepth);
    void print(std::ostream &str, int depth);
};

#endif