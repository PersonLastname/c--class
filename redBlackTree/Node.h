#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node {
 public:
  Node();
  Node(int data);
  ~Node();//destroy the node
  
  void setData(int newData);
  int getData();

  void setParent(Node * newPar);
  Node * getParent();

  Node * getGrand();

  Node * getAunt();

  Node * getSibling();

  Node * getSLC();

  Node * getSRC();

  void setLeft(Node * newLeft);
  Node * getLeft();
  
  void setRight(Node * newRight);
  Node * getRight();
  
 private:

  int data;

  Node * parent;
  Node * left;
  Node * right;
    
};

#endif
