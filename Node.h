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

    std::string getName() const;
    void setName(std::string* name);
    int getNrOfChildren() const;
    Node* getChild(const int i) const;
    void addChild(Node* child);
};

#endif