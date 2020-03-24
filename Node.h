#ifndef Node_h
#define Node_h

#include <string>
#include <vector>

class Node
{
  private:
    std::string name;
    
  public:
    Node(std::string name);
    std::string getName();
};

#endif