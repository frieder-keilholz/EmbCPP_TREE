#ifndef Node_h
#define Node_h

#include <string>
#include <vector>

class Node
{
  private:
    std::string name;
    std::vector<Node*> children;
  public:
    Node(const std::string* name);
    ~Node();

    std::string getName();
    void setName(std::string* name);
    int numOfChilds();
    Node* getChild(int i);
    void addChild(Node* child);
};

#endif